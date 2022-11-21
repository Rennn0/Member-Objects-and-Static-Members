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
        static double min,max;
        static bool first; //true if its first
        void set_min_max(double d);
    public:
        RESULT(double d, const DAYTIME &z=current_time());
        RESULT(double d, int hr, int min, int sec);

        double get_val()const {return val;}
        void set_val(double w){val=w;}
        const DAYTIME &get_time()const {return time;}
        void print()const{cout<<val<<'\t';time.print();}
        static double get_min(){return min;}
        static double get_max(){return max;}
};

RESULT::RESULT(double d, const DAYTIME &z)
    : val(d),time(z)
    {
        set_min_max(d);
    }

RESULT::RESULT(double d, int hr, int min, int sec)
    :val(d),time(hr,min,sec)
    {
        set_min_max(d);
    }

double RESULT::min=0.0;
double RESULT::max=0.0;
bool   RESULT::first=true;
void   RESULT::set_min_max(double d){
    if(first){
        min=max=d; first=false;
    }
    else if(d<min) min=d;
    else if(d>max) max=d;
}
