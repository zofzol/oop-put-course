#include "headers2.h";


void HangmanGame::Gallows(int a)
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

void Game::Your_Name()
{
     this->your_name=name_;

}

void HangmanGame::Your_Name()
{
    system("CLS");
    cout<<"\n ENTER NAME: ";
    cin>>name_;
}


void HangmanGame::Play()
{
    string guessed_letters=" ";
    int wrong_guesses = 0;
    int sea = 0; //checks if we guessed
	srand(time(NULL));
	int n = rand() % 101; //choose random word
	word = words[n];

    string word_to_be_guessed = string(word.length(), 158); // makes new word with all letters changed to x
                                                            //amount of x is equal to amount of letter in word

	while (wrong_guesses< maxx)
	{   cout<<endl;
        //system("pause");
	    system("CLS");

        cout<<endl;

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
    Gallows(wrong_guesses);//finally hung
    Guessed_Letters(guessed_letters);
    char see;
    cout<<"\n DO YOU WANT TO SEE THE WORD?\n Y - YES\n other - NO \n";
    cin>>see;
    if(see=='Y'||see=='y')
       {
            cout<<"\n the word was: "<<word<<"\n"<<endl<<endl;
            system("pause");
       }
    }
    cout<<endl;
    system("CLS");
}

int HangmanGame::Is_In_Word(char users_guess, string &wtbg)
{
	int i;
	int is_in_word = 0;
	int word_length = word.length();


  for (i = 0; i < word_length; i++)
	{
		if (users_guess == word[i])//is in word?
		{
			wtbg[i] = users_guess; //changes x to guessed letter
			is_in_word=1;
		}
	}

	return is_in_word;

}


void HangmanGame::Guessed_Letters(string guessed_letters)
{
    //guessed_letters=guessed_letters+letter+", ";//updates guessed letters list
    cout<<"\n letters you've already guessed:"<<guessed_letters<<endl;
}

void HangmanGame::Rules()
{
    system("CLS");
    cout<<endl;
    cout<<" HANGMAN RULES:\n";
    cout<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<" 1) you will be given one out of 101 animal names"<<endl;
	cout<<" 2) you have to guess what animal it is letter by letter"<<endl;
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
