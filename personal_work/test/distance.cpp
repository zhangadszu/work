#include <cmath>
#include <iostream>

using namespace std;

int GetDistance(float longitude1, float latitude1, float longitude2, float latitude2)
{
    const double EARTH_RADIUS = 6378137.0;    //地球半径，单位M  
    const double PI = acos(-1);

    double radLatitud1 = latitude1 * PI / 180;
    double radLatitud2 = latitude2 * PI / 180;
    double dRadLatitud = radLatitud1 - radLatitud2;
    double radLongitud1 = longitude1 * PI / 180;
    double radLongitud2 = longitude2 * PI / 180;
    double dRadLongitud = radLongitud1 - radLongitud2;


    return EARTH_RADIUS * 2 * asin(sqrt(pow(sin(dRadLatitud / 2), 2) + cos(radLatitud1) * cos(radLatitud2) * pow(sin(dRadLongitud / 2), 2)));
}

int main(int argc, char *argv[])
{
	cout<<GetDistance(atof(argv[1]), atof(argv[2]), atof(argv[3]), atof(argv[4]))<<endl;
}

