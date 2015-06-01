FIND_PACKAGE(PkgConfig REQUIRED)
find_package(Boost COMPONENTS system filesystem program_options  REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

MESSAGE("Boost_INCLUDE_DIR: "  ${Boost_INCLUDE_DIRS})
MESSAGE("Boost_LIBRARY_DIR: "  ${Boost_LIBRARY_DIRS})
MESSAGE("Boost_LIBRARIES: "  ${Boost_LIBRARIES})


include_directories(SYSTEM ${Boost_INCLUDE_DIRS} )
link_directories(${Boost_LIBRARY_DIRS})

add_library(plugin_animals SHARED plugins1.cpp)
add_library(plugin_fantasy SHARED plugins2.cpp)

rock_executable(test_class_loader test.cpp  ${Boost_LIBRARIES}    DEPS_PKGCONFIG class_loader )
