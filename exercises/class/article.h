//define class article
#include "../../members/library.h"

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
        void print();
        //access
        const   string  &get_name()const{return name;}
        long            get_nr()const   {return nr;}
        double          get_sp()const   {return sp;}
        static int      get_count()     {return obj_counter;}

        bool set_name(const string &s){
            if(s.size()<1)
                return false;
            name=s;
            return true;
        }

        void set_nr(long n) {nr=n;}
        void set_sp(double v){
            //only +
            sp= v > 0.0 ? v : 0.0;
        }
};

// class methods

int ARTICLE::obj_counter=0;

ARTICLE::ARTICLE(long nr,const string &name,double sp)
    {
        set_nr(nr);set_name(name);set_sp(sp);
        ++obj_counter;
        
        cout<<"an article "<<name<<" is created\n"
            <<"this is "<<obj_counter<<" object\n";

    }

ARTICLE::ARTICLE(const ARTICLE &newart)
    :nr(newart.nr),name(newart.name),sp(newart.sp)
    {
        ++obj_counter;
        cout<<"copy of  article "<<name<<" is generated\n"
            <<"this is "<<obj_counter<<" object\n";
    }

ARTICLE::~ARTICLE()
    {
        --obj_counter;
        cout<<"article "<<name<<" is destroyed\n"
            <<"there is "<<obj_counter<<" object left\n";
    }

    void ARTICLE::print(){
        cout<<"name_"<<name<<endl;
        cout<<"number_"<<nr<<endl;
        cout<<"sp_"<<sp<<endl;
    }
