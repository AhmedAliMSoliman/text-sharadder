#include <iostream>
#include "Shredder.h"

int main() 
{
    std::unordered_map<std::string, int> corpus;

    Shredder shradder;
    shradder.CreatDict(corpus);

    std::vector<std::vector<std::string>> input;
    shradder.ReadInput(input);
}