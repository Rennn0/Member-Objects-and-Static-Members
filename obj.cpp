#include "members/RESULT.h"

int main(){
    DAYTIME start(10,15);
    RESULT  m1(101.01,start),
            m2(m1),
            m3(99.9);

    m2.set_val(100.9);
    cout<<"\nresult time\n";
    m1.print();m2.print();m3.print();
}