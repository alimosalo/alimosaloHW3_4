#include "user.h"
User::User(std::string username ,std::string private_key,Server* server):username{username}
,private_key{private_key}
,server{server}
{
}
bool User::send_text_message(std::string text, std::string receiver)
{
    bool flag{};
    for(auto x:server->get_users())
    {
      if(x.get_username()==receiver)
      {flag =true ;
       break ; 
      }

    }
    if(receiver=="") {return false;}
    if(flag==false) {return false; }
    
  TextMessage msg(text,username,receiver);
   std::string signature = crypto::signMessage(private_key, username);
   bool t = server->create_message(&msg,signature);
   if(t==false){ return false;}
    return true ; 
}
bool User::send_voice_message(std::string receiver)
{
  bool flag{};
    for(auto x:server->get_users())
    {
      if(x.get_username()==receiver)
      {flag =true ;
       break ; 
      }

    }
    if(receiver=="") {return false;}
    if(flag==false) {return false; }
    VoiceMessage msg(username,receiver);
    std::string signature = crypto::signMessage(private_key, username);
    bool t = server->create_message(&msg,signature);
    if(t==false){ return false;}
    return true ; 

}