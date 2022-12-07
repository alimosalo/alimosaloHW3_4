// #include "server.h"
// #include "user.h"
#include "server.h"
#include "user.h"
User Server::create_user(const std::string username)
{
    for(auto x:users)
    {
        if(username==x.get_username())
            throw std::logic_error("logic_error");

    }
    std::string public_key {},private_key{};
    crypto::generate_key(public_key,private_key);
    public_keys.insert(std::pair<std::string,std::string>(public_key,private_key));
    User temp(username,private_key,this);
    users.push_back(temp);

    
    return temp ;
}
bool Server::create_message(Message* msg, std::string signature)
{   
    std::map<std::string,std::string>::iterator itr; 
    bool authentic ; 
    for(itr=public_keys.begin();itr!=public_keys.end();itr++)
    {
        
        for(auto x:get_users())
            {
                    
                  authentic = crypto::verifySignature(itr->first, x.get_username(), signature);
                  if(authentic==true)
                  {
                    if(msg->get_type()=="text")
                    {
                    TextMessage* textmsg = reinterpret_cast<TextMessage*>(msg);
                    TextMessage* a =new TextMessage{*textmsg};
                    messages.push_back(a);
                    }
                    else{
                    VoiceMessage* textmsg = reinterpret_cast<VoiceMessage*>(msg);
                    VoiceMessage* a =new VoiceMessage{*textmsg};
                    messages.push_back(a);
                    
                    }
                    
                    
                    return true ;
                  }
            }
    }    
    
    return false; 
}
std::vector<Message*> Server::get_all_messages_from(std::string username)
{
    std::vector<Message*> a{};
    std::vector <int> t{1,2,4,5};
    std::for_each(messages.begin(),messages.end(),[username,&a](Message* k){
    if(k->get_sender()==username)
    {a.push_back(k);};});
    
    return a;
}
std::vector<Message*> Server::get_all_messages_to(std::string username)
{
    std::vector<Message*> a{};
    std::vector <int> t{1,2,4,5};
    std::for_each(messages.begin(),messages.end(),[username,&a](Message* k){
    if(k->get_receiver()==username)
    {a.push_back(k);};});
    
    return a;
}
std::vector<Message*> Server::get_chat(std::string user1, std::string user2)
{
    std::vector<Message*> t ;
    std::for_each(messages.begin(),messages.end(),[user1,user2,&t](Message* k)
    {
        if(k->get_receiver()==user1&&k->get_sender()==user2){t.push_back(k);}
        if(k->get_receiver()==user2&&k->get_sender()==user1){t.push_back(k);}
    }
    );
    return t ; 
}
 void Server::sort_msgs(std::vector<Message*> &msgs)
{
    
    std::sort(msgs.begin(),msgs.end(),[](const auto& time1, const auto& time2){
    return time1->get_time() < time2->get_time();
    });
    
}
