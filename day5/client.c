#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void)
{
    // ① 创建 socket（像「开一个寄件窗口」）
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // ② 填写服务器地址（像「填写收件人地址」）
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // ③ 连接服务器（像「给快递点打电话」）
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }
    printf("Connected to server!\n");

    // ④ 发数据（像「把包裹扔进窗口」）
    const char *msg = "Hello TCP!";
    send(sock, msg, strlen(msg), 0);
    printf("Sent: %s\n", msg);

    // ⑤ 收回显（像「等回单」）
    char buffer[1024] = {0};
    ssize_t n = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (n > 0) {
        printf("Received echo: %s\n", buffer);
    }

    // ⑥ 挂断（像「挂电话」）
    close(sock);
    printf("Client shutdown.\n");
    return 0;
}