#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hello
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <iterator>
#include "fun.h"

using namespace std;
// int divide(int x, int y);
int add( int i, int j)
{
	return i + j;
}
string word(string x)
{
	 return x;
}
BOOST_AUTO_TEST_SUITE(Math)
numbers numbrs;
BOOST_AUTO_TEST_CASE(Addition)
{
	// numbers *numbrs = new numbers();
	BOOST_CHECK(add(1, 1) < 3);
	BOOST_REQUIRE(add(4, 3) > 6 && add(4,3) < 4);
	BOOST_CHECK(add(3, 2) == 5);
	BOOST_CHECK(numbrs.divide(3,2) == 3); 
}
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE(Words)
BOOST_AUTO_TEST_CASE(thesaurus)
{
	BOOST_CHECK(word("delta") == "delta");
}
BOOST_AUTO_TEST_SUITE_END()
