add_executable(frasaso main.cpp)

add_library(Utlil_lib Util.cpp include/Util.hpp)

target_link_libraries(frasaso Utlil_lib)
target_link_libraries(frasaso cxxopts)

target_include_directories(Utlil_lib PUBLIC include)