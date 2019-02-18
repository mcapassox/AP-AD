#include <iostream>
using namespace std;

void unique(){
  unsigned int counter = 1;
  string line1, line2;
  getline(cin,line1);

  while(getline(cin,line2)){
    if (line1 == line2) {
      counter++;
    }
    else
    {
      cout << counter << ' ' << line1 << endl;
      line1 = line2;
      counter = 1;
    }
  }
}

int main() {
  unique();
  return 0;
}
