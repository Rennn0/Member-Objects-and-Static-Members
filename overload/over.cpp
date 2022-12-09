#include "add_day.cpp"


int main(void)
{
    Day obj1(11,10,0), obj2(11,11,0), obj3;
    
    cin>>obj3;
    cout<<obj3;

    bool b=obj3>obj2;
    cout<<boolalpha<<b<<endl;

    b=obj3==obj1;
    cout<<boolalpha<<b<<endl;
//  ok
    // ++obj2;
    // cout<<obj2;// not ok
    
}