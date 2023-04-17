#include <iostream>
#include <map>

class Cantor {
 public:
  Cantor() = default;
  virtual ~Cantor() = default;

  virtual double Rate(const std::string& abbreviation) const = 0;
};

class FakeUsdCantor : public Cantor {
 public:
  FakeUsdCantor() {
    // rates_ map with values for ten most popular currencies relative to USD
    rates_ = {
      {"EUR", 0.85},
      {"JPY", 110.66},
      {"GBP", 0.73},
      {"CHF", 0.91},
      {"CAD", 1.25},
      {"AUD", 1.34},
      {"CNY", 6.47},
      {"HKD", 7.78},
      {"NZD", 1.44},
      {"KRW", 1153.89}
    };
  }

  double Rate(const std::string& abbreviation) const override {
    auto it = rates_.find(abbreviation);
    if (it != rates_.end()) {
      return it->second;
    }
    // Handle error case when currency abbreviation is not found
    return 0.0;
  }

 private:
  std::map<std::string, double> rates_;
};

class Currency {
 public:
  Currency() = default;
  virtual ~Currency() = default;

  virtual double ConvertedToDollars(const Cantor& cantor) const = 0;
  virtual std::string Abbreviation() const = 0;
  virtual double Amount() const = 0;
};

class Yen: public Currency{
    private:
        //double to_dollars;
        std::string abbrv;
        double money_amount;
    
    public:
        
    Yen(std::string abbrv,double money_amount)
    {
        this->money_amount=money_amount;
        this->abbrv=abbrv;
        //this->to_dollars=to_dollars;
    }
    
     double ConvertedToDollars(const Cantor& cantor) const override
    {
        return money_amount/cantor.Rate(this->abbrv);
    }
    
     std::string Abbreviation() const override
    {
      return this->abbrv;   
         
    }
    
    double Amount() const override
    {
        return this->money_amount;
    }
    
};

int main() {
    
    FakeUsdCantor money1;
    Yen yen("JPY",599.0);
    
    std::cout<<yen.ConvertedToDollars(money1);
    
  return 0;
}
