#include <iostream>

#include "Shredder.cpp"

//Function declartion
    //Creating dic of 4-grams with its frequency distrubition 
    void CreatDict(std::unordered_map<std::string, int>& corpus);

    //Returing likelihood of substring str being a valid 4-gram 
    float Probability(std::unordered_map<std::string , int>& corpus , std::string str);

    // Reads the srabled input data from ***.txt file 
    void ReadInput(std::vector<std::vector<std::string>>& input);

    // Calculates and returns the probability of 2 rows being next to each other from the transposed input matrix
    float StripCorrction(std::unordered_map<std::string, int>& corpus, std::vector<std::string> left, std::vector<std::string> right);

    //Prints a vector of vector of strings
    void PrintVector(const std::vector<std::vector<std::string>>& input);

    //Displays the unscrambled output
    void DisplayOut(const std::vector<std::vector<std::string> >& input);
    
    // Takes in the transposed form of the original input data.
    // Reorders the strips into corrected data.
    std::vector<std::vector<std::string> > Reorder(std::unordered_map<std::string, int>& corpus, std::vector<std::vector<std::string> >& input);

    //Transposes input matrix for ease of accessing each strips.
    std::vector<std::vector<std::string> > TrasnposeMatrix(std::vector<std::vector<std::string> >& input);


int main()
{
    std::unordered_map<std::string, int> corpus;

     CreatDict(corpus);

    std::vector<std::vector<std::string>> input;
     ReadInput(input);

     PrintVector(input);

    std::cout << std::endl;

    std::vector<std::vector<std::string>> input_trans = TrasnposeMatrix(input);
    std::vector<std::vector<std::string>> final =  Reorder(corpus, input_trans);

     DisplayOut( TrasnposeMatrix(input));


    //Testing
    //  StripCorrction(corpus, input[0], input[1]);
    
}

//   display_out(transpose_matrix(result));
//   return 0;
// }
