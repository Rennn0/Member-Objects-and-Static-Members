#include "members/library.h"

// use enum within class

class LIGHTS
{
    public:
        enum State{off,red,green,amber};
    private:
        State state;
    public:
        LIGHTS(State s=off):state(s){}
        State get_state()const {return state;}
        void set_state(State s)
        {
            switch (s)
            {
            case off:
                cout<<" OFF \n";
                break;
            case red:
                cout<<" RED \n";
                break;
            case green:
                cout<<" GREEN \n";
                break;
            case amber:
                cout<<" AMBER \n";
                break;
            default:
                return;
            }
        }
};

enum year{
    jan,feb,mar,apr,may
};

int main(){
    // LIGHTS a1,a2(LIGHTS::red);
    // LIGHTS::State asf;
    // asf=a2.get_state();
    // if(asf==LIGHTS::red)
    // {
    //     a1.set_state(LIGHTS::red);
    //     a2.set_state(LIGHTS::amber);
    // }
    // cout<<endl;
    int i;
    for(i=jan;i<=may;++i){
        cout<<i<<" ";
    }
}