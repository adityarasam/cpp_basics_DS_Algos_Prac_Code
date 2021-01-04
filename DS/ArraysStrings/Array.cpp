#include "Array.h"



bool isUnique(string s)
{
    unordered_set <char> s_copy;

    for(char w : s)
    {
        if(s_copy.count(w)==0)
        {
            s_copy.insert(w);
        }
        else
        {
            return false;
        }
    }

    return true;

}
