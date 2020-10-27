#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define SERV_PORT 9002
#define MAXLINE 1024

void dg_cli(FILE *fp, int sockfd, const struct sockaddr *pservaddr, socklen_t servlen)
{

    int n;

    char sendline[MAXLINE], recvline[MAXLINE + 1];

    while (fgets(sendline, MAXLINE, fp) != NULL)
    {
        sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);
        n = recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL);

        recvline[n] = '\0';
        /* null terminate */
        fputs(recvline, stdout);
    }
}

int main(int argc, char **argv)
{

    int sockfd;

    struct sockaddr_in servaddr;

    if (argc != 2)
    {
        perror("usage: udpcli <IPaddress>");
        exit(-1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    dg_cli(stdin, sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    exit(0);
}
