#include "headers1.h";


class Multiplayer: public Game
{
    private:
        const int maxx;
        void Play1();
        void Play2();
        int Is_In_Word (char, string&);

        string word;

    public:
        void Your_Name() override;
        void Play() override;
        void Rules() override;

        void Gallows(int);
        void Guessed_Letters(string);
        void GiveWord();

        string name_2;
        int points1;
        int points2;

    Multiplayer();


};
