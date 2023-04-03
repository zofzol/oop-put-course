#include <iostream>

class books
{   private:
    int pages;
    std::string author;
   
public:
void bookinfo()
{
std::cout<<"how many pages: "<<pages<<std::endl;
std::cout<<"author: "<<author<<std::endl;
}

books(int pages, std::string author)
{
   this->pages=pages;
   this->author=author;
}

books (std::string author):books(0, author){} //!!!!!!!
};

int main()
{
books first(463,"mickiewicz");
books second("slowacki");
first.bookinfo();
second.bookinfo();

return 0;

}

