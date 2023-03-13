#include <iostream>
#include <string>
using namespace std;

class books
{
public:
    string name;
    string author;
    int length;
};

class movies
{
public:
    string name;
    string director;
    int length;
};


int main()
{
    books book1;
    movies movie1;
    movie1.name = "hauru's moving castle";
    movie1.director = "Hayao Miyazaki";
    book1.name="The secret history";
    book1.author="Donna Tartt";
    book1.length = 516;
    std::cout << book1.length<<"stron \n"<<book1.name<<endl;
}

