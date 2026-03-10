#include <iostream>
#include <cstring>
#include "func.h"

int main()
{
  const size_t max_size = 1024;
  char* input = new char[max_size];

  size_t len = khvaevskiy::read_line(input, max_size);

  if (len == 0)
  {
    std::cerr << "Error: no input provided\n";
    delete[] input;
    return 1;
  }

  char* result = new char[max_size];

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
