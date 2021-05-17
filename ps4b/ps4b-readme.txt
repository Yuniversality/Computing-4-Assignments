/**********************************************************************
 *                                                  
 *  PS3b: StringSound implementation and SFML audio output 
 **********************************************************************/

Name: Ethan Yu

Hours to complete assignment: 10 hours

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/

	I could not get my main function to play 37 different sounds.
	The problem was I could never get sound to play from my main function.
	My StringSound functions work because the example code works with
	it but when I try to set the sound buffer to different notes, then it 
	stops working.
	
	Also the switch statement is kinda weird with SFML because if I
	wanted to retreive the user input and set it to a variable, it
	would freak out and ignore the default case and make me implement
	all the other cases.
	That is why I gave up and just used a 37 case switch statement 
	with the starter code.
	

/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  
 **********************************************************************/

	No I did not try the extra credit.

/**********************************************************************
 *  Did you implement exceptions to check your StringSound 
 *	implementation?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/

	Yes, I put exceptions in my StringSound double value constructor
	so it would throw a runtime error if a 0 or negative frequency is
	given (because you can't have 0 or negative frequency right)
	
	I also put a runtime error in my peek() function that would be
	thrown if it was peeking into an empty container (because you
	can't peek at nothing)

/**********************************************************************
 *  Did you implement lambda expression?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/

	Yes I made a lambda expression to generate my random numbers in
	my pluck() function
	
     auto generateRandomNums = [=] () {
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<int16_t> dist(-32768, 32767);
    
      while (!(*_cb).isFull()) {
        (*_cb).enqueue(dist(gen));
      }
    };

/**********************************************************************
 *  Did your code pass cpplint?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/

	Yes, I ran it with cpplint.py

/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/

Assignment Instructions Explained Differently: https://www.cs.princeton.edu/courses/archive/spr17/cos126/assignments/guitar.html 
What to use instead of rand(): https://youtu.be/0Ez-KqDTVXg 
How can I initialize C++ object member variables in the constructor?: https://stackoverflow.com/questions/12927169/how-can-i-initialize-c-object-member-variables-in-the-constructor 
ceil(): http://www.cplusplus.com/reference/cmath/ceil/ 


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

	Using sf::Events with a stitch statement is wack.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 
 
 
