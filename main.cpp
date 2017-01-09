#include <iostream>
#include <cmath>

using namespace std;

//Даны координаты вершин некоторого треугольника и координаты некоторой точки внутри него.
//Найти расстояние от данной точки до ближайшей стороны треугольника.


//Алгоритм взят из источника http://grafika.me/node/237
int ifLineCrossed( float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy )
{
    int ifYes = 0;
    float abx, aby, acx, acy, adx, ady, cdx, cdy, cbx, cby, cax, cay, v1, v2, v3, v4;

    abx = bx - ax ;
    aby = by - ay;

    acx = cx - ax;
    acy = cy - ay;

    adx = dx - ax;
    ady = dy - ay;

    cdx = dx - cx;
    cdy = dy - cy;

    cbx = bx - cx;
    cby = by - cy;

    cax = ax - cx;
    cay = ay - cy;

    v1 = ( abx * acy ) - ( aby * acx);
    v2 = ( abx * ady ) - ( aby * adx );
    v3 = ( cdx * cay ) - ( cdy - cax );
    v4 = ( cdx - cby ) - ( cdy - cbx );

    if ( (v1 * v2 < 0) && (v3 * v4 < 0) )
    {
        ifYes++;
    }

    return ifYes;
}

//Расстояние между точкой и вершиной треугольника
double distCount( double ax, double ay, double bx, double by)
{
    return sqrt( ( ( bx - ax ) * ( bx - ax ) ) + ( ( by - ay ) * ( by - ay ) ) );

}

void main()
{
    double x1, x2, x3, px, y1, y2, y3, py, d1, d2, d3;

    double ox, oy = 0;
    int crossLineIndicate = 0;

    cout << "Enter coordinates of your triangle. Type at first X coord. ";
    cout << "First top A is:\n "; 
    cin >> x1 >> y1;
    cout << "Second top B is:\n "; 
    cin >> x2 >> y2;
    cout << "And third C:\n "; 
    cin >> x3 >> y3;
    cout << "Your point to chack it's distance:\n "; 
    cin >> px >> py;

    ox = px;



    crossLineIndicate += ifLineCrossed( ox, oy, px, py, x1, y1, x2, y2);
    crossLineIndicate += ifLineCrossed( ox, oy, px, py, x3, y3, x2, y2);
    crossLineIndicate += ifLineCrossed( ox, oy, px, py, x1, y1, x3, y3);

    if ( crossLineIndicate % 2 == 0 )
    {
        cout << "\nYour point lie in triangle! " 
            "\nNow we will detect the smallest distance betwen point and triangle side!";
    }
    else
    {
        cout << "Please, enter another point that will be lie in the triangle!";
        cin >> px >> py;
    }

    d1 = distCount( px, py, x1, y1 );
    d2 = distCount( px, py, x2, y2 );
    d3 = distCount( px, py, x3, y3 );

    if ( d1 > d2 && d1 > d3 )
        cout << "Your point close to side BC.";

    else  if ( d2 > d1 && d2 > d3 )
        cout << "Your point close to side AC.";

    else  if ( d3 > d1 && d3 > d2 )
        cout << "Your point close to side AB.";



    system( "pause" );
}
