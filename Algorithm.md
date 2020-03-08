Steps: 
1. Creates a dictionary of 4-grams with its frequency distribution.
2. Returns likelihood of substring str being a valid 4-gram.
3. Reads the scrambled input data from input.txt file.
4. Calculates and returns the probability of 2 rows being next to each other from the transposed input matrix. 
5. Prints a vector of vector of strings.
6. Displays the unscrambled output.
7. Takes in the transposed form of the original input data.
   Reorders the strips into corrected data.
8. Transposes input matrix for ease of accessing each strips.

//Main:

int main()
{
  unordered_map<string, int> corpus;
  create_dict(corpus);

  
  vector<vector<string> > input;
  read_input(input);
  print_vec(input);
  cout << endl; 

  vector<vector<string> > input_transpose = transpose_matrix(input);
  vector<vector<string> > result = reorder(corpus,input_transpose);
  
  display_out(transpose_matrix(result));
  return 0;
}