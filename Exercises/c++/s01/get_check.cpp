#include <iostream>
using namespace std;

int get_int() {
  int i;
  while (!(cin>>i)) {
    cin.clear();
    cin.ignore();
    cout << "Non valido, inserire un int: ";

  }
  return i;
}
double get_double(){
  double j;
  while (!(cin>>j)) {
    cin.clear();
    cin.ignore();
    cout << "Non valido, inserire un double: ";
  }
  return j;
}

int main() {
  cout << "Inserire un int: ";
  int i = get_int();
  cout << "Inserire un double: ";
  double j = get_double();

  cout << "L'int è: " << i << endl;
  cout << "Il double è: " << j << endl;
  return 0;
}
