#include <iostream>
#include <vector>

using namespace std;

class MyFirstClass{

public:
    MyFirstClass(){                     // Constructor
        cout << "Hello world!" << endl;
        cout << "Enter your name: ";
        cin >> name;

    }
    string name;

    void print_name(){
    cout<< name<< endl;

    }



};

//ACCESSING PRIVATE VIA PUBLIC
class Circle{
public:
    Circle(){

    cout<<"Some Operations on circle"<<endl;

    }

    double areaOfCircle(double r){

        radius = r;                                     // Writing the private variables via  public method

        float pi = 3.142;

    return pi*radius*radius;
    }

private:
    double radius;




};



class Protectdemo{          //PARENT CLASS

public:
    Protectdemo(){

    cout<<"Some Operations on Protected member"<<endl;
    cout<< "ParentClass Constructor"<<endl;
    id =5;
    cout<<id<<endl;

    }

protected:
    int id;                 //PROTECTED MEMEBER


};


class child: public Protectdemo{                // INHERITED CHILD CLASS

public:


    void set_id(int i){
    id = i;                 //ACCESSING PROTECTED MEMBER IN PARENT CLASS
    cout<<i<<endl;

    }




};



class FriendDemo{

public:
    FriendDemo(){
    cout<<"Friend Class Demo"<<endl;
    }

    void printfunc(){

    cout<< radius<<endl;
    }

private:
    int radius;

    friend void execute(FriendDemo &obj, int r);


};


void execute(FriendDemo &obj, int r){

obj.radius = r;             //WRITING PRIVATE MEMEBERS USING FRIEND FUNCTION


obj.printfunc();

}


//  INHERITANCE CONCEPT
class vehicles{

public:
    vehicles(){
        cout<<"Parent class constructor"<<endl;
    }

    void set_parameters(string t, int W, int S, int D){
        type = t;
        numOfWheels = W;
        noOfseats = S;
        noOfdoors = D;

        cout<<"The vehicle is "<<type<<endl;
        cout<<"The vehicle has "<<numOfWheels<<" wheels, "<<noOfseats<<" seats, "<<noOfdoors<<" doors, "<<endl;
        cout<<endl;

        return;


    }

     virtual void set_information(string t, int W, int S, int D){};

private:
    string type;
    int numOfWheels, noOfseats, noOfdoors;
};


class car: public vehicles{
public:
    car(){
        cout<<"Constructor for car"<<endl;
        set_parameters("sedan", 4, 4, 4);
    }


};


class bike: public vehicles{
public:
    bike(){
        cout<<"Constructor for bike"<<endl;

    }

    ~bike(){
        cout<<"Destructor for bike"<< endl;

    }

    void set_information(string t, int W, int S, int D){
        set_parameters(t,W,S,D);
    }


};



int main()
{
    int ListL;
    vector<int> l;
    /*
    //  Objects & Pointers

    MyFirstClass m;     // Object Instantiation
    MyFirstClass *p;
    p = &m;

    m.print_name();
    cout<<"new class";

    p->print_name();*/

    /*
    // Objects and accessing private members
    double radius=0.0;

    Circle C;
    cout<<"Enter radius"<<endl;
    cin>>radius;

    cout<< C.areaOfCircle(radius)<<endl;
    return 0;*/

    /*

    //PROTECTED MEMBER
    child c;

    c.set_id(300);
*/
    //FriendDemo* Myobj = new FriendDemo;       //FriendDemo Myobj;

    //execute(*Myobj, 10);      //execute(Myobj, 10);


    car *C = new car;
    //bike *n;
    vehicles *b =  new bike;        //Polymorphism  base class with inherited class mem allocation
    bike *d =  new bike;

    b->set_information("sportsbike",2,2,0);         //Polymorphism
    d->set_information("scooter",2,2,0);


    delete(b);


///------------Parent class pointer can point to base class object--------------
                ///  Parent *P = new base
///------------Base class pointer cannot point to Parent class
                /// Base *B = new Parent ----wont work

/*
cout<<"Please enter list elements\n";



for (int i=0; i < 5;i++){

    cin>>ListL;
    l.push_back(ListL);
}

for (int i=0; i < 5;i++){

    cout<<l[i];
}

*/
return 0;
}
