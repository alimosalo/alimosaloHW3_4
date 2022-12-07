#ifndef SERVER_H
#define SERVER_H
#include <string>
#include <vector>
#include <iostream>
#include "message.h"
#include <map>
#include <algorithm>
#include <functional>
class User ; 
class Server
{
public:
Server()=default ; 
//GETTER FUNCTIONS
std::vector<User> get_users() {return users;}
std::map<std::string, std::string> get_public_keys(){return public_keys;}
std::vector<Message*> get_messages(){return messages;}
//MEMBER FUNCTIONSs
User create_user(const std::string );
bool create_message(Message* msg, std::string signature);
//STL////////////
std::vector<Message*> get_all_messages_from(std::string username);
std::vector<Message*> get_all_messages_to(std::string username);
std::vector<Message*> get_chat(std::string user1, std::string user2);
static void sort_msgs(std::vector<Message*>& msgs);
private:
    std::vector<User> users;                        // to store our users
    std::map<std::string, std::string> public_keys; // map usernames to their publickeys
    std::vector<Message*> messages;                 // to store all the messages sent by users

};
#endif