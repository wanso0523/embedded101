#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void)
{
    int sock = socket(AF_INET,SOCK_STREAM,0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;
    
    if (bind(sock,(struct sockaddr *)&addr,sizeof(addr)) == -1) {
        perror("bind");
        return 1;
    }
    printf("client connected!\n");

    char buffer[1024] = {0};
    socket client_fd = accept(server_fd,NULL,NULL);
    ssize_t n = recv(client_fd,buffer,sizeof(buffer) - 1,0);
    if (n > 0) {
        printf("received: %s\n",buffer);
        send(client_fd,buffer,n,0);
        printf("echoed back!\n");
    }

    close(client_fd);
    close(sock);
    printf("server shutdown.\n");
    return 0;
}