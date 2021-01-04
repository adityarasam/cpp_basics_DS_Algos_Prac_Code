

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>

using namespace std;



int main(){
    int *p;
    cout<<"Array Basics\n";
    int arr[] = {1,5,10,15,25};
    //int (*ptr)[5] = new int [5];

    int* ptr = new int [5];
    

    p=arr;

    cout<<"arr[0] is = "<<arr[0]<<endl;
    cout<<"*arr is = "<<*arr<<endl;
    cout<<"*arr+1 is = "<<*arr+1<<endl;
    cout<<"*(arr+1) is = "<<*(arr+1)<<endl;
    cout<<"*(arr+3) is = "<<*(arr+3)<<endl;
    cout<<"(*p+3) is = "<<*(p+3)<<endl;
    cout<<"------"<<ptr[0]<<endl;


    cout<<"Pointer Basics\n";
    int *q;
    //int **o = &q;
    //This is equivalent to 
    int **o;
    o = &q;
    //o points to address of qby q
    //*o has content of q i.e. address of x
    //**o = *(q) =  content at address pointed 

    int x = 5;

    q = &x;
    cout<<q<<endl;
    cout<<*q<<endl;
    cout<<"o"<<o<<endl;
    cout<<"*o has address = "<<*o<<endl;
    cout<<"**o has content at *o = "<<**o<<endl;

    string abc= "asdfghjkl";
    string def = "qwertyuiop";

    cout<<abc+def<<endl;
   
   return 0;

}