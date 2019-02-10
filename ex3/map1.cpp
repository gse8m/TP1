// Copyright [2019] <>
// header-start
//////////////////////////////////////////////////////////////////////////////////
//
// \file      mean_and_median.cpp
//
// \brief     This file belongs to the C++ tutorial project
//
// \author    Bernard
//
// \copyright Copyright ng2goodies 2015
//            Distributed under the MIT License
//            See http://opensource.org/licenses/MIT
//
//////////////////////////////////////////////////////////////////////////////////
// header-end
//;;;


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
#include <iomanip>
#include <sstream>

using std::string;
using std::vector;
using namespace std;
// This simple program reads from a file a set of numbers (double format)
// computes a running mean value, computes the median after sort

// This program has several problems, can you spot them

int main(int argc, char *argv[]) {
  string file_name{argv[1]};
  std::ifstream fin(file_name, std::ios::in);

  vector<string> I;
  vector<double> V;

  string iden,valeur;
  //  double valeur;
  string line;
  string identifiant;

  while (std::getline(fin, line)) {
    std::istringstream stream(line);
    stream >> iden >> valeur;
    std::cout << iden<<"   "<< valeur<<std::endl;
    
    V.push_back(valeur);
    I.push_back(iden);
  }
  for(;;)
    {
      bool FLAG=0;
      std::cout << "query> ";
      std::cin >> identifiant;

      if(identifiant=="END")
	break;
      else
	{
	  for(unsigned i=0;i<I.size();i++)
	    {
	      if(identifiant == I[i])
		{
		  std::cout << "value[" << I[i] <<"]= " << V[i] << std::endl;
		  FLAG=1;
		}
	    }
	}

      if(FLAG==0)
	std::cout << "This ID does not exists."<< std::endl;
    }
  std::cout<<"Bye..."<<std::endl;
  return EXIT_SUCCESS;
}

