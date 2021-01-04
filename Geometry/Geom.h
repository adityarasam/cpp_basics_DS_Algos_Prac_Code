#include <iostream>

using namespace std;

struct point
{
    float x;
    float y;
};

class line
{
    public:
    line();
    line(point &point1, point &point2);
    
     point p;
     point q;
     float m, c;
     bool x_parallel = false, y_parallel=false;
};


class lineAlgo 
{
    public:
    lineAlgo();

    bool ColinearpointOnLine(line &l,point p3);
    point pointOfIntersection(line& l1, line& l2 );
    
};

