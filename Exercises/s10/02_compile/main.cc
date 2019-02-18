#include <utility.h>
#include <foo.h>
#include <iostream>
void print_upper(std::string);
void print_lower(std::string);

int main()
{
  print_lower("EXPECT TO SEE LOWER CASE");
  print_upper("expect to see upper case");
  Foo foo;
  std::cout << Foo::f << foo.bar << " " << to_lower(foo.bar) << std::endl;
  return 0;
}
