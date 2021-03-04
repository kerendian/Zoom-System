/*
 * StandardRoom.h
 *
 *  Created on: Jan 3, 2021
 *      Author: ise
 */

#ifndef STANDARDROOM_H_
#define STANDARDROOM_H_

#include "Room.h"

class StandardRoom: public Room {
public:
	StandardRoom():Room(){};
	virtual void addToLazy(Student* newStudent){};
	virtual void addToWorker(Student* newStudent){};
	virtual ~StandardRoom(){};
};

#endif /* STANDARDROOM_H_ */
