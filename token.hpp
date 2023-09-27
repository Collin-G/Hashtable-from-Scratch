#include <iostream>
class Token{
    public:
        Token(std::string word, int index);
        ~Token();
        Token * get_next();
    private: 
        Token * _next;
        std::string _word;
        int _index;
        int _key;



};