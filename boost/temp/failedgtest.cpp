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


BOOST_AUTO_TEST_SUITE(Lwlyn)
// Build things from class Interaction for testing
LwlynSmithQELCCPXSec * lwlyn = new LwlynSmithQELCCPXSec();
Interaction * inter = new Interaction();
KinePhaseSpace_t kps = kPSQ2fE;
// int A nd Z represent carbon
int A = 12;
int Z = 6; 
int probe_pdgc = 14;
int target_pdgc = pdg::IonPdgCode(A,Z);
// int for GeV
double Ev = 3;
//Setting up TLorentzVector
TLorentzVector nu_p4(0., 0., Ev, Ev); //px, py, pz, E
ProcessInfo proc_info(kScQuasiElastic, kIntWeakCC);
BOOST_AUTO_TEST_CASE(doubles)
{
inter->InitStatePtr()->SetPdgs(target_pdgc, probe_pdgc);
inter->InitStatePtr()->SetProbeP4(nu_p4);
std::cout << "The XSec is " << lwlyn->XSec(inter, kps) << std::endl;
BOOST_CHECK(lwlyn->XSec(inter, kps) == 5.3365984441833672E-11);


}
BOOST_AUTO_TEST_SUITE_END()
}
