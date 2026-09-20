#define BOOST_TEST_MODULE test_sorting

#include "lib.h"

#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(test_sorting)

BOOST_AUTO_TEST_CASE(test_splitting)
{
    BOOST_CHECK(DidSplit());
}
BOOST_AUTO_TEST_CASE(test_simple_sorting)
{
    BOOST_CHECK(DidSort());
}
BOOST_AUTO_TEST_CASE(test_full_sorting)
{
    BOOST_CHECK(DidSort2());
}

BOOST_AUTO_TEST_SUITE_END()
