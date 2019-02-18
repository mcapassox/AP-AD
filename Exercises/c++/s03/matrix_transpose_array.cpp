#include <iostream>
#include <array>

double* transpose(double *matrix, size_t nRow, size_t nCol);

int main() {

  size_t nRow = 5;
  size_t nCol = 15;
  double* matrix = new double [nRow*nCol]{};
  double* trMat= new double [nRow*nCol]{};
  for (size_t i = 0; i < nRow*nCol; i++) {
    matrix[i]=i+10;
  }
  trMat = transpose(matrix, nRow, nCol);

  for (size_t i = 0; i < nRow*nCol; i++) {
    std::cout << matrix[i] << "   ";
    if ((i+1)%nCol == 0)
      std::cout << std::endl;
  }
  std::cout << std::endl;
  for (size_t i = 0; i < nRow*nCol; i++) {
    std::cout << trMat[i] << "   ";
    if ((i+1)%nRow == 0)
      std::cout << std::endl;
  }
  delete[] trMat, matrix;
  return 0;
}

double* transpose(double *matrix, size_t nRow, size_t nCol){
  double* trMat= new double [nRow*nCol]{};
  for (size_t i = 0; i < nCol; i++) {
    for (size_t j = 0; j < nRow; j++) {
        trMat[i*nRow+j] = matrix[j*nCol+i];
    }
  }
return trMat;
}
