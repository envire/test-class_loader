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
      loader1.createInstance<Base>("Cat")->saySomething();
    }
    catch(class_loader::ClassLoaderException& e)
    {
      std::cout << "ClassLoaderException: " << e.what() << "\n";
    }


    try
    {
      class_loader::ClassLoader loader2(LIBRARY_2, false);
      loader2.createInstance<Base>("Monster")->saySomething();
    }
    catch(class_loader::ClassLoaderException& e)
    {
      std::cout << "ClassLoaderException: " << e.what() << "\n";
    }




}


int main(int argc, char **argv)
{
    simple_loading_example(argc, argv);
}



