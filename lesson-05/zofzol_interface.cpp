#include<iostream>

class menu 
{
    public:
    virtual int Volume()=0;
    virtual std::string Flavour()=0;
    
};    
   
   
    
    
    


class Drink: public menu
{
    private:
    int volume;
    std::string flavour;
    
    public:
    Drink(int volume, std::string flavour)
    {
        this->volume=volume;
        this->flavour=flavour;
    }
    
     int Volume()
    {
      return this->volume;   
         
    }
    
    std::string Flavour()
    {
        return this->flavour;
    }
    
};


int main()
{
    Drink lemonsoda(500,"lemon");
    Drink strawberry_juice(330,"strawberry");
    
    std::cout<<"lemonsoda: "<<lemonsoda.Volume()<<"ml"<<std::endl;
    std::cout<<"strawberry juice: "<<strawberry_juice.Volume()<<"ml"<<std::endl;
    
    return 0;
}
