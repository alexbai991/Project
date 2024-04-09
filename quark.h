// quark.h
// Student ID: 10629046
// Date: 25/03/2024
#ifndef QUARK_H
#define QUARK_H

#include <iostream>
#include <memory>
#include "four_momentum.h"

class quark 
{

protected:
  double rest_mass;
  int particle_charge;
  std::unique_ptr<four_momentum> momentum; 
  bool is_antiparticle;

public:
  quark(double mass, double E, double px, double py, double pz, int charge)
  : rest_mass(mass), particle_charge(charge),
    momentum(std::make_unique<four_momentum>(E, px, py, pz)) 
    {
    std::cout<<"quark constructor\n";
    }

  virtual ~quark() 
  {
    std::cout<<"Destroying quark\n";
  }

  void set_four_momentum(const four_momentum& m);
  four_momentum get_four_momentum() const;
  void is_anti();
  virtual void show() const; 
};

#endif // quark_H
