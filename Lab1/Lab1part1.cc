#include <iostream>
using namespace std;


int fact(int n){

  if (n <= 1){
    return 1;
  }
  else{
    return(n * fact(n-1));
  }
} //12!

long int fact_long(long int n){

  if (n <= 1){
    return 1;
  }
  else{
    return(n * fact_long(n-1));
  }
} //20!



int main(){

  for (int i = 0; i < 26; i++) {
    cout << i << "!: "<< fact(i) << endl;
  }


for (int i = 0; i < 26; i++) {
  cout << i << "!: "<< fact_long(i) << endl;
}







return 0;
}
