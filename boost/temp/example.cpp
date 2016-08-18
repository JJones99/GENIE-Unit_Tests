#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Genie
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <iterator>
#include "LlewellynSmith/LwlynSmithQELCCPXSec.h"
#include "Interaction/Interaction.h"
#include "Interaction/KPhaseSpace.h"
#include "Interaction/XclsTag.h"
#include "Interaction/Kinematics.h"
#include "PDG/PDGUtils.h"


using namespace std;
namespace genie{


BOOST_AUTO_TEST_SUITE(Physics)
BOOST_AUTOO_TEST_CASE(Acceleration)
{
	// Here we would test acceleration based funcions.
}
BOOST_AUTO_TEST_SUITE(Force)
{
	// here we  would test functions having to do with force.
}
BOOST_AUTO_TEST_SUITE_END

