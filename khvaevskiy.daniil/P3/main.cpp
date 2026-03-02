#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include "func.h"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Usage: " << argv[0] << " num input output\n";
    return 1;
  }
  if (argv[1][0] != '1' && argv[1][0] != '2')
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  if (argv[1][1] != '\0')
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }

  int rows, cols;
  int* matrix = nullptr;
  bool is_fixed = (argv[1][0] == '1');

  std::ifstream infile(argv[2]);
  if (!infile.is_open())
  {
    std::cerr << "Error reading matrix from file\n";
    return 2;
  }

  std::ofstream outfile(argv[3]);
  if (!outfile.is_open())
  {
    infile.close();
    return 2;
  }

  try
  {
    long long temp_rows, temp_cols;
    if (!(infile >> temp_rows >> temp_cols))
    {
      infile.close();
      outfile.close();
      std::cerr << "Error reading matrix dimensions from file\n";
      return 2;
    }
    rows = static_cast<int>(temp_rows);
    cols = static_cast<int>(temp_cols);

    if (rows < 0 || cols < 0)
    {
      infile.close();
      outfile.close();
      std::cerr << "Invalid matrix dimensions\n";
      return 2;
    }

    if (is_fixed)
    {
      if (rows > 100 || cols > 100)
      {
        infile.close();
        outfile.close();
        std::cerr << "Invalid matrix dimensions for fixed array\n";
        return 2;
      }
      if (static_cast<long long>(rows) * cols > 10000)
      {
        infile.close();
        outfile.close();
        std::cerr << "Too many elements for fixed array\n";
        return 2;
      }

      int fixed_matrix[10000];
      infile.close();
      infile.open(argv[2]);
      infile >> temp_rows >> temp_cols;

      Khvaevskii::readMatrix(infile, fixed_matrix, rows, cols);
      matrix = fixed_matrix;

      long long result = Khvaevskii::maxSumDiagonal(matrix, rows, cols);
      outfile << result << "\n";
    }
    else
    {
      matrix = static_cast<int*>(malloc(rows * cols * sizeof(int)));
      if (!matrix)
      {
        infile.close();
        outfile.close();
        std::cerr << "Memory allocation error\n";
        return 2;
      }

      infile.close();
      infile.open(argv[2]);
      infile >> temp_rows >> temp_cols;

      Khvaevskii::readMatrix(infile, matrix, rows, cols);

      int result = Khvaevskii::countSaddlePoints(matrix, rows, cols);
      outfile << result << "\n";

      Khvaevskii::freeMatrix(matrix);
      matrix = nullptr;
    }
  }
  catch (const std::exception& e)
  {
    infile.close();
    outfile.close();

    if (!is_fixed && matrix)
    {
      Khvaevskii::freeMatrix(matrix);
      matrix = nullptr;
    }
    std::cerr << e.what() << "\n";
    return 2;
  }

  infile.close();
  outfile.close();
  return 0;
}
