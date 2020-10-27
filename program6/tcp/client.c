#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define MAXLINE 1000
#define SERV_PORT 9002

void str_cli(FILE *fp, int sockfd)
{
    char sendline[MAXLINE], recvline[MAXLINE];
    while (fgets(sendline, MAXLINE, fp))
    {

        write(sockfd, sendline, strlen(sendline));

        if (read(sockfd, recvline, MAXLINE) == 0)
        {

            perror("str_cli: server terminated prematurely");
            exit(EXIT_FAILURE);
        }

        fputs(recvline, stdout);
    }
}

int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in servaddr;

    if (argc != 2)
    {
        perror("usage: tcpcli <IPaddress>");
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    str_cli(stdin, sockfd); /* do it all */
    exit(0);
}
