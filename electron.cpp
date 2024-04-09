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

// ELECTRON IMPLEMENTATION

// Set percentage of energy that each layer takes
const std::array<double, 4> electron::layer_percentages = {0.25, 0.4, 0.3, 0.05};

void electron::set_layer_energies() 
{
  double total_energy = get_four_momentum().get_E();

  // Calculate and set the energy for each calorimeter layer based on the total energy
  for (size_t i = 0; i < calorimeter_layers.size(); ++i) 
  {
    calorimeter_layers[i] = total_energy * layer_percentages[i];
  }
}

std::array<double, 4> electron::get_layer_energies() const 
{
  return calorimeter_layers;
}

void electron::show() const  
{   
  if (particle_charge == -1) 
  {
    std::cout<<"\nParticle type: Electron"<<std::endl;
  } 
  else if (particle_charge == 1) 
  {
    std::cout<<"\nParticle type: Antielectron"<<std::endl;
  }
  lepton::show();
}