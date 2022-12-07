#include "../members/library.h"

/*
1)if the program is launched withoout anyu arguments it does not issue 
an error message and terminate but requests user inout 
for the names of the source and target files. if an empty string
is given as the name of the target file that is re return keu is pressed
the source file is displayued ons creen
2)if the command line or user dialog contains valid source and target file names a binaryu copy 
operation is performed
3) copy data blokc by blokc with the read() and write() methods, def size 1024 byte
4)the copy funciton returns false if an errir occurs while copying and true in all other*/

char usage[]="Call : fcopy [source[destionation]]";

inline void openerror(const char* file)
{
    cerr<<"Error opening file "<<file<<endl;
    exit(1);
}

bool copy(istream& is,ostream& os), ok=true;

int main(int argc, char** argv)
{
    char source[256]="", dest[256]="";
    switch(argc)
    {
    case 1: 
        cout<<"Copying source file to destination file ";
        cin.getline(source,256);
        if(strlen(source)==0)
        {
            cerr<<"No source files"<<endl;
            return 1;
        }
        cin.sync();

        cout<<"Destination file: ";
        cin.getline(dest,256);
        break;
    case 2:
        strcpy(source,argv[1]);
        break;
    case 3:
        strcpy(source,argv[1]);
        strcpy(dest,argv[2]);
        break;
    default:
        cerr<<usage<<endl;
        return 2;
    }

    if(strlen(dest)==0)
    {
        ifstream infile(source);
        if(!infile)
            openerror(source);
        
        ok=copy(infile,cout);
    }
    else
    {
        ifstream infile(source, ios::in|ios::binary);
        if(!infile)
            openerror(source);
        else
        {
            ofstream outfile(source, ios::out|ios::binary);
            if(!outfile)
                openerror(dest);
            ok=copy(infile,outfile);
            if(ok)
                cerr<<"file "<<source<<" to file "<<dest<<" copied"<<endl;
        }
    }
    if(!ok)
    {
        cerr<<"Error while copying"<<endl;
        return 3;
    }
    return 0;
}

bool copy(istream& is, ostream& os)
{
    const int buf=1024;
    char buffer[buf];
    do
    {
        is.read(buffer,buf);
        if(is.gcount()>0)
            os.write(buffer,is.gcount());
    }   while(!is.eof() && !is.fail() && !os.fail());
    
    if(!is.eof()) return false;
    else return true;
}