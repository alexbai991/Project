// electron.h
// Student ID: 10629046
// Date: 25/03/2024
#ifndef ELECTRON_H
#define ELECTRON_H
#include "lepton.h"
#include <array>
#include <numeric> 
#include <algorithm> 

class electron : public lepton 
{
private:
  std::array<double, 4> calorimeter_layers{}; // Energy deposits in EM_1, EM_2, HAD_1, HAD_2
  static const std::array<double, 4> layer_percentages;
public:
  electron(double E, double px, double py, double pz, int charge)
    : lepton(0.511, E, px, py, pz, charge) 
    {
      std::cout<<"Constructing electron\n";
    }

  virtual ~electron() 
  {
    std::cout<<"Destroying electron\n";
  }

  void set_layer_energies(); 
  std::array<double, 4> get_layer_energies() const; 

  virtual void show() const override; 

};

#endif // ELECTRON_H
