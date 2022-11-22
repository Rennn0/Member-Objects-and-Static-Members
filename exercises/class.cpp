#include "class.h"

void Lights::set_state(State s){
        switch(s){
            case off: cout<<"\tOFF\t"; break;
            case red: cout<<"\tRED\t"; break;
            case green: cout<<"\tGREEN\t"; break;
            case amber: cout<<"\tAMBER\t"; break;
            default: return;
        }
        state=s;
    }