#include "client.h"


int talks(int PORT) {
    int sockD = socket(AF_INET, SOCK_STREAM, 0);
  
    struct sockaddr_in servAddr;
  
    servAddr.sin_family = AF_INET;
    servAddr.sin_port
        = htons(PORT); // use some unused port number
    servAddr.sin_addr.s_addr = INADDR_ANY;
  
    int connectStatus
        = connect(sockD, (struct sockaddr*)&servAddr,
                  sizeof(servAddr));
  
    if (connectStatus == -1) {
        printf("Error...\n");
    }
  
    else {
        while(1){
            if (connectStatus == -1){
                exit(0);
            }
        char *Msg = malloc(sizeof(char)*256);
        char recMsg[255] = "";
        recv(sockD, &recMsg, sizeof(recMsg), 0);
        printf("Server: %s\n", recMsg);
        fgets(Msg, 256, stdin);
        printf("Moi: %s", Msg);
        send(sockD, Msg, strlen(Msg), 0);
        }
    }
    close(sockD);
}

void main(int argc, char *argv[]) {
        if (argc < 2) {
            printf("Usage: %s <ip address>", argv[0]);
        }else {
            talks(atoi(argv[1]));
        }
}