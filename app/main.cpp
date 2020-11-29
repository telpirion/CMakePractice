#include <iostream>
#include <string>
#include "Cat.h"

using namespace std;

int main() {
    cout << "Cat says: " << Cat::Meow("my friend") << endl;
    return 0;
}