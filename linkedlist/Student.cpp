#include "Student.h"

Student::Student()
{
	studentId = 0;
	studentName = "";
	studentGpa = 0.0;
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

void Student::DisplayStudent()
{
	cout << "Student ID: " << studentId << endl;
	cout << "Student Name: " << studentName << endl;
	cout << "Student GPA: " << studentGpa << endl;
}
