#include <iostream>
#include <vector>
using namespace std;

vector <int> transpose(vector <int> &matrix, size_t nRow, size_t nCol);

int main() {

  size_t nRow = 10;
  size_t nCol = 10;
  vector <int> matrix(nRow*nCol,10);
  vector <int> trMat(nRow*nCol,0);
  for (size_t i = 1; i < nRow*nCol; i++) {
    matrix[i]=i+10;
  }
  trMat = transpose(matrix, nRow, nCol);

  for (size_t i = 0; i < nRow*nCol; i++) {
    cout << matrix[i] << "   ";
    if ((i+1)%nCol == 0)
      cout << endl;
  }
  cout << endl;
  for (size_t i = 0; i < nRow*nCol; i++) {
    cout << trMat[i] << "   ";
    if ((i+1)%nRow == 0)
      cout << endl;
  }
  return 0;
}

vector <int> transpose(vector <int> &matrix, size_t nRow, size_t nCol){
  vector<int> trMat;
  for (size_t i = 0; i < nCol; i++) {
    for (size_t j = 0; j < nRow; j++) {
        trMat.push_back(matrix[j*nCol+i]);
    }
  }
return trMat;
}
