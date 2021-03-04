/*
 * LazyRoom.cpp
 *
 *  Created on: Jan 3, 2021
 *      Author: ise
 */

#include "LazyRoom.h"


void LazyRoom::addToLazy(Student* newStudent){
	newStudent->addStudentToLazyRoom(this);
}

