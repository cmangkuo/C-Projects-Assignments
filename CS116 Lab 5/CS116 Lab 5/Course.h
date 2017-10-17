#pragma once

#include <string>
using namespace std;
class Course
{
private:
	string CourseID;
	int Credits;
	char Grade;
public:
	Course();
	Course(string, int, char);
	void setCourse();
	void setCredits();
	void setGrade();
	string getCourse() { return CourseID; }
	int getCredits() { return Credits; }
	char getGrade() { return Grade; }
};

