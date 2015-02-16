FIND_PACKAGE(PkgConfig REQUIRED)
find_package(Boost COMPONENTS system filesystem program_options  REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

MESSAGE("Boost_INCLUDE_DIR: "  ${Boost_INCLUDE_DIRS})
MESSAGE("Boost_LIBRARY_DIR: "  ${Boost_LIBRARY_DIRS})
MESSAGE("Boost_LIBRARIES: "  ${Boost_LIBRARIES})


include_directories(SYSTEM ${Boost_INCLUDE_DIRS} )
link_directories(${Boost_LIBRARY_DIRS})

#rock_library(manipulator_planner_library
#    SOURCES     ${manipulator_motion_planner_cpp_files}
        
#DEPS_PKGCONFIG base-types ompl fcl assimp octomap kdl_conversions kdl_parser srdfdom  urdfdom urdfdom_headers orocos-kdl pcl_common-1.7 pcl_features-1.7 pcl_filters-1.7 pcl_geometry-1.7 pcl_io-1.7 pcl_kdtree-1.7 pcl_keypoints-1.7  pcl_octree-1.7 pcl_outofcore-1.7 pcl_people-1.7 pcl_recognition-1.7  pcl_registration-1.7 pcl_sample_consensus-1.7 pcl_search-1.7 pcl_segmentation-1.7  pcl_surface-1.7 pcl_tracking-1.7 pcl_visualization-1.7)





rock_executable(test_class_loader test.cpp  ${Boost_LIBRARIES}    DEPS_PKGCONFIG class_loader )
