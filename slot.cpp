#include <iostream>
#include "token.hpp"
#include "slot.hpp"


Slot::Slot(){
    _head = nullptr;
    _tail = nullptr;

}
std::string Slot::append(Token * tok){
    Token * cur = _head;
    
    while(cur){
        if (cur->get_word() == tok->get_word()){
            return "failure";
        }

    }  
    if (_tail = nullptr){
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