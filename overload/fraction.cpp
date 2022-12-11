#include "fraction.h"

    Fraction operator+(const Fraction& a, const Fraction& b)
    {
        Fraction temp;
        temp.denominator=a.denominator*b.denominator;
        temp.numerator=a.numerator*b.denominator+b.numerator*a.denominator;
        cout<<temp.numerator<<' '<<temp.denominator<<endl;
        temp.value();
        return temp;
    }
    Fraction operator-(const Fraction& a, const Fraction& b)
    {
        Fraction temp;
        temp.denominator=a.denominator*b.denominator;
        temp.numerator=a.numerator*b.denominator-b.numerator*a.denominator;
        cout<<temp.numerator<<' '<<temp.denominator<<endl;
        temp.value();
        return temp;
    }
    Fraction operator*(const Fraction& a, const Fraction& b)
    {
        Fraction temp;
        temp.denominator=a.denominator*b.denominator;
        temp.numerator=a.numerator*b.numerator;
        cout<<temp.numerator<<' '<<temp.denominator<<endl;
        temp.value();
        return temp;
    }
    Fraction operator/(const Fraction& a, const Fraction& b)
    {
        Fraction temp;
        temp.denominator=a.denominator*b.numerator;
        temp.numerator=a.numerator*b.denominator;
        cout<<temp.numerator<<' '<<temp.denominator<<endl;
        temp.value();
        return temp;
    }
    istream& operator>>(istream& is, Fraction& obj)
    {
        cout<<"Numerator_ ";
        while(!(is>>obj.numerator))
        {
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"try again_ ";
        }
        cout<<"Denominator_";
        while(!(is>>obj.denominator) || obj.denominator==0)
        {
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"try again_ ";
        }
        obj.value();
        return is;
    }
    ostream& operator<<(ostream& os, const Fraction& obj)
    {
        cout<<obj.numerator<<' '<<obj.denominator<<endl;
        obj.value();
        return os;
    }
    
int main()
{
    Fraction obj(2,3), obj2(4,5),obj3;
    // cout<<obj<<obj2<<obj3;

    // ++obj, --obj2, obj3=obj+obj2;
    
    // cin>>obj3;
}