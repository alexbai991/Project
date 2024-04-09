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

// FOUR MOMENTUM IMPLEMENTATION

  void four_momentum::set_E(double val) 
  {
  if (val <= 0) {
    throw std::invalid_argument("Energy must be greater than 0.");
  }
  E = val;
  }

  void four_momentum::set_Px(double val) { px = val; }
  void four_momentum::set_Py(double val) { py = val; }
  void four_momentum::set_Pz(double val) { pz = val; }

  // Getters
  double four_momentum::get_E() const { return E; }
  double four_momentum::get_Px() const { return px; }
  double four_momentum::get_Py() const { return py; }
  double four_momentum::get_Pz() const { return pz; }

four_momentum::four_momentum(const four_momentum& other)
: E{other.E}, px{other.px}, py{other.py}, pz{other.pz} 
{
  std::cout<<"Copying four_momentum\n";
}

  // Move constructor
four_momentum::four_momentum(four_momentum&& other) noexcept
  : E{other.E}, px{other.px}, py{other.py}, pz{other.pz} 
  {
    std::cout<<"Moving four_momentum\n";
    other.E = 0;
    other.px = 0;
    other.py = 0;
    other.pz = 0;
  }
  
// Copy assignment operator
four_momentum& four_momentum::operator=(const four_momentum& other) 
{
  if (this != &other)
   { 
    E = other.E;
    px = other.px;
    py = other.py;
    pz = other.pz;
    std::cout<<"Copy assigning four_momentum\n";
  }
  return *this;
}

// Move assignment operator
four_momentum& four_momentum::operator=(four_momentum&& other) noexcept 
{
  if (this != &other) 
  {
    E = other.E;
    px = other.px;
    py = other.py;
    pz = other.pz;
    std::cout<<"Move assigning four_momentum\n";
    other.E = 0;
    other.px = 0;
    other.py = 0;
    other.pz = 0;
  }
  return *this;
}
