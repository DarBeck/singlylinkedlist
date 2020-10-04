#pragma once

#include "Node.h"

class SinglyLinkedList
{
public:
	SinglyLinkedList();
	void InsertAtBack(shared_ptr<Student> data);
	void RemoveStudent(int studentId);
	shared_ptr<Student> SearchStudent(int studentId);
	void DisplayList();
	void DestroyList();

private:
	shared_ptr<Node> head;
};

