//============================================================================
// Name        : FootballTournament.cpp
// Author      : Ivailo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <cstring>

#include "Match.h"
#include "Event.h"
#include "Team.h"
#include "Player.h"
#include "Attacker.h"
#include "Midfielder.cpp"
#include "Defender.h"
#include "Goalkeeper.h"
#include "Point.h"
#include "Zone.h"

using namespace std;

int main()
{
    cout<<"Welcome to the football match simulaor!\n";
    cout<<"Please enter the names of the teams in the match.\nTeam one:";
    string name1, name2;
    getline(cin,name1);
    cout<<"Team two:";
    getline(cin,name2);


    //reading the players from file for easier input
    //...
    Player players1[18];
	Player players2[18];
    Team team1(name1, players1);
    Team team2(name2, players2);
    Match match(team1, team2);
    match.setStartPosition();
    Event game;
    cout<<"Let the match begin!\n";
    match.playMatch();
    cout<<game<<endl;
    cout<<team1.getTeamName()<<"   "<<game.goalsOfTeamA<<" : "<<game.goalsOfTeamB<<"   "<<team2.getTeamName()<<endl<<endl;
    cout<<"The winner is ";
    if(game.goalsOfTeamA>game.goalsOfTeamB){
        cout<<"The winner is "<<team1.getTeamName()<<"!"<<endl;
    } else if(game.goalsOfTeamA<game.goalsOfTeamB){
            cout<<"The winner is "<<team2.getTeamName()<<"!"<<endl;
        } else cout<<team1.getTeamName()<<" and "<<team2.getTeamName()<<" ended in a draw!"<<endl;
	return 0;
}
