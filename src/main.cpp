#include <iostream>
#include "Shredder.h"

int main()
{
    std::unordered_map<std::string, int> corpus;

    Shredder shradder;
    // shradder.CreatDict(corpus);

    std::vector<std::vector<std::string>> input;
    shradder.ReadInput(input);

    shradder.PrintVector(input);



    //Testing
    // shradder.StripCorrction(corpus, input[0], input[1]);
}