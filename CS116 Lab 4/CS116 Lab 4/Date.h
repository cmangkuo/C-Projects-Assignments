#pragma once
class Date
{
private:
	int month, day, year;
public:
	Date();
	Date(int, int, int);
	bool setDate(int, int, int);
	void getDate(int&, int&, int&);
	void printShort();
	void printLong();
	bool isEqual(Date);
	void increment();
	void decrement();
	int checkDays(int, int);
};

