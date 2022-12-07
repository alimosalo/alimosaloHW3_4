#ifndef MESSAGE_H
#define MESSAGE_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <random>
#include <ostream>
#include <ctime>
#include <iomanip>
class Message{
public:
//CONSTRUCTOR
Message(const std::string ,const std::string ,const std::string );
Message();
//GETTER_FUNCTIONS
std::string get_type();
std::string get_sender();
std::string get_receiver();
std::string get_time();
//STREAM OPERATOR
virtual void print(std::ostream &) ;
friend std::ostream& operator<<(std::ostream&os ,  Message&c)
{
    c.print(os);
    return os;
}
private:
    std::string type;     
    std::string sender;    
    std::string receiver; 
    std::string time;
};

class TextMessage : public Message
{
public:
TextMessage(std::string  , std::string  , std::string  );
virtual void print(std::ostream &os);
std::string get_text() {return text ;}
private:
std::string text{} ;
};
class VoiceMessage :public Message
{
    public:
    VoiceMessage(const std::string&, const std::string&);
    void print(std::ostream &os);
    std::vector<unsigned char> get_voice();

    private:
    std::vector<unsigned char> voice;

};

#endif