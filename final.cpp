//Compile with g++ -g main.cpp -L/usr/local/lib/ -lboost_filesystem -lboost_system

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <stdlib.h>

typedef std::unordered_map<std::string, int> map; 
typedef std::pair<std::string, int> pair;

void MapToVec( const  map & m, std::vector<pair> & v ) {
    for( auto it = m.begin(); it != m.end(); ++it ) {
        v.push_back(*it);
    }
}

int lt(const pair p0, const pair p1){
    return (p0.second > p1.second);
}


//funtion to get position of every n characters
void get_pos(std::ifstream & in, std::string & string, int streamsize){
        int pos=0;
        while(pos<streamsize){
                in >> string[pos];
                ++pos;
        }
}



using namespace boost::filesystem;

int main()
{
  map letter;
  std::ofstream NewFile;
  NewFile.open("final.txt", std::ios_base::app);
  
  path p = "./data";
  directory_iterator it{p};
  while (it != directory_iterator{}){
    std::string path = it->path().string();
    std::string filename = path;
    
      std::ifstream input(filename);

      std::string str; 
      while (std::getline(input, str))
	{
	  size_t a = str.find(':');
	  std::string ngram = str.substr(0, a);
	  std::string number = str.substr(a+1);
	  int n = std::stoi(number);
	  letter[ngram] = letter[ngram] + n;
	}

      input.close();    

      std::cout << filename << '\n';
      *it++;
  }
  

      
    
  std::vector<pair> v;
  
  MapToVec(letter, v);
  std::sort(v.begin(), v.end(), lt);
      
  letter.clear();
  
  for (auto it = v.begin(); it!=v.end(); ++it)
    {
      //std::cout << it->first << " : " << it->second << '\n';
      NewFile << it->first << ":" << it->second << '\n';
      
    }
  v.clear();
 

    
  NewFile.close();
  
  
  return 0;
    
 
}
