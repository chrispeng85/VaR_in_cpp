cmake_minimum_required(VERSION 3.10)
project(var_calculator VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories($var/include)

add_library(var_lib
        src/Asset.cpp 
        src/VaRCalculator.cpp
        src/Statistics.cpp        
)


target_link_libraries(var_calculator var_lib)

