#ifndef TABLE_HPP
#define TABLE_HPP
class Slot;
class Table{
    public:
    Table(int m);
    // ~Table();
    void add_to_table(std::string word);
    int hash(int k);
    std::string find(int t);
    int string_to_key(std::string word);
    int tokenize(std::string word);
    void parse_file(std::ifstream * file);
    void resize_tokens();
    private:
    int _m;
    Slot ** _table;
    std::string * _tokens;
    int _count = 0;


};
#endif 