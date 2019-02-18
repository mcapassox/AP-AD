#include <iostream>
#include <string>

template <typename num>
class Vector {
  num* elem;
  size_t _size;

 public:
  Vector(const std::size_t size) : elem{new num[size]}, _size{size} {}

  // automatically release the acquired memory
  ~Vector() { delete[] elem; }

  // try to remove the const and recompile
  auto size() const { return _size; }

  num& operator[](const std::size_t i) { return elem[i]; }

  // try to comment this line and recompile
  auto operator[](const std::size_t i) const { return elem[i]; }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
  for (auto i = 0u; i < v.size(); ++i)
    os << "v[" << i << "] = " << v[i] << std::endl;
  return os;
}

int main() {
  Vector<double> v{10};

  for (auto i = 0u; i < v.size(); ++i)
    v[i] = i;

  std::cout << v << std::endl;

  Vector<double>* pv{&v};

  // first dereference the pointer, then I can use the defined operators
  (*pv)[0] = -99.999;

  pv->operator[](1) = 77777.3333;  // or I call the function by name

  std::cout << *pv << std::endl;

  Vector<double>& rv{v};

  rv[5] = 555;

  std::cout << rv << std::endl;

  return 0;
}
