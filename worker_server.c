#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 9090
#define BUFFER_SIZE 1024

void handle_client(int client_sock);

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_sock, 3) < 0) {
        perror("Listen failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Worker server listening on port %d\n", PORT);

    while (1) {
        // Accept client connections
        if ((client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }
        
        printf("Connected to main server\n");

        handle_client(client_sock);
        close(client_sock);
    }

    close(server_sock);
    return 0;
}

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int result;

    while ((bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0)) > 0) {
        // Assuming the buffer contains a simple arithmetic operation like "2+2"
        int a, b;
        char op;
        sscanf(buffer, "%d%c%d", &a, &op, &b);
        switch(op) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
            default: strcpy(buffer, "Invalid operation"); send(client_sock, buffer, strlen(buffer), 0); continue;
        }
        sprintf(buffer, "Result: %d", result);
        send(client_sock, buffer, strlen(buffer), 0);
    }
}
