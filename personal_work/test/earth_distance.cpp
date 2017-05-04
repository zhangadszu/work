#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 5)
    {
        cout<<"param error, please input ./"<<argv[0]<<" x1 y1 x2 y2"<<endl;
        return 1;
    }

    const static double r = 6371.009;
    const static double pi = acos(-1.0);
   
    double x1, y1, x2, y2;
    x1 = atof(argv[1]) / 180 * pi;
    y1 = atof(argv[2]) / 180 * pi;
    x2 = atof(argv[3]) / 180 * pi;
    y2 = atof(argv[4]) / 180 * pi;
    auto dx = fabs(x1 - x2);
    auto dy = fabs(y1 - y2);
    
    auto rd1 = acos(sin(x1) * sin(x2) + cos(x1) * cos(x2) * cos(dy));
    cout<<"first algorithm, output:"<<rd1 * r<<endl;

    auto rd2 = 2 * asin(sqrt(pow(sin(dx / 2), 2) + cos(x1) * cos(x2) * pow(sin(dy / 2), 2)));
    cout<<"second algorithm, output:"<<rd2 * r<<endl;

    return 0;
}

