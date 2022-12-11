#include "../members/library.h"

/*
    class with numerator and a denominator of type long
    the constructor has two parameters of type  long: the first
    parameter (numerator) contains the default value 0, and second
    parameter(denominator) contains the value 1. declare operator
    functions as methods for unary ++ --(both pre) += -= *= /=
    binary + - * /  and as frineds >> <<
*/

class Fraction
{
    private:
        long numerator, denominator;
    public:
        Fraction(long n=0, long d=1)
        {
            if(d==0)
            {
                cerr<<"u dumb?"<<endl; exit(1);
            }
            numerator=n, denominator=d;
        }
        Fraction& operator ++()
        {
            numerator+=denominator;
            cout<<numerator<<' '<<denominator<<endl; 
            return *this;
        }
        Fraction& operator --()
        {
            numerator-=denominator; 
            cout<<numerator<<' '<<denominator<<endl;
            return *this;
        }
        // lets forget about math from here
        Fraction& operator +=(const Fraction& obj)
        {   
            this->numerator=
            this->numerator*obj.denominator+obj.numerator*this->denominator;
            this->denominator*=obj.denominator;
            cout<<numerator<<' '<<denominator<<endl;
            return *this;
        }
        Fraction& operator -=(const Fraction& obj)
        {
            this->numerator=
            this->numerator*obj.denominator-obj.numerator*this->denominator;
            this->denominator*=obj.denominator;
            cout<<numerator<<' '<<denominator<<endl;
            return *this;
        }
        Fraction& operator *=(const Fraction& obj)
        {
            this->numerator*=obj.numerator;
            this->denominator*=obj.denominator;
            cout<<numerator<<' '<<denominator<<endl;
            return *this;
        }
        Fraction& operator /=(const Fraction& obj)
        {
            this->numerator*=obj.denominator*1.;
            this->denominator*=obj.numerator*1.;
            cout<<numerator<<' '<<denominator<<endl;
            return *this;
        }  
        friend Fraction operator+(const Fraction&,const Fraction&);
        friend Fraction operator-(const Fraction&,const Fraction&);
        friend Fraction operator/(const Fraction&,const Fraction&);
        friend Fraction operator*(const Fraction&,const Fraction&);
        friend ostream& operator<<(ostream&,const Fraction&);
        friend istream& operator>>(istream&,Fraction&);

};