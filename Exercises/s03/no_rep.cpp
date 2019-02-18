#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//vector <double> transpose(vector <double> &matrix, size_t nRow, size_t nCol);

int main() {

  vector <string> words;
  vector <string> words_filtered;
  vector <string> repeated_words;
  string word;
  unsigned int n;

  cout << "How many words do you want to read? ";
  cin >> n;
  cout << "Please insert the words: " << endl;
  for (size_t i = 0; i < n; i++) {
    cin >> word;
    words.push_back(word);
  }
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
/*
vector <double> transpose(vector <double> &matrix, size_t nRow, size_t nCol){

return trMat;
}
*/
