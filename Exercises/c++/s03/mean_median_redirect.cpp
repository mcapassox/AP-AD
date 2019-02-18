#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
double mean(std::vector <double>& temperature_vec);
double median(std::vector <double> &temperature_vec);


int main() {

  std::vector <double> temperature_vec;
  std::ifstream file("temperatures.txt");
  std::string str;
  double val = 0;
  while (file>>val) {
    temperature_vec.push_back(val);
  };
  //Close The File
	file.close();

  std::cout << "The mean is: " << mean(temperature_vec) << std::endl;
  std::cout << "The median is: " << median(temperature_vec) << std::endl;


  return 0;
}
double mean(std::vector <double>& temperature_vec){
  double sum=0;
  for (size_t i = 0; i < temperature_vec.size(); i++)
    sum+=temperature_vec.at(i);
  return sum/temperature_vec.size();
}

double median(std::vector <double>& temperature_vec){
std::sort(temperature_vec.begin(),temperature_vec.end());

  return temperature_vec.at(temperature_vec.size()/2);
}
