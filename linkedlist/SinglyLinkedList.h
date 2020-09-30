#pragma once

#include "Node.h"

class SinglyLinkedList
{
public:
	SinglyLinkedList();
	void InsertAtBack(shared_ptr<Student> data);
	void RemoveStudent(int studentId);
	void DisplayList();

private:
	shared_ptr<Node> head;

};

