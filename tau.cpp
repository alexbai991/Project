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

// TAU IMPLEMENTATION

void tau::set_decay_type(const std::string& type) {decay_type = type;}
std::string tau::get_decay_type() const { return decay_type; }

void tau::show() const 
{
  std::cout<<"\nInitial state:"<<std::endl;
  if (particle_charge == -1) 
  {
    std::cout<<"\nParticle type: Tau"<<std::endl;
  } 
  else if (particle_charge == 1) 
  {
    std::cout<<"\nParticle type: Antitau"<<std::endl;
  }
  lepton::show();
  std::cout<<"\nDecay Products:"<<std::endl;

  if (decay_type == "Hadronic")
  {
    std::cout<<"Hadron particle."<<std::endl;
    for (const auto& product : decay_products) 
    {
      product->show();
    }
  }
  else if (decay_type == "Muon" || decay_type == "Electron")
  {
    for (const auto& product : decay_products) 
    {
      product->show();
    }
  }
}

void tau::decay() 
{
  // Clear any existing decay products
  decay_products.clear();

  if (decay_type == "Hadron") 
  {
    // Simulate the decay into a hadron and a tau neutrino
    decay_products.push_back(std::make_unique<neutrino>(5, 0, 0, 0, neutrino::tau_neutrino, false));
  } 
  if (decay_type == "Muon") 
  {
    // Tau decays into a muon, a tau neutrino, and a muon neutrino
    decay_products.push_back(std::make_unique<muon>(15, 0, 0, 0, -1,true)); 
    decay_products.push_back(std::make_unique<neutrino>(5, 0, 0, 0, neutrino::tau_neutrino, false));
    decay_products.push_back(std::make_unique<neutrino>(4, 0, 0, 0, neutrino::muon_neutrino, false));
  } 
  else if (decay_type == "Electron")
  {
    // Antitau decays into a antielecton, a tau neutrino, and a electron neutrino
    decay_products.push_back(std::make_unique<electron>(10, 1, 2, 3, 1)); 
    decay_products.push_back(std::make_unique<neutrino>(5, 0, 0, 0, neutrino::tau_antineutrino, false));
    decay_products.push_back(std::make_unique<neutrino>(4, 0, 0, 0, neutrino::electron_neutrino, false));
  }
  else 
  {
    std::cout<<"Unknown decay type."<<std::endl;
  }
}
