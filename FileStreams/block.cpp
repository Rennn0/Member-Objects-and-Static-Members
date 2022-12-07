#include "../members/library.h"
// output records block by block
char header[]="**********pizza*************\n";

struct Pizza{char name[21]; float price;};
const int MAX=10;

Pizza menu[MAX]=
{
    {"peperoni",9.9},{"white",1.9},{"mushroom",3.9},
    {"pepeeeroni",5.9},{"calzone",2.9},{"ham",4.9}
};

int cnt=6;
char pizza_file[1024]="pizza.txt";

int main()
{
    cout<<header;

    int exit=0;
    ofstream outfile(pizza_file, ios::out | ios::binary );

    if(!outfile)
    {
        cerr<<"Error opening file"<<endl;
        exit=1;
    }
    else
    {
        for(size_t t=0;t<cnt;++t)
        {
            if(!outfile.write((char*)&menu[t], sizeof(Pizza)))
            {
                cerr<<"Error writing"<<endl;
                exit=2;
            }
        }
    }
    if(exit==0)
    {
        cout<<"Data has been added "<<pizza_file<<endl;
    }
    return exit;
} 

