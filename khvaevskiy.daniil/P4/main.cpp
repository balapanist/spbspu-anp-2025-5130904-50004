#include <iostream>
#include <cstring>
#include "func.h"

int main()
{
  const size_t max_size = 1024;
  char* input = new (std::nothrow) char[max_size];

  if (!input)
  {
    std::cerr << "Error: cannot allocate memory for input\n";
    return 1;
  }

  std::cin.getline(input, max_size);

  if (std::cin.fail() || std::cin.eof() || std::strlen(input) == 0)
  {
    std::cerr << "Error: no input provided\n";
    delete[] input;
    return 1;
  }

  size_t len = std::strlen(input);

  char* result = new (std::nothrow) char[max_size];

  if (!result)
  {
    std::cerr << "Error: cannot allocate memory for result\n";
    delete[] input;
    return 1;
  }

  size_t res_len = khvaevskiy::exc_snd(input, len, "abc", 3, result);
  result[res_len] = '\0';
  std::cout << result << '\n';

  res_len = khvaevskiy::rmv_vow(input, len, result);
  result[res_len] = '\0';
  std::cout << result << '\n';

  delete[] result;
  delete[] input;

  return 0;
}
