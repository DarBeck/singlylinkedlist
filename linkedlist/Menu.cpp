#include "Menu.h"

#include <string>

Menu::Menu()
{
	studentList = make_shared<SinglyLinkedList>();
	InitializeMenu();
}

void Menu::InitializeMenu()
{
	cout << "# # # # # # # # # # # # # # # # # # # #" << endl;
	cout << "#                                     #" << endl;
	cout << "# Welcome To School Management System #" << endl;
	cout << "#                                     #" << endl;
	cout << "# # # # # # # # # # # # # # # # # # # #" << endl;
	ShowMenu();
}

void Menu::ShowMenu()
{
	cout << endl;
	cout << "----------------- Menu ----------------" << endl;
	cout << endl;
	cout << "[1] Add Student" << endl;
	cout << "[2] Remove Student" << endl;
	cout << "[3] Search Student" << endl;
	cout << "[4] Show All Students" << endl;
	cout << "[5] Remove All Students" << endl;
	cout << "[6] Exit" << endl;
	cout << endl;

	int menuOption = 0;

	cout << "Select Option (1-6): ";
	cin >> menuOption;

	switch (menuOption)
	{
	case 1:
		AddStudentOption();
		break;
	case 2:
		RemoveStudentOption();
		break;
	case 3:
		SearchStudentOption();
		break;
	case 4:
		ShowAllStudentsOption();
		break;
	case 5:
		RemoveAllStudentsOption();
		break;
	case 6:
		cout << "Exiting Program..." << endl;
		break;
	default:
		cout << "Invalid Option Selected" << endl;
		ShowMenu();
		break;
	}
}

void Menu::AddStudentOption()
{
	cout << endl;
	cout << "------------- Add Student -------------" << endl;
	int inStudentId;
	string inStudentName;
	double inStudentGpa;

	do
	{
		cout << endl;
		cout << "Enter Student ID (Enter 0 to Exit): ";
		cin >> inStudentId;

		if (inStudentId != 0)
		{
			// validate ID is unique
			if (studentList->SearchStudent(inStudentId) != nullptr) {
				cout << "Error! Student ID already taken!" << endl;
				continue;
			}
			while ((getchar()) != '\n'); // clears buffer

			cout << "Enter Student Name: ";
			getline(cin, inStudentName);

			cout << "Enter Student GPA: ";
			cin >> inStudentGpa;

			shared_ptr<Student> inStudent(make_shared<Student>(inStudentId, inStudentName, inStudentGpa));

			studentList->InsertAtBack(inStudent);
		}
		
	} while (inStudentId != 0);
	
	ShowMenu();

}

void Menu::RemoveStudentOption()
{
	cout << endl;
	cout << "------------ Remove Student -----------" << endl;

	int inStudentId;

	do
	{
		cout << endl;
		cout << "Enter Student ID (Enter 0 to Exit): ";
		cin >> inStudentId;

		if (inStudentId != 0)
		{
			
			studentList->RemoveStudent(inStudentId);
		}

	} while (inStudentId != 0);

	ShowMenu();
}

void Menu::SearchStudentOption()
{
	cout << endl;
	cout << "------------ Search Student -----------" << endl;

	int inStudentId;
	shared_ptr<Student> student;

	do
	{
		cout << endl;
		cout << "Enter Student ID (Enter 0 to Exit): ";
		cin >> inStudentId;

		if (inStudentId != 0)
		{

			student = studentList->SearchStudent(inStudentId);
			if (student != nullptr) 
			{
				cout << endl;
				cout << "---------------------------------------" << endl;
				student->DisplayStudent();
				cout << "---------------------------------------" << endl;
			}
			else
			{
				cout << "---------------------------------------" << endl;
				cout << "Error! Student ID not found" << endl;
				cout << "---------------------------------------" << endl;
			}
				
		}

	} while (inStudentId != 0);

	ShowMenu();
}

void Menu::ShowAllStudentsOption()
{
	cout << endl;
	cout << "------- Displaying All Students -------" << endl;

	cout << endl;
	studentList->DisplayList();
	cout << endl;
	ShowMenu();
}

void Menu::RemoveAllStudentsOption()
{
	cout << endl;
	cout << "--------- Remove All Students ---------" << endl;

	// prompt the user to confirm deleting list
	cout << endl;
	cout << "Are You Sure You Want To Delete List?" << endl;
	cout << "Enter 1 to Confirm | 0 to Cancel: ";
	int confirm;
	cin >> confirm;

	if (confirm == 1)
	{
		studentList->DestroyList();
	}
	ShowMenu();
}
