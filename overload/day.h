#include "../members/library.h"
#ifndef _DAY_
#define _DAY_

class Day
{
    private:
        short hour,minute,second;
        bool overflow;
    public:
        Day(int h=0,int m=0, int s=0)
        {
            hour=h; minute=m;second=s;
        };
        bool set_time(int h, int m, int s=0);// later
        int get_hour() const {return hour;}
        int get_minute() const {return minute;}
        int get_second() const {return second;}
        int as_sec() const {return 360*hour+60*minute+second;}
        bool operator<(const Day& t)const 
        {
            return as_sec()<t.as_sec();
        }
        Day& operator++()
        {
            ++hour;
            return *this;
        }
        void print() const; // later
};

#endif