#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//vector <double> transpose(vector <double> &matrix, size_t nRow, size_t nCol);

int main() {

  vector <string> temperature_vec;
  ifstream file("temperatures.txt");
  string str;
  if(!file)
	{
		std::cerr << "Cannot open the File Temperatures.txt "<< endl;
		return false;
	}
  // Read the next line from File untill it reaches the end.
  while (getline(file, str))
  {
  	// Line contains string of length > 0 then save it in vector
  	if(str.size() > 0)
  		temperature_vec.push_back(str);
  }
  //Close The File
	file.close();
  for (size_t i = 0; i < temperature_vec.size(); i++)
    cout << temperature_vec.at(i) << endl;
  return 0;
}
/*
vector <double> transpose(vector <double> &matrix, size_t nRow, size_t nCol){

return trMat;
}
*/
