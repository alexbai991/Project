#ifndef FOUR_MOMENTUM_H
#define FOUR_MOMENTUM_H

#include <vector>
#include <iostream>

class four_momentum 
{
private:
  double E;
  double px;
  double py;
  double pz;

public:
  // Default constructor
  four_momentum() = default;
  
  // Constructor with direct initialization
  four_momentum(double E_in, double px_in, double py_in, double pz_in)
  : E{E_in > 0 ? E_in : throw std::invalid_argument("Energy must be greater than 0.")}, 
    px{px_in}, py{py_in}, pz{pz_in} 
    {}

  // Destructor
  ~four_momentum() 
  {
    std::cout<<"Destroying four_momentum"<<std::endl;
  }

  // Copy Constructor
  four_momentum(const four_momentum& other); 
  // Move constructor
  four_momentum(four_momentum&& other) noexcept; 
  // Copy assignment operator
  four_momentum& operator=(const four_momentum& other);
  // Move assignment operator
  four_momentum& operator=(four_momentum&& other) noexcept;

  // Setters
  void set_E(double val);
  void set_Px(double val); 
  void set_Py(double val);
  void set_Pz(double val); 

 // Getters
  double get_E() const;
  double get_Px() const;
  double get_Py() const;
  double get_Pz() const;
};

#endif // FOUR_MOMENTUM_H
