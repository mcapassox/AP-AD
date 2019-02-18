#include <iostream>
#include <cmath>

int main(){

  // counters
  int i,j,l;

  //
  size_t size;
  std::cout << "Give me the size: ";
  std::cin >> size;

  bool check_array[size];
  for(i=2;i<=size;i++)
    check_array[i]=true;
  i=2;
  l=0;

  do{
    l=0;
    for(j=i*i;j<=size;j=i*i+l*i){
      check_array[j]=false;
      l++;
    }
    i++;
  }
  while(i<=std::sqrt(size));
  for(i=2;i<=size;i++){
    if( check_array[i]==true)
      std::cout << i <<" ";
    }
}
