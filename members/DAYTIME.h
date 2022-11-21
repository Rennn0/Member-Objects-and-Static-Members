//represents the time in hs,min,sec
#include "library.h"

class DAYTIME
{
    private:
        short hour,minute,second;
        bool overflow;
    public:
        DAYTIME(int h=0, int m=0, int s=0){
            overflow=false;
            if(!set_time(h,m,s))
                hour=minute=second=0;
        }
        bool set_time(int hour, int minute, int second){
            if(
                hour>=0 && hour<=24
                && minute>=0 && minute<=60
                && second>=0 && second<=60
            ){
                this->hour=(short)hour;
                this->minute=(short)minute;
                this->second=(short)second;
                return true;
            } else
                return false;
        }
        int get_hour()const {return hour;}
        int get_minute()const {return minute;}
        int get_second()const {return second;}
        void print()const{
            cout<<this->hour<<'\t'
            <<this->minute<<'\t'
            <<this->second<<endl;
        }
        
        int as_seconds()const { //time in seconds
            return hour*3600+minute*60+second;
        }

        bool is_less(DAYTIME t)const{ //compare 2 object
            return this->as_seconds()<t.as_seconds();
        }
};