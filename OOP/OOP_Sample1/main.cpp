#include <iostream>

using namespace std;

#define pi 3.142;

///----------------Simple Class-------------------------------------------------
class Myclass
{
public:
    Myclass()
    {
        cout<<"Constructor"<<endl;
    }

    float distance(float speed, float time)
    {
        float distance;

        return distance = speed * time;
    }


    void Operation(int& sum)        //Passing by reference
    {
        sum =  sum+5;
    }
};


///----------------Class Public Members & Private Members Example---------------
class Geometry
{
public:
    Geometry(float s, float l,float b,float h,float r)
    {
        side =s;
        length = l;
        height = h;
        breadth = b;
        radius = r;
    }

    float getAreaSquare()
    {
        return side*side;
    }

    float getAreaTriangle()
    {
        return 0.5*breadth*height;
    }

    float getAreaRectangle()
    {
        return breadth*length;
    }

    float getAreaCube()
    {
        return length*breadth*height;
    }

    float getAreaCircle()
    {
        return radius*radius*pi;
    }

private:
    float side;
    float height;
    float length;
    float breadth;
    float radius;

};

///----------------Inheritance--------------------------------------------------

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


///----------------Inheritance with Parent class with arguments
class specs
{
public:
    specs(float vel, float dist, float tim, float acc, float jer)
    {
        cout<<"Constructor of specs"<<endl;
        velocity = vel;
        distance = dist;
        time = tim;
        acceleration = acc;
        jerk= jer;

    }

protected:
    float velocity;
    float distance;
    float time;
    float acceleration;
    float jerk;



};

class unknownDistance : public specs
{
public:


    void calDist()
    {
        cout<< "Distance is: "<< velocity*time<<endl;
    }

};

class unknownTime : public specs
{
public:


    void calTime()
    {
        cout<< "Time is :"<< distance/velocity <<endl;
    }
};


int s=10;

int main()
{
    cout << "Hello world!" << endl;

    ///------------Object Instantiation-----------------------------------------
    //Myclass M;                      //----Instantiation using a variable---
    //M.Operation(s);
    Myclass* MP = new Myclass();
    cout<<"Distance"<<MP->distance(10,2)<<endl;
    cout<<s<<endl;



    ///------------Class pointer to that points to class object-----------------
    Myclass *P;
    //P = &M;


    cout<< MP->distance(5.0,2.0)<<endl;



    ///------------Class  Constructor and Public Function Calling and Private Members---
    Geometry G(5,8,4,3,2);
    Geometry* GP = &G;



    cout<<"Area of Circle : "<<GP->getAreaCircle()<<endl;
    cout<<"Area of Square : "<<GP->getAreaSquare()<<endl;
    cout<<"Area of Triangle : "<<GP->getAreaTriangle()<<endl;
    cout<<"Area of Rectangle : "<<GP->getAreaRectangle()<<endl;
    cout<<"Area of Cube : "<<GP->getAreaCube()<<endl;




    ///-----------inheritance with Constructor Parameter----------------------------------
    specs S(100,1000,5,10000,100000);
    specs* SP;

    ///-----------Simple inheritance--------------------------------------------
    cout<<endl<<endl;
    car C;          ///--------Constructor runs only when an object is created
    bike B;

    vehicles *V;    ///--------Pointer does not creates any object and hence no Constructor
    car* CP;
    //V=&C;

    ///----------Printing section ---------------------




    return 0;
}
