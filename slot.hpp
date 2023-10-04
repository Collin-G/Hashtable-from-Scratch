class Token;
class Slot{
    public:
    Slot();
    ~Slot();
    std::string append(Token * tok);
    Token * get_head();
    private:
    Token * _head;
    Token * _tail;
    
    
};