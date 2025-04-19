#ifndef PARSE_HPP
#define PARSE_HPP


#include <string>
#include <vector>
#include <iostream>



class Server;
class Client;

class parse
{
    private:
        std::string cmd;
        std::string arg;
        std::vector<std::string> channels;
        std::vector<std::string> keys;

    public:
        parse(char *buff,Server *server,Client *client);
        int cmd_lenght(std::string str);


};




#endif