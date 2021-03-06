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
BOOST_AUTO_TEST_SUITE(True or False)
	BOOST_AUTO_TEST_CASE(Mr.T)
        {
        	BOOST_CHECK(PityTheFool() = "True");
                BOOST_REQUIRE(MohawkGameStrong() = "True");
        }
}
