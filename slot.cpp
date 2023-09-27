#include "token.hpp"
#include "slot.hpp"


Slot::Slot(){
    _head = nullptr;
    _tail = nullptr;

}
void Slot::append(Token * tok){
    if (_tail = nullptr){
        _tail = tok;
        _head = tok;
    }
    else{
        _tail->set_next(tok);
        _tail = tok;
    }
}
Token * Slot::get_head(){
    return _head;
}