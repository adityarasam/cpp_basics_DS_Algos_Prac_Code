
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>

using namespace std;

string s = "Mary had a littele lamd";

int main(){

   map<string,int> a;
   vector<string> b;
   b.push_back("sky");
   b.push_back("is");
   b.push_back("blue");
   b.push_back("rose");
   b.push_back("is");
   b.push_back("red");
   b.push_back("the");
   b.push_back("is");

   for(int i =0; i<b.size();i++){
       cout<<"Key="<<b[i]<<"   count"<<a.count(b[i])<<endl;
       if(a.count(b[i])==1){
           a[b[i]]++;
       }
       else
       {
           a.emplace(b[i],1);
       }
       
   }


   map<string,int>::iterator it;


   for(it=a.begin();it!=a.end();++it){
       cout<<"map a: "<<"Key= "<<it->first<<" & val= "<<it->second<<endl;
   }


   cout<<endl;

    cout<<a["is"]<<endl;


    return 0;
}