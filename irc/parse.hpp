#ifndef PARSE_HPP
#define PARSE_HPP


#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "server.hpp"
#include "client.hpp"
// #include "channel.hpp"
// #include <iomanip>



class Server;
class Client;
class channel; //-> forward declaration of channel class

class parse
{
    private:
        std::string cmd;
        std::string arg;
        std::vector<std::string> channels;
        std::vector<std::string> keys;
        void execute_cmd(std::string cmd, std::string arg, Server *server, Client *client);
        int cmd_lenght(std::string str);
        void execute_join(std::string arg, Server *server, Client *client);

    public:
        parse(char *buff,Server *server,Client *client);


};




#endif