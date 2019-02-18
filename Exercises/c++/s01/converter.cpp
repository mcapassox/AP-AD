#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {

  string  inches, meters;
  float factor = 0.0254;

  cin >> inches;
  cout << strtof((inches).c_str(),0)*factor << " meters" << endl;

  return 0;
}
