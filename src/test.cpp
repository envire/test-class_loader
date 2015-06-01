#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <class_loader/class_loader.h>
#include "base.h"


void simple_loading_example(int argc, char **argv)
{
    std::string LIBRARY_1="libplugin_animals.so";
    std::string LIBRARY_2="libplugin_fantasy.so";
    try
    {
        class_loader::ClassLoader loader1(LIBRARY_1, false);
        std::vector<std::string> classes = loader1.getAvailableClasses<Base>();
        for(unsigned int c = 0; c < classes.size(); ++c)
        {
            boost::shared_ptr<Base> plugin = loader1.createInstance<Base>(classes[c]);
            plugin->saySomething();
        }
    }
    catch(class_loader::ClassLoaderException& e)
    {
      std::cout << "ClassLoaderException: " << e.what() << "\n";
    }
    catch (class_loader::CreateClassException& e)
    {
        std::cout <<"CreateClassException: "<< e.what() << "\n";
    }


    try
    {
        class_loader::ClassLoader loader2(LIBRARY_2, false);
        std::vector<std::string> classes = loader2.getAvailableClasses<Base>();
        for(unsigned int c = 0; c < classes.size(); ++c)
        {
            boost::shared_ptr<Base> plugin = loader2.createInstance<Base>(classes[c]);
            plugin->saySomething();
        }

    }
    catch(class_loader::ClassLoaderException& e)
    {
      std::cout << "ClassLoaderException: " << e.what() << "\n";
    }
    catch (class_loader::CreateClassException& e)
    {
        std::cout <<"CreateClassException: "<< e.what() << "\n";
    }
}


int main(int argc, char **argv)
{
    simple_loading_example(argc, argv);
}



