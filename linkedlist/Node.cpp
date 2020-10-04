#include "Node.h"

Node::Node()
{
	student = nullptr;
	nextNode = nullptr;
}

Node::~Node()
{
	/*cout << endl;
	cout << "Node Linking to: " << GetData()->GetStudentId() << " deleted" << endl;
	cout << endl;*/
}

Node::Node(shared_ptr<Student> data)
{
	student = data;
	nextNode = nullptr;
}

Node::Node(shared_ptr<Node> node)
{
	student = node->student;
}

void Node::SetNextNode(shared_ptr<Node> inNextNode)
{
	nextNode = inNextNode;
}

shared_ptr<Node> Node::GetNextNode()
{
	return nextNode;
}

shared_ptr<Student> Node::GetData()
{
	return student;
}

void Node::DisplayData()
{
	student->DisplayStudent();
}

