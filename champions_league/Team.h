
#ifndef TEAM_H_
#define TEAM_H_
#include <iostream>
using namespace std;

class Team
{
	char * m_Name ;
	int m_Points ;
	int m_PlayersNum;

public:
	Team();
	Team(const char * Name , int Points , int playersNum);
	Team(const Team & other);
	~Team();
	char * getName(){return m_Name;};
	bool setName(const char * Name);
	bool operator ==(const Team &other) const;
	bool operator >(const Team &other) const;
	Team& operator =(const Team &other);
	int operator+(const Team &other) const;
	Team& operator++();
	Team operator++(int);
	Team& operator +=(const Team& other);
	friend ostream& operator << (ostream & out , const Team & other);

};


#endif /* TEAM_H_ */
