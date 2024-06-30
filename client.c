#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int client_sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Create socket
    if ((client_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Connect to server
    if (connect(client_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(client_sock);
        exit(EXIT_FAILURE);
    }

    printf("Connected to main server\n");

    while(1){
        // Send a request
        printf("Enter an arithmetic operation (e.g., 2+2): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(client_sock, buffer, strlen(buffer), 0);

        // Receive response
        bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0);
        buffer[bytes_received] = '\0';
        printf("Response from server: %s\n", buffer);
    }
    
    close(client_sock);
    return 0;
}
