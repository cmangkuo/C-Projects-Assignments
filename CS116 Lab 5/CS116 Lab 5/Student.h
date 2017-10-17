#pragma once
#include "Course.h"
#include <string>
#include <vector>
using namespace std;

class Student
{
private:
	string name;
	int idNumber;
	vector<Course> VectorOfCourses;
public:
	Student();
	Student(string, int);
	void setName();
	void setID();
	void setID(int);
	string getName() { return name; }
	int getID() { return idNumber; }
	void addCourse();
	double getGPA();
	void printTranscript();
};

