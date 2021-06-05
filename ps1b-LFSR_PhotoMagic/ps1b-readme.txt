/**********************************************************************
 *  Linear Feedback Shift Register (part B) ps1b-readme.txt template
 **********************************************************************/

Name: Ethan Yu

Hours to complete assignment: 8 hours
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

	This assignment takes a source image and encrypts it using the
given seed. This is done by taking 3 command-line arguments: the source 
image name, the output image name, and the seed to run the program. 

	The way the program works is the source image is take, the colors are 
inverted, then the seed is used along with the remaining color data to 
be XOR'ed and generate a new color. Do this for all the pixels in the
image and what comes out should be an image that looks like TV static.
After that, you can decrypt it by putting the output image as the new 
source image and running the program with the same seed and the resulting
image will be the original source image you gave.	

/**********************************************************************
 *  If you did any implementation for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/

	I added support for alphanumeric characters in the seed so not 
only 0 and 1 are accepted. Now it takes values from 0 - 9, A - Z, a - z
for the seed.
	
	The way I implemented it was if any of those valid characters are
present, then a 1 would be added to the seed in its place. (For example:
10A0Z0a0z09050f0 would become 1010101010101010).
	
	The seed must still be 16 characters long for it to work.

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/

Professor starter code (pixel.cpp)
	Command Line Arguments: https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/ 
	SFML Image Documentation: https://www.sfml-dev.org/documentation/2.5.1/		classsf_1_1Image.php#a85409951b05369813069ed64393391ce 
	SFML Color Documentation: https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Color.php#a6a5256ca24a4f9f0e0808f6fc23e01e1 
	How to convert a string into a const: https://www.codegrepper.com/code-examples/cpp/c%2B%2B+convert+string+to+const+char%2A 

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
	
	I was having trouble getting the example code to work and the terminal
would always say "undefined reference to sf::[some SFML class]" but eventually
I figured out the problem was I put the "-lsfml-graphics -lsfml-window" in the 
wrong place in my Makefile

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 
 
