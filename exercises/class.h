#include <iostream>
#include <ctime>
using namespace std;

class Lights 
{
    public:
        enum State{off,red,green,amber};
    
    private:
        State state;
    
    public:
        Lights(State s=off) : state(s){}
        State get_state() const {return state;}
        void set_state(State);
};