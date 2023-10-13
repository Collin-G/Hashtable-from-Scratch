#include <iostream>
#include "token.hpp"
#include "slot.hpp"


Slot::Slot(){
    _head = nullptr;
    _tail = nullptr;

}
Slot::~Slot(){
    Token * cur;
    while(cur){
        cur = _head;
        _head = cur->get_next();
        delete cur;
        cur = nullptr;

    }
}
std::string Slot::append(Token * tok){
    Token * cur = _head;
    while(cur){
        if (cur->get_word() == tok->get_word()){
            return "failure";
        }
        cur = cur->get_next();

    }  
    if (_tail == nullptr){
        _tail = tok;
        _head = tok;
    }
    else{
       
        _tail->set_next(tok);
        _tail = tok;
    }
    return "success";
}
Token * Slot::get_head(){
    return _head;
}