#include <iostream>

using namespace std;

enum DAY
{
	Sunday    = 0,
	Monday    = 1,
	Tuesday   = 2,
	Wednesday = 3,
	Thursday  = 4,
	Friday    = 5,
	Saturday  = 6
};


int main()
{
    DAY days[7];

	for (int i = 0; i < 7; ++i)
		days[i] = (DAY)i;

	cout<< day[2]<< endl;
    cout << "Hello world!" << endl;
    return 0;
}
