#include "Student.h"

Student::Student()
{
	studentId = 0;
	studentName = "";
	studentGpa = 0.0;
}

Student::~Student()
{
	/*cout << endl;
	cout << "Student: " << studentId << " is deleted" << endl;
	cout << endl;*/
}

Student::Student(int inStudentId, string inStudentName, double inStudentGpa)
{
	studentId = inStudentId;
	studentName = inStudentName;
	studentGpa = inStudentGpa;
}

int Student::GetStudentId()
{
	return studentId;
}

string Student::GetStudentName()
{
	return studentName;
}

void Student::DisplayStudent()
{
	cout << "Student ID: " << studentId << endl;
	cout << "Student Name: " << studentName << endl;
	cout << "Student GPA: " << studentGpa << endl;
}
