// PHYS 30762 Programming in C++
// Project
// Student ID: 10629046
// Date: 09/04/2024

#include "four_momentum.h"
#include "lepton.h"
#include "neutrino.h"
#include "electron.h"
#include "muon.h"
#include "tau.h"

// LEPTON IMPLEMENTATION

void lepton::show() const 
{
  std::cout<<"Rest Mass (MeV): "<<rest_mass
           <<"\nCharge: "<<particle_charge
           <<"\nFour-momentum: ("<<momentum->get_E()<<", "
           <<momentum->get_Px()<<", "
           <<momentum->get_Py()<<", "
           <<momentum->get_Pz()<<")\n"<<std::endl;
}

void lepton::is_anti() 
{
  particle_charge *= -1; // Flip the charge
}

// Set and get the four_momentum of the lepton
void lepton::set_four_momentum(const four_momentum& m) 
{
  momentum = std::make_unique<four_momentum>(m.get_E(), m.get_Px(), m.get_Py(), m.get_Pz());
}

four_momentum lepton::get_four_momentum() const {return *momentum;}


lepton sumLeptons(const lepton& l1, const lepton& l2) 
{
  // Retrieve four-momenta using the accessor methods
  four_momentum fm1 = l1.get_four_momentum();
  four_momentum fm2 = l2.get_four_momentum();

  // Sum the components of the four-momenta
  double E_sum = fm1.get_E() + fm2.get_E();
  double px_sum = fm1.get_Px() + fm2.get_Px();
  double py_sum = fm1.get_Py() + fm2.get_Py();
  double pz_sum = fm1.get_Pz() + fm2.get_Pz();

  double resultMass = 100; 
  int charge = 1; 

  return lepton(resultMass, E_sum, px_sum, py_sum, pz_sum, charge);
}

double dotLeptons(const lepton& l1, const lepton& l2) 
{
  // Retrieve four-momenta using accessor methods
  four_momentum fm1 = l1.get_four_momentum();
  four_momentum fm2 = l2.get_four_momentum();

  // Calculate the dot product based on the components of the four-momentum
  double E_product = fm1.get_E() * fm2.get_E();
  double px_product = fm1.get_Px() * fm2.get_Px();
  double py_product = fm1.get_Py() * fm2.get_Py();
  double pz_product = fm1.get_Pz() * fm2.get_Pz();

  // Subtract the spatial component dot product from the energy product
  double result = E_product - (px_product + py_product + pz_product);

  return result;
}
