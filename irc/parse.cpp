#include "parse.hpp"


int parse::cmd_lenght(std::string str)
{
    int i = 0;
    while(str[i] && str[i] != ' ')
        i++;
    return i;
}

void parse::execute_join(std::string arg, Server *server, Client *client)
{
    std::string ch;
    std::string key;
    int i = 0;
    while(arg[i] && arg[i] != ' ')
        i++;
    ch = arg.substr(0, i);
    if(arg[i])
        key = arg.substr(i + 1);
    if(key == "0")
    {
        // remove client from all channels
    }
    std::stringstream ss(ch);
    std::string token;

    while (std::getline(ss, token, ','))
    {
        channels.push_back(token);
    }
    std::stringstream ss2(key);
    while (std::getline(ss2, token, ','))
    {
        keys.push_back(token);
    }
    int j = 0;
    while (j < channels.size())
    {
        if (channels[j][0] != '#')
        {
            client->send_msg("ERR_NOSUCHCHANNEL\n");
            std::cout << "ERR_NOSUCHCHANNEL" << std::endl;
        }
        else if (channels[j][0] == '#')
        {
            if(server->channel_exist(channels[j]))
            {
                if (server->client_exist(channels[j], client))
                {
                    std::cout << "Client already in channel" << std::endl;
                    client->send_msg("ERR_USERONCHANNEL\n");
                }
                else
                {
                   std :: cout << "add clint to channel" << std::endl;
                   if () // check if has key
                   else
                   {
                        server->add_client_to_channel(channels[j], client);
                   }
                }
            }
            else
            {
                server->add_channel(channels[j]);
                server->add_client_to_channel(channels[j], client);
                std::cout << "Channel created" << std::endl;
            }
        }
        j++;
    }

}

void parse::execute_cmd(std::string cmd, std::string arg, Server *server, Client *client)
{
    if(cmd == "JOIN")
    {
        execute_join(arg, server, client);
    }
}

parse::parse(char* buff, Server* server, Client* client)
{
    int len = cmd_lenght(buff);
    cmd = std::string(buff, len);
    arg = std::string(buff + len + 1);
    execute_cmd(cmd, arg, server, client);
}