//n-gram frequency analysis

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>



int main()
{


    std::unordered_map<char, int> letter;
    for(int i = 0; i < 26; ++i)
    {
        letter[char(i+97)] = 0;
    }

    

    // for(const auto &pair: letter)
    // {
    //     std::cout << pair.first << " : " << pair.second << '\n'; 
    // }

    
    
    
    // char character;
    // fstream fin("file", fstream::in);
    // while (fin >> noskipws >> character) {
    //     cout << character; 
    // }
    return 0;
}
