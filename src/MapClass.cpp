#include "MapBase.h"
#include <iostream>
#include <class_loader/class_loader.h>

#include <fcl/octree.h>
#include <octomap/OcTree.h>


class Ocotmapplugin :public MapBase
{
    fcl::CollisionObject * collision_object_ptr;
public:
    virtual void saySomething(){std::cout << "I'm Ocotmapplugin" << std::endl;}
};



class Flcplugin :public MapBase
{
    octomap::OcTree * octree;
public:
  virtual void saySomething(){std::cout << "I'm Flcplugin" << std::endl;}
};


class MLSplugin :public MapBase
{

public:
  virtual void saySomething(){std::cout << "I'm mls" << std::endl;}
};


CLASS_LOADER_REGISTER_CLASS(MLSplugin, MapBase);
CLASS_LOADER_REGISTER_CLASS(Ocotmapplugin, MapBase);
CLASS_LOADER_REGISTER_CLASS(Flcplugin, MapBase);


const std::string LIBRARY_1 = "libclass_loader_TestPlugins1.so";
const std::string LIBRARY_2 = "libclass_loader_TestPlugins2.so";
