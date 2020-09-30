#include "Node.h"

Node::Node()
{
	student = nullptr;
	nextNode = nullptr;
}

Node::Node(shared_ptr<Student> data)
{
	student = data;
	nextNode = nullptr;
}

void Node::SetNextNode(shared_ptr<Node> inNextNode)
{
	nextNode = inNextNode;
}

shared_ptr<Node> Node::GetNextNode()
{
	return nextNode;
}

void Node::DisplayData()
{
	student->DisplayStudent();
}
