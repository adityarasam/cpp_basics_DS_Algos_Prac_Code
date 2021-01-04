#include <iostream>

using namespace std;

class myClass{
    public:
        myClass(int k, int j);
        int a;
        int b;
        const int c;
        void func_1(int x);

    private:
        int d;
        int e;

        void func_2();

    friend void myfriend(myClass &x);
};

myClass::myClass(int k, int j):c(k),e(j){
    cout<<"Constructer intitalized \n";
    cout<<"c"<<c<<endl;
    cout<<"e"<<e<<endl;
}


void myClass::func_2(){
    cout<<"Func2 called \n";
    
}

void myClass::func_1(int x){
    d = x;
    cout<<"d is ="<<d<<endl;
    cout<<"func1 executed \n";
    myClass::func_2();


}

void myfriend(myClass &x){
    cout<<"Friend d is "<<x.d<<endl;
}



int main(){
    myClass *m = new myClass(3, 7);
    m->func_1(5);
    

    myfriend(*m);
    return 0;
}


