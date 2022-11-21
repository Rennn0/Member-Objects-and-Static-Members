//class Result to represent a measurement
//and the time of measurement
#include "DAYTIME.h"

const DAYTIME &current_time(){
    static DAYTIME cur_time;
    time_t sec; time(&sec);
    struct tm *ptr=localtime(&sec);

    cur_time.set_time(ptr->tm_hour, ptr->tm_min, ptr->tm_sec);

    return cur_time;
}

class RESULT 
{
    private:
        double val;
        const DAYTIME time;

    public:
        RESULT(double d, const DAYTIME &z=current_time());
        RESULT(double d, int hr, int min, int sec);

        double get_val()const {return val;}
        void set_val(double w){val=w;}
        const DAYTIME &get_time()const {return time;}

        void print()const{cout<<val<<'\t';time.print();};
};

RESULT::RESULT(double d, const DAYTIME &z)
    : val(d),time(z)
    {
        /*...*/
    }

RESULT::RESULT(double d, int hr, int min, int sec)
    :val(d),time(hr,min,sec)
    {
        /*...*/
    }