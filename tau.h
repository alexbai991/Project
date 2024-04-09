// tau.h
// Student ID: 10629046
// Date: 25/03/2024
#ifndef TAU_H
#define TAU_H
#include "lepton.h"
#include "neutrino.h"
#include <iostream>
#include <memory>
#include <vector>
#include <string>

class tau : public lepton 
{
private:
    std::string decay_type; // "Hadron", "Muon" or "Electron"
    std::vector<std::unique_ptr<lepton>> decay_products; // Smart pointers to decay products

public:
    tau(double E, double px, double py, double pz, int charge, const std::string& decay_type)
        : lepton(1776.86, E, px, py, pz, charge), decay_type(decay_type) 
    {
        std::cout << "Tau constructor\n";
    }

    virtual ~tau() 
    {
        std::cout << "Destroying tau\n";
    }

    void set_decay_type(const std::string& type); 
    std::string get_decay_type() const;
    void decay();
    virtual void show() const override; 
};

#endif // TAU_H
