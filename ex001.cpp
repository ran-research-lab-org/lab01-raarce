// Este programa demuestra como usar rapidcsv y fmt
// Para saber como instalar fmt puedes ver el README.md

#include <iostream>
#include <vector>
#include "rapidcsv.h"
#include <algorithm>
#include <numeric>


#include <fmt/chrono.h>


using namespace std;
using namespace fmt;
int main()
{
  rapidcsv::Document doc("colrowhdr.csv");

  vector<float> col = doc.GetColumn<float>("Close");
  cout << "Read " << col.size() << " values." << endl;
  

  for (auto f: col)
    cout << f << endl;

  double sum = accumulate(col.begin(), col.end(), 0.0);
  cout << sum << endl;

  auto now = std::chrono::system_clock::now();
  print("Date and time: {}\n", now);
  
  print("Time: {:%H:%M}\n", now);
  print("My name is {}", "chicky");

  print("Here is your table\n");
  int rows = doc.GetRowCount();
  int cols = doc.GetColumnCount();
  
  for (unsigned int i = 0; i < rows; i++) {
    vector<float> r = doc.GetRow<float>(i);
    for (auto f: r) {
      print("{}\t",f);
      
    }
    print("\n");
  }

}
