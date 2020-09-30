#pragma once

#include <iostream>

using namespace std;

class Student
{
public:
	Student();
	Student(int inStudentId, string inStudentName, double inStudentGpa);
	int GetStudentId();
	void DisplayStudent();

private:
	int studentId;
	string studentName;
	double studentGpa;

};

