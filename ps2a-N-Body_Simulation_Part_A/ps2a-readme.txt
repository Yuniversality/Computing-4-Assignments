/**********************************************************************
 *  N-Body Simulation ps2a-readme.txt template
 **********************************************************************/

Name: Ethan Yu
Hours to complete assignment: 10 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
	
	The assignment was to create a universe simulation that would show
celestial bodies and scale their distances to fit the screen. The celestial
bodies are just sprites and do not move for now. 

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/

	In the Universe class, a vector of smart pointers to 
CelestialBodies was used to hold all the planets and such.  
	Upon instantiation, the Universe object would read input to fill 
its member variables (numPlanets and universeRadius) and then uses an
overloaded insertion operator >> to fill in create CelestialBody objects
to push back into the vector.

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how you used smart pointers 
 *  Include code excerpts.
 **********************************************************************/
	
	The Universe's bodyVector is a vector of CelestialBody smart pointers.
	
	Inside the Universe default constructor is this:
		std::shared_ptr<CelestialBody> celestialBodyPtr(new CelestialBody);
		bodyVector.push_back(celestialBodyPtr);
		std::cin >> *bodyVector.back();
	
	For every CelestialBody in Universe, a smart pointer is created 
for it, it is pushed to the back of the vector, then input is read to create
the CelestialBody for the pointer just added using an overloaded insertion
operator.

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
Lectures and notes,
Reading scientific notation from file: https://stackoverflow.com/questions/30713157/c-wont-read-in-scientific-notation-data-from-a-txt-file 
sf::Drawable class Documentation: https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Drawable.php 
Vector functions: https://www.cplusplus.com/reference/vector/vector/ 
Smart Pointers: https://www.geeksforgeeks.org/smart-pointers-cpp/ 

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

	The instructions were slightly unclear and it was confusing to 
figure out which class a member variable should go or what class was 
doing what. 
	Also, it took a long time to figure out a way to get the planet's
positions right because the positions given were large scientific numbers
and there was no way they would fit on the screen normally.
	Also, I just need more smart pointer practice because they're still
a bit confusing to me.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 
 	A background image and smart pointers were used.
 
