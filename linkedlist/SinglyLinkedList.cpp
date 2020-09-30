#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList()
{
	head = nullptr;
}

void SinglyLinkedList::InsertAtBack(shared_ptr<Student> data)
{
    unique_ptr<Node> temp(make_unique<Node>(data));

    if (temp != nullptr)
    {
        if (head == nullptr)
        {
            head = move(temp);
        }
        else
        {
            shared_ptr<Node> temp2 = head;
            while (temp2->GetNextNode() != nullptr)
            {
                temp2 = temp2->GetNextNode();
            }
            temp2->SetNextNode(move(temp));
        }

    }
    else
    {
        cerr << "Error! Out of Memory!" << endl;
    }
}

void SinglyLinkedList::RemoveStudent(int studentId)
{

}

void SinglyLinkedList::DisplayList()
{
    shared_ptr<Node> temp = head;
    while (temp != nullptr)
    {
        temp->DisplayData();
        temp = temp->GetNextNode();
    }
}
