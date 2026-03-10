#ifndef FUNC_H
#define FUNC_H

#include <cstddef>
#include <cctype>
#include <iostream>

namespace khvaevskiy
{
  size_t read_line(char* buffer, size_t max_size);
  size_t exc_snd(const char* str1, size_t len1, const char* str2, size_t len2, char* result);
  size_t rmv_vow(const char* str, size_t len, char* result);
}

#endif
