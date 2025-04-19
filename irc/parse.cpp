#include "parse.hpp"


int parse::cmd_lenght(std::string str)
{
    int i = 0;
    while(str[i] && str[i] != ' ')
        i++;
    return i;
}

parse::parse(char* buff, Server* server, Client* client)
{
    int len = cmd_lenght(buff);
    std::cout << len << std::endl;
}