/**********************************************************************
 *  readme 
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Ethan Yu

Hours to complete assignment: 7 hours

/**********************************************************************
 * Explain which approach you decided to use when implementing
 * (either recursive with memoization, recursive without memoization,
 * dynamic programming or Hirschberg's algorithm). Also describe why
 * you chose this approach and what its pros and cons are.
 **********************************************************************/

	I used Needleman-Wunsch dynamic programming for my program.
I chose this because we went over it in class and it is more efficient
than the recursion methods and I did not research the Hirschberg algorithm
enough to feel comfortable using it.
	I also used vectors instead of a dynamic 2D array because vectors
are easier to work with.

/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Input: (Contents of endgaps7.txt)
	atattat
	tattata
Expected output:
	Edit Distance = 4
	a - 2
	t t 0
	a a 0
	t t 0
	a a 0
	t t 0
	- a 2

What happened: I got the expected output 
	(or at least, I think it should be right)


/**********************************************************************
 * Look at your computer's specs in the settings. 
 * How much RAM does your computer have and explain what this means? 
 **********************************************************************/

	I have 8 GB which means it can handle 8 GB of short term memory data at a time.

/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
a = 1
b = 25
largest N = 2.5

/**********************************************************************
 * Run valgrind if you can and attach the output file to your submission. 
 * If you cannot run it, explain why, and list all errors you're seeing. 
 * If you can run it successfully, does the memory usage nearly match that 
 * found in the question above? 
 * Explain why or why not. 
/**********************************************************************

	I included a file from the ecoli2500.txt test, it should be
the massif.out.2107 file.

/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt		118		0.434706	39.35
ecoli5000.txt		160		1.47877	156.8
ecoli7000.txt		194		2.50052	219.3
ecoli10000.txt		223		5.24941	625.9
ecoli20000.txt		My computer couldn't handle past this point
ecoli28284.txt		

/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730



/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 
b = 
largest N = 
	I don't quite understand the doubling method, sorry.
/
**********************************************************************
 *  Did you use the lambda expression in your assignment? If yes, where 
 * (describe a method or provide a lines numbers)
 **********************************************************************/

	I used a lambda function in the main function to run the program.
	It takes the input strings and does everything else in the program.
	
	auto runProgram = [rowString, columnString]()
	{
		ED test(rowString, columnString);
		int optimalDistance = test.OptDistance();
		std::cout << "Edit Distance = " << optimalDistance << std::endl;
		std::string pathMessage = test.Alignment();
		std::cout << pathMessage << std::endl;
	};

	runProgram();

**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/

Static Functions: https://www.tutorialspoint.com/static-functions-in-c 
2D Vector: https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/ 
Push_back vector into a vector: https://stackoverflow.com/a/19853840 
to_string function: http://www.cplusplus.com/reference/string/to_string/ 
Lambda functions: https://www.geeksforgeeks.org/lambda-expression-in-c/ 
Info about RAM: https://www.avast.com/c-what-is-ram-memory 

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

	It took a while to understand the Needleman-Wunsch alorithm.
	Also it would be nice to know what the doubling method is talking
	about.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 
 
 
