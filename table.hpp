#ifndef TABLE_HPP
#define TABLE_HPP
class Slot;
class Table{
    public:
        Table(int m);
        ~Table();
        std::string add_to_table(std::string word);
        int hash(int k);
        std::string find(int t);
        int string_to_key(std::string word);
        int tokenize(std::string word);
        std::string parse_file(std::fstream& file);
        void resize_tokens();
        void get_row(int k);
    private:
        int _m;
        int _count = 1;
        Slot ** _table = nullptr;
        std::string * _tokens = nullptr;
    


};
#endif 