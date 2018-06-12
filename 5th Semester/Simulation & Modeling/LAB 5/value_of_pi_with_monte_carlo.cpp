#include <iostream>
#include <cstdlib>      //defines rand(), srand(), RAND_MAX
#include <ctime>        //defines ctime() for random numbers
#include <cmath>        //defines math functions
using namespace std;

//calculates the distance of the dart from the origin
double dist(double x, double y)
{
    double throwDist;
    throwDist = sqrt(x*x+y*y);  //Euclidean Distance Formula from point (0,0)
    return throwDist;
}
//calculates pi using number of darts thrown in the circle vs all darts thrown
double pie(int numThrows, double a)
{
    double pieValue = a / numThrows;
    return pieValue;
}
int main()
{
    double coord_x, coord_y, test;
    srand(time(NULL));      //creates the seed time
    test = rand() / double(RAND_MAX);
    double throwDist;       //distance from the origin
    double a = 0;              //times a dart ends up inside the circle
    int numThrows;          //times to throw the dart
    cout<< "Enter how many time to throw the dart: ";
    cin>> numThrows;

    //creates 2 random numbers 'n' times
    for(int i = 1; i <= numThrows; i++)
    {
        coord_x = (double)rand() / (RAND_MAX);
        coord_y = (double)rand() / (RAND_MAX);
        throwDist = dist(coord_x, coord_y);
        //counts how often the dart is thrown inside the circle
        if(throwDist <= 1)
        {
            a++;
        }
    }
    double pieCalc = pie(numThrows, a);
    cout<< "The value of PI is: " << 4*pieCalc;
return 0;
}
