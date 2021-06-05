/**********************************************************************
 *  ps5-readme 
 *  Recursive Graphics (Triangle Fractal)                       
 **********************************************************************/

Your name: Ethan Yu

Hours to complete assignment: 6 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

    This program makes the Sierpinski Triangle using recursion.
    You type in the initial length of the triangle sides and the 
    number of iterations you want to go through and these are passed to 
    the recursive function along with other values. 

 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/

    To store the triangles, a vector was used and every recursive call 
    pushes 1 triangle into it.
    To create and draw the triangles, we added lines to a sf::VertexArray 
    and passed a collection of those lines to the draw() function to 
    display the triangle.
    The sf::VertexArray is a member variable of each Triangle object so 
    each triangle stores its own lines.
    
/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/

    The recursive function starts by drawing a triangle and then if 
    another iteration is needed, then the recursive function is called 
    3 times (1 for each child triangle) with values derived from this 
    parent triangle.
    The original/base triangle is always set to have its center in the 
    middle of the window.

 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/

    I learned how to draw and color shapes in SFML.
    I also learned the power of recursion in generating objects.

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/

Get screen size in SFML: https://en.sfml-dev.org/forums/index.php?topic=18306.0 
VertexArray documentation: https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1VertexArray.php#a15729e01df8fc0021f9774dfb56295c1 
VertexArray tutorial: https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php 
Passing a vector by reference: https://www.geeksforgeeks.org/passing-vector-function-cpp/ 

/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/

    I forgot the difference between integer and double division so I 
    was wondering for an hour why (2/3) * height [height being a double] 
    was returning 0.
    
/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 
    Color was added to the triangles' outlines.
 
    The math for determining where the triangle centers would be 
    was hard. I need to brush up on my geometry.
