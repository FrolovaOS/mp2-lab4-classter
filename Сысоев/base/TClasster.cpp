#include "TClasster.h"
#include <iostream>
#include <ctime>
#include "iomanip"

TClasster::TClasster()
{
	CountTask = 0;
	CountCompleteTask = 0;
	CountNotCompleteTask = 0;
	CountTaskError = 0;
	LoadProc = 0;
	pTact = 0;
}

TClasster::~TClasster()
{
	if (masProc!=nullptr) delete[] masProc;
}

void TClasster::RunNewJob(int _Proc, int _tact, int _size,double _p)
{
	Proc = _Proc;
	tact = _tact;
	pTact = 1 -_p;
	CountFreeProc = Proc;
	masProc = new int[Proc];
	for (int i = 0; i < Proc; i++)
	{
		masProc[i] = 0;
	}
	TQueue<Task> q2ue(_size);
	Process(q2ue);
}

void TClasster::Process(TQueue<Task>& q2ue)
{
	for (int i = 0; i < tact; i++)
	{
		Task Task;
		Task = TaskGeneration(Task);
		
		 if (Task.CountProc != 0)
		{
			 CountTask++;
			if (Task.CountProc > Proc) CountTaskError++;
			else q2ue.Push(Task);
		}
		
		
		if (!q2ue.IsEmpty())
		{
			int CountProc = q2ue.GetTop().CountProc;
			int CountTact = q2ue.GetTop().tacts;
			int ChangeCountProc = CountProc;

			if (CountFreeProc >= CountProc)
			{
				for (int i = 0; i < Proc; i++)
				{
					if ((masProc[i] == 0) && (ChangeCountProc > 0))
					{
						masProc[i] = CountTact + 1;
						ChangeCountProc--;
					}
					if (ChangeCountProc == 0)break;
				}
				CountFreeProc -= CountProc;
				q2ue.Pop().CountProc;
			}
		}
		
		for (int i = 0; i < Proc; i++)
		{
			if (masProc[i] > 0)
			{
				masProc[i]--;
				if (masProc[i] == 0)
				{
					CountFreeProc++;
				}
			}
		}
		LoadProc  += (Proc - CountFreeProc);
	}
	CountNotCompleteTask = q2ue.TQueueLength();
}

Task TClasster::TaskGeneration(Task k)
{
	srand((unsigned int)time(NULL));
	double r = (double)(rand() % 100) / 100;
	if (r >= pTact)
	{
		k.CountProc = rand() % (Proc * 1,3 ) + 1;
		k.tacts = rand() % (tact * 1,1) + 1;
	
	}
	else k.CountProc=0;
	return k;
}

void TClasster::PrintResult()
{
	CountCompleteTask = CountTask - (CountNotCompleteTask + CountTaskError);
	cout << "Count of generation task: " << setw(10)  << CountTask << endl;
	cout << "Count of Complete task: " << setw(12) << CountCompleteTask << endl;
	cout << "Count of Not Complete task: " << setw(8) << CountNotCompleteTask << endl;
	cout << "Count of task error: " << setw(15) << CountTaskError << endl;
	cout << "Average load processors: " << setw(10) << LoadProc / tact + 1 << " of " <<Proc<< endl;
}
