#include "func.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>

bool Khvaevskii::isValidNumber(long long num)
{
  const long long MIN_VALUE = -1000000;
  const long long MAX_VALUE = 1000000;
  return (num >= MIN_VALUE && num <= MAX_VALUE);
}

void Khvaevskii::readMatrix(std::ifstream& file, int* matrix, int rows, int cols)
{
  if (!file.is_open())
  {
    throw std::runtime_error("File is not open");
  }
  for (size_t i = 0; i < static_cast<size_t>(rows); i++)
  {
    for (size_t j = 0; j < static_cast(cols); j++)
    {
      long long temp_val;
      if (!(file >> temp_val))
      {
        throw std::runtime_error("Error reading matrix element");
      }
      if (!Khvaevskii::isValidNumber(temp_val))
      {
        throw std::runtime_error("Invalid matrix element");
      }
      matrix[i * cols + j] = static_cast<int>(temp_val);
    }
  }
}

void Khvaevskii::freeMatrix(int* matrix)
{
  if (matrix)
  {
    free(matrix);
  }
}

long long Khvaevskii::maxSumDiagonal(int* matrix, int rows, int cols)
{
  if (rows == 0 || cols == 0)
  {
    return 0;
  }
  long long max_sum = -9223372036854775807LL - 1;
  for (size_t col_offset = 0; col_offset < static_cast<size_t>(cols); col_offset++)
  {
    long long sum = 0;
    size_t i = 0;
    size_t j = col_offset;
    while (i < static_cast<size_t>(rows) && j < static_cast<size_t>(cols))
    {
      sum += matrix[i * cols + j];
      i++;
      j++;
    }
    if (sum > max_sum)
    {
      max_sum = sum;
    }
  }
  for (size_t row_offset = 1; row_offset < static_cast<size_t>(rows); row_offset++)
  {
    long long sum = 0;
    size_t i = row_offset;
    size_t j = 0;
    while (i < static_cast<size_t>(rows) && j < static_cast<size_t>(cols))
    {
      sum += matrix[i * cols + j];
      i++;
      j++;
    }
    if (sum > max_sum)
    {
      max_sum = sum;
    }
  }
  return max_sum;
}

int Khvaevskii::countSaddlePoints(int* matrix, int rows, int cols)
{
  if (rows == 0 || cols == 0)
  {
    return 0;
  }
  int count = 0;
  for (size_t i = 0; i < static_cast<size_t>(rows); i++)
  {
    int min_in_row = matrix[i * cols + 0];
    for (size_t j = 1; j < static_cast<size_t>(cols); j++)
    {
      if (matrix[i * cols + j] < min_in_row)
      {
        min_in_row = matrix[i * cols + j];
      }
    }
    for (size_t j = 0; j < static_cast<size_t>(cols); j++)
    {
      if (matrix[i * cols + j] == min_in_row)
      {
        bool is_max_in_col = true;
        for (size_t k = 0; k < static_cast<size_t>(rows); k++)
        {
          if (matrix[k * cols + j] > matrix[i * cols + j])
          {
            is_max_in_col = false;
            break;
          }
        }
        if (is_max_in_col)
        {
          count++;
        }
      }
    }
  }
  return count;
}

