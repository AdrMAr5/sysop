#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT_NO 5000
#define BUFFER_SIZE 256

void handleClient(int sockfd)
{
    char buffer[BUFFER_SIZE];
    int n;

    while (1)
    {
        memset(buffer, 0, BUFFER_SIZE);
        n = read(sockfd, buffer, BUFFER_SIZE - 1);
        if (n < 0)
        {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Received message from client: %s\n", buffer);

        if (strcmp(buffer, "exit\n") == 0)
        {
            break;
        }

        n = write(sockfd, "Message received by server", BUFFER_SIZE - 1);
        if (n < 0)
        {
            perror("ERROR writing to socket");
            exit(1);
        }
    }
}

int main()
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    portno = PORT_NO;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while (1)
    {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0)
        {
            perror("ERROR on accept");
            exit(1);
        }

        handleClient(newsockfd);

        close(newsockfd);
    }

    close(sockfd);

    return 0;
}
