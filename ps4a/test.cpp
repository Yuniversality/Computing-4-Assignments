// Copyright 2021 Ethan Yu

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
#include "CircularBuffer.h"

BOOST_AUTO_TEST_CASE(testFunctionsWork) {
    // std::cout << "Testing good function output\n";
    CircularBuffer testObj(3);
    // std::cout << "Size of deque is " << testObj.size() << std::endl;
    testObj.enqueue(1);
    // std::cout << "Size of deque is " << testObj.size() << std::endl;
    testObj.enqueue(2);
    testObj.enqueue(3);

    BOOST_REQUIRE(testObj.size() == 3);
    BOOST_REQUIRE(testObj.isEmpty() == false);
    BOOST_REQUIRE(testObj.isFull() == true);
    BOOST_REQUIRE(testObj.dequeue() == 1);
    BOOST_REQUIRE(testObj.peek() == 2);
}

BOOST_AUTO_TEST_CASE(testExceptionsThrow) {
    // std::cout << "Testing exception throws\n";
    BOOST_CHECK_THROW(CircularBuffer testObj(0), std::invalid_argument);
    BOOST_CHECK_THROW(CircularBuffer testObj(-1), std::invalid_argument);

    CircularBuffer testObj(1);
    BOOST_CHECK_THROW(testObj.dequeue(), std::runtime_error);
    BOOST_CHECK_THROW(testObj.peek(), std::runtime_error);

    testObj.enqueue(1);
    BOOST_CHECK_THROW(testObj.enqueue(2), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(testExceptionsDontThrow) {
    // std::cout << "Testing exceptions aren't thrown\n";
    BOOST_CHECK_NO_THROW(CircularBuffer testObj(1));

    CircularBuffer testObj(1);
    BOOST_CHECK_NO_THROW(testObj.enqueue(1));
    BOOST_CHECK_NO_THROW(testObj.peek());
    BOOST_CHECK_NO_THROW(testObj.dequeue());
}


