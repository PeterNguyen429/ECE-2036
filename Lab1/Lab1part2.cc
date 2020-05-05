#include <iostream>
#include <cmath>
using namespace std;




float roots_float(float a, float b, float c, bool flag){
if (flag){ //positive root
  float x1; // declare x1 float
  x1 = -1 * b; // x = -b
  x1 = x1 + sqrt(b*b - 4*a*c); //sqrt term
  x1 = x1 / (2*a); // divide by 2a
  return x1;
}
else
{
  float x1; // declare x1 float
  x1 = -1 * b; // x = -b
  x1 = x1 - sqrt(b*b - 4*a*c); //sqrt term
  x1 = x1 / (2*a); // divide by 2a
  return x1;

}



}


double roots_double(double a, double b, double c, bool flag){

  if (flag){ //positive root
    double x1; // declare x1 float
    x1 = -1 * b; // x = -b
    x1 = x1 + sqrt(b*b - 4*a*c); //sqrt term
    x1 = x1 / (2*a); // divide by 2a
    return x1;
  }
  else
  {
    double x1; // declare x1 float
    x1 = -1 * b; // x = -b
    x1 = x1 - sqrt(b*b - 4*a*c); //sqrt term
    x1 = x1 / (2*a); // divide by 2a
    return x1;

  }

}



int main(){

float x1_float; // DECLARATIONS
float x2_float;
double x1_double;
double x2_double;
float percentErrorFloat;
double percentErrorDouble;
x1_float = -0.001;
x2_float = -3000;
x1_double = -0.001;
x2_double = -3000;

cout << "Using the float data type the roots are:" << endl;
percentErrorFloat = 100*((roots_float(1,3000.001,3,true) - x1_float)/x1_float);
cout <<"x1: "<< roots_float(1,3000.001,3,true) << "    % error = " << percentErrorFloat << endl; // postive float
percentErrorFloat = 100*((roots_float(1,3000.001,3,false) - x2_float)/x2_float);
cout <<"x2: "<< roots_float(1,3000.001,3,false) << "    % error = " << percentErrorFloat << endl; // negative float root


cout << "Using the double data type the roots are:" << endl;
percentErrorDouble = 100*((roots_double(1,3000.001,3,true) - x1_double)/x1_double);
cout <<"x1: "<< roots_double(1,3000.001,3,true) << "    % error = " << percentErrorDouble << endl; // postive double root
percentErrorDouble = 100*((roots_double(1,3000.001,3,false) - x2_double)/x2_double);
cout <<"x2: "<< roots_double(1,3000.001,3,false) << "    % error = " << percentErrorDouble << endl; // negative double root






  return 0;
}
