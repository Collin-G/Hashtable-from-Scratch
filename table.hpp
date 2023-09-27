
class Table{
    public:
    Table(int m);
    ~Table();
    void add_to_table(std::string word, int ind = -1);
    int hash(int k);
    std::string find(int t);

    private:
    int _m;
    Slot ** _table;
    int _count = 0;


};