champions_league: champions_league.o League.o Team.o
	g++ champions_league.o League.o Team.o -o champions_league
champions_league.o: champions_league.cpp Team.h League.h
	g++ -c champions_league.cpp
League.o: League.cpp League.h Team.h
	g++ -c League.cpp
Team.o: Team.cpp Team.h
	g++ -c Team.cpp
clean:
	rm -f *.o

