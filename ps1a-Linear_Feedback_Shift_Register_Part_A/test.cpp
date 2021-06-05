#include <iostream>
#include <string>

#include "FibLFSR.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

	FibLFSR l("1011011000110110");
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 1);
	BOOST_REQUIRE(l.step() == 1);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 0);
	BOOST_REQUIRE(l.step() == 1);

	FibLFSR l2("1011011000110110");
	BOOST_REQUIRE(l2.generate(9) == 51);

}

//Tests to see if the program will throw an exception when the seed given isn't
//16 bits long
//If FibLFSR.cpp works correctly, then an exception will be thrown
BOOST_AUTO_TEST_CASE(fifteenBits)
{
	BOOST_CHECK_THROW(FibLFSR incorrectNumOfBits("1010101010"), FibLFSRException);

}

//Tests to see if the program will throw an exception if the seed contains bits
//that are not 0 or 1
//If FibLFSR.cpp works correctly, then an exception will be thrown
BOOST_AUTO_TEST_CASE(sixteenBitsWithNonbinaryDigits) 
{
	BOOST_CHECK_THROW(FibLFSR invalidBits("1234567890123456"), FibLFSRException);

}


