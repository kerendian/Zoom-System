#include "Team.h"
#include <string.h>

	Team::Team()
	{
		m_Name = nullptr;
		setName("default");
		m_Points = 0;
		m_PlayersNum = 0 ;
	};
	bool Team::setName(const char * Name)
	{
		if( Name == nullptr)
		{
			return false;
		}

		char * temp = new char[strlen(Name)+1];
		if ( !temp)
		{
			return false;
		}
		strcpy(temp, Name);

		delete[] m_Name;
		m_Name = temp;

		return true;
	}

	Team::Team(const char * Name , int Points , int playersNum)
	{
		m_Name = nullptr;
		setName(Name);
		m_PlayersNum = playersNum;
		m_Points = Points;
	}
	Team::Team(const Team & other)
	{
		m_Name = nullptr;
		setName(other.m_Name);
		m_Points = other.m_Points;
		m_PlayersNum = other.m_PlayersNum;
	}
	Team::~Team()
	{
		if(m_Name)
		{
			delete[] m_Name;
		}
	}

	bool Team::operator ==(const Team &other) const
	{
	return (strcmp(other.m_Name, m_Name)==0);
	}
	bool Team::operator >(const Team &other) const
	{
		return (m_Points > other.m_Points);
	}
	Team& Team::operator =(const Team &other)
	{
		if(this == &other)
			return *this;
		m_PlayersNum = other.m_PlayersNum;
		m_Points = other.m_Points;
		setName(other.m_Name);
		return *this;
	}
	int Team::operator+(const Team &other) const
	{
		return (m_Points + other.m_Points);
	}
	Team& Team::operator++()
	{
		m_Points += 1 ;
		return *this;
	}
	Team Team::operator++(int x)
	{
		Team temp(*this);
		m_Points += 1;
		return temp;
	}
	Team& Team::operator +=(const Team& other)
	{
		char * temp = new char[strlen(m_Name)+strlen(other.m_Name)+1];
		strcpy(temp, m_Name);
		setName(strcat(temp,other.m_Name));
		delete[] temp;
		return *this;
	}
	ostream& operator << (ostream & out , const Team & other)
	{
		out << "---" << endl;
		out << "name: " << other.m_Name << endl;
		out << "number of players: " << other.m_PlayersNum << endl;
		out << "points: " << other.m_Points << endl;
		return out;

	}

