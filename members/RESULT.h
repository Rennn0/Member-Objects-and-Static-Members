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
        DAYTIME time;

    public:
        RESULT(); //default
        RESULT(double d, const DAYTIME &z=current_time());
        RESULT(double d, int hr, int min, int sec);

        double get_val()const {return val;}
        void set_val(double w){val=w;}
        const DAYTIME &get_time()const {return time;}
        void set_time(const DAYTIME &z){time=z;}
        bool set_time(int hr,int min, int sec){
            return time.set_time(hr,min,sec);
        }
        void print()const;
};

RESULT::RESULT() {val=0.0;}

RESULT::RESULT(double d, const DAYTIME &z)
    {
        val=d; time=z;
    }

RESULT::RESULT(double d, int hr, int min, int sec)
    {
        val=d; time=DAYTIME(hr,min,sec);//temporary object
    }