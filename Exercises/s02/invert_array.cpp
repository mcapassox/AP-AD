#include <iostream>
using namespace std;

// Predefinitions
template <typename T>
T* allocate(size_t length_array);
template <typename T>
void invert(T* array, size_t length_array);

// Main
int main() {

  size_t length_array;
  double * pointer;
  cout << "Insert the length of the array: ";
  cin >> length_array;
  // allocate space (Return pointer)
  pointer = allocate<double>(length_array);
  // invert array
  invert(pointer, length_array);
  return 0;
}

template <typename T>
T* allocate(size_t length_array){
  T* array{new T[length_array]};  // allocated on the HEAP, or free-store
  for (size_t i = 0; i < length_array; i++) {
    cout << "Insert the element number " << i << " of the array: ";
    cin >> array[i];
  }
  return array;
}

template <typename T>
void invert(T* array, size_t length_array){
  cout << "The array in revers order is: ";
  for (size_t i = 0; i < length_array; i++) {
    cout << array[length_array-i-1] << " ";
  }
  delete[] array;
}
