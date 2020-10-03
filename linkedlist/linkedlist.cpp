
#include "SinglyLinkedList.h"

int main()
{
    shared_ptr<Student> student1(make_shared<Student>(2322, "James Brown", 3.80));
    shared_ptr<Student> student2(make_shared<Student>(2323, "Jean Thomas", 3.40));
    shared_ptr<Student> student3(make_shared<Student>(1111, "Joe Grande", 3.20));
    unique_ptr<SinglyLinkedList> studentList(make_unique<SinglyLinkedList>());

    studentList->InsertAtBack(student1);
    studentList->InsertAtBack(student2);
    studentList->InsertAtBack(student3);


    //studentList->DisplayList();
    cout << endl;
    cout << endl;

    shared_ptr<Student> searchStudent = studentList->SearchStudent(65444);
    if (searchStudent != nullptr) searchStudent->DisplayStudent();

    studentList->DestroyList();
    

    //studentList->RemoveStudent(124444);
    cout << endl;
    cout << "After Destroy List" << endl;
    cout << endl;
    studentList->DisplayList();




   
}


