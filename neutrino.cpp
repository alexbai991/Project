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

// NEUTRINO IMPLEMENTATION

void neutrino::set_flavour(neutrino_flavour f) { flavour = f; }
neutrino::neutrino_flavour neutrino::get_flavour() const { return flavour; }

const std::array<std::string, 6> neutrino::flavour_names = 
{
  "Electron Neutrino", "Muon Neutrino", "Tau Neutrino",
  "Electron Antineutrino", "Muon Antineutrino", "Tau Antineutrino"
};

void neutrino::show() const {
  std::cout<<"\nParticle type: "<<flavour_names.at(flavour)<<std::endl;
  std::cout<<"Did it interact?: "<<(has_interacted ? "Yes" : "No")<<std::endl;
  lepton::show(); 
}

// Setter and Getter for is_antineutrino
void neutrino::set_is_antineutrino(bool is) { is_antineutrino = is; }
bool neutrino::get_is_antineutrino() const { return is_antineutrino; }

// Setter and Getter for has_interacted
void neutrino::set_has_interacted(bool has_interacted) { this->has_interacted = has_interacted; }
bool neutrino::get_has_interacted() const { return has_interacted; }
