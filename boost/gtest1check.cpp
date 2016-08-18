
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
using namespace genie;

int main()
{
// Build things from class Interaction for testing
LwlynSmithQELCCPXSec * lwlyn = new LwlynSmithQELCCPXSec();
Interaction * inter = new Interaction();
//Interaction inter;
//delete inter;

//InitialState myinitstate;
//ProcessInfo myprocinfo;
//Kinematics mykmat;
//XclsTag myxtag;
//KPhaseSpace mykps;
KinePhaseSpace_t kps = kPSQ2fE;
// int A nd Z represent carbon
int A = 12;
int Z = 6; 
int probe_pdgc = 14;
int target_pdgc = pdg::IonPdgCode(A,Z);
//int target_pdgc = 42;

// int for GeV
double Ev = 3;
//Setting up TLorentzVector
TLorentzVector nu_p4(0., 0., Ev, Ev); //px, py, pz, E
ProcessInfo proc_info(kScQuasiElastic, kIntWeakCC);
inter->InitStatePtr()->SetPdgs(target_pdgc, probe_pdgc);
inter->InitStatePtr()->SetProbeP4(nu_p4);
std::cout << "idk yo" << inter->ProcInfo().IsQuasiElastic() << std::endl;
// Could use the below to create a buffer of exactness
//BOOST_CHECK(lwlyn->XSec(inter, kps) > 5.33E-11 && lwlyn->XSec(inter, kps) <= 5.34E-11);
std::cout << "The XSec is " << lwlyn->XSec(inter, kps) << std::endl;
delete inter;
delete lwlyn;
return 0;
}



