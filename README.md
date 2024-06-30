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

## Authors

- Min Khant Soe Oke
- Kaung Sithu
