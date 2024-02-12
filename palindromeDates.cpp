#include <bits/stdc++.h>
using namespace std;

const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 1800;

bool isLeap(int year)
{
	return (((year % 4 == 0)
			&& (year % 100 != 0))
			|| (year % 400 == 0));
}

bool isValidDate(int d, int m, int y)
{
	if (y > MAX_VALID_YR || y < MIN_VALID_YR)
		return false;
	if (m < 1 || m > 12)
		return false;
	if (d < 1 || d > 31)
		return false;

	if (m == 2) {
		if (isLeap(y))
			return (d <= 29);
		else
			return (d <= 28);
	}

	if (m == 4 || m == 6 || m == 9 || m == 11)
		return (d <= 30);

	return true;
}

void printPalindromeDates(int y1, int y2)
{
	for (int year = y1; year <= y2; year++) {

		string str = to_string(year);

		string rev = str;
		reverse(rev.begin(), rev.end());

		int day = stoi(rev.substr(0, 2));
		int month = stoi(rev.substr(2, 2));

		if (isValidDate(day, month, year)) {
			cout << rev.substr(0,2) << "-"<< rev.substr(2,3) << "-" << str << endl;
		}
	}
}


int main(){

//Program to find all the Palindrome dates that come between the year 01-01-2001 till 31-12-2021. eg. 10-02-2001
	int y1 = 2001, y2 = 2021;
	printPalindromeDates(y1, y2);
    return 0;
}