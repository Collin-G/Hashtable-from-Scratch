#include <iostream>
#include <fstream>
#include <string>
#include "token.hpp"
#include "slot.hpp"
#include "table.hpp"
Table::Table(int m){
    // Dynamically allocate array to hold dynamically allocated linked lists
    _table = new Slot*[m];
    _m = m;
    for(int i{0}; i<_m; ++i){
        Slot * slot = new Slot(); 
        _table[i] = slot;
    }
    // Dynamically allocated array to hold words and act as a dictionary
    _tokens = new std::string[m+1];
}
Table::~Table(){
    // Delete all linked lists before deleting the array
    for(int i{0}; i<_m; ++i){
        
        delete _table[i];
        _table[i] = nullptr;
    }
    
    delete [] _table;
    _table = nullptr;
    
    delete [] _tokens;
    _tokens = nullptr;
}
int Table::string_to_key(std::string word){
    int key = 0;
    for (char c : word){
        int k = (int)c;
        key += k;
    }
    return key;
        

}
void Table::resize_tokens(){
    // Allocate a new array of double the size and copy the elements of the old dictionary
    std:: string * new_tokens = new std::string[_count*2];
    for(int i{1}; i <_count; ++i){
        new_tokens[i] = _tokens[i];
    }
   
    delete [] _tokens;

    _tokens = new_tokens;

}

std::string Table::add_to_table(std::string word){
    for (char c : word){
        if (!(isalpha(c))){
            return "failure";
            
        }
    }
    Token * tok = new Token(word, _count);
    tok->set_key(string_to_key(word));
    std::string result = (_table[hash(string_to_key(word))])->append(tok);
    if (result == "success"){
        if ( sizeof(_tokens)/sizeof(_tokens[0]) < _count){
           resize_tokens();
        }
        _tokens[_count] = word;
        ++_count;
    }
    return result;

}
int Table::tokenize(std::string word){
    // Return index of a word in a dictionary
    int slot_index = hash(string_to_key(word));
    Slot * slot = _table[slot_index];
    Token * cur  = slot->get_head();
    while(cur){
        if (cur->get_word() == word){
            return cur->get_index();
        }
        cur = cur->get_next();   
    }
    return 0;
}

std::string Table::find(int t){
    // Return word based on index in a dictionary
    if (t == 0 || t >= _count){
        return "UNKNOWN";  
    }
    else{
        return _tokens[t];
    }   
}

int Table::hash(int k){
    
    return k % _m;
}

void Table::get_row(int k){
    Slot * slot = _table[k];
    if (slot->get_head()){
        Token * cur  = slot->get_head();
        while(cur){
            std::cout<<cur->get_key()<<" ";
            cur = cur->get_next();
        }
    }
    else{
        std::cout<<"chain is empty";
    }
    std::cout<<std::endl;
}

std::string Table::parse_file(std::fstream& file){
    std::string to_read;
    std::string status = "failure";
    while (file>>to_read){
        std::string result = add_to_table(to_read);
        if (result == "success"){
            status = "success";
        }
    }
    return status;
}



