//define class article

#include <string>
using namespace std;

class ARTICLE
{
    private:
        long nr;
        string name;
        double sp;

        static int obj_counter;

    public:
        ARTICLE(long nr=0,const string &name="noname",double sp=0.0);
        //copy
        ARTICLE(const ARTICLE &newart);
        //destructor
        ~ARTICLE();
};