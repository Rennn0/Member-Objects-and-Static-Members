#include "class/article.h"

void test(ARTICLE );
ARTICLE article1(1111, "woof", 159.9);

int main(){
    cout<<"begin\n";
    ARTICLE article2(2222,"jiggle jiglle",6969);

    cout<<"now test\n\n";
    test(article2);

    cout<<"finish\nstill "<<ARTICLE::get_count()<<" objects"<<endl;    
}

void test(ARTICLE a){
    cout<<"\ngive object\n";
    a.print();

    static ARTICLE bike(3333,"dogggggoo",999.99);
    cout<<"\nstatic object here\n";
    bike.print();

    cout<<"\nadios muchacho\n";
}