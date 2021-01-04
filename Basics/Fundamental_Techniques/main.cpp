#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>


using namespace std;

string name;
int arr[5]={1,2,3,4,5};

void Test_1()
{


    for(char w: name)                       // for(<data_type> var: array)  for(int i: array)
    {
        cout<<w<<endl;
    }
    cout << "Hello world!" << endl;

    for(int i: arr)                       // for(<data_type> var: array)  for(int i: array) i takes value of array not the index
    {
        cout<<i<<endl;
    }

}



void stringSort()
{
    vector<char> sortedname;
    for(char w : name)
    {
        sortedname.push_back(w);
    }

    sort(name.begin(),name.end());

    for(char w: name)
    {
        cout<<w<<endl;
    }

}
int main()
{
    cin>>name;
    stringSort();
    return 0;
}
