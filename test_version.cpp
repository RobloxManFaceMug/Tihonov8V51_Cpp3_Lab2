#define BOOST_TEST_MODULE test_sorting

#include "lib.h"

#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(test_sorting)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
    BOOST_CHECK(DidSplit());
    BOOST_CHECK(DidSort());
    BOOST_CHECK(DidSort2());
}


BOOST_AUTO_TEST_SUITE_END()
