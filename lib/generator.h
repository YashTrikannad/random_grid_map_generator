//
// random_grid_map_generator
// Created by yash on 9/7/19.
//

#pragma once

#include <vector>
#include <random>

/// Function to Generate a Random 2D grid map
/// @tparam GridMapType - Return Type (In this case, 2d STL vector)
/// @tparam DataType - DataType of Contents of each node
/// @tparam FreeType - DataType value of Free Node
/// @tparam ObstacleType - DataType value of Obstacle Node
/// @param rows - no. of rows required
/// @param cols - no. of cols required
/// @param n_obstacles - no. of obstacles required
/// @return Random 2D grid map
template <typename GridMapType, typename DataType, DataType FreeType, DataType ObstacleType,
        typename = std::enable_if_t<std::is_same<std::vector<std::vector<DataType>>, GridMapType>::value>>
GridMapType generate_map(size_t rows, size_t cols, size_t n_obstacles)
{
    std::vector<std::vector<DataType>> map(rows, std::vector<DataType>(cols, FreeType));

    std::random_device r;
    std::default_random_engine engine(r());
    std::uniform_int_distribution<int> random_row(1, rows);
    std::uniform_int_distribution<int> random_col(1, cols);
    std::uniform_int_distribution<int> random_height(1, rows / 3);
    std::uniform_int_distribution<int> random_width(1, cols / 3);

    while (n_obstacles > 0)
    {
        const auto upper_left_obstacle_row = random_row(engine);
        const auto upper_left_obstacle_col = random_col(engine);
        const auto obstacle_height = random_height(engine);
        const auto obstacle_width = random_width(engine);

        for (size_t row_index = upper_left_obstacle_row, height = 0;
             row_index < rows && height < obstacle_height;
             row_index++, height++)
            for (size_t col_index = upper_left_obstacle_col, width = 0; col_index < cols &&
                                                                                  width <
                                                                                  obstacle_width; col_index++, width++)
            {
                map[row_index][col_index] = ObstacleType;
            }

        n_obstacles--;
    }

    return map;
}
