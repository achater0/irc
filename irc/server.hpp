#ifndef SERVER_HPP
#define SERVER_HPP


#include<string>
#include <vector>
#include"client.hpp"
#include"channel.hpp"

class Server //-> class for server
{
private:
	int Port; //-> server port
	int SerSocketFd; //-> server socket file descriptor
	static bool Signal; //-> static boolean for signal
	std::vector<Client> clients; //-> vector of clients
	std::vector<struct pollfd> fds; //-> vector of pollfd
public:
	Server(){SerSocketFd = -1;} //-> default constructor

	void ServerInit(); //-> server initialization
	void SerSocket(); //-> server socket creation
	void AcceptNewClient(); //-> accept new client
	void ReceiveNewData(int fd); //-> receive new data from a registered client

	static void SignalHandler(int signum); //-> signal handler
	
	void CloseFds(); //-> close file descriptors
	void ClearClients(int fd); //-> clear clients
	Client* get_client(int fd)
	{
		for(size_t i = 0; i < clients.size();i++)
		{
			if(clients[i].GetFd() == fd)
				return &clients[i];
		}
		return NULL;
	}
};


#endif