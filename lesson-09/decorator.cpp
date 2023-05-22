#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class IntegerSequence{
    
    public:
    virtual std::vector<int> Numbers()=0;

};

class VectorComponent : public IntegerSequence{
   private:
    std::vector<int> vector1;
    
   public:
    std::vector<int> Numbers() override
    {
      return vector1;
    }
    
    VectorComponent(std::vector<int> input){
        this->vector1=input;
    }
};

class PositiveSequence : public IntegerSequence{
   private:
    IntegerSequence *seq;
   public:
    std::vector<int> Numbers() override {
        std::vector<int> temp = seq->Numbers();
        for(int i=0; i<temp.size(); i++){
            if(temp[i]<0){
                temp.erase(temp.begin()+i);
            }
        }
        return temp;
    }
    
    PositiveSequence(IntegerSequence *seq){
        this->seq=seq;
    }
};

class EvenSequence : public IntegerSequence{
   private:
    IntegerSequence *seq;
   public:
    std::vector<int> Numbers() override {
         std::vector<int> temp = seq->Numbers();
        for(int i=0; i<temp.size(); i++){
            if(temp[i]%2==1){
                temp.erase(temp.begin()+i);
            }
        }
        return temp;
    }
    
    EvenSequence(IntegerSequence *seq){
        this->seq=seq;
    }
};

class SortedSequence : public IntegerSequence{
   private:
    IntegerSequence *seq;
    public:
    std::vector<int> Numbers() override {
       std::vector<int> temp = seq->Numbers();
        
        return temp;
    }
    SortedSequence(IntegerSequence *seq){
        this->seq=seq;
    }
};

int main()
{
    std::unique_ptr<IntegerSequence> vectorrr = std::make_unique<VectorComponent>(
        std::make_unique<PositiveSequence>(
            std::make_unique<EvenSequence>(
                std::make_unique<SortedSequence>())))
    
    
    return 0;
}
