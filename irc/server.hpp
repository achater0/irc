#ifndef SERVER_HPP
#define SERVER_HPP


#include<string>
#include <vector>
#include"client.hpp"
#include"channel.hpp"
#include <poll.h>

class Client; //-> forward declaration of client class
class channel; //-> forward declaration of channel class

class Server //-> class for server
{
private:
	int Port; //-> server port
	int SerSocketFd; //-> server socket file descriptor
	static bool Signal; //-> static boolean for signal
	std::vector<Client> clients; //-> vector of clients
	std::vector<struct pollfd> fds; //-> vector of pollfd
	std::vector<channel> channels; //-> vector of channels
public:
	Server(){SerSocketFd = -1;} //-> default constructor
	void add_channel(std::string name,std::string key, int i) //-> add channel
	{
		channel c(name,key, i);
		channels.push_back(c);
	}
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
	int channel_exist(std::string channel_name)
	{
		for(size_t i = 0; i < channels.size();i++)
		{
			std::cout << "channel name: " << channel_name <<"?" << std::endl;
			if(channels[i].GetName() == channel_name)
				return 1;
		}
		return 0;
	}
	int client_exist(std::string channel_name, Client *client)
	{
		for(size_t i = 0; i < channels.size();i++)
		{
			if(channels[i].GetName() == channel_name)
			{
				if(channels[i].client_exist(client))
					return 1;
				else
					return 0;
			}
		}
		return 0;
	}
	void add_client_to_channel(std::string channel_name, Client *client)
	{
		for(size_t i = 0; i < channels.size();i++)
		{
			if(channels[i].GetName() == channel_name)
			{
				channels[i].add_client(client);
				return;
			}
		}
	}
	int channel_has_key(std::string channel_name)
	{
		for(size_t i = 0; i < channels.size();i++)
		{
			if(channels[i].GetName() == channel_name)
			{
				if(channels[i].GetKey() != "")
					return 1;
				else
					return 0;
			}
		}
		return 0;
	}
	std ::string get_channel_key(std::string channel_name)
	{
		for(size_t i = 0; i < channels.size();i++)
		{
			if(channels[i].GetName() == channel_name)
			{
				return channels[i].GetKey();
			}
		}
		return "";
	}
	void remove_client_from_channels(Client *client)
	{
		for(size_t i = 0; i < channels.size();i++)
		{
			if(channels[i].client_exist(client))
			{
				channels[i].remove_client(client);
			}
		}
	}
};


#endif