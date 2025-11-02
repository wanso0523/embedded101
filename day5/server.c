#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void)
{
    // ① 创建 socket（像「开一个快递窗口」）
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        return 1;
    }

    // ② 绑定地址（像「把窗口挂在 127.0.0.1:8080」）
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return 1;
    }

    // ③ 监听（像「挂牌：现在开始收件」）
    if (listen(server_fd, 1) == -1) {
        perror("listen");
        return 1;
    }
    printf("Server listening on 127.0.0.1:8080\n");

    // ④ 等待连接（像「等客户敲门」）
    struct sockaddr_in client_addr;
    socklen_t addrlen = sizeof(client_addr);
    int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen);
    if (client_fd == -1) {
        perror("accept");
        return 1;
    }
    printf("Client connected!\n");

    // ⑤ 收数据（像「拿快递」）
    char buffer[1024] = {0};
    ssize_t n = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
    if (n > 0) {
        printf("Received: %s\n", buffer);
        // ⑥ 回数据（像「快递回单」）
        send(client_fd, buffer, n, 0);
        printf("Echoed back!\n");
    }

    // ⑦ 关门（像「下班锁门」）
    close(client_fd);
    close(server_fd);
    printf("Server shutdown.\n");
    return 0;
}