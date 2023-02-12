#include "lib.hpp"

auto main() -> int
{
  auto const lib = library {};

  return lib.name == "test-exe" ? 0 : 1;
}
