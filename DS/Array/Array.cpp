#include "Array.h"


bool isUnique(string s)
{
    unordered_set<char> s_copy;

    for (char w : s)
    {
        if (s_copy.count(w) == 0)
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

/*Function for checking whether a string is unique or not withOut a BUFFER*/
bool isUniqueNoBuffer(string s)
{
    sort(s.begin(), s.end());

    for(int i=0; i< s.size()-1; i++)
    {
        if(s.at(i)==s.at(i+1))
        {
            return false;
        }
    }

    return true;
}



/*---------------IS PERMUTATION------------------*/
bool isPermutation(string a, string b)
{
    //check for lenght
    if (a.size() != b.size()) return false;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i=0; i< a.size(); i++)
    {
        if (a.at(i)!=b.at(i))
        {
            return false;
        }
    }

    return true;
}

/*---------------URLify------------------*/

string URLify(string s)
{
    int len = s.size();
    string mystr;
   

    for(char w: s)
    {
        if (w == ' ')
        {
            mystr.append("%20");
        }
        else
        {
            mystr.append(to_string(w));                 // Conversion to string before appending a charater to string
            
        }
    }

    return mystr;

}


/*--------------------Permutation of Plaindrome --------------------------*/

bool isPermPalindrome(string s)
{
    int cnt =0;
    map <char, int> myMap;
    map <char, int> :: iterator iter;

    for(int i=0; i<s.size(); i++)
    {
        if(myMap[s.at(i)]==1)
        {
            myMap[s.at(i)]+=1;
        }
        else
        {
            myMap[s.at(i)]=1;
        }
    }
    cout<< s.size()<<endl;
    for(iter = myMap.begin(); iter != myMap.end(); iter ++)
    {
        if (s.size()%2 == 0)
        {
            cout<<"even"<<endl;
            if(iter->second % 2 != 0)
            {
                return false;
                cout<<"even_false"<<endl;
            }
        }

        else if (s.size()%2 !=0 )
        {
            cout<<"odd"<<endl;
            if(iter->second % 2 != 0)
            {
                cnt += 1;
            }

            if (cnt > 1)
            {
                return false;
                cout<<"odd_false"<<endl;
            }
        }
    }
    return true;
}
