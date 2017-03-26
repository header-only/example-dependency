# This one is for the library developer, not necessarily for the user
# It is up to library user to write it if wanted.

add_executable(example_test example_test.cpp)
target_link_libraries(example_test header-only::example-dependency)
