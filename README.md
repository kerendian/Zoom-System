# ZOOM-simulation-system
**A system that simulates the video chatting software ZOOM**
This system contains rooms and students, where students can perform actions according to their type.

# System Architecture
***There are three different types of students:*** A student can only belong to one of these types.

• Diligent student - works when the room to which he belongs receives a work order, every time the room works he announces that he is working.

• Lazy student - complains every time he has to move room and every time the room is deleted he complains.

• Responsible student - has the ability to send messages to all members of the room (compared to other students who can not send messages at all, just receive).

**There are three types of rooms in the system:**

• Standard room - a room that at the time of its creation every student is capable of being.

• Diligent room - a room that at the time of its creation holds only diligent students.

• Lazy room - a room that at the time of creation holds only lazy students.

# System Functionality 
**Split room:**

• The system will receive the type of split requested from the user and create 2 new sub-rooms
: Left room and right room and then move the relevant students to the new rooms.
There are 2 different types of splits: split according to the number of students and split according to the nature of the student.

• Split by character: 2 rooms are created (left room is diligent, and right is lazy (students are transferred to the room according to their character when in this type of split a responsible student remains in the split room. Examine what type of student these are by realizing polymorphism.

• Split by quantity: 2 standard rooms are created and the students are divided into rooms according to the order in which they are added to the current room, half of the students who joined the room first will move to the left room, and the other half to the right. For example, if there are 9 students in a room then after the split the 4 old students will belong to the left room and the new 5 to the right room (if there is an odd number the right room will be larger). After this split no students are left in the split room.

**Deleting a room:** We performed recursively - as deleting from binary tree

• When a room is deleted, all the sub-rooms associated with it are also deleted. That is, all students belonging to this room or to one of its sub-rooms (can be more than 2 if its sub-room is also split) will move to the room that created it (its father’s room). If there is no master bedroom (i.e. a room that was not created as a result of splitting is deleted) the students will be left without a room (as if they have just entered the system, ID room -1).

• The order to delete the rooms is left-handed, right-handed and only then the father (this order is valid in all cases - even if there are "grandchildren" and even more)

• The order in which the students are taken out of the room is according to their order of entry - the oldest leaves first and enters the father's room.

• Every time a lazy student leaves his room following a room erasure he prints a complaint message.

# Error handling 
**according to the types of errors:**

• exception id - thrown when no matching ID is found in the student or room system.

• Student permissions - thrown when trying to send a message from an irresponsible student.

• before Split - thrown when trying to split a previously split room.

• Invalid details - thrown when trying to create a new student and at least one of the parameters is incorrect. For example, an average greater than 100 or a student type that is not one of the letters W \ R \ L
