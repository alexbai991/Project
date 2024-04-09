// PHYS 30762 Programming in C++
// Assignment 5
// Practicing inheritance, smart pointers and friendship 
// Student ID: 10629046
// Date: 25/03/2024
// Main file

// Compile with: 
// g++ -std=c++17 main.cpp four_momentum.cpp electron.cpp lepton.cpp muon.cpp neutrino.cpp tau.cpp -o a5
// Run with: 
// ./project

#include<iostream>
#include<string>
#include<vector>
#include <memory>
#include "four_momentum.h"
#include "lepton.h"
#include "neutrino.h"
#include "electron.h"
#include "muon.h"
#include "tau.h"

int main() 
{
  // Vector to hold all leptons
  std::vector<std::unique_ptr<lepton>> leptons;

  // Adding leptons to the vector
  leptons.push_back(std::make_unique<electron>(10, 1, 2, 3, -1));
  leptons.push_back(std::make_unique<electron>(20, 4, 5, 6, -1));
  leptons.push_back(std::make_unique<muon>(15, 5, 3, 2, -1, false));
  leptons.push_back(std::make_unique<muon>(16, 4, 3, 2, -1, false));
  leptons.push_back(std::make_unique<muon>(17, 3, 3, 2, -1, true));
  leptons.push_back(std::make_unique<muon>(18, 2, 3, 2, -1, true));
  
  // Adding antielectron and antimuon
  auto e3 = std::make_unique<electron>(20, 4, 5, 6, -1);
  e3->is_anti();
  leptons.push_back(std::move(e3));
  auto m5 = std::make_unique<muon>(20, 2, 3, 2, -1, false);
  m5->is_anti();
  leptons.push_back(std::move(m5));

  // Adding neutrinos
  leptons.push_back(std::make_unique<neutrino>(10.0, 1.0, 2.0, 3, neutrino::muon_neutrino));
  leptons.push_back(std::make_unique<neutrino>(20.0, 4.0, 5.0, 3, neutrino::electron_neutrino));

  // Adding two tau particles and decaying them
  auto t1 = std::make_unique<tau>(12, 4, 6, 7, -1, "Muon");
  t1->decay(); 
  leptons.push_back(std::move(t1));
  auto t2 = std::make_unique<tau>(14, 5, 6, 2, -1,"Electron");
  t2->is_anti();
  t2->decay(); 
  leptons.push_back(std::move(t2));

  // Loop through and call print each lepton
  for (const auto& lepton : leptons) 
  {
    lepton->show();
  }
  
  if (leptons.size() >= 2) 
  {
  lepton summed = sumLeptons(*leptons[0], *leptons[1]);
  double result = dotLeptons(*leptons[7],*leptons[8] );

  // Retrieve the four-momentum of the summed lepton for printing
  four_momentum sum_fm = summed.get_four_momentum();

  // Print the summed four-momentum
  std::cout<<"\nSummed four-momentum of first two electrons:"
           <<"\nE = "<<sum_fm.get_E()
           <<"\nPx = "<<sum_fm.get_Px()
           <<"\nPy = "<<sum_fm.get_Py()
           <<"\nPz = "<<sum_fm.get_Pz()<<std::endl;

  std::cout<<"\nDotted four-momentum of antielectron and antimuon:"<<result<<std::endl;
  }
  
  //Creare new electron
  auto new_electron = std::make_unique<electron>(25, 7, 8, 9, -1);
  std::cout<<"\nCreating a new electron...";
  new_electron->show();

  // Moving the new electron to another electron in the original vector
  if (!leptons.empty()) 
  {
    leptons[0] = std::move(new_electron);
    std::cout<<"Moved the new electron to the first position in the leptons vector.\n";
  }

  // Create a shared_ptr for a tau lepton
  std::shared_ptr<tau> tauPtr = std::make_shared<tau>(30, 1, 2, 3, -1, "electron");
  std::cout<<"Created a shared_ptr for a tau lepton.\n";
  tauPtr->show(); 

  // Create multiple variables that own the tau lepton
  std::shared_ptr<tau> tauPtr2 = tauPtr; 
  std::shared_ptr<tau> tauPtr3 = tauPtr; 
  
  // Demonstrate that the tau lepton is shared
  std::cout<<"The tau lepton is now owned by 3 variables.\n";
  std::cout<<"Use count: "<<tauPtr.use_count()<<std::endl; 

  return 0;
}
