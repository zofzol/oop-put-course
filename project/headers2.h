#include "headers1.h";


class HangmanGame: public Game
{
    private:
        const int maxx;
        string word;
        string words[101];
        int Is_In_Word (char, string&);


    public:
        void Your_Name() override;
        void Play() override;
        void Rules() override;

        void Gallows(int);
        void Guessed_Letters(string);

   HangmanGame();



};


