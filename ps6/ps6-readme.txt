/**********************************************************************
 *  readme.txt template                                                   
 *  PS6 Kronos 
 **********************************************************************/

Name: Ethan Yu

Hours to complete assignment: 5 hours

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/

	Yes, the assignment is done. I know gives expected output and it does
	not throw any errors.

/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
Regex for finding startup message:
boost::regex startExpr{"^([\\d]{4})\\-([\\d]{2})\\-([\\d]{2})\\s([\\d]{2}):([\\d]{2}):([\\d]{2}):\\s(\\(log\\.c\\.166\\) server started)\\s$"};

	With this, I looked for 3 numbers (the date) split by dashes (-) and then 
	3 numbers (the time) split by 3 colons (:) and then I searched for the 
	string "(log.c.166) server started ".
	I could have probably optimized it so the month, day, hour, minute, and 
	second be bundled into ([\\d]{2}){5} or something similar, but I 
	could not figure it out in time.

Regex for finding end of startup message:
boost::regex endExpr{"^([\\d]{4})\\-([\\d]{2})\\-([\\d]{2})\\s([\\d]{2}):([\\d]{2}):([\\d]{2})\\.([\\d]{3}):INFO:oejs.AbstractConnector:Started SelectChannelConnector@0\\.0\\.0\\.0:9080$"};

	With this, I looked for 3 numbers (the date) split by dashed (-) and then 
	3 numbers (the time) split by colons (:) and then I searched for the 
	string "INFO:oejs.AbstractConnector:Started SelectChannelConnector
	@0\\.0\\.0\\.0:9080"
	I don't know how to optimize this besides optimizing the capture of the 
	2 digit numbers.

/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/

	The way I solved this problem was to use the regular expressions to 
	advance the code. What I mean by this is I would read through the 
	input file line-by-line and compare it to either the startup or 
	finishing regex and if there was a match, then the program would 
	advance and check to see if a startup was already happening and/or
	start a new startup. If it matched with the ending regex, then 
	it would start calculating the startup time. If none the line did 
	not match with a regex, then it was ignored and the search would
	continue.

/**********************************************************************
 *  Did you use lambda expression? If yes describe there.
 **********************************************************************/

	Yes, I made a lambda function to find how long it took to startup.
	It takes the start and end times and subtracts then to get the 
	startup time and then it prints out each part of the time.
	
	auto findElapsedTime = [](ptime startTime, ptime endTime) {
        time_duration elapsedTime = endTime - startTime;
        std::cout << "Elapsed Time: " << elapsedTime.hours() <<
          ":" << elapsedTime.minutes() << ":" <<
          elapsedTime.seconds() << "\n\n";
    };

/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/
Starter code from Prof. Rykalova and Prof. Martin
Boost.Regex: https://theboostcpplibraries.com/boost.regex 
https://stackoverflow.com/questions/40303500/c-how-to-read-a-line-with-delimiter-until-the-end-of-each-line 
Opening and closing a file: https://www.cplusplus.com/reference/fstream/fstream/open/
Copying from one file to another: https://pencilprogrammer.com/cpp-programs/copy-one-file-to-another/ 
Std::smatch: https://www.geeksforgeeks.org/smatch-regex-regular-expressions-in-c/ 
How to get a capture group: https://stackoverflow.com/questions/42983337/how-to-get-only-given-captured-group-regex-c 
Unknown escape sequence warnings: https://stackoverflow.com/questions/38717526/c-regex-unknown-escape-sequence-warning 
Stoi() function: https://www.cplusplus.com/reference/string/stoi/ 
Gregorian documentation: https://www.boost.org/doc/libs/1_76_0/doc/html/date_time/examples.html#date_time.examples.dates_as_strings
Posix documentation: https://www.boost.org/doc/libs/1_76_0/doc/html/date_time/posix_time.html 

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

