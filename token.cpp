#include <iostream>
#include "token.hpp"
Token::Token(std::string word, int index){
    _word = word;
    _index = index;
    _next = nullptr;
}
Token * Token::get_next(){
    return _next;
}
std::string Token::get_word(){
    return _word;
}
int Token::get_index(){
    return _index;
}
int Token::get_key(){
    return _key;
}
void Token::set_next(Token * tok){
    _next = tok;
}
void Token::set_index(int i){
    _index = i;
}
void Token::set_key(int k){
    _key = k;
}



