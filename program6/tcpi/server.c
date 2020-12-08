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
#define LISTENQ 1024
void str_echo(int sockfd)
{
    ssize_t n;
    char buf[1000];

again:

    while ((n = read(sockfd, buf, 1000)) > 0)
    {
        write(sockfd, buf, n);
        memset(buf, '\0', strlen(buf));
    }

    if (n < 0 && errno == EINTR)
        goto again;
    else if (n < 0)
        perror("str_echo: read error");
}

int main()
{
    int listenfd, connfd;
    id_t childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    listen(listenfd, LISTENQ);

    for (;;)
    {
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
        // if ((childpid = fork()) == 0)
        // {                     /* child process */
        //     close(listenfd);  /* close listening socket */
        //     str_echo(connfd); /* process the request */
        //     exit(0);
        // }
        str_echo(connfd);
        close(connfd); /* parent closes connected socket */
    }
}
