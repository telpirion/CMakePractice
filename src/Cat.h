#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <string>

using namespace std;

class Cat
{
public:
    static string Meow(string greeting);
    static int GetNumberOfPaws();
};

#endif