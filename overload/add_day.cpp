#include "day.h"

// additional overloads for class Day
// > < <= >= == !=  ++(pre pos) --(pre pos)
// >> << as globals

bool Day::operator>(const Day& obj)const
    {
        return as_sec()>obj.as_sec();
    }

bool Day::operator<=(const Day& obj)const
    {
        return as_sec()<=obj.as_sec();
    }

bool Day::operator>=(const Day& obj)const
    {
        return as_sec()>=obj.as_sec();
    }

bool Day::operator==(const Day& obj)const
    {
        return as_sec()==obj.as_sec();
    }

bool Day::operator!=(const Day& obj)const
    {
        return as_sec()!=obj.as_sec();
    }

ostream& operator<< (ostream& os, const Day& obj)
    {
        os<<"Day Time:\n";
        os<<obj.hour<<':'<<obj.minute<<':'<<obj.second<<endl;
        return os;
    }

istream& operator>> (istream& is, Day& obj)
    {
        // no error handling for this, im lazy
        short h,m,s;
        cout<<"Enter hour minute second"<<endl;
        is>>h>>m>>s;
        obj=Day(h,m,s);
        return is;
    }

void Day::inc()
    {
        ++second;
        if(second>=60)
            second=0, ++minute;
        if(minute>=60)
            minute=0, ++hour;
        if(hour>=24)
            hour=0, overflow=true;
    }

void Day::dec()
    {
        --second;
        if(second<0)
            second=59,--minute;
        if(minute<0)
            minute=59,--hour;
        if(hour<0)
            hour=23, underflow=true;
    }
Day& Day::operator++()
    {
        inc();
        return *this;
    }

Day& Day::operator++(int)
    {
        Day temp(*this);
        inc();
        return temp;
    }

Day& Day::operator--()
    {
        dec();
        return *this;
    }

Day& Day::operator--(int)
    {
        Day temp(*this);
        dec();
        return temp;
    }