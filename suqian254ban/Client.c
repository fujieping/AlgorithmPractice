#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>
#include <error.h>
#include <stdlib.h>

#define CLIENT_PORT 8868
#define INET_PTON "192.168.204.128" 
#define BUFFER_SIZE 128

int main()
{
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd == -1)
    {
        perror("sockfd error");
        exit(-1);
    }

    struct sockaddr_in client;
    memset(&client, 0, sizeof(client));

    client.sin_family = AF_INET;
    client.sin_port = htons(CLIENT_PORT);

    int ret = inet_pton(AF_INET, INET_PTON, (void *)&client.sin_addr.s_addr);
    if (ret == -1)
    {
        perror("inet_pton error");
        exit(-1);
    }


    ret = connect(sockfd, (struct sockaddr*)&client, sizeof(client));
    if (ret == -1)
    {
        perror("connect error");
        exit(-1);
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    char recvBuffer[BUFFER_SIZE];
    memset(recvBuffer, 0, sizeof(recvBuffer));

    while (1)
    {

        strncpy(buffer, "123456", sizeof(buffer) - 1);

        write(sockfd, buffer, sizeof(buffer));

        sleep(1);

        read(sockfd, recvBuffer, sizeof(recvBuffer));

        printf("recv:%s\n", recvBuffer);
    }

    close(sockfd);



    return 0;
}