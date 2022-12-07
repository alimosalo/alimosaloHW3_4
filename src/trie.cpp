#include "trie.h"
void Trie::insert(const std::string& str)
{
    //first time calling;
    Node*  a {root};
    
    auto init{root->children.size()};
    if(init==0)
    {
        for(size_t i{};i<str.length();i++)
        {
            a->children.push_back(new Node{str[i],false});
            a = a->children[0];
            if(i==str.length()-1)
                a->is_finished=true;
        }
    }
    //other times 
    Node* b{root};
    int counter{};
    size_t c{};
    bool same;
    bool first{true} ;
    bool loop_end{false};
    if(init!=0)
    {
        for(size_t i{};i<str.length();i++)
        {
            same =false ; 
            if(loop_end==false)
            {
            for(size_t j{};j < b->children.size();j++)
            {
                if(b->children[j]->data==str[i])
                {
                    b = b->children[j] ; 
                     counter++;
                     
                     same=true;
                    break; 
                }
            }
            }
            if(same==false)
            {
                if(first==true)
                {
                b->children.push_back(new Node{str[i],false});
                b = b->children[b->children.size()-1];

                first = false; 
                loop_end = true; 
                }
                else{
                    b->children.push_back(new Node{str[i],false});
                    b = b->children[0];
                    

                }
            }
            if(i==str.length()-1)
            {
                b->is_finished = true;
            } 
        }

    }       
        
}
//search function//////////////////////
bool Trie::search(const std::string& query)
{
    Node* a{root};
    bool is_same{false};
    for(size_t i{};i<query.length();i++)
    {
        is_same =false;
        for(size_t j{};j<a->children.size();j++)
        {
                
                if(a->children[j]->data==query[i])
                {
                    if(a->children[j]->is_finished==true)
                    if(a->children[j]->is_finished==true)
                        is_same =true;
                    a=a->children[j];
                }
              
            
        }
    }
    if(is_same)
    {
        return true;
    }
    return false;
}
void Trie::bfs(std::function<void(Node*& node)> func)
{
    Node* _root{root};
    std::vector <Node*> b; 
    
    size_t counter{};
    b.push_back(_root);
    size_t i{} ;
    size_t saver{};
    while((_root=b[counter]))
    {
        for(auto x:_root->children)
        {
            if(x==nullptr) {break;}
            b.push_back(x);
            
        }
        counter++;
    }
    for(auto x:b)
    {
        func(x);
    }
    
}
Trie::Trie( Trie& trie)
{
    Node* _root{root} ;
    Node* saver{_root}; 
    _root =new Node{*trie.root};
    saver = _root ; 





    int counter{} ;
    int i{} ; 
    Node* __root{root} ; 
    __root = new Node{trie.root->data,trie.root->is_finished};
    root = __root; 
    std::vector<Node*> main ; 
    std::vector<Node*> copy ; 
    main.push_back(trie.root);

    copy.push_back(root);
    while((__root=main[counter]))
    {
        for(auto x:__root->children)
        {
            if(x==nullptr) {break;}
            __root->children[i] = new Node{*x};

            main.push_back(x); 
            copy.push_back(x);
            i++;
        }
        i = 0;
        counter++;
        __root = copy[counter];
    }    
    root =saver ;
}
void Trie::operator=(const Trie &trie)
{
     Node* _root{root} ;
    Node* saver{_root}; 
    _root =new Node{*trie.root};
    saver = _root ; 
    std::cout<<saver<<std::endl;
    std::cout<<_root<<std::endl;





    int counter{} ;
    int i{} ; 
    Node* __root{root} ; 
    __root = new Node{trie.root->data,trie.root->is_finished};
    root = __root; 
    std::vector<Node*> main ; 
    std::vector<Node*> copy ; 
    main.push_back(trie.root);

    copy.push_back(root);
    while((__root=main[counter]))
    {
        for(auto x:__root->children)
        {
            if(x==nullptr) {break;}
            __root->children[i] = new Node{*x};

            main.push_back(x); 
            copy.push_back(x);
            i++;
        }
        i = 0;
        counter++;
        __root = copy[counter];
    }    
    root =saver ;
}
//move semantics 
Trie::Trie(Trie&& trie)
{
    Node* a{};
    a = trie.root ; 
    root =a ; 
    trie.root = nullptr; 
}
void Trie::operator=( Trie&& trie)
{
    Node* a{}; 
    a = trie.root ; 
    root = a;
    trie.root =nullptr; 





}


//end of programming



