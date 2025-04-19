#ifndef CHANNEL_HPP
#define CHANNEL_HPP


#include <string>
#include <vector>

class client;

class channel
{
    private:
        std::string name;
        std::string topic;
        std::vector<client*> users;
};




#endif