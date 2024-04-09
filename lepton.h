// lepton.h
// Student ID: 10629046
// Date: 25/03/2024
#ifndef LEPTON_H
#define LEPTON_H

#include <iostream>
#include <memory>
#include "four_momentum.h"

class lepton 
{
  friend lepton sumLeptons(const lepton& l1, const lepton& l2);
  friend double dotLeptons(const lepton& l1, const lepton& l2);

protected:
  double rest_mass;
  int particle_charge;
  std::unique_ptr<four_momentum> momentum; 
  bool is_antiparticle;

public:
  lepton(double mass, double E, double px, double py, double pz, int charge)
  : rest_mass(mass), particle_charge(charge),
    momentum(std::make_unique<four_momentum>(E, px, py, pz)) 
    {
    std::cout<<"Lepton constructor\n";
    }

  virtual ~lepton() 
  {
    std::cout<<"Destroying lepton\n";
  }

  void set_four_momentum(const four_momentum& m);
  four_momentum get_four_momentum() const;
  void is_anti();
  virtual void show() const; 
};

#endif // LEPTON_H
