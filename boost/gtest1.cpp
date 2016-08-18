
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
	int recoil_nuc;
	bool isP;
	int target_pdgc = pdg::IonPdgCode(A,Z);
	//int target_pdgc = 42;

	// int for GeV
	double Ev = 3;
	//Setting up TLorentzVector
	TLorentzVector nu_p4(0., 0., Ev, Ev); //px, py, pz, E
	ProcessInfo proc_info(kScQuasiElastic, kIntWeakCC);
	BOOST_AUTO_TEST_CASE(bools)
	{
		inter->InitStatePtr()->SetPdgs(target_pdgc, probe_pdgc);
		inter->InitStatePtr()->SetProbeP4(nu_p4);
		std::cout<< "hmmm " << kISkipProcessChk  << std::endl;
		std::cout<<"testing recoil nucleon"<<recoil_nuc<<std::endl;
		std::cout<<"testing proton "<<isP<<"target_pdgc = " << target_pdgc<<std::endl;
		cout<<kScQuasiElastic<<endl;
		cout<<"TESTING BOOLS"<<endl;
		BOOST_CHECK(probe_pdgc == 14);
		cout<<"MOVING ON"<<endl;
		BOOST_CHECK(proc_info.IsQuasiElastic() == 1);
		cout<<"MOVING ON"<<endl;
		BOOST_CHECK(proc_info.IsDeepInelastic() == 0);
		cout<<"MOVING ON"<<endl;
		BOOST_CHECK(proc_info.IsResonant() == 0);
		cout<<"MOVING ON"<<endl;
		BOOST_CHECK(proc_info.IsCoherent() == 0);
		cout<<"MOVING ON"<<endl;
		BOOST_CHECK(proc_info.IsCoherentElas() == 0);
		cout<<"MOVING ON"<<endl;
		BOOST_CHECK(proc_info.IsSingleKaon() == 0);
		cout<<"MOVING ON"<<endl;
		BOOST_CHECK(proc_info.IsElectronScattering() == 0);
		cout<<"MOVING ON"<<endl;
		BOOST_CHECK(proc_info.IsNuElectronElastic() == 0);
		cout<<"MOVING ON"<<endl;
		BOOST_CHECK(proc_info.IsInverseMuDecay() == 0);
		cout<<"MOVING ON"<<endl;
		BOOST_CHECK(proc_info.IsIMDAnnihilation () == 0);
		cout<<"MOVING ON"<<endl;
		BOOST_CHECK(proc_info.IsInverseBetaDecay() == 0);
		cout<<"MOVING ON"<<endl;
		BOOST_CHECK(proc_info.IsGlashowResonance() == 0);
		cout<<"MOVING ON"<<endl;
		BOOST_CHECK(proc_info.IsAMNuGamma() == 0);
		cout<<"MOVING ON"<<endl;
		BOOST_CHECK(proc_info.IsMEC() == 0);
		cout<<"MOVING ON"<<endl;
		BOOST_CHECK(proc_info.IsDiffractive() == 0);
		cout<<"MOVING ON"<<endl;
		BOOST_CHECK(proc_info.IsEM() == 0);
		cout<<"MOVING ON"<<endl;
		BOOST_CHECK(proc_info.IsWeak() == 0);
		cout<<"MOVING ON"<<endl;
		BOOST_CHECK(proc_info.IsWeakCC() == 0);
		cout<<"MOVING ON"<<endl;
		BOOST_CHECK(proc_info.IsWeakNC() == 0);
		cout<<"MOVING ON"<<endl;
		BOOST_CHECK(proc_info.IsWeakMix () == 0);
		cout<<"CLEAR"<<endl;
	}
	BOOST_AUTO_TEST_CASE(doubles)
	{
		std::cout<<"TESTING target_pdgc"<<std::endl;
		BOOST_CHECK(target_pdgc == 1000060120);
		BOOST_CHECK(proc_info.InteractionTypeId() == 2);
		BOOST_CHECK(proc_info.ScatteringTypeId() == 1);
		cout<<"CLEAR"<<endl;
	}

BOOST_AUTO_TEST_SUITE_END()
}


