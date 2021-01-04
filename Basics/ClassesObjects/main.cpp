#include <iostream>

using namespace std;


class motor{

public:
    int speed = 5;
    int control_on = 1;

    void print_speed(){
    speed =  100;
    cout<< speed<< endl;

    }


    int calc_speed(int distance, int time){
        if (time !=0){
            return speed = distance/ time;
        }

    }

};

class left:public motor{
public:
    void lspeed(){
    cout<< control_on<<endl;

    }


};

int main()
{

    motor M;
    M.print_speed();


    left lm;
    lm.lspeed();
    cout<<M.calc_speed(10, 2)<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
