// Copyright [2019] <SUN Hao, LIU Bohua, ZHAO Hairen>
// header-start
//////////////////////////////////////////////////////////////////////////////////
//
// \file      histogram.cpp
//
// \brief     This file belongs to the C++ tutorial project
//
// \author    SUN, LIU, ZHAO
//
// \copyright Copyright ng2goodies 2015
//            Distributed under the MIT License
//            See http://opensource.org/licenses/MIT
//
//////////////////////////////////////////////////////////////////////////////////
// header-end
//


// C++ version
// Compilation with g++ 5.3.0 & g++ 6.3.0
// mingwin: g++ -std=c++14 -O3 -o mean_and_median mean_and_median.cpp

// Compilation with g++ 4.9.3
// cygwin:  g++ -D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_DYNAMIC -std=c++14 -O3 ...

// Other tool chain
// msvc:    ok!
// clang:   ok!


#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using std::string;
using std::vector;
using std::count_if;


// This simple program reads from a file a set of numbers (double format)
// computes a running mean value, computes the median after sort


int main(int argc, char *argv[]) {
  string file_name{argv[1]};
  vector<double> buf;
  std::ifstream fin(file_name, std::ios::in);

  string line;
  auto mean = 0.0;

  while (std::getline(fin, line)) {
    auto d = std::stod(line);
    buf.push_back(d);
    mean = (buf.size() == 1) ? d : mean + (d - mean) / buf.size();
  }

  std::sort(buf.begin(), buf.end());

  auto mid = buf.size() / 2;
  double median = (buf.size() % 2) ? buf[mid] :
                                     (buf[mid - 1] + buf[mid]) / 2;

  std::cout << "number of elements = " << buf.size()
            << ", median = " << median
            << ", mean = " << mean << std::endl;



  vector<int> bin;
  for (int b = 0; b < 8000; b += 100) {
    int c = b + 100;
    int num = 0;
    num = count_if(buf.begin(), buf.end(), [&](int i){return i >= b && i < c;});
    bin.push_back(num);
  }
  int max = 0;
  for (double j = 0; j < bin.size(); ++j) {
    if (bin[j]> max) {
      max = bin[j];
    }
  }
  int a = 0;
  for (double j = 0; j< bin.size(); ++j) {
    std::cout.setf(std::ios::right);
    std::cout.width(6);
    std::cout << a;
    std::cout.setf(std::ios::right);
    std::cout.width(8);
    std::cout << bin[j] << "  ";
    for (int etoile = 0; etoile < 60 * bin[j] / max; etoile++) {
      std::cout << "*";
    }
    std::cout << std::endl;
    a = a + 100;
  }
  return EXIT_SUCCESS;
}
