/**********************************************************************
 *  readme.txt template                                                   
 *  Synthesizing a Plucked String Sound:
 *  CircularBuffer implementation with unit tests and exceptions 
 **********************************************************************/

Name: Ethan Yu

Hours to complete assignment: 4 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

	I created the groundwork for making a program that simulates
string sound. Currently the program implements a deque as the container
used to store the values. 

/**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/

	For the CircularBuffer, I used a deque as the container because 
you can easily do all the functions needed using a deque.

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/

	Most of the functions that needed to be implemented are member 
functions of the deque class. Like we were asked to implement size(),
empty(), enqueue(), dequeue(), and peek() functions, but deques come
with the size(), push_back(), pop_front(), and front() functions 
respectively which do what we want already.
	Most of the code is calling a deque member function with an 
if-statement to see if an exception should be thrown.

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/

	The whole assignment should be working. I know because the test.cpp
file has tests for all the functions requiring a throw or no throw and 
makes sure expected output is given for functions using BOOST_REQUIRE.

/**********************************************************************
 *  Does your CircularBuffer implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/

	Yes because they pass the unit tests in the test.cpp file.

/**********************************************************************
 *  Explain the time and space performance of your CircularBuffer
 *	implementation
 **********************************************************************/

	The time is .006 seconds and memory used is 245.9 kb.
The time should be low because I used the compiler flag -O1 when compiling
and all the functions implemented should only take constant time.


/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/

Choosing deque vs list: https://stackoverflow.com/questions/1436020/whats-the-difference-between-deque-and-list-stl-containers 
Deque functions: https://www.cplusplus.com/reference/deque/deque/ 
std::exception class: http://www.cplusplus.com/reference/exception/exception/ 

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 
 Here's the lambda function I used in my value constructor:
 
 auto checkBadInput = [=]() {
		if (capacity > 0) {
			max_container_size = capacity;
		}
		else {
			throw std::invalid_argument("CircularBuffer constructor: capacity must be greater than zero.");
		}
 	};
 	
 	
