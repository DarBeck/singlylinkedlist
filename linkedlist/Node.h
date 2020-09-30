#pragma once

#include "Student.h"
#include <memory>

class Node
{
public:
	Node();
	Node(shared_ptr<Student> data);
	void SetNextNode(shared_ptr<Node> inNextNode);
	shared_ptr<Node> GetNextNode();
	void DisplayData();

private:
	shared_ptr<Student> student;
	shared_ptr<Node> nextNode;
};

