#include <iostream>
#include "token.hpp"
#include "slot.hpp"
#include "table.hpp"
Table::Table(int m){
    _table = new Slot*[m];
    for(int i{0}; i<m; ++i){
        Slot * slot = new Slot; 
        _table[i] = slot;
    }
   
}
void Table::add_to_table(std::string word, int ind = -1){
    int key = 0;
    for (char c : word){
        int k = (int)c;
        key += k;
    }

    if (ind < 0){
        ind = _count;
    }
    Token * tok = new Token(word, ind);

    _table[_m]->append(tok);


}

std::string Table::find(int t){
    Slot * slot = _table[t];
    Token * cur  = slot->get_head();
    while(cur){
        return cur->get_word();
        cur = cur->get_next();   
    }
    return "UNKNOWN";  
}

int Table::hash(int k){
    return k % _m;
}