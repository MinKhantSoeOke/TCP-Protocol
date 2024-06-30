# TCP Client-Server Communication

**by**: Min Khant Soe Oke, Kaung Sithu

## Overview

This project demonstrates a TCP client-server communication model. It includes a main server, a worker server, and a client. The servers handle incoming connections and facilitate communication between clients, with one client acting as a data producer and another as a consumer. The focus is on understanding TCP/IP protocols, socket programming, and inter-process communication in a networked environment.

## Dependencies

**To run this project, you need to have the following dependencies installed:**

* GCC (GNU Compiler Collection)
* Standard C Libraries
* Basic knowledge of UNIX architecture and TCP/IP protocols

## Features

**TCP Server**
- Handles incoming connections using the TCP protocol.
- Listens for connections on a specified port.
- Accepts multiple client connections.
- Facilitates communication between clients.

**TCP Client**
- Connects to the server using the TCP protocol.
- Sends and receives data to/from the server.
- Acts as a data producer or consumer based on the implementation.

**Communication Model**
- The server coordinates data exchange between two clients.
- One client acts as a producer, sending data to the server.
- The server forwards the data to the consumer client.

## Example Execution

1. **Run the Main Server**:
    ```sh
    ./main_server
    ```
    Output:
    ```
    Main server listening on port 1000...
    ```

2. **Run the Worker Server**:
    ```sh
    ./worker_server
    ```
    Output:
    ```
    Worker server listening on port 1001...
    ```

3. **Run the Client**:
    ```sh
    ./client <server_ip> 1000
    ```
    Replace `<server_ip>` with the IP address of the server machine.

    Output:
    ```
    Connected to server <server_ip> on port 1000.
    ```

4. **Client Interaction**:
    - **Producer Client**: Send data by typing and pressing Enter.
    - **Consumer Client**: Receive data and display it.

## How to Use

1. **Start the Main Server**:
    - Open a terminal and run `./main_server`.

2. **Start the Worker Server**:
    - Open another terminal and run `./worker_server`.

3. **Start the Clients**:
    - Open additional terminals for each client and run `./client <server_ip> 1000`.

4. **Producer Client**:
    - Type messages and press Enter to send data to the server.

5. **Consumer Client**:
    - Receive messages from the server and display them.

## Authors

- Min Khant Soe Oke
- Kaung Sithu
