//n-gram frequency analysis

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <fstream>


typedef std::unordered_map<char, int> map; 
typedef std::pair<char, int> pair;

void MapToVec( const  map & m, std::vector<pair> & v ) {
    for( auto it = m.begin(); it != m.end(); ++it ) {
        v.push_back(*it);
    }
}


int main()
{

    
    std::unordered_map<char, int> letter;
    for(int i = 0; i < 26; ++i)
    {
        letter[char(i+97)] = 0;
    }

    char character;
    std::fstream fin("clean_file.txt", std::fstream::in);
    while (fin >> std::noskipws >> character)
    {
        letter[character]++; 
    }
    
    
    // for(const auto &pair: letter)
    // {
    //     std::cout << pair.first << " : " << pair.second << '\n'; 
    // }

    std::vector<pair> v;

    MapToVec(letter, v);
    for (auto it = v.begin(); it!=v.end(); ++it)
    {
        std::cout << it->first << " : " << it->second << '\n';
    }
    
    
    return 0;
}
