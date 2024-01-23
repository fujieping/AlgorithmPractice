#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>
#include <pthread.h>
#include <stdlib.h>

#define SERVER_PORT 8868
#define LISTEN 128
#define BUFFER_SIZE 128

int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket error");
        exit(-1);
    }

    /* 设置端口复用*/
    int enableOpt = 1;
    int ret = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (void *)&enableOpt, sizeof(enableOpt));
    if (ret == -1)
    {
        perror("setsockopt error");
        exit(-1);
    }

    struct sockaddr_in Server;
    memset(&Server, 0, sizeof(Server));

    Server.sin_family = AF_INET;
    Server.sin_port = htons(SERVER_PORT);
    Server.sin_addr.s_addr = INADDR_ANY;

    ret = bind(sockfd, (struct sockaddr *)&Server, sizeof(Server));
    if (ret == -1)
    {
        perror("bind error");
        exit(-1);
    }

    ret = listen(sockfd, LISTEN);
    if (ret == -1)
    {
        perror("ret error");
        exit(-1);
    }

    struct sockaddr_in Client;
    memset(&Client, 0, sizeof(Client));

    int clientfd = 0;

    char clientduf[BUFFER_SIZE];
    memset(clientduf, 0, sizeof(clientduf));

    char serverduf[BUFFER_SIZE];
    memset(serverduf, 0, sizeof(serverduf));

    

    while (1)
    {
       socklen_t Clientlen = 0;
        clientfd = accept(sockfd, (struct sockaddr *)&Client, &Clientlen);
        if (clientfd == -1)
        {
            perror("client error");
            exit(-1);
        }

        ret = read(clientfd, clientduf, sizeof(clientduf));
        if (ret <= 0)
        {
            perror("read error");
            close(clientfd);
            break;
        }
        else
        {
            printf("client:%s\n", clientduf);

            strncpy(serverduf, "hhhhhhh", strlen("hhhhhhh"));

            write(clientfd, serverduf, sizeof(serverduf));
        }
        

    }

    close(sockfd);


    return 0;
}