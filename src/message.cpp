#include "message.h"
Message::Message(const std::string _type,const std::string _sender,const std::string _receiver):type{_type}
,sender{_sender}
,receiver{_receiver}
{
// auto t {std::time(nullptr)};
// auto tm{*std::localtime(&t)};
// std::ostringstream oss ; 
// oss<<std::put_time(&tm,"%a %b %d %H:%M:%S %Y");
// time=oss.str(); //member variable time was initialized
std::time_t now = std::time(0);
    std::string time1 = std::ctime(&now);
    time1.erase(time1.find_last_not_of(" \n\r\t")+1);
    time =time1;
}
Message::Message():Message("","","")
{}
std::string Message::get_type()
{
    return type ; 
}
std::string Message::get_sender()
{
    return sender ; 
}
std::string Message::get_receiver()
{
    return receiver ; 
}
std::string Message::get_time()
{
    return time ; 
}
 void Message::print(std::ostream &os) 
{
    os<<std::string(25,'*')<<std::endl;
    os<<sender<<"->"<<receiver<<std::endl;
    os<<"message type: "<<type<<std::endl;
    os<<"message time: "<<time<<std::endl;
    os<<std::string(25,'*')<<std::endl;
}
TextMessage::TextMessage(std::string text, std::string _sender , std::string _receiver ):text{text}
,Message("text",_sender,_receiver)
{

}
 void TextMessage::print(std::ostream &os)
{
    os<<std::string(25,'*')<<std::endl;
    os<<Message::get_sender()<<"->"<<Message::get_receiver()<<std::endl;
    os<<"message type: "<<Message::get_type()<<std::endl;
    os<<"message time: "<<Message::get_time()<<std::endl;
    os<<"text: "<<text<<std::endl;
    os<<std::string(25,'*')<<std::endl;
}
/////////VoiceMessage/////////
VoiceMessage::VoiceMessage(const std::string& _sender,const std::string& _receiver):
Message("voice",_sender,_receiver)
{
    std::random_device engine;
    for(size_t i{};i<5;i++)
    {
        voice.push_back(engine());
    }    
}
 void VoiceMessage::print(std::ostream &os)
{
    os<<std::string(25,'*')<<std::endl;
    os<<Message::get_sender()<<"->"<<Message::get_receiver()<<std::endl;
    os<<"message type: "<<Message::get_type()<<std::endl;
    os<<"message time: "<<Message::get_time()<<std::endl;

    os<<"voice: ";
    for(auto x:voice)
    {
        os<<static_cast<int>(x)<<' ';

    }
    os<<std::endl;
    os<<std::string(25,'*')<<std::endl;
}
std::vector<unsigned char> VoiceMessage::get_voice()
{
std::cout<<"hello"<<std::endl;
return voice ; 
}