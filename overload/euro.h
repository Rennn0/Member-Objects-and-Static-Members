#ifndef _EURO_H_
#define _EURO_H_
//calss euro containig arithmetic operators
#include "../members/library.h"

class Euro
{
    private:
        long data;
    public:
        Euro(int euro=0,int cents=0)
        {
            data=100L*(long)euro+cents;
        }
        Euro(double x)
        {
            x*=100.0;
            data=(long)(x>=0.0?x+.5:x-.5);
        }
    long get_whole()const {return data/100;}
    int get_cents()const {return (int)(data%100);}
    double as_double()const{return (double)(data/100.0);}
    string as_string()const
    {
        stringstream str_stream;
        long temp=data;
        if(temp<0)
        {
            str_stream<<'-';temp=-temp;
        }
        str_stream<<temp/100<<','<<setfill('0')<<setw(2)<<temp%100;
        return str_stream.str();
    }   
    void print(ostream& os)const
    {
        os<<as_string()<<" Euro"<<endl;
    }
    Euro operator-()const
    {
        Euro temp;
        temp.data=-data;
        return temp;
    }
    Euro operator+(const Euro& e)const
    {
        Euro temp;
        temp.data=e.data+data;
        return temp;
    }
    Euro operator-(const Euro& e)const
    {
        Euro temp;
        temp.data=data-e.data;
        return temp;
    }
    Euro operator/(double x)
    {
        return (*this*(1.0/x));
    }
    Euro& operator+=(const Euro& e)
    {
        data+=e.data;
        return *this;
    }
    Euro& operator-=(const Euro& e)
    {
        data-=e.data;
        return *this;
    }
    friend Euro operator+(const Euro&,const Euro&);
    friend Euro operator-(const Euro&,const Euro&);
    friend Euro operator*(const Euro& obj1, double x)
    {
        Euro temp(((double)obj1.data/100.)*x);
        return temp;
    }
    friend Euro operator*(double x, const Euro& obj1)
    {
        return obj1*x;
    }
};

// global addition and substracion funcitons
// later on delacred as friends

inline Euro operator+(const Euro& obj1,const Euro& obj2)
    {
        Euro temp(obj1);
        temp+=obj2;
        return temp;
    }

inline Euro operator-(const Euro& obj1,const Euro& obj2)
    {
        Euro temp(obj1);
        temp-=obj2;
        return temp;
    }

#endif