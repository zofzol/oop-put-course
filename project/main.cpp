#include "headers2.h"
#include "headers3.h";


int main()
{
    HangmanGame hangmangame;
    Multiplayer multiplayer;

    char option;
    while(true)
    {
        cout<<"\n 1 - PLAY THE GAME\n";
        cout<<" 2 - SHOW ME THE RULES\n";
        cout<<" other - END GAME\n";
        cout<<"\n Please enter your choice: ";
        cin>>option;
        cout<<endl;

    if(option!='1'&&option!='2')
    {
        system("CLS");
        //cout<<"\n\t\t\t~~~~~~see you later~~~~~~\n\n\n\n\n\n\n"<<endl;
        throw std::invalid_argument("\n\t\t\t~~~~~~see you later~~~~~~\n\n\n\n\n\n\n");
        break;
    }
        switch(option)
        {
        case '1':
        {
        system("CLS");
        char singmult;
        cout<<endl<<"\n SINGLE(1) OR MULTIPLAYER(other): ";
        cin>>singmult;
           if(singmult=='1'){
            hangmangame.Your_Name();
            char again='y';
            while(again=='Y'||again=='y')
            {
                hangmangame.Play();
                hangmangame.number_of_played_games++;
                cout<<"\n you've played: "<<hangmangame.number_of_played_games<<" games\n"<<endl;
                cout<<" DO YOU WANT TO PLAY AGAIN:\n Y - YES\n other - NO \n";
                cin>>again;
                if(again=='N'||again=='n')break;
            }
            system("CLS");
           }else{
               multiplayer.Your_Name();
            char again='y';
            int points_1=0, points_2=0;
            while(again=='Y'||again=='y')
            {
                multiplayer.Play();
                multiplayer.number_of_played_games++;
                cout<<"\n you've played: "<<multiplayer.number_of_played_games<<" games\n"<<endl;
                points_1=points_1+multiplayer.points1;
                points_2=points_2+multiplayer.points2;
                cout<<"\t SCORES\n "<<multiplayer.name_<<": "<<points_1<<" points\n ";
                cout<<multiplayer.name_2<<": "<<points_2<<" points\n\n";
                cout<<" DO YOU WANT TO PLAY AGAIN:\n Y - YES\tother - NO \n";
                cin>>again;
                if(again=='N'||again=='n')break;
            }
            system("CLS");
           }
            break;
        }
        case '2':
        {
            system("CLS");
        char siult;
        cout<<endl<<"\n SINGLE(1) OR MULTIPLAYER(other): ";
        cin>>siult;
           if(siult=='1')
            hangmangame.Rules();
            else multiplayer.Rules();
            break;
        }
        }
    }
    try {
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }


    return 0;
}
