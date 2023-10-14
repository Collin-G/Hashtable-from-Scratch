#include <iostream>
#include <fstream>
#include <istream>
#include "table.hpp"
int main(){
    std::string cmd{};
    std::string word{};
    int val1{};
    int val2{};
    Table * hashtable{};
    while(std::cin >> cmd){
        if (cmd == "M"){
            std::cin>>val1;
            hashtable = new Table(val1);
            std::cout<<"success"<<std::endl;   

        }
        else if(cmd == "INSERT"){
            std::cin>>word;
            std::cout<<hashtable->add_to_table(word)<<std::endl;
        }
        else if (cmd == "TOKENIZE"){
            std::cin>>word;
            std::cout<<hashtable->tokenize(word);
        }
        else if (cmd == "RETRIEVE"){
            std::cin>>val1;
            std::cout<<hashtable->find(val1);
        }
        else if (cmd == "TOKS"){
            std::cin >> val1;
            while (val1 != -1){
                std::cout<<hashtable->find(val1)<<" ";
                std::cin >> val1;
            }
            std::cout<<std::endl;
        }
        else if (cmd == "STOK"){
            std::cin >> word;
            while (word != "_DONE_"){
                std::cout<<hashtable->tokenize(word)<<" ";
                std::cin >> word;
            }
            std::cout<<std::endl;
        }
        else if (cmd == "PRINT"){
            std::cin >> val1;
            hashtable->get_row(val1);
        }
        else if (cmd == "READ"){
            std::cin >> word;
            std::fstream fin(word.c_str());
            std::cout<<hashtable->parse_file(fin)<<std::endl;

        }
        else if (cmd == "EXIT"){
            break;
        }
        
    }
    // delete hashtable;
    // hashtable = nullptr;
   
    
    return 0;
}
