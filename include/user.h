#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include "server.h"
#include "crypto.h"
class Server ; 
class User
{
public:
User(std::string username, std::string private_key, Server* const server);
std::string get_username() {return username;}
bool send_text_message(std::string text, std::string receiver);
bool send_voice_message(std::string receiver);
    std::string private_key;  // private key of the user
    Server* const server;     // a pointer to the server for communications
private:
    std::string username;     // username of the user
};
#endif
