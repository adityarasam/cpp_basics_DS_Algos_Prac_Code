#include "Geom.h"



line::line(point &point1, point &point2)
{
    p=point1;
    cout<<"Point 1 is: "<<p.x<<", " <<p.y<<endl;
    q=point2;
    cout<<"Point 2 is: "<<q.x<<", " <<q.y<<endl;

    if ((q.x != p.x) && (q.y != p.y))
    {
        m = (q.y-p.y)/(q.x-p.x);
        c = p.y - m*p.x;
    }
    else if (q.x == p.x)
    {
        x_parallel = false;
        y_parallel = true;
        cout<< "y_parallel "<<y_parallel<<endl;
    }
    else if (q.y == p.y)
    {
        x_parallel = true;
        y_parallel = false;
        cout<< "x_parallel "<<x_parallel<<endl;
    }
    cout<<"Slope is: "<< m<<endl;
    
    cout<<"intercept is: "<< c<<endl;
}

lineAlgo::lineAlgo(){}


bool lineAlgo:: ColinearpointOnLine(line& l,point p3)
{
    if ((p3.x > min(l.p.x,l.q.x)) && (p3.x < max(l.p.x,l.q.x)) && (p3.y >  min(l.p.y,l.q.y)) &&(p3.y < max(l.p.y,l.q.y)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

point lineAlgo::pointOfIntersection(line& l1, line& l2)
{
    point ptOfint;

    if (l1.y_parallel && l2.x_parallel)
    {
        ptOfint.x = l1.p.x;
        cout<<ptOfint.x<<endl;
        ptOfint.y = l2.p.y;
    }

    else if (l1.y_parallel)
    {
        ptOfint.x = l1.p.x;
        ptOfint.y = l2.m *ptOfint.x + l2.c;
    }
    else  if (l2.y_parallel)
    {
        ptOfint.x = l2.p.x;
        ptOfint.y = l1.m *ptOfint.x + l1.c;
    }
    else if (l1.x_parallel)
    {
        ptOfint.y = l1.p.y;
        ptOfint.x = (ptOfint.y - l2.c)/l2.m;
    }
     else if (l2.x_parallel)
    {
        ptOfint.y = l2.p.y;
        ptOfint.x = (ptOfint.y - l1.c)/l1.m;
    }
    
    else{
  
    ptOfint.x = (l2.c - l1.c)/(l1.m-l2.m);
    ptOfint.y = (l2.m*l1.c - l1.m*l2.c)/(l2.m-l1.m);
    }
    return ptOfint;

}