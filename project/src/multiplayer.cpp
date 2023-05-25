#include "headers3.h"

void Multiplayer::Your_Name()
{
    system("CLS");
    cout<<"\n ENTER NAME OF 1ST PLAYER: ";
    cin>>name_;
    cout<<"\n ENTER NAME OF 2ND PLAYER:: ";
    cin>>name_2;
}

void Multiplayer::Gallows(int a)
{
  switch(a)
  {
    case 0:
    {
    cout<<"\t\t _________"<<endl;
    cout<<"\t\t |     '  "<<endl;
    cout<<"\t\t |"<<endl;
    cout<<"\t\t |"<<endl;
    cout<<"\t\t |"<<endl;
    cout<<"\t\t_|____"<<endl;
    break;
    }
     case 1:
    {
    cout<<"\t\t _________"<<endl;
    cout<<"\t\t |     O"<<endl;
    cout<<"\t\t |"<<endl;
    cout<<"\t\t |"<<endl;
    cout<<"\t\t |"<<endl;
    cout<<"\t\t_|____"<<endl;
     break;
    }
    case 2:
    {
    cout<<"\t\t _________"<<endl;
    cout<<"\t\t |     O"<<endl;
    cout<<"\t\t |     |"<<endl;
    cout<<"\t\t |"<<endl;
    cout<<"\t\t |"<<endl;
    cout<<"\t\t_|____"<<endl;
     break;
    }
       case 3:
    {
    cout<<"\t\t _________"<<endl;
    cout<<"\t\t |     O"<<endl;
    cout<<"\t\t |   --|"<<endl;
    cout<<"\t\t |"<<endl;
    cout<<"\t\t |"<<endl;
    cout<<"\t\t_|____"<<endl;
     break;
    }
         case 4:
    {
    cout<<"\t\t _________"<<endl;
    cout<<"\t\t |     O"<<endl;
    cout<<"\t\t |   --|--"<<endl;
    cout<<"\t\t |"<<endl;
    cout<<"\t\t |"<<endl;
    cout<<"\t\t_|____"<<endl;
     break;
    }
          case 5:
    {
    cout<<"\t\t _________"<<endl;
    cout<<"\t\t |     O"<<endl;
    cout<<"\t\t |   --|--"<<endl;
    cout<<"\t\t |     |"<<endl;
    cout<<"\t\t |"<<endl;
    cout<<"\t\t_|____"<<endl;
     break;
    }
         case 6:
    {
    cout<<"\t\t _________"<<endl;
    cout<<"\t\t |     O"<<endl;
    cout<<"\t\t |   --|--"<<endl;
    cout<<"\t\t |     | "<<endl;
    cout<<"\t\t |    /   "<<endl;
    cout<<"\t\t_|____"<<endl;
     break;
    }
          case 7:
    {
    cout<<"\t\t _________"<<endl;
    cout<<"\t\t |     O"<<endl;
    cout<<"\t\t |   --|--"<<endl;
    cout<<"\t\t |     |           YOU'VE BEEN HUNG"<<endl;
    cout<<"\t\t |    / \\ "<<endl;
    cout<<"\t\t_|____"<<endl;
     break;
    }
  }
}



void Multiplayer::Play()
{
    system("CLS");
    Play1();
    Play2();
}

void Multiplayer::GiveWord() {
    char word_[100],word_2[100];
    cin >> word_;
    for (int i=0; i<100; i++)
    word_2[i]=toupper(word_[i]); //changes input to capital letters
    word=word_2;
}

void Multiplayer::Play1()
{
    points1=70;
    string guessed_letters=" ";
    int wrong_guesses = 0;
    string word_;
    int sea = 0; //checks if we guessed
    cout<<endl<<" "<<name_<<" GIVE A WORD TO GUESS FOR "<<name_2<<": ";
    GiveWord();
	cout<<endl;
	system("pause");
	system("CLS");

    string word_to_be_guessed = string(word.length(), 158); // makes new word with all letters changed to x
                                                            //amount of x is equal to amount of letter in word

	while (wrong_guesses< maxx)
	{   cout<<endl;
        //system("pause");
	    system("CLS");

        cout<<endl;
        cout<<"\t\t"<<name_2<<"'s GAME:"<<endl<<endl;//who is guessing
        Gallows(wrong_guesses); //shows you you hangman process
        Guessed_Letters(guessed_letters);//shows you letters you guessed

        cout<<endl;
		cout<<"\t\t "<<word_to_be_guessed<<endl;//cout amount of x as there is letters in word to be guessed by a player
                                                //cout the HIDDEN WORD
		cout<<endl<<" Guess a letter: ";
        char letter;
        cin >> letter; //give me a guess
        if (letter >= 'a' && letter <= 'z')
        {
        letter = letter - 'a' + 'A'; //CHECK IF LETTER IS CAPITAL IF NOT CHANGE
        }


        guessed_letters += letter; // add character to guessed letters list
        guessed_letters += ", "; // add a comma and a space after the letter
        //updates guessed letters list

        cout<<endl;



		if (Is_In_Word(letter, word_to_be_guessed) == 0) // put the letter or increase number of wrong guesses

		{
		    if(letter>='A'&&letter<='Z')
        {
            wrong_guesses++;
            points1-=10;
        }

		}

		if (word == word_to_be_guessed)//word guessed
		{
		    sea=1;
			cout<<"\t\t "<<word<<endl;//cout complete word that you guessed
			cout<<"\n CONGRATULARIONS "<<name_2<<" YOU'VE GUESSED THE WORD\n"<<endl;
			system("pause"); //pause to show this scope
			break;
		}


	}

    if(sea==0)
    {
    system("CLS");
    cout<<"\t\t"<<name_2<<"'s GAME:"<<endl<<endl;//who is guessing
    Gallows(wrong_guesses);//finally hung
    Guessed_Letters(guessed_letters);
    cout<<"\n the word was: "<<word<<"\n"<<endl<<endl;
    system("pause");
    }
    //cout<<endl;
    system("CLS");
}

void Multiplayer::Play2()
{
    points2=70;
    string guessed_letters=" ";
    int wrong_guesses = 0;
    int sea = 0; //checks if we guessed
    cout<<endl<<" "<<name_<<" GIVE A WORD TO GUESS FOR "<<name_<<": ";
    GiveWord();
    cout<<endl;
    system("pause");
	system("CLS");

    string word_to_be_guessed = string(word.length(), 158); // makes new word with all letters changed to x
                                                            //amount of x is equal to amount of letter in word

	while (wrong_guesses< maxx)
	{   cout<<endl;
        //system("pause");
	    system("CLS");

        cout<<endl;

        cout<<"\t\t"<<name_<<"'s GAME:"<<endl<<endl;//who is guessing
        Gallows(wrong_guesses); //shows you you hangman process
        Guessed_Letters(guessed_letters);//shows you letters you guessed

        cout<<endl;
		cout<<"\t\t "<<word_to_be_guessed<<endl;//cout amount of x as there is letters in word to be guessed by a player
                                                //cout the HIDDEN WORD
		cout<<endl<<" Guess a letter: ";
        char letter;
        cin >> letter; //give me a guess
        if (letter >= 'a' && letter <= 'z')
        {
        letter = letter - 'a' + 'A'; //CHECK IF LETTER IS CAPITAL IF NOT CHANGE
        }


        guessed_letters += letter; // add character to guessed letters list
        guessed_letters += ", "; // add a comma and a space after the letter
        //updates guessed letters list

        cout<<endl;



		if (Is_In_Word(letter, word_to_be_guessed) == 0) // put the letter or increase number of wrong guesses

		{
		    if(letter>='A'&&letter<='Z')
        {
            wrong_guesses++;
            points2-=10;
        }

		}

		if (word == word_to_be_guessed)//word guessed
		{
		    sea=1;
			cout<<"\t\t "<<word<<endl;//cout complete word that you guessed
			cout<<"\n CONGRATULARIONS "<<name_<<" YOU'VE GUESSED THE WORD\n"<<endl;
			system("pause"); //pause to show this scope
			break;
		}


	}

    if(sea==0)
    {
    system("CLS");

    cout<<"\t\t"<<name_<<"'s GAME:"<<endl<<endl;//who is guessing
    Gallows(wrong_guesses);//finally hung
    Guessed_Letters(guessed_letters);
    cout<<"\n the word was: "<<word<<"\n"<<endl<<endl;
    system("pause");
    }
    //cout<<endl;
    system("CLS");
}


int Multiplayer::Is_In_Word(char users_guess, string &wtbg)
{
	int i;
	int is_in_word = 0;
	int word_length = word.length();

  for (i = 0; i < word_length; i++)
	{
		if (users_guess == word[i])//is in word?
		{
			wtbg[i] = users_guess; //changes x to guessed letter
			is_in_word=1;//no longer a zero
		}
	}
	return is_in_word;

}

void Multiplayer::Guessed_Letters(string guessed_letters)
{
    cout<<"\n letters you've already guessed:"<<guessed_letters<<endl;
}

void Multiplayer::Rules()
{
    system("CLS");
    cout<<endl;
    cout<<" HANGMAN RULES:\n";
    cout<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<" 1) you will be given one word by your opponent"<<endl;
	cout<<" 2) you have to guess what it is letter by letter"<<endl;
	cout<<" 3) if you guess wrong you loose part of your body to the gallows"<<endl;
    cout<<" 4) entering non-letter character will not result in you loosing a try"<<endl;
	cout<<" 5) when your body is fully on the gallows you loose compleatly"<<endl;
	cout<<" 6) this is what a full body looks like:"<<endl;
    cout<<endl;
    cout<<"       O"<<endl;
    cout<<"     --|--"<<endl;
    cout<<"       |    "<<endl;
    cout<<"      / \\ "<<endl;
    cout<<endl;
    cout<<"    it consist out of 7 parts which means you can make up to 7 mistakes"<<endl;
	cout<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<endl;
    system("pause");
    system("CLS");
}

