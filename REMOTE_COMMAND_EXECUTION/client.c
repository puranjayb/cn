#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define SERVER_IP "127.0.0.1"
#define BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_address;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    
    inet_pton(AF_INET, SERVER_IP, &server_address.sin_addr);

    connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    char message[] = "open";
    send(client_socket, message, strlen(message), 0);
    printf("Message sent to server: %s\n", message);

    close(client_socket);

    return 0;
}
