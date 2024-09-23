#include <iostream>
// #include "Algorithm.hpp"
// #include <algorithm>
#include <vector>
#include <array>
#include <map>


int main()
{
    std::map<int,int> mp;


    for (int i = 1; i <= 10; ++i )
    {
        mp.insert({i,i + 1});
    }

    for (auto it : mp)
    {
        std::cout << it.first << " " << it.second << std::endl;
    }

    auto it = std::find(mp.begin(), mp.end(), 9);

    if (it == mp.end())
    {
        std::cout << "chka axper jan" << std::endl;
    }else {
        std::cout << it->first << " " << it->second << std::endl;
    }
    
}



