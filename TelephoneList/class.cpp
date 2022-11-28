#include "class.h"

bool TelList::append(const string &name,const string &number)
    {
        if(count<max && name.length()>1 && search(name)==pseudo)
            {
                v[count].name=name;
                v[count].number=number;
                ++count;
                return true;
            }
        
        return false;
    }

bool TelList::erase(const string &key)
    {
        int i=search(key);
        if(i!=pseudo)
        {
            v[i]=v[count-1]; --count;
            return true;
        }
        
        return false;
    }

int TelList::search(const string &key)
    {
        for(int i=0;i<count;i++)
            if(v[i].name==key)
                return i;
            
        return pseudo;
    }

inline void tab_header()
    {
        cout<<"\nName\t\t\tTelephone#\n"
            "--------------------------------\n";
    }

inline void print_line(const Element &el)
    {
        cout<<left<<setw(30)<<el.name.c_str()
            <<left<<setw(20)<<el.number.c_str()<<endl;
    }

void TelList::print()
    {
        if(count==0)
            cout<<"\nEmpty\n";
        else
        {
            tab_header();
            for(int i=0;i<count;++i)
                print_line(v[i]);
        }
    }

int TelList::print(const string &name)
    {
        int matches=0,len=name.length();

        for(int i=0;i<count;++i)
        {
            if(v[i].name.compare(0,len,name)==0)
            {
                if(matches==0)tab_header();
                ++matches;
                print_line(v[i]);
            }
        }
        if(matches==0)
            cout<<"No matches\n";
        
        return matches;
    }

int TelList::get_new()
    {
        int input=0;

        cout<<"\nenter new name and number\n";

        Element el;
        while(true)
        {
            cout<<"new lastname, firstname:";
            cin.sync();getline(cin,el.name);

            if(el.name.empty())
                break;
            
            cout<<"\nnumber";
            cin.sync();getline(cin,el.number);
            if(!append(el))
            {
                cout<<"\nname not fount\n";
                if(count==max)
                {
                    cout<<"table is full\n";
                    break;
                }
                if(search(el.name)!=pseudo)
                    cout<<"name exists\n";
            }
            else
            {
                ++input;
                cout<<"new element inserted\n";
            }
        }
        return input;
    }
