#include <iostream>
#include "Shredder.h"

int main()
{
    std::unordered_map<std::string, int> corpus;

    Shredder shradder;
    shradder.CreatDict(corpus);

    std::vector<std::vector<std::string>> input;
    shradder.ReadInput(input);

    shradder.PrintVector(input);

    std::cout << std::endl;

    std::vector<std::vector<std::string>> input_trans = shradder.TrasnposeMatrix(input);
    std::vector<std::vector<std::string>> final = shradder.Reorder(corpus, input_trans);

    shradder.DisplayOut(shradder.TrasnposeMatrix(input));


    //Testing
    // shradder.StripCorrction(corpus, input[0], input[1]);
    
}

//   display_out(transpose_matrix(result));
//   return 0;
// }
