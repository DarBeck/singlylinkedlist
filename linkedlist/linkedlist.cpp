
#include "SinglyLinkedList.h"

int main()
{
    shared_ptr<Student> student1(make_shared<Student>(2322, "James Brown", 3.80));
    shared_ptr<Student> student2(make_shared<Student>(2323, "Jean Thomas", 3.40));
    unique_ptr<SinglyLinkedList> studentList(make_unique<SinglyLinkedList>());

    studentList->InsertAtBack(student1);
    studentList->InsertAtBack(student2);

    studentList->DisplayList();

   
}


