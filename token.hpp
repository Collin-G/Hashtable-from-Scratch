#ifndef TOKEN_HPP
#define TOKEN_HPP
class Token{
    public:
        Token(std::string word, int index);
        // ~Token();
        Token * get_next();
        int get_index();
        void set_index(int i);
        int get_key();
        std::string get_word();
        void set_key(int k);
        void set_next(Token * tok);
        
    private: 
        Token * _next;
        std::string _word;
        int _index{};
        int _key{};
    

};
#endif