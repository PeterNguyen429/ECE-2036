#include <iostream>
#include <cmath>
using namespace std;


int fact(int n){

  if (n <= 1){
    return 1;
  }
  else{
    return(n * fact(n-1));
  }
} //12!

float fact_long(long int n){

  if (n <= 1){
    return 1;
  }
  else{
    return(n * fact_long(n-1));
  }
} //20!
float e_float = 2.71828182845904523536028747135266249775724709369995f;
double e = 2.71828182845904523536028747135266249775724709369995;

int main(){
int i;
float x_float;
double x_double; // declarations
float percentErrorFloat;
double percentErrorDouble;
cout << "Input the number of terms in the power series using FLOAT: ";
cin >> i; // how many terms


for (int count = 0; count < i; count++) {
  x_float = x_float + float (pow(1,count)/fact_long(count));
  percentErrorFloat = 100 * ((e_float - x_float)/e_float);
  cout << "--------"<<endl;
  cout << "#terms = " << count + 1 << endl;
  cout << "approx = " << x_float << endl;
  cout << "%error = " << percentErrorFloat << endl;
}
cout << endl;
cout << "Input the number of terms in the power series using DOUBLE: ";
cin >> i;

for (int count = 0; count < i; count++) {
  x_double = x_double + pow(1,count)/fact_long(count);
  percentErrorDouble = 100 * ((e - x_double)/e);
  cout << "--------"<<endl;
  cout << "#terms = " << count + 1 << endl;
  cout << "approx = " << x_double << endl;
  cout << "%error = " << percentErrorDouble << endl;
}















  return 0;
}
