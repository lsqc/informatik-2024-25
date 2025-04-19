#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>       
#include <arpa/inet.h>    
#include <sys/socket.h>   

#define PORT 8080
#define BACKLOG 5
#define BUFFER_SIZE 1024

int main()
{
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    socklen_t addr_len = sizeof(client_addr);

    // create socket (IPv4, TCP, standard protocol)
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set address and port
    server_addr.sin_family = AF_INET;         
    server_addr.sin_addr.s_addr = INADDR_ANY; // all available addresses on the current host
    server_addr.sin_port = htons(PORT);       // port in network byte order  
    
    // bind socket to address
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // listen for connections
    if (listen(server_fd, BACKLOG) < 0)
    {
        perror("listening failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("listening on port %d...\n", PORT);

    // try to accept connection
    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
    if (client_fd < 0)
    {
        perror("failed to accept connection");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("connection accepted\n");

    // receive data
    memset(buffer, 0, BUFFER_SIZE);
    ssize_t bytes_read = read(client_fd, buffer, BUFFER_SIZE);
    printf("received data: %s\n", buffer);
    
    printf("received data (binary):\n");
    for (ssize_t i = 0; i < bytes_read; ++i)
    {
        for (int bit = 7; bit >= 0; --bit)
        {
            putchar((buffer[i] >> bit) & 1 ? '1' : '0');
        }
        putchar(' '); 
    }
    putchar('\n');
    
    printf("received data (hex):\n");
    for (ssize_t i = 0; i < bytes_read; ++i)
    {
        printf("0x%02x ", (unsigned char)buffer[i]);
    }

    putchar('\n');

    // send response
    char* reply = "hello owo";
    write(client_fd, reply, strlen(reply));

    // close connections
    close(client_fd);
    close(server_fd);

    return 0;
}

