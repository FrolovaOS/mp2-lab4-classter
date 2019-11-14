#ifndef __TClasster_H__
#define __TClasster_H__

#include <string>
#include "TQueue.h"

using namespace std;

struct Task
{
	int CountProc = 0;
	int tacts = 0;
};


class TClasster
{
private:
	int Proc;					//количество процессоров
	int* masProc;				//массив процессоров
	int CountFreeProc;			//количество занятых процессоров
	int CountTask;				//число появившихся задач
	int CountCompleteTask;		// число выполненных задач
	int CountNotCompleteTask;	//число невыполненых задач (остались в очереди после прерывания)
	int CountTaskError;			//число задач с отказом (не хватает процессоров)
	int LoadProc;				//количество занятых процессоров на каждом такте
	int tact;					//время выполнения программы
	double pTact;				//вероятность появления задач
public:
	TClasster();
	~TClasster();
	void RunNewJob(int _Proc, int _tact, int _size, double _p); 
	void Process(TQueue<Task>& q2ue);				
	Task TaskGeneration(Task k);
	void PrintResult();

};
#endif