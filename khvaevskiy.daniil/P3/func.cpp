#include "func.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <limits>
#include <stdexcept>

void Khvaevskii::readMatrix( std::ifstream& file, int* matrix, size_t rows, size_t cols )
{
  for ( size_t i = 0; i < rows; i++ )
  {
    for ( size_t j = 0; j < cols; j++ )
    {
      long long temp_val;
      if ( !( file >> temp_val ) )
      {
        throw std::runtime_error( "Error reading matrix element" );
      }
      matrix[i * cols + j] = static_cast< int >( temp_val );
    }
  }
}

long long Khvaevskii::maxSumDiagonal( int* matrix, size_t rows, size_t cols )
{
  if ( rows == 0 || cols == 0 )
  {
    return 0;
  }
  long long max_sum = std::numeric_limits< long long >::min();
  for ( size_t col_offset = 0; col_offset < cols; col_offset++ )
  {
    long long sum = 0;
    size_t i = 0;
    size_t j = col_offset;
    while ( i < rows && j < cols )
    {
      sum += matrix[i * cols + j];
      i++;
      j++;
    }
    if ( sum > max_sum )
    {
      max_sum = sum;
    }
  }
  for ( size_t row_offset = 1; row_offset < rows; row_offset++ )
  {
    long long sum = 0;
    size_t i = row_offset;
    size_t j = 0;
    while ( i < rows && j < cols )
    {
      sum += matrix[i * cols + j];
      i++;
      j++;
    }
    if ( sum > max_sum )
    {
      max_sum = sum;
    }
  }
  return max_sum;
}

int Khvaevskii::countSaddlePoints( int* matrix, size_t rows, size_t cols )
{
  if ( rows == 0 || cols == 0 )
  {
    return 0;
  }
  int count = 0;
  for ( size_t i = 0; i < rows; i++ )
  {
    int min_in_row = matrix[i * cols + 0];
    for ( size_t j = 1; j < cols; j++ )
    {
      if ( matrix[i * cols + j] < min_in_row )
      {
        min_in_row = matrix[i * cols + j];
      }
    }
    for ( size_t j = 0; j < cols; j++ )
    {
      if ( matrix[i * cols + j] == min_in_row )
      {
        bool is_max_in_col = true;
        for ( size_t k = 0; k < rows; k++ )
        {
          if ( matrix[k * cols + j] > matrix[i * cols + j] )
          {
            is_max_in_col = false;
            break;
          }
        }
        if ( is_max_in_col )
        {
          count++;
        }
      }
    }
  }
  return count;
}
