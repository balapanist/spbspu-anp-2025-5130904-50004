#ifndef FUNC_H
#define FUNC_H

#include <fstream>

namespace Khvaevskii
{
  void readMatrix( std::ifstream& file, int* matrix, size_t rows, size_t cols );
  long long maxSumDiagonal( int* matrix, size_t rows, size_t cols );
  int countSaddlePoints( int* matrix, size_t rows, size_t cols );
}

#endif
