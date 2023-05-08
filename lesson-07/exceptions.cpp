#include <iostream>
#include <stdexcept>
#include <iostream>
#include <cmath>

class Logarithm {
 
 private:
  double base_;
  double argument_;
  
 public:
  Logarithm(double base, double argument) 
  {
    base_ = base;
    argument_ = argument;
  }

  double Calculate() const 
  {
      
     if(base_<=0 || base_==1)
     {
         throw std::invalid_argument("wrong value for base");
     }
     if(argument_<=0)
     {
         throw std::invalid_argument("wrong value for argument");
     }
    return std::log(argument_) / std::log(base_);
  }

};



int main() {
    
 try {
    class Logarithm leg(2.0,-4.0);
    std::cout << "You entered: " << leg.Calculate() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  
  return 0;
}



