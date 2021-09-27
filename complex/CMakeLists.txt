add_library(complex source/Complex.cpp)
target_include_directories(complex PUBLIC include)
target_link_libraries(complex flt)

add_subdirectory(unit-tests)