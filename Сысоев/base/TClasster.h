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
	int Proc;					//���������� �����������
	int* masProc;				//������ �����������
	int CountFreeProc;			//���������� ������� �����������
	int CountTask;				//����� ����������� �����
	int CountCompleteTask;		// ����� ����������� �����
	int CountNotCompleteTask;	//����� ������������ ����� (�������� � ������� ����� ����������)
	int CountTaskError;			//����� ����� � ������� (�� ������� �����������)
	int LoadProc;				//���������� ������� ����������� �� ������ �����
	int tact;					//����� ���������� ���������
	double pTact;				//����������� ��������� �����
public:
	TClasster();
	~TClasster();
	void RunNewJob(int _Proc, int _tact, int _size, double _p); 
	void Process(TQueue<Task>& q2ue);				
	Task TaskGeneration(Task k);
	void PrintResult();

};
#endif