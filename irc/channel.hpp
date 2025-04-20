#ifndef CHANNEL_HPP
#define CHANNEL_HPP


#include <string>
#include <vector>

class Client;

class channel
{
    private:
        std::string name;
        std::string topic;
        std::vector<Client*> users;
    public:
        channel(std::string name) : name(name) {} //-> constructor
        std::string GetName() { return name; } //-> getter for name
        void add_client(Client *c)
        {
            users.push_back(c);
        }
        int client_exist(Client *c)
        {
            for(size_t i = 0; i < users.size();i++)
            {
                if(users[i] == c)
                    return 1;
            }
            return 0;
        }
};




#endif