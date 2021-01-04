#include "Arrays.h"
#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;

bool hasduplicates(vector<int> &arr)
{
    vector<int> :: iterator itr, itr_1;

    int cntr=0;

    for(itr = arr.begin(); itr != arr.end();++itr)
    {
        for(itr_1 = itr+1; itr_1 != arr.end();++itr_1)
        {
            cout<<"Outer: "<<*itr<<" INNER: "<<*itr_1<<endl;
            if (*itr==*itr_1)
            {
                cntr += 1;
            }
        }
    }

    cout<< cntr<<endl;

    return false;

}

/*  WHETHER A STRING HAS UNIQUE CHARACTERS, CASE SENSITIVE, USING ADD DATA STRUCTURE*/
bool isUnique(string str)
{
    unordered_set <char> str_alias;

    for(char w: str)
    {
        if(str_alias.count(w) == 0)
        {
            str_alias.insert(w);
        }
        else
        {
            return false;
        }
    }

    return true;

}

bool isUnique_n2(string str)
{
    for(int j=0;  j<str.length(); j++)
    {
        for(int i=j+1; i<str.length(); i++)
        {
            if(str[j]==str[i])
            {
                return false;
            }
        }

    }
    return true;
}
