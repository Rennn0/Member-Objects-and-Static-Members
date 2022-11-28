#include "class.cpp"
#include <cctype>
// controler functions

inline void clear()
{
    cout<<"\033[2j\n";
}

inline void go_on()
{
    cout<<"\ngo on with return";
    cin.sync(); cin.clear();
    while(cin.get()!='\n');
}

char header[]="\n\n\t\t***telephone list****\n\n";
TelList friends;

int menu()
{
    static char menu[]=
        "\n\n\t\tD=Display all entries"
        "\n\n\t\tF=find a number"
        "\n\n\t\tA=append a new entrie"
        "\n\n\t\tE=erase an entrie"
        "\n\n\t\tQ=quit program"
        "\n\nyour choice";

        clear();
        cout<<header;

        char choice;
        cin.sync();cin.clear();
        if(!cin.get(choice))
            choice='B';
        else 
            choice=toupper(choice);

        cin.sync();
        return choice;
}

int main()
{
    int action=0;
    string name;

    friends.append("lucky luuukk", "599288177");

    while(action !='B')
    {
        action=menu();
        clear();

        cout<<header<<endl;

        switch(action)
        {
            case 'D':
                friends.print();
                go_on();
            break;
            case 'F':
                cout<<"enter name";
                getline(cin,name);
                if(!name.empty())
                {
                    friends.print(name);
                    go_on();
                }
            break;
            case 'A':
                friends.get_new();
            break;
            case 'E':
                cout<<"enter name";
                getline(cin,name);
                if(!name.empty())
                {
                    if(!friends.erase(name))
                        cout<<name<<"no found\n";
                    else    
                        cout<<"entry for "<<name<<" deleted\n";
                    
                    go_on();
                }
            break;
            case 'T': 
                clear();
                break;
        }
    }
    return 0;
}
