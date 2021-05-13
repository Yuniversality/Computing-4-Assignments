/**********************************************************************
 *  Linear Feedback Shift Register (part A) ps1a-readme.txt template
 **********************************************************************/

Name: Ethan Yu
Hours to complete assignment: 7 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.

 **********************************************************************/

	The task was to make a Linear Feedback Shift Register (LFSR) that would
generate a new bit by XOR'ing the leftmost bit and the tap bits and append that
to the end of the register after it is left-shifted.
	The shifting and appending happened in the step() function and the 
generate(n) function just called the step() function n amount of times.
	I also made an error exception class called FibLFSRException for
FibLFSR.cpp to throw if something happened when making a FibLFSR object
(its main purpose is to check if the seed supplied is valid).
	The output operator << is also overloaded for FibLFSR objects so it
will display the contents of the register and the most recent bit added.

/**********************************************************************
 *  Explain the representation you used for the register bits 
 *  (how it works, and why you selected it)
 **********************************************************************/

	I used a vector to represent the register bits because you can easily
add to the back of it using the .push_back() function and you can erase the
first bit using the .erase() function. You can also easily get its size 
using the .size() or .length() functions.
	I used this over a dynamically allocated array because a vector "shifts"
automatically while an array would need to have its contents reassigned 
after every shift to match its new place in the register.
 
/**********************************************************************
 * Discuss what's being tested in your two additional Boost unit tests
  **********************************************************************/

	My first test tests if the seed given is 16 bits long. If not, then
an exception is thrown and a FibLFSRException object will be made with a
string member saying "Incorrect number of bits".
	My second test tests if the seed given contains any non-binary digits
(any number besides 0 and 1). If so, then an exception is thrown and a 
FibLFSRException object will be made with a string member saying 
"Non-binary digit detected".
	Since I used the BOOST_CHECK_THROW() function to check for these
possibilities and I passed in bad seeds for the tests, then it will only 
pass these tests if the exceptions are thrown.

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/

String functions: http://www.cplusplus.com/reference/string/string/ 
Vector functions: https://www.cplusplus.com/reference/vector/vector/ 
Left shift operator: https://www.geeksforgeeks.org/left-shift-right-shift-operators-c-cpp/ 
Overloading the Output Operator: https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/ 
BOOST_CHECK_THROW Documentation: https://www.boost.org/doc/libs/1_31_0/libs/test/doc/components/test_tools/reference/BOOST_CHECK_THROW.html 
Makefile Documentation: https://www.gnu.org/software/make/manual/make.html 

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

	It took me a long time to wrap my head around how to make a Makefile.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

	It would be nice to spend more time in class learning about Makefiles
and also how to use the Boost library.


