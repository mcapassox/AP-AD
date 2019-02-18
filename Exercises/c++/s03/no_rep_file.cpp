#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//vector <double> transpose(vector <double> &matrix, size_t nRow, size_t nCol);

int main() {

  vector <string> words;
  vector <string> words_filtered;
  string word;
  ifstream file("LittleWomen.txt");
  string str;
  if(!file)
  {
    std::cerr << "Cannot open the File LittleWomen.txt "<< endl;
    return false;
  }
  // Read the next line from File untill it reaches the end.
  while (file>>str) {
    words.push_back(str);
  };
  //Close The File
  file.close();
  words_filtered = words;
  for (size_t i = 0; i < words_filtered.size(); i++) {
    for (size_t j = 0; j < words_filtered.size(); j++) {
      if((words_filtered.at(i) == words_filtered.at(j))&&(i!=j)){
        words_filtered.erase(words_filtered.begin()+j);
        j--;
      }
    }
  }
  cout << endl;
  cout << "The filtered words are: " << endl;
  for (size_t i = 0; i < words_filtered.size(); i++) {
    cout << words_filtered.at(i) << endl;
  }
  return 0;
}
