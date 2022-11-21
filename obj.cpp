#include "members/RESULT.h"

int main(){
    DAYTIME morning(6,45);
    RESULT  temp1(6.45,morning),
            temp2(11.2,12,0,0);

    double temp=0.0;
    cout<<"air tempr? ";cin>>temp;

    RESULT temp3(temp);
    cout<<"temp\ttime\n";
    temp1.print();temp2.print();temp3.print();
    cout<<"max_"<<RESULT::get_max()
        <<"\nmin_"<<RESULT::get_min()<<endl;
}