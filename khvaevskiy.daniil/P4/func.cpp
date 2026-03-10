#include "func.h"

size_t khvaevskiy::read_line(char* buffer, size_t max_size)
{
  size_t len = 0;
  char ch;

  while (len < max_size - 1 && std::cin.get(ch) && ch != '\n')
  {
    buffer[len++] = ch;
  }

  buffer[len] = '\0';
  return len;
}

size_t khvaevskiy::exc_snd(const char* str1, size_t len1,
                           const char* str2, size_t len2,
                           char* result)
{
  size_t result_len = 0;

  for (size_t i = 0; i < len1; ++i)
  {
    bool found = false;
    for (size_t j = 0; j < len2; ++j)
    {
      if (str1[i] == str2[j])
      {
        found = true;
        break;
      }
    }
    if (!found)
    {
      result[result_len++] = str1[i];
    }
  }

  return result_len;
}

size_t khvaevskiy::rmv_vow(const char* str, size_t len,
                           char* result)
{
  constexpr const char* vowels = "aeiouAEIOU";
  size_t result_len = 0;

  for (size_t i = 0; i < len; ++i)
  {
    bool is_vowel = false;
    for (size_t j = 0; j < 10; ++j)
    {
      if (str[i] == vowels[j])
      {
        is_vowel = true;
        break;
      }
    }
    if (!is_vowel)
    {
      result[result_len++] = str[i];
    }
  }

  return result_len;
}
