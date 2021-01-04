#include "Arrays.h"     /*VERY IMPORTANT - INTERFACE(LOCALS) MUST BE INCLUDED FIRST*/
#include <iostream>
#include <vector>



using namespace std;

bool hasduplicates(vector<int> &arr);

bool isUnique(string str);
bool isUnique_n2(string str);


int main()
{
    vector<int> smp_arr;
    string name = "aditya";
    bool isit;
    cout << "Hello world!" << endl;
    int j=0;

    for(int i=0; i< 10; i++)
    {
        smp_arr.emplace_back(j);
        cout<<smp_arr[i]<<endl;
        j=i;
        if(i==5)
        {
            j--;
        }
    }

   isit = hasduplicates(smp_arr);

   isit = isUnique(name);
   isit = isUnique_n2(name);
   cout<<isit<<endl;


    return 0;
}
