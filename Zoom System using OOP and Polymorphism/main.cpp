//
#include "ZoomSys.h"

int main(int argc, char*argv[]) {

	ZoomSys* zoomSys = new ZoomSys(argv[1]);
	char menuOption;
	while(menuOption!='0')
	{
		cout<< "1. Add Student" << endl;
		cout<< "2. Remove Student" << endl;
		cout<< "3. Assign Student" << endl;
		cout<< "4. Add Room" << endl;
		cout<< "5. Split Room" << endl;
		cout<< "6. Remove Room" << endl;
		cout<< "7. Work" << endl;
		cout<< "8. Send Message" << endl;
		cout<< "9. Print Rooms" << endl;
		cout<< "p. Print Students" << endl;
		cout<< "d. Print Student details" << endl;
		cout<< "0. Exit" << endl;
		cin >> menuOption;
		switch(menuOption){
		case '1':
			zoomSys->addStudent();
			break;
		case '2':
			zoomSys->removeStudent();
			break;
		case '3':
			zoomSys->assignStudent();
			break;
		case '4':
			zoomSys->addRoom();
			break;
		case '5':
			zoomSys->splitRoom();
			break;
		case '6':
			zoomSys->removeRoom();
			break;
		case '7':
			zoomSys->work();
			break;
		case '8':
			zoomSys->sendMessage();
			break;
		case '9':
			zoomSys->printRooms();
			break;
		case 'p':
			zoomSys->printStudents();
			break;
		case 'd':
			zoomSys->printStudentDetails();
			break;
		case '0':
			cout<<"Bye.."<<endl;
			delete zoomSys;
			break;
		}
	}
	/*Room * r0 = new StandardRoom();
	Room * r1 = new WorkerRoom();
	Room * r2 = new LazyRoom();
	//Room * r3 = new StandardRoom();
	//Room * r4 = new StandardRoom();
	//Room * r5 = new StandardRoom();
	//Room * r6 = new StandardRoom();
	r0->splitByChar(r1, r2);
	//r2->splitByNum(r3, r4);
	//r1->splitByNum(r5, r6);
	r2->removeRoom();
	stack<Room*> rooms;
	stack<int> roomID;
	r0->roomToRemove(rooms, roomID);
	r0->removeRoom();*/

	return 0;
}

