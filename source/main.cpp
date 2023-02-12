#include <iostream>
#include <string>

#include "lib.hpp"
#include "test-lib/test-lib.hpp"

auto main() -> int
{
  auto const lib = library {};
  auto const message = "Hello from " + lib.name + "!";
  std::cout << message << '\n';

  auto const tlib = new exported_class();
  std::cout << "external lib: " << tlib->name() << std::endl;
  delete tlib;
  return 0;
}
