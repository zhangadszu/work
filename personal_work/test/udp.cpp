#include <strings.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>

using namespace std;

int main()
{
	int fd1 = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd1 < 0)
	{
		cout<<"socket error:"<<fd1<<" "<<__LINE__<<endl;
		return -1;
	}
	struct sockaddr_in svr_addr;
	bzero(&svr_addr, sizeof(svr_addr));
	svr_addr.sin_family = AF_INET;
	inet_aton("10.12.18.75", &svr_addr.sin_addr);
	svr_addr.sin_port = htons(20121);
	
	int ret = bind(fd1, (sockaddr*)&svr_addr, sizeof(svr_addr));
	if(ret != 0)
	{
		cout<<"bind error "<<ret<<" "<<__LINE__<<endl;
	}
	
	
	int fd2 = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd2 < 0)
	{
		cout<<"socket error:"<<fd2<<" "<<__LINE__<<endl;
		return -1;
	}
	struct sockaddr_in cli_addr;
	bzero(&cli_addr, sizeof(cli_addr));
	cli_addr.sin_family = AF_INET;
	inet_aton("10.12.18.75", &cli_addr.sin_addr);
	cli_addr.sin_port = htons(20122);
	ret = bind(fd2, (sockaddr*)&cli_addr, sizeof(cli_addr));
	if(ret != 0)
	{
		cout<<"bind error "<<ret<<" "<<__LINE__<<endl;
	}
	
	ret = connect(fd2, (sockaddr*)&svr_addr, sizeof(svr_addr));
	if(ret != 0)
	{
		cout<<"connect error "<<ret<<" "<<__LINE__<<endl;
	}
	
	const char msg[] = "abcdefg";
	char buf[128] = {0};
/*
	cout<<"send"<<send(fd2, msg, sizeof(msg), 0)<<" byte"<<endl;
	
	cout<<"recv "<<recvfrom(fd1, buf, sizeof(buf), 0, NULL, 0)<<" byte: "<<msg<<endl;

	cout<<"sendto "<<sendto(fd1, msg, sizeof(msg), 0, (sockaddr*)&cli_addr, sizeof(cli_addr))<<" byte"<<endl;
	cout<<"sendto "<<sendto(fd1, msg, sizeof(msg), 0, (sockaddr*)&cli_addr, sizeof(cli_addr))<<" byte"<<endl;
*/

	int fd3 = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd3 < 0)
	{
		cout<<"socket error:"<<fd3<<" "<<__LINE__<<endl;
		return -1;
	}
	struct sockaddr_in svr_addr2;
	bzero(&svr_addr2, sizeof(svr_addr2));
	svr_addr2.sin_family = AF_INET;
	inet_aton("10.12.18.75", &svr_addr2.sin_addr);
	svr_addr2.sin_port = htons(20123);	
	ret = bind(fd3, (sockaddr*)&svr_addr2, sizeof(svr_addr2));
	if(ret != 0)
	{
		cout<<"bind error "<<ret<<" "<<__LINE__<<endl;
	}	
		
	close(fd2);	
	fd2 = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd2 < 0)
	{
		cout<<"socket error:"<<fd2<<" "<<__LINE__<<endl;
		return -1;
	}
	ret = bind(fd2, (sockaddr*)&cli_addr, sizeof(cli_addr));
	if(ret != 0)
	{
		cout<<"bind error "<<ret<<" "<<__LINE__<<endl;
	}

	cout<<"sendto "<<sendto(fd1, msg, sizeof(msg), 0, (sockaddr*)&cli_addr, sizeof(cli_addr))<<" byte "<<__LINE__<<endl;
	ret = connect(fd2, (sockaddr*)&svr_addr2, sizeof(svr_addr2));
	if(ret != 0)
	{
		cout<<"connect error "<<ret<<" "<<__LINE__<<endl;
	}
	
	char msg2[] ="123456789";
	cout<<"sendto "<<sendto(fd3, msg2, sizeof(msg2), 0, (sockaddr*)&cli_addr, sizeof(cli_addr))<<" byte "<<__LINE__<<endl;

	
	bzero(buf, sizeof(buf));
	cout<<"recv "<<recv(fd2, buf, sizeof(buf), 0)<<" byte: "<<msg<<" "<<__LINE__<<endl;
	cout<<"recv "<<recv(fd2, buf, sizeof(buf), 0)<<" byte: "<<msg<<" "<<__LINE__<<endl;
	cout<<"recv "<<recv(fd2, buf, sizeof(buf), 0)<<" byte: "<<msg<<" "<<__LINE__<<endl;
	
	
	return 0;
}
