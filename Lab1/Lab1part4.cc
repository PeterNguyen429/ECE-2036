#include <iostream>
#include <cmath>
using namespace std;


float float_array[100];
double double_array[100];

float e_float = 2.71828182845904523536028747135266249775724709369995f;
double e = 2.71828182845904523536028747135266249775724709369995;

float fact_float(int n){

  if (n <= 1){
    return 1;
  }
  else{
    return(n * fact_float(n-1));
  }
} //12!

double fact_double(int n){

  if (n <= 1){
    return 1;
  }
  else{
    return(n *  fact_double(n-1));
  }
} //20!


int main(){
float sum_float_forward;
float sum_float_backward;
double sum_double_forward;
double sum_double_backward;
float percentErrorFloat_forward;
float percentErrorFloat_backward;
double percentErrorDouble_forward;
double percentErrorDouble_backward;
for (int i = 0; i < 100; i++) {
  float_array[i] = float (1/fact_float(i));
  double_array[i] = double (1/fact_double(i));
} //intializing arrays


cout << "--------" << endl; //21st term
for (int i = 0; i < 100; i++) {
  sum_float_forward = float (sum_float_forward + float_array[i]);
}
for (int i = 99; i > -1; i--){
  sum_float_backward = float (sum_float_backward + float_array[i]);
}
percentErrorFloat_forward = 100 * ((e - sum_float_forward)/e);
percentErrorFloat_backward = 100 * ((e - sum_float_backward)/e);

  cout << "forward approx = " << sum_float_forward << endl;
  cout << "forward %error = " << percentErrorFloat_forward << endl;
  cout << "backward approx = " << sum_float_backward << endl;
  cout << "backward %error = " << percentErrorFloat_backward << endl;

  cout << "--------" << endl;

  for (int i = 0; i < 100; i++) {
    sum_double_forward = sum_double_forward + double_array[i];
  }
  for (int i = 99; i > -1; i--){
    sum_double_backward = sum_double_backward + double_array[i];
  }
  percentErrorDouble_forward = 100 * ((e - sum_double_forward)/e);
  percentErrorDouble_backward = 100 * ((e - sum_double_backward)/e);

  cout << "forward approx = " << sum_double_forward << endl;
  cout << "forward %error = " << percentErrorDouble_forward << endl;
  cout << "backward approx = " << sum_double_backward << endl;
  cout << "backward %error = " << percentErrorDouble_backward << endl;
  return 0;
}
