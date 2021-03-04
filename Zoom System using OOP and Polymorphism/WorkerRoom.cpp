/*
 * WorkerRoom.cpp
 *
 *  Created on: Jan 3, 2021
 *      Author: ise
 */

#include "WorkerRoom.h"

void WorkerRoom::addToWorker(Student* newStudent){
	newStudent->addStudentToWorkerRoom(this);
}

