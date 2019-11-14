#include "TClasster.h"
#include <iostream>

using namespace std;

int main()
{
	int CountProc, SizeQueue, CountTact;
	double p;

	cout << "Enter the count of Proccesors" << endl;
	cin >> CountProc;

	cout << "Enter the probability of occurrence of tasks (0-1)" << endl;
	cin >> p;

	cout << "Enter the size of Queue" << endl;
	cin >> SizeQueue;

	cout << "Enter the count of Tacts" << endl;
	cin >> CountTact;

	TClasster tmp;

	tmp.RunNewJob(CountProc, CountTact, SizeQueue,p);
	tmp.PrintResult();

	system("pause");
	return 0;
}