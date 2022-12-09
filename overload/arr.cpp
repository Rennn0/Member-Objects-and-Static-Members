#include "../members/library.h"
#define max 100
//class to represent an array with range checkin


class Float
{
    private:
        float array[max];
    public:
        float& operator[](int i);
        static int max_index(){return max-1;}
};

float& Float::operator[](int i)
{
    if(i<0 || i>=max)
    {
        cerr<<"\noutside of range"<<endl;
        exit(1);
    }
    return array[i];
}

int main(void)
{
    cout<<"\narray with range checking"<<endl;
    Float random;
    int i;
    for(i=0;i<=Float::max_index();++i)
        random[i]=rand()%101;
    
    cout<<"\nenter number between 0 and "<<Float::max_index()<<endl;

    while(cout<<"\nIndex_ " && cin>>i)
        cout<<i<<".element: "<<random[i];
    return 0;
}