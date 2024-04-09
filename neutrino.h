// neutrino.h
// Student ID: 10629046
// Date: 25/03/2024
#ifndef NEUTRINO_H
#define NEUTRINO_H
#include "lepton.h"
#include <iostream>
#include <string>

class neutrino : public lepton 
{
public:
  enum neutrino_flavour 
  {
    electron_neutrino = 0,
    muon_neutrino = 1,
    tau_neutrino = 2,
    electron_antineutrino = 3,
    muon_antineutrino = 4,
    tau_antineutrino = 5
  };
private:
  neutrino_flavour flavour;
  bool is_antineutrino;  
  bool has_interacted; 
  static const std::array<std::string, 6> flavour_names;

public:
  neutrino(double E, double px, double py, double pz, neutrino_flavour flavour, bool has_interacted = false)
    : lepton(0.0, E, px, py, pz, flavour >= electron_antineutrino), 
      flavour(flavour), has_interacted(has_interacted) 
  {
    std::cout<<"Neutrino constructor\n";
  }

  virtual ~neutrino() 
  {
    std::cout<<"Destroying neutrino\n";
  }

  // Setter and Getter for flavour
  void set_flavour(neutrino_flavour f);
  neutrino_flavour get_flavour() const;

  // Setter and Getter for is_antineutrino
  void set_is_antineutrino(bool is); 
  bool get_is_antineutrino() const;

  // Setter and Getter for has_interacted
  void set_has_interacted(bool has_interacted); 
  bool get_has_interacted() const;
  virtual void show() const override; 
};

#endif // NEUTRINO_H
