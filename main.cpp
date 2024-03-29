//Compile with g++ -g main.cpp -L/usr/local/lib/ -lboost_filesystem -lboost_system


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

int main(int argc, char *argv[])
{
  int num = atoi(argv[1]);
  std::cout << num;
  path p = "./clean-textfiles";
  directory_iterator it{p};
  while (it != directory_iterator{}){
    std::string path = it->path().string();
    std::string filename = path;
    int dotpos = filename.find("_");
    int dotpos2 = filename.find(".t");
    std::string newfilename = "./data/" + filename.substr(dotpos + 1, (dotpos2 - (dotpos + 1))) + "_data.txt";
    std::cout << newfilename << '\n';
    std::ofstream NewFile;
    NewFile.open(newfilename.c_str(), std::ios_base::app);
    
    for(int nth = 1; nth <= num; ++nth ){
      map letter;
      std::ifstream input(filename);
      // Current string(character) being read from file
      std::string cursor;
      
      cursor.resize(nth);
      
      // Position in stream
      int pos=1;
      while( !input.eof() ){
    	// Get a ngram from the file stream
    	get_pos(input, cursor, nth );
        
    	if (!input.eof())
    	  {
    	    letter[cursor]++;
    	  } 
    	else
    	  {
    	    break;
    	  }
        
            //keeps track of position in stream
    	input.seekg( pos++ );
        
      }
      
      input.close();    
    
      
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
    }
    NewFile.close();
    
    
    std::cout << filename << '\n';
    *it++;
  }
  return 0;
    
 
}
