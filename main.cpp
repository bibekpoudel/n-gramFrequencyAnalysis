//n-gram frequency analysis
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <fstream>


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


int main(int argc, char *argv[])
{
    map letter;
    // for(int i = 0; i < 26; ++i)
    // {
    //     letter[(char(i+97))] = 0;
    // }

    char character;
    std::fstream fin(std::string(argv[1]), std::fstream::in);
    while (fin >> std::noskipws >> character)
    {
        std::string s;
        s.push_back(character);
        letter[s]++; 
    }
    
    
    // for(const auto &pair: letter)
    // {
    //     std::cout << pair.first << " : " << pair.second << '\n'; 
    // }

    std::vector<pair> v;

    MapToVec(letter, v);
    std::sort(v.begin(), v.end(), lt);
    
    for (auto it = v.begin(); it!=v.end(); ++it)
    {
        std::cout << it->first << " : " << it->second << '\n';
    }
    
    return 0;
}
