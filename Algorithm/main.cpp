#include <iostream>
#include <set>
#include <algorithm> // For std::find

int main()
{
    std::set<int> set = {8, 6, 3, 7, 1, 3, 7, 9, 42, 1, 48, 99};

    std::for_each(set.begin(), set.end(), [](int elem){
        std::cout << elem << " ";
    });

    std::cout << std::endl;
}
