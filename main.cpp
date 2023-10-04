#include <iostream>
#include "table.hpp"
int main(){
    std::string cmd{};
    std::string word;
    int val1{};
    int val2{};
    Table hashtable(0);
    while(std::cin >> cmd){
        if (cmd == "M"){
            std::cin>>val1;
            Table hashtable(val1);
            
        }
        else if(cmd == "INSERT"){
            std::cin>>word;
            hashtable.add_to_table(word);
        }
        else if (cmd == "TOKENIZE"){
            std::cin>>word;
            std::cout<<hashtable.tokenize(word);
        }
        else if (cmd == "RETRIEVE"){
            std::cin>>val1;
            std::cout<<hashtable.find(val1);
        }
        else if (cmd == "TOKS"){
            std::cin >> val1;
            while (val1 != -1){
                std::cout<<hashtable.find(val1)<<" ";
            }
        }
        else if (cmd == "STOK"){
            std::cin >> word;
            while (word != "_DONE_"){
                std::cout<<hashtable.tokenize(word)<<" ";
            }
        }
        
    }
   
    
    return 0;
}
