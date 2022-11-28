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