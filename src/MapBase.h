#ifndef MAP_BASE_H
#define MAP_BASE_H
#include <string>
class MapBase
{
  public:
    virtual void saySomething() = 0;
    int unique_id;
    std::string label;
    void getClassName();
};

#endif
