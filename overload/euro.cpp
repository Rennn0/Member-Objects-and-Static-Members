#include "euro.h"

int main()
{
    cout<<"testting the class euro\n\n";
    
    Euro wholesale(20,50), retail;
    retail=wholesale;
    retail+=9.49;
    cout<<"wholesale price "; wholesale.print(cout);
    cout<<"retail price "; retail.print(cout);

    Euro discout(2.10);
    retail-=discout;
    cout<<"retail price including discount: ";
    retail.print(cout);

    wholesale=34.10;
    cout<<"\nnew wholesale price "; wholesale.print(cout);

    Euro profit(retail-wholesale);
    cout<<"\nthe profit ";
    profit.print(cout);
    return 0;
}