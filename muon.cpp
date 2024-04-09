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

// MUON IMPLEMENTATION

// Setter for is_isolated
void muon::set_is_isolated(bool isolated) 
{
  is_isolated = isolated;
}

// Getter for is_isolated
bool muon::get_is_isolated() const 
{
  return is_isolated;
}

void muon::show() const  
{
  if (particle_charge == -1) 
  {
    std::cout<<"\nParticle type: Muon"<<std::endl;
  } 
  else if (particle_charge == 1) 
  {
    std::cout<<"\nParticle type: Antimuon"<<std::endl;
  }
  std::cout<<"Isolation status: "<<(is_isolated ? "Isolated" : "Not Isolated")<<std::endl;
  lepton::show();
}
