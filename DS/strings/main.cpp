
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>

using namespace std;

vector<string> logs;

 bool isUnique(string k){
     unordered_set<char> myset;
     if(k.empty())
     return false;
    cout<<k<<endl;
     for(char ch : k){
         if(myset.count(ch)==1){
             cout<<ch<<endl;
             return false;
         }
         else
         {
             myset.insert(ch);
         }       
     }
    return true;
 }

 bool isPermutation(string s1, string s2){
     if(s1.empty() || s2.empty())
        return false;
     else if(s1.length()!=s2.length())
        return false;

    cout<<"here  \n"; 

     sort(s1.begin(),s1.end());
     sort(s2.begin(),s2.end());  

     

     for(int i = 0;i<s1.size(); i++){
         cout<<s1[i]<<endl;
         cout<<s2[i]<<endl;
         if(s1[i]!=s2[i])
            return false;
         
     }

     return true;
 }

bool isPalindrome(string s){
    map<char, int> mymap;

    for(char a : s){
        if(mymap[a]==1)
            mymap[a]+=1;
        else
        {
            mymap[a]=1;
        }
        
    }

    map<char, int>::iterator it;
    int cnt =0;
    for(it=mymap.begin();it!=mymap.end();++it){
        if(it->second%2!=0){
            cnt = cnt + 1;
        }
    }

    if(cnt>1)
        return false;
    else
    {
        return true;
    }
    




}
 

string s = "Mary had a littele lamd";

int main(){

    logs.push_back("Mary had a little  lamb");
    logs.push_back("Dary had a little  chicken");
    logs.push_back("Hary had a little  apple");
    /*
    for(char a : s){
        if(a==' ')
            continue;
        else    
            cout<<a<<endl;
    }*/

    for (string b : logs){
        cout<<b<<endl;
        cout<<b.substr(0,5)<<endl;
        cout<<b.find("l")<<endl;
        cout<<"Lenght = "<<b.length()<<endl;
        sort(b.begin(),b.end());
        cout<<b<<endl;

    }
bool b = isUnique(s);
cout<<b<<endl;
string d = "asdfghjk l";
cout<<d.size()<<"........"<<endl;
 b = isUnique(d);
cout<<b<<endl;
d="";
b = isUnique(d);
cout<<b<<endl;

string e = "dog";
d="dgko";
b = isPermutation(d,e);
cout<<b<<endl;
d="aagdgd";
b=isPalindrome(d);
cout<<b<<endl;


int arr[]={1,2,3};
vector<vector<int>> vec{{5,2,3},{3,1,8}};
cout<<vec[0][0]<<endl;
cout<<vec[0].size()<<"---"<<endl;
sort(vec[0].begin(),vec[0].end());
cout<<vec[0][0]<<endl;


d = "aaa bbbb, cccc";
sort(d.begin(),d.end());
cout<<d<<endl;

d="dog";
e="dg";
if(d==e)
    cout<<"true \n";


vector<vector<int>> mvec;
for(int i=0;i<5;i++){
    mvec.push_back(vector<int>());
}
cout<<mvec.size()<<endl;
d="";
cout<<!d.empty()<<endl;

vector<string> vec1{"",""};
sort(vec1.begin(),vec1.end());
cout<<vec1[0]<<endl;


    return 0;
}