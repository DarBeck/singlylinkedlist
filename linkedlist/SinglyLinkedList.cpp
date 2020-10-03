#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList()
{
	head = nullptr;
}

void SinglyLinkedList::InsertAtBack(shared_ptr<Student> data)
{
    shared_ptr<Node> temp(make_shared<Node>(data));

    if (temp != nullptr)
    {
        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            shared_ptr<Node> temp2 = head;
            while (temp2->GetNextNode() != nullptr)
            {
                temp2 = temp2->GetNextNode();
            }
            temp2->SetNextNode(temp);
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
        cout << endl;
        cout << "Error! The List is Empty" << endl;
        return;
    }

    // check if head contains the ID number
    if (selector->GetData()->GetStudentId() == studentId)
    {
        studentToRemove = make_shared<Node>(selector);
        head = selector->GetNextNode();
        cout << endl;
        cout << "---------------------------------------" << endl;
        cout << "Student Removed: " << endl;
        studentToRemove->DisplayData();
        cout << "---------------------------------------" << endl;
        cout << endl;
    }
    else {
        while (selector->GetNextNode() != nullptr)
        {
            if (selector->GetNextNode()->GetData()->GetStudentId() == studentId)
            {
                studentToRemove = selector->GetNextNode();
                selector->SetNextNode(studentToRemove->GetNextNode());
                cout << endl;
                cout << "---------------------------------------" << endl;
                cout << "Student Removed: " << endl;
                studentToRemove->DisplayData();
                cout << "---------------------------------------" << endl;
                cout << endl;
                return;
            }

            selector = selector->GetNextNode();
        }

        // if student was not found
        cout << endl;
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
        //cout << "Error! The List is Empty" << endl;
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

    //cout << "Error! Student ID not found" << endl;
    
    return student;
}

void SinglyLinkedList::DisplayList()
{
    if (head == nullptr)
        cout << "Error! List is Empty!" << endl;

    shared_ptr<Node> temp = head;
    while (temp != nullptr)
    {
        cout << endl;
        cout << "---------------------------------------" << endl;
        temp->DisplayData();
        cout << "---------------------------------------" << endl;
        temp = temp->GetNextNode();
    }
}

void SinglyLinkedList::DestroyList()
{
    if (head == nullptr)
    {
        cout << "Error! The List is Empty" << endl;
    }
    else
    {
        shared_ptr<Node> selector2 = head->GetNextNode();
        
        while (head != nullptr)
        {
            head = nullptr;
            head = selector2;
            if (selector2 != nullptr)
                selector2 = selector2->GetNextNode();
        }
    }

   
}
