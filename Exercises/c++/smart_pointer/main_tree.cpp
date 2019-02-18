#include <iostream>
#include <memory>
#include <random>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <algorithm>

template <class T>
class smart_pointer{
  private:
    T* ptr;
  public:
    T& get_ref(){return *ptr;}
    T* get(){return ptr;};
    void reset(T* p) {ptr = p;};
    // constructor
    smart_pointer() : ptr{nullptr}{}
    // constructor 2
    smart_pointer(T* p) : ptr{p}{}
    // destructor
    ~smart_pointer(){delete ptr; std::cout << "destructor" << std::endl;}
    //void operator=(T* p){reset(p);}
};

int main() {

    smart_pointer<int> pointer;
    int a = 2;
    smart_pointer<int> pointer2 = &b;
    //pointer2.reset(&a);
    //pointer = pointer2;

    return 0;
}
