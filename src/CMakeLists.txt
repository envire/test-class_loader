#rock_library(class_loader_library
#    SOURCES plugins1.cpp plugins2.cpp
#    HEADERS base.h
#    DEPS_PKGCONFIG fcl class_loader)


rock_library(class_loader_library
    SOURCES MapClass.cpp
    HEADERS MapBase.h
    DEPS_PKGCONFIG octomap fcl class_loader)

