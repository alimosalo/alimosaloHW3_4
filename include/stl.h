#ifndef STL_H
#define STL_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
//initial_vector_with_3_mutiples
static void initial_vector_with_3_mutiplies(std::vector<int>& v, size_t size)
{
v.resize(size);
std::fill(v.begin(),v.end(),1);

int i {0};
 std::generate(v.begin(),v.end(),[&i](){i++ ;return i*3;});

}
//count_unique_above
static int count_unique_above(std::vector<int> v, int n)
{
    std::sort(v.begin(),v.end());
    v.erase(std::unique(v.begin(),v.end()),v.end());
    int total =std::count_if(v.begin(),v.end(),
    [&n](int a){return a>n ;});
    return total ; 
}
//vector_to_string
static std::string vector_to_string(std::vector<int> v, char separator)
{
    std::cout<<"question"<<std::endl;
    auto format=[&separator](std::string a,int b)
    {
        return std::move(a)+ separator + std::to_string(b); 
    };
    std::string str =std::accumulate(v.rbegin(),v.rend(),std::to_string(v[0]),format);
    str.erase(str.begin(),str.begin()+2); 
    return str ;
}
#endif //STL_H