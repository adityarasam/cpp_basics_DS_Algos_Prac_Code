
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>

using namespace std;
//-----------------------------FIBONACCI------------------------


int fibo(int n){
    if(n==0) return n;
    if(n==1) return n;

    return fibo(n-1)+fibo(n-2); 
}


//-------------Recursing function with memoization--------------
int fibo_dyn_mem(int i, vector<int> &mem){
    if(i==0||i==1) return i;

    if(mem[i]>-1){
        return mem[i];
    }
    else
    {
        mem[i] = fibo_dyn_mem(i-1,mem)+fibo_dyn_mem(i-2,mem);
        return mem[i];
    }
    
}


int fibo_dyn(int n){
    vector<int> mem (n+1, -1);                  //Initialize the vector
    return fibo_dyn_mem(n, mem);                //Call recursing function
}


//--------------------------CHILD STEP PROBLEM--------------------------
 
int count_ways(int n){
    if(n==0) return 1;
    if(n<0) return 0;

    return count_ways(n-1)+count_ways(n-2)+count_ways(n-3);
    
}

//---Dynamic implementation-----------
int count_ways_dyn_mem(int i, vector<int> &mem ){
    if(i==0) return 1;
    if(i<0) return 0;

    if(mem[i]>-1){
        return mem[i];
    }
    else
    {
        mem[i] = count_ways_dyn_mem(i-1, mem)+count_ways_dyn_mem(i-2, mem)+count_ways_dyn_mem(i-3, mem);
        return mem[i];
    }
    
}

int count_ways_dyn(int n){
    vector<int> mem(n+1, -1);
    return count_ways_dyn_mem(n, mem);
}


int main(){
    int x =  10;
    //cout<<"nth fibonacci number is "<<fibo(x)<<endl;
    //cout<<"nth fibonacci number with dyn prog is "<<fibo_dyn(x)<<endl;
   cout<<"Ways for n steps are  "<<count_ways(x)<<endl;
    cout<<"Ways for n steps with dynamic prog are  "<<count_ways_dyn(x)<<endl;
    return 0;
}










