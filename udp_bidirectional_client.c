#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void main()
{
	int sd,len,len1,len2;
	char sm[20],rm[20];
	struct sockaddr_in client,server;
	sd = socket(AF_INET,SOCK_DGRAM,0);
	
	client.sin_family = AF_INET;
	client.sin_addr.s_addr = htonl(INADDR_ANY);
	client.sin_port = htons(12349);
	
	len1 = sizeof(client);
	len2 = sizeof(server);
	do
	{
	printf("Client Says : ");
	fgets(sm,20,stdin);
	len=strlen(sm);
	sm[len-1]='\0';
	sendto(sd,sm,len,0,(struct sockaddr*)&client,len1);
	printf("Server Says : ");
	recvfrom(sd,rm,20,0,(struct sockaddr*)&server,&len2);
	printf("%s\n",rm);
	}
	while(strcmp(rm,"bye")!=0);
}
