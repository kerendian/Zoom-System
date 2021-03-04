

#ifndef LEAGUE_H_
#define LEAGUE_H_
#include <iostream>
using namespace std;
#include "Team.h"
#include <string.h>


class League
{
	Team ** m_League; // dynamic array of pointers to Team

public:
	static int LeagueSize;
	static int TeamNum;
	League();
	League(const League & other);
	bool addTeam(  Team* const mTeam);
	bool removeTeam(const char* TeamName);
	void printTeams();
	static void printLeagueDetails();
	~League();
	Team* operator[](const char* TeamName);
};




#endif /* LEAGUE_H_ */
