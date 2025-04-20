#ifndef CLIENT_HPP
#define CLIENT_HPP

#include<string>
#include<vector>
#include <string>
#include <sys/socket.h>

class channel;

class Client //-> class for client
{
private:
	int Fd; //-> client file descriptor
	std::string IPadd; //-> client ip address
public:
	Client(){}; //-> default constructor
	int GetFd(){return Fd;} //-> getter for fd

	void SetFd(int fd){Fd = fd;} //-> setter for fd
	void setIpAdd(std::string ipadd){IPadd = ipadd;} //-> setter for ipadd
	void send_msg(std::string msg)
	{
		//-> send message to client
		std::cout << "Sending message to client: " << msg << std::endl;
		send(Fd, msg.c_str(), msg.length(), 0);
	}
};



#endif