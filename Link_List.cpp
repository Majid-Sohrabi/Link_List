#include <iostream>
#include <conio.h>
#include <string>
#define Null 0
using namespace std;

class node {
public:
	string name;
	int studentNum;
	int grade1 = 0;
	int grade2 = 0;
	int grade3 = 0;
	float ave;
	node *next;
	node *pre;
	node()
	{
		name = "";
		grade1 = grade2 = grade3 = 0;
		studentNum = 0;
		next = pre = 0;
	}
	float avgcalculate()
	{
		float avg = ((grade1 + grade2 + grade3) / 3);
		return avg;
	}

}*first, *last;

void addNode() {
	system("cls");
	cout << "1.Add a student :\n\n";
	node *newptr = new node();
	if (!newptr) {
		cout << "allocation error!";
		cin.get();
	}
	newptr->next = Null;
	cout << "Name of the student : ";
	cin >> newptr->name;
	cout << "Student ID : ";
	cin >> newptr->studentNum;
	cout << "First Grade : ";
	cin >> newptr->grade1;
	cout << "Second Grade : ";
	cin >> newptr->grade2;
	cout << "Third Grade : ";
	cin >> newptr->grade3;
	if (first == Null)
		first = last = newptr;
	else {
		last->next = newptr;
		last = newptr;
	}
}

void delNode(int &no) {
	node *curptr = first, *nextptr = first;
	while (nextptr) {
		if (no == nextptr->studentNum)
			if (nextptr == first) {
				first = first->next;
				delete nextptr;
				break;
			}
			else {
				if (nextptr == last)
					last = curptr;
				curptr->next = nextptr->next;
				delete(nextptr);
				break;
			}
		else {
			curptr = nextptr;
			nextptr = nextptr->next;
		}
	}
}

void display() {

	system("cls");
	node *curptr = first;
	cout << "3.Display List: \n\n";
	cout << "Name\t" << "StudentNum\t" << "Grade1\t" << "Grade2\t" << "Grade3\t" << "Avrage\t\n";
	cout << "-------------------------------------------------------\n";
	while (1) {
		cout << curptr->name << "\t  " << curptr->studentNum << "\t  " << curptr->grade1 << "\t  " << curptr->grade2 << "\t  " << curptr->grade3 << "\t  " << curptr->avgcalculate() << "\t  \n";
		if (curptr->next == 0)
			break;
		curptr = curptr->next;
	}
	cin.get();
	cin.get();
}

void search() {
	int s = 0;
	string name;
	system("cls");
	cout << "4.Search by name :\n\n";
	cout << "Enter name to search : ";
	cin >> name;
	node *curptr = first;
	while (1)
	{
		if (!name.compare(curptr->name))
		{
			s = 1;
			break;
		}
		if (curptr->next == 0)
			break;
		curptr = curptr->next;
	}
	if (s == 1)
	{
		system("cls");
		cout << "name : " << curptr->name << "\nID : " << curptr->studentNum << "\naverage : " << curptr->avgcalculate();
	}
	else
		cout << "\nnot found!";
	cin.get();
	cin.get();
}
int menu();
int main() {

	int no;
	for (;;) {
		system("cls");
		switch (menu()) {
		case 1:
			addNode();
			break;
		case 2:
			system("cls");
			cout << "2.Delete a student:\n\n";
			cout << "Enter Student Number to delete: ";
			cin >> no;
			delNode(no);
			break;
		case 3:
			display();
			break;
		case 4:
			search();
			break;
		case 5:
			return 0;
		}
	}
}

int menu() {
	int choise;
	cout << "1.Add a student : \n";
	cout << "2.Delete a student: \n";
	cout << "3.Display List :\n";
	cout << "4.Search by name :\n";
	cout << "5.Exit :\n\n";
	cout << "Select 1-5 : ";
	cin >> choise;
	return choise;
}