// scrolling a message

#include "../members/library.h"

#define DELAY 100000000L

inline void clear()
{
    cout<<"\033[2j\n";
}

inline void locate(int x, int y)
{
    cout<<"\033["<<x<<';'<<y<<'H';
}

char msg[]="* * * * * B R E A K * * * * * ";

int main()
{
    int i, start=0, len=strlen(msg);

    clear(); locate(24,20);
    cout<<"-- press interupt key to terminate (^c) --";

    while(true)
    {
        locate(12,25);
        i=start;
        do
        {
            cout<<msg[i++];
            i=i%len;
        }   while(i!=start);
        cout<<endl;
        for(int count=0;count<DELAY;++count);
        ++start;
        start%=len;
    }
    clear();
    return 0;
}