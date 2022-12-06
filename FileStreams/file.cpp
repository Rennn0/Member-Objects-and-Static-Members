//creating file streams
// reads a text file and outputs it n pages
#include "../members/library.h"

int main(int argc, char** argv)
{
    if(argc!=2) //file declared?
    {
        cerr<<"Use: showfile filename"<<endl;
        return 1;
    }
    ifstream file(argv[1]);

    if(!file)
    {
        cerr<<"An error occured when opening the file"<<argv[1]<<endl;
        return 2;
    }

    char line[80];
    int cnt=0;
    while(file.getline(line,80))
    {
        cout<<line<<endl;
        if(++cnt==20)
        {
            cnt=0;
            cout<<"\n\t----<return> to continue----"<<endl;
            cin.sync();cin.get();
        }
    }
    if(!file.eof()) //end of file??
    {
        cerr<<"Error reading file"<<argv[1]<<endl;
        return 3;
    }

    return 0;
}