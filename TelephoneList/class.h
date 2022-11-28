#include "../members/library.h"

#define pseudo -1
#define max 100

struct Element {string name,number;};

class TelList
{
    private:
    Element v[max];
    int count;

    public:
    TelList(){count=0;}
    int get_count()const{return count;}
    Element *retrieve(int i)
    {
        return i>=0 && i<=count?&v[i]:NULL;
    }
    bool append(const Element &el)
    {
        return append(el.name,el.number);
    }
    bool append(const string &name, const string &number);
    bool erase(const string &name);
    void print();
    int print(const string &name);
    int get_new();
    int search(const string &name);
    
};