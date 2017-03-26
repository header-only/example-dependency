
# This is an #inglued <> generated CMakeLists.txt (https://github.com/header-only/inglued)
# To modify it edit CMakeLists.txt.tpl ( i.e. Generate it with `inglued cmaketpl` )


cmake_minimum_required(VERSION 3.7.2)

project(example-dependency VERSION "0.0.1")
enable_testing()

set(CMAKE_CXX_STANDARD 14)

# Compile with shipped-with headers or without 
option(INGLUED "Enable use of #inglued shipped with dependencies." ON)

# Compile unit tests
option(UNIT_TESTS "Enable Unit Testing" OFF)


# Warning as errors to ensure example-dependency quality
string(TOUPPER "${CMAKE_CXX_COMPILER_ID}" COMPILER_IN_USE)
if ("${COMPILER_IN_USE}" STREQUAL "GNU" OR "${COMPILER_IN_USE}" MATCHES "CLANG")
	add_definitions(
    -Wall
		-Werror
		-Wno-unused-local-typedefs
		-Wno-unused-variable
  )
endif()



# assert
if (INGLUED)
  include_directories(AFTER deps/boostorg/assert/include/)
else ()
  find_package(Boost REQUIRED)
endif()

# config
if (INGLUED)
  include_directories(AFTER deps/boostorg/config/include/)
else ()
  find_package(Boost REQUIRED)
endif()

# core
if (INGLUED)
  include_directories(AFTER deps/boostorg/core/include/)
else ()
  find_package(Boost REQUIRED)
endif()

# detail
if (INGLUED)
  include_directories(AFTER deps/boostorg/detail/include/)
else ()
  find_package(Boost REQUIRED)
endif()

# exception
if (INGLUED)
  include_directories(AFTER deps/boostorg/exception/include/)
else ()
  find_package(Boost REQUIRED)
endif()

# function
if (INGLUED)
  include_directories(AFTER deps/boostorg/function/include/)
else ()
  find_package(Boost REQUIRED)
endif()

# function_types
if (INGLUED)
  include_directories(AFTER deps/boostorg/function_types/include/)
else ()
  find_package(Boost REQUIRED)
endif()

# functional
if (INGLUED)
  include_directories(AFTER deps/boostorg/functional/include/)
else ()
  find_package(Boost REQUIRED)
endif()

# fusion
if (INGLUED)
  include_directories(AFTER deps/boostorg/fusion/include/)
else ()
  find_package(Boost REQUIRED)
endif()

# integer
if (INGLUED)
  include_directories(AFTER deps/boostorg/integer/include/)
else ()
  find_package(Boost REQUIRED)
endif()

# move
if (INGLUED)
  include_directories(AFTER deps/boostorg/move/include/)
else ()
  find_package(Boost REQUIRED)
endif()

# mpl
if (INGLUED)
  include_directories(AFTER deps/boostorg/mpl/include/)
else ()
  find_package(Boost REQUIRED)
endif()

# predef
if (INGLUED)
  include_directories(AFTER deps/boostorg/predef/include/)
else ()
  find_package(Boost REQUIRED)
endif()

# preprocessor
if (INGLUED)
  include_directories(AFTER deps/boostorg/preprocessor/include/)
else ()
  find_package(Boost REQUIRED)
endif()

# static_assert
if (INGLUED)
  include_directories(AFTER deps/boostorg/static_assert/include/)
else ()
  find_package(Boost REQUIRED)
endif()

# throw_exception
if (INGLUED)
  include_directories(AFTER deps/boostorg/throw_exception/include/)
else ()
  find_package(Boost REQUIRED)
endif()

# tuple
if (INGLUED)
  include_directories(AFTER deps/boostorg/tuple/include/)
else ()
  find_package(Boost REQUIRED)
endif()

# type_index
if (INGLUED)
  include_directories(AFTER deps/boostorg/type_index/include/)
else ()
  find_package(Boost REQUIRED)
endif()

# type_traits
if (INGLUED)
  include_directories(AFTER deps/boostorg/type_traits/include/)
else ()
  find_package(Boost REQUIRED)
endif()

# typeof
if (INGLUED)
  include_directories(AFTER deps/boostorg/typeof/include/)
else ()
  find_package(Boost REQUIRED)
endif()

# utility
if (INGLUED)
  include_directories(AFTER deps/boostorg/utility/include/)
else ()
  find_package(Boost REQUIRED)
endif()

# json
if (INGLUED)
  include_directories(AFTER deps/nlohmann/json/src/)
else ()
  find_package(nlohmann_json REQUIRED)
endif()


# Define header only library
include_directories(BEFORE ${CMAKE_CURRENT_LIST_DIR})
add_library(example-dependency INTERFACE)
add_library(header-only::example-dependency ALIAS example-dependency)

set(include_install_dir "include")

if (INGLUED)

  target_include_directories(example-dependency INTERFACE 
    # Transitive libraries location once installed
    $<INSTALL_INTERFACE:${include_install_dir}/example-dependency/deps> 
  )


else()

  target_link_libraries(example-dependency INTERFACE 
      Boost::boost
      Boost::boost
      Boost::boost
      Boost::boost
      Boost::boost
      Boost::boost
      Boost::boost
      Boost::boost
      Boost::boost
      Boost::boost
      Boost::boost
      Boost::boost
      Boost::boost
      Boost::boost
      Boost::boost
      Boost::boost
      Boost::boost
      Boost::boost
      Boost::boost
      Boost::boost
      Boost::boost
      nlohmann_json
  )

endif()


if( UNIT_TESTS )
 add_subdirectory(test)
endif()

# IDE Supports (XCode, VS, QtCreator they don't list headers)
file (GLOB_RECURSE HPP_FILES example-dependency/*.h*)
add_custom_target(sources SOURCES ${HPP_FILES})

# Installing

# Layout. This works for all platforms:
#   * <prefix>/lib/cmake/<PROJECT-NAME>
#   * <prefix>/lib/
#   * <prefix>/include/
set(config_install_dir "lib/cmake/${PROJECT_NAME}")

set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")

# Configuration
set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(targets_export_name "${PROJECT_NAME}Targets")
set(namespace "${PROJECT_NAME}::")

# Include module with fuction 'write_basic_package_version_file'
include(CMakePackageConfigHelpers)

# Configure '<PROJECT-NAME>ConfigVersion.cmake'
# Note: PROJECT_VERSION is used as a VERSION
write_basic_package_version_file(
    "${version_config}" COMPATIBILITY SameMajorVersion
)

# Configure '<PROJECT-NAME>Config.cmake'
# Use variables:
#   * targets_export_name
#   * PROJECT_NAME
configure_package_config_file(
    "cmake/modules/Config.cmake.in"
    "${project_config}"
    INSTALL_DESTINATION "${config_install_dir}"
)


# Targets:
install(
    TARGETS example-dependency
    EXPORT "${targets_export_name}"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
    RUNTIME DESTINATION "bin"
    INCLUDES DESTINATION "${include_install_dir}"
)

# Headers:
install(
    DIRECTORY example-dependency
    DESTINATION "${include_install_dir}"
    FILES_MATCHING PATTERN "*.[ih]*"
)

# Install the deps when run in INGLUED mode
if (INGLUED)


  install(
      DIRECTORY deps/boostorg/assert/include/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/boostorg/assert/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


  install(
      DIRECTORY deps/boostorg/config/include/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/boostorg/config/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


  install(
      DIRECTORY deps/boostorg/core/include/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/boostorg/core/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


  install(
      DIRECTORY deps/boostorg/detail/include/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/boostorg/detail/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


  install(
      DIRECTORY deps/boostorg/exception/include/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/boostorg/exception/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


  install(
      DIRECTORY deps/boostorg/function/include/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/boostorg/function/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


  install(
      DIRECTORY deps/boostorg/function_types/include/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/boostorg/function_types/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


  install(
      DIRECTORY deps/boostorg/functional/include/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/boostorg/functional/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


  install(
      DIRECTORY deps/boostorg/fusion/include/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/boostorg/fusion/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


  install(
      DIRECTORY deps/boostorg/integer/include/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/boostorg/integer/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


  install(
      DIRECTORY deps/boostorg/move/include/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/boostorg/move/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


  install(
      DIRECTORY deps/boostorg/mpl/include/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/boostorg/mpl/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


  install(
      DIRECTORY deps/boostorg/predef/include/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/boostorg/predef/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


  install(
      DIRECTORY deps/boostorg/preprocessor/include/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/boostorg/preprocessor/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


  install(
      DIRECTORY deps/boostorg/static_assert/include/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/boostorg/static_assert/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


  install(
      DIRECTORY deps/boostorg/throw_exception/include/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/boostorg/throw_exception/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


  install(
      DIRECTORY deps/boostorg/tuple/include/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/boostorg/tuple/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


  install(
      DIRECTORY deps/boostorg/type_index/include/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/boostorg/type_index/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


  install(
      DIRECTORY deps/boostorg/type_traits/include/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/boostorg/type_traits/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


  install(
      DIRECTORY deps/boostorg/typeof/include/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/boostorg/typeof/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


  install(
      DIRECTORY deps/boostorg/utility/include/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/boostorg/utility/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


  install(
      DIRECTORY deps/nlohmann/json/src/
      DESTINATION ${include_install_dir}/example-dependency/deps
      FILES_MATCHING PATTERN "*.[ih]*"
      PATTERN deps/nlohmann/json/deps EXCLUDE # Transitive deps are hikedup on `glue seal`.
      )


endif(INGLUED)

# Config
#   * <prefix>/lib/cmake/example-dependency/example-dependencyConfig.cmake
#   * <prefix>/lib/cmake/example-dependency/example-dependencyConfigVersion.cmake
#   * <prefix>/lib/cmake/example-dependency/example-dependencyTargets.cmake
install(
    FILES "${project_config}" "${version_config}"
    DESTINATION "${config_install_dir}"
)
install(
    EXPORT "${targets_export_name}"
    NAMESPACE "${namespace}"
    DESTINATION "${config_install_dir}"
)

