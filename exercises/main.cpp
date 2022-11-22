#include "class.h"

    inline void wait(int sec){
        time_t end=time(NULL)+sec;
        while(time(NULL)<end);
    }
        Lights a1,a2;
    enum {
        greent1=10,ambert1=1,greent2=14,ambert2=2
    };


int main()
{
    while(true){
        a1.set_state(Lights::red);
        a2.set_state(Lights::amber);cout<<endl;
        wait(ambert2);
        cout<<"\t\t";
        a2.set_state(Lights::green);cout<<endl;
        wait(greent2);
        cout<<"\t\t";
        a2.set_state(Lights::amber);cout<<endl;
        a1.set_state(Lights::amber);
        a2.set_state(Lights::red);cout<<endl;
        wait(ambert1);
        a1.set_state(Lights::green);cout<<endl;
        wait(greent1);
        a1.set_state(Lights::amber);cout<<endl;
        wait(ambert1);
    }
}