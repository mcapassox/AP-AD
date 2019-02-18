#include <iostream>
using namespace std;
int funct(int a) {
  return a;
}
int main() {
  char* a;
  funct(a);
  cout << funct(a) << endl;
  return 0;
}
