cmake_minimum_required(VERSION 3.20)
project(QuickCppSetup VERSION 1.0.0 LANGUAGES CXX)

# Требуем C++26
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Оптимизация
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra")

# Ищем libcurl
find_package(CURL REQUIRED)
if(NOT CURL_FOUND)
    message(FATAL_ERROR "libcurl not found. Install: sudo apt install libcurl4-openssl-dev")
endif()

# Добавляем исполняемый файл (main.cpp лежит в src/)
add_executable(cpp_setup src/main.cpp)

# Подключаем заголовки и библиотеки curl
target_include_directories(cpp_setup PRIVATE ${CURL_INCLUDE_DIRS})
target_link_libraries(cpp_setup PRIVATE ${CURL_LIBRARIES})

# Проверка компилятора на поддержку C++26
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 14)
    message(WARNING "GCC < 14 may not fully support C++26")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 18)
    message(WARNING "Clang < 18 may not fully support C++26")
endif()

# Установка бинарника (опционально)
install(TARGETS cpp_setup DESTINATION bin)
