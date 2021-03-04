#include "League.h"


	int League::LeagueSize = 3;
	int League::TeamNum = 0;
	League::League()
	{
		m_League= new Team*[3];
	}
	League::League(const League & other)
	{
		m_League = nullptr;
		Team ** temp;
		temp = new Team*[LeagueSize];
		if(!temp)
		{
			return;
		}
		int i;
		for(i=0 ; i< TeamNum ; i++)
		{
			temp[i] = new Team(*other.m_League[i]);
			if(temp[i] == nullptr)
			{
				return ;
			}
		}

		m_League = temp;
	}
	bool League::addTeam(  Team* const mTeam)// to check where is correct to put the const
	{
		if(mTeam == nullptr)
		{
			return false;
		}
		if (LeagueSize == 0)
		{
			Team **temp = new Team *[2];
			delete[] m_League;
			m_League = temp;
			LeagueSize=2;
		}
		if (TeamNum == 0)
		{
			m_League[TeamNum] = new Team(*mTeam);
			delete mTeam;
			TeamNum++;
			return true;
		}

		int i;
		for(i=0 ; i< TeamNum ; i++)
		{
			if(*m_League[i] == *mTeam)
			{
				cout << "This Team is already in the League" << endl ;
				//delete mTeam; the forum said not to delete in this case.
				return false;
			}
			else
			{
				if(LeagueSize == TeamNum)
				{
					Team ** temp;
					temp = new Team*[2*LeagueSize];
					if(!temp)
					{
						return false;
					}
					int i;
					for(i=0 ; i< TeamNum ; i++)
					{
						temp[i] = m_League[i];
						if(temp[i] == nullptr)
						{
							return false;
						}

					}
					temp[TeamNum]= new Team(*mTeam);
					delete mTeam;
					delete[] m_League;
					m_League = temp;
					TeamNum++;
					LeagueSize*=2;
					return true;
				}
				else
				{
					m_League[TeamNum]= new Team(*mTeam);
					TeamNum++;
					delete mTeam;
					return true;
				}
			}
		}
		return true;
	}

	bool League::removeTeam(const char* TeamName)
	{
		int i;

		for(i=0 ; i< TeamNum ; i++)
		{
			if(strcmp(TeamName , m_League[i]->getName())==0)
			{
				delete m_League[i];
				m_League[i] = nullptr;
				TeamNum -=1;
				if (i == TeamNum)
				{
					if ((TeamNum ) <= (LeagueSize / 2))
					{
						Team **temp = new Team *[LeagueSize / 2];
						int j;
						for ( j = 0; j< TeamNum; j++)
						{
							temp[j] = m_League[j];
						}
						delete [] m_League;
						m_League = temp;
						LeagueSize = LeagueSize / 2;
						return true;
					}

				}
				else
				{
					if ((TeamNum ) <= (LeagueSize / 2))
					{
						Team **temp = new Team *[LeagueSize / 2];
						int j;
						for (j = 0; j< TeamNum; j++)
						{
							if (j < i)
							{
								temp[j] = m_League[j];
							}
							else //j>=i
							{
								temp[j] = m_League[j+1];
							}
						}
						delete [] m_League;
						m_League = temp;
						LeagueSize = LeagueSize / 2;
						return true;

					}
					else
					{
						Team **temp = new Team *[LeagueSize];
						int j;
						for (j = 0; j< TeamNum; j++)
						{
							if (j < i)
							{
								temp[j] = m_League[j];
							}
							else //j>=i
							{
								temp[j] = m_League[j+1];
							}
						}
						delete [] m_League;
						m_League = temp;
						return true;
					}
				}
				return true;
			}
		}
		cout << "This Team isn't in the League" << endl;
		return false;
	}
	void League::printTeams()
	{
		cout << "---Teams---" << endl;
		int i;
		for(i=0 ; i< TeamNum ; i++)
		{
			cout << *m_League[i];
		}
	}
	void League::printLeagueDetails()
	{
		cout << "---League Details---" << endl;
		cout << "number of teams: " << TeamNum << endl;
		cout << "league size: " << LeagueSize << endl;
	}
	League::~League()
	{
		int i ;

		for(i=0 ; i< TeamNum ; i++)
		{
			delete m_League[i];

		}
		delete[] m_League;

	}
	Team* League::operator[](const char* TeamName)
	{
		if(TeamName == nullptr)
		{
			return nullptr;
		}
		int i;
		for(i=0 ; i< TeamNum ; i++)
		{
			if(strcmp(m_League[i]->getName() , TeamName) == 0 )
			{
				return m_League[i];
			}
		}
		return nullptr;
}




