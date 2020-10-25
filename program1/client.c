#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    int create_socket;
    int bufsize = 1024, cont;
    char *buffer = malloc(bufsize);
    char fname[256];
    struct sockaddr_in address;

    if ((create_socket = socket(AF_INET, SOCK_STREAM, 0)) > 0)
        printf("The Socket was created\n");
    else
        exit(0);

    address.sin_family = AF_INET;
    address.sin_port = htons(15000);
    inet_pton(AF_INET, argv[1], &address.sin_addr);

    if (connect(create_socket, (struct sockaddr *)&address, sizeof(address)) == 0)
        printf("The connection was accepted with the server %s...\n", argv[1]);
    else
        exit(0);

    printf("Enter The Filename to Request : ");
    scanf("%s", fname);
    send(create_socket, fname, sizeof(fname), 0);
    printf("Request Accepted by server...Waiting to receive contents of file...\n\n");
    printf("Result obtained, the contents of file are...\n\n");
    while ((cont = recv(create_socket, buffer, bufsize, 0)) > 0)
    {
        write(1, buffer, cont);
    }
    printf("\nEOF\n");
    return close(create_socket);
}
// int main(int argc,char *argv[]){
//     int sockfd = socket(AF_INET,SOCK_STREAM,0);

//     if(sockfd > 0){
//         printf("Client socket created successfully\n");
//     } else {
//         printf("Socket creation failed\n");
//         exit(0);
//     }

//     struct sockaddr_in addr;
//     addr.sin_family = AF_INET;
//     inet_pton(AF_INET,argv[1],&addr.sin_addr);
//     addr.sin_port = htons(15000);

//     if(connect(sockfd,(struct sockaddr*)&addr,sizeof(addr))==0){
//         printf("The connection was accepted with the server %s",inet_ntoa(addr.sin_addr));
//     }
//     char fname[256];

//     printf("Enter the filename to request: ");
//     scanf("%s",fname);

//     send(sockfd,fname,sizeof(fname),0);
//     printf("Request accepted... Receiving file...\n\n");
//     printf("the contents of the file are ... : ");
//     int cont,buffsize=1024;
//     char buffer[buffsize];
//     while((cont=recv(sockfd,buffer,buffsize,0)) > 0){
//         write(1,buffer,cont);
//     }
//     printf("EOF\n");
//     close(sockfd);

//     return 0;
// }
