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
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(12349);
	
	len1=sizeof(client);
	len2=sizeof(server);
	
	bind(sd,(struct sockaddr*)&server,len2);
	do
	{
	recvfrom(sd,rm,20,0,(struct sockaddr*)&client,&len1);
	printf("client Says : %s\n",rm);
	printf("Server Says : ");
	fgets(sm,20,stdin);
	len=strlen(sm);
	sm[len-1]='\0';
	sendto(sd,sm,len,0,(struct sockaddr*)&client,len1);
	}
	while(strcmp(sm,"bye")!=0);
}
