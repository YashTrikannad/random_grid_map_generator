//
// random_grid_map_generator
// Created by yash on 9/7/19.
//

#include <iostream>
#include "generator.h"


void print(const std::vector<std::vector<bool>>& grid_map)
{
    for(const auto& row: grid_map)
    {
        for(const auto& element: row)
        {
            std::cout << element << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    // get random map
    const auto grid_map = generate_map<std::vector<std::vector<bool>>, bool, true, false>(50, 50, 10);
    print(grid_map);
}


