// Print target char in a string using recursion
// 2 September 2023



#include <iostream>
using namespace std;

void printDig(int n){
  if(n==0){
    return;
  }
  int dig=n%10;
  cout<<dig<<" ";
  int newval=n/10;
  printDig(newval);



}

int main() {

  int n=647;
  printDig(n);


  return 0;
}
