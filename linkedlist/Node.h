#pragma once

#include "Student.h"
#include <memory>

class Node
{
public:
	Node();
	~Node();
	Node(shared_ptr<Student> data);
	Node(shared_ptr<Node> node);
	void SetNextNode(shared_ptr<Node> inNextNode);
	shared_ptr<Node> GetNextNode();
	shared_ptr<Student> GetData();
	void DisplayData();

private:
	shared_ptr<Student> student;
	shared_ptr<Node> nextNode;
};

