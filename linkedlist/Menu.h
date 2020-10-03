#pragma once

#include "SinglyLinkedList.h"

class Menu
{
public:
	Menu();
	void InitializeMenu();
	void ShowMenu();
	void AddStudentOption();
	void RemoveStudentOption();
	void SearchStudentOption();
	void ShowAllStudentsOption();
	void RemoveAllStudentsOption();

private:
	shared_ptr<SinglyLinkedList> studentList;
};

