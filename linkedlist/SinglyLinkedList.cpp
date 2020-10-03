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
            shared_ptr<Node> temp2 (make_shared<Node>(head));
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
    shared_ptr<Node> selector = head;
    shared_ptr<Node> studentToRemove;

    if (selector == nullptr)
    {
        cout << "Error! The List is Empty" << endl;
        return;
    }

    // check if head contains the ID number
    if (selector->GetData()->GetStudentId() == studentId)
    {
        studentToRemove = make_shared<Node>(selector);
        head = move(selector->GetNextNode());
        cout << "Removed: " << studentToRemove->GetData()->GetStudentId() << endl;
        cout << endl;
    }
    else {
        while (selector->GetNextNode() != nullptr)
        {
            if (selector->GetNextNode()->GetData()->GetStudentId() == studentId)
            {
                studentToRemove = selector->GetNextNode();
                selector->SetNextNode(studentToRemove->GetNextNode());
                cout << "Removed: " << studentToRemove->GetData()->GetStudentId() << endl;
                cout << endl;
                return;
            }

            selector = selector->GetNextNode();
        }

        // if student was not found
        cout << "Error! Student ID was not found" << endl;
        cout << endl;
    }
}

shared_ptr<Student> SinglyLinkedList::SearchStudent(int studentId)
{
    shared_ptr<Node> selector = head;
    shared_ptr<Student> student = nullptr;

    if (selector == nullptr)
    {
        cout << "Error! The List is Empty" << endl;
        return student;
    }

    while (selector != nullptr)
    {
        if (selector->GetData()->GetStudentId() == studentId)
        {
            return selector->GetData();
        }

        selector = selector->GetNextNode();
    }

    cout << "Error! Student ID not found" << endl;
    
    return student;
}

void SinglyLinkedList::DisplayList()
{
    shared_ptr<Node> temp = head;
    while (temp != nullptr)
    {
        temp->DisplayData();
        cout << "---------------" << endl;
        temp = temp->GetNextNode();
    }
}

void SinglyLinkedList::DestroyList()
{
    shared_ptr<Node> selector = head;
    shared_ptr<Node> selector2 = head->GetNextNode();

    if (selector == nullptr)
    {
        cout << "Error! The List is Empty" << endl;
        return;
    }

    do
    {
        selector ;
        selector = selector2;
        if (selector2 != nullptr)
            selector2 = selector2->GetNextNode();
    } while (selector != nullptr);
}
