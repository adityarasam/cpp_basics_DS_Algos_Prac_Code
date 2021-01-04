#include "Geom.h"

int main()
{
    point p1,p2, r, s, z;
    p1.x = 0.0;
    p1.y = 0.0;

    p2.x = 0.0;
    p2.y = 10.0;

    r.x = 3.0;
    r.y = 3.0;

    s.x = -3.0;
    s.y = 3.0;
    

    line l1(p1,p2);
    line l2(r,s);
    lineAlgo la ;

    //cout<<la.ColinearpointOnLine(l1,r)<<endl;

    
    z = la.pointOfIntersection(l1,l2);

    cout<<"("<<z.x<<", "<< z.y<<")"<<endl;

    
    //line* l = new line(p1,p2);
    cout << "Hello world!" << endl;
    return 0;
}
