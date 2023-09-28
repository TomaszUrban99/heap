#ifndef TEST_NO_ONE_HH
#define TEST_NO_ONE_HH

#define BOOST_TEST_MODULE test_module_one
#include "../inc/titleRating.hh"
#include "../inc/priorityQueue.hh"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_no_one) {
    
    priorityQueue<titleRating, int> newQueue;
    
    BOOST_TEST(newQueue.getRecordsNumber() != 1);
    BOOST_TEST(newQueue.getRecordsNumber() == 0);
}


    
#endif