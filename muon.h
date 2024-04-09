// muon.h
// Student ID: 10629046
// Date: 25/03/2024
#ifndef MUON_H
#define MUON_H
#include "lepton.h"
#include <iostream>

class muon : public lepton 
{
private:
  bool is_isolated; 
public:
  muon(double E, double px, double py, double pz, int charge, bool isolated = true)
    : lepton(105.7, E, px, py, pz, charge), is_isolated(isolated) 
  {
    std::cout<<"Constructing muon\n";
  }

  virtual ~muon() 
  {
    std::cout<<"Destroying muon\n";
  }

  // Setters and Getters for is_isolated
  void set_is_isolated(bool isolated); 
  bool get_is_isolated() const; 

  virtual void show() const override; 
};

#endif // MUON_H
