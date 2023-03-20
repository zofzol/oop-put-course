#include <iostream>
#include <string>
#include <vector>

class bottle
{
    private:
    std::string volume;
    
    public:
    bottle choosevolume(std::string newvolume)
    {
        this->volume=std::move(newvolume);
        return *this;
    }
    
    std::string currentvolume()
    {
       return this->volume;
    };
};

class drink
{
    private:
    std::string beverage;
    
    public:
    void choosedrink(std::string newbeverage)
    {
        this->beverage=std::move(newbeverage);
    };
    
    std::string nameofbevrage()
    {
       return this->beverage; 
    };
};

int main()
{
    bottle bottle1;
    drink drink1;
    bottle newvolume=bottle1.choosevolume("750ml");
    drink1.choosedrink("lemonsoda");
    
    std::cout<<bottle1.currentvolume()<<" "<<drink1.nameofbevrage()<<std::endl;
    
    return 0;
}
