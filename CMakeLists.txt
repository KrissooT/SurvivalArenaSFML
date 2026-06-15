cmake_minimum_required(VERSION 3.28)
project(SurvivalArenaSFML CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SFML_BUILD_NETWORK OFF)
set(SPDLOG_USE_STD_FORMAT ON)
set(TGUI_BACKEND SFML_GRAPHICS)

include(FetchContent)
FetchContent_Declare(SFML URL https://github.com/SFML/SFML/archive/refs/tags/3.1.0.tar.gz)
FetchContent_Declare(JSON URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz)
FetchContent_Declare(TGUI URL https://github.com/texus/TGUI/archive/refs/tags/v1.12.1.tar.gz)
FetchContent_MakeAvailable(SFML JSON TGUI)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS Source/*.cpp)
add_executable(SurvivalArenaSFML ${SOURCES})

add_custom_command(TARGET SurvivalArenaSFML POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/Content
    $<TARGET_FILE_DIR:SurvivalArenaSFML>/Content
)

target_include_directories(SurvivalArenaSFML PRIVATE Include)
target_compile_features(SurvivalArenaSFML PRIVATE cxx_std_20)
target_compile_options(SurvivalArenaSFML PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra>
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra>)
target_link_libraries(SurvivalArenaSFML PRIVATE 
	SFML::Graphics 
	SFML::Audio 
	nlohmann_json::nlohmann_json 
        TGUI::TGUI)