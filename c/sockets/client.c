#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>       // close()
#include <arpa/inet.h>    // inet_pton(), htons()
#include <sys/socket.h>   // socket functions

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int sock;
    
    struct sockaddr_in server_addr;
    
    // buffer for reading data
    char buffer[BUFFER_SIZE];

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // create server/target address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // convert ip string to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0)
    {
        perror("invalid or unsupported address");
        exit(EXIT_FAILURE);
    }

    // connect to server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("failed to connect to server");
        exit(EXIT_FAILURE);
    }

    // send message
    char* msg = "hellu >w<";
    send(sock, msg, strlen(msg), 0);
    printf("sent: %s\n", msg);

    // read response from server
    memset(buffer, 0, BUFFER_SIZE);
    read(sock, buffer, BUFFER_SIZE);
    printf("response: %s\n", buffer);

    // close socket
    close(sock);

    // end program without error
    return 0;
}

