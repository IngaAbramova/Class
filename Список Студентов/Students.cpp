//���������� ���������� � ������������ ����
#include <iostream>
#include "Students.h"
using namespace std;
int main()
{
	//���������� ������� ���������
	setlocale(LC_ALL, "Russian");
	//������� ������������
	int comand = -1;
	cout << "1. ��������� ������ ��������� �� �����" << endl;
	cout << "2. ��������� ������ ��������� � ����" << endl;
	cout << "3. ������� ������ ��������� �� �����" << endl;
	cout << "4. ��������� ������ ��������� �� �����" << endl;
	cout << "5. ��������� ������ ��������� � ����" << endl;
	cout << "6. ������� ������ ��������� �� �����" << endl;
	cout << "7. �������� �������" << endl;
	cout << "8. ��������� ������ �������������� �� �����" << endl;
	cout << "9. ������� ������ �������������� �� �����" << endl;
	cout << "10. ��������� ������ ����� �� ������" << endl;
	cout << "11. ������� ������ ����� �� �����" << endl;
	cout << "12. �������� ������" << endl;
	cout << "13. �������� ��������" << endl;
	cout << "14. �������� �������������" << endl;
	cout << "15. ������� ��������" << endl;
	cout << "16. ������� �������������" << endl;
	cout << "0. �����" << endl;
	//������������� ������ �������
	cin >> comand;
	//�������������� ������
	List<Information> *P = new List<Information>();
	List<Prep> *F = new List<Prep>();
	List<Prep> *L = new List<Prep>();
	List<People> *T = new List<People>();
	List<Subjects> *K = new List<Subjects>();
	K->LoadSubjectsFromFile("SubjectsIn.txt");
	while (comand != 0)
	{
		//�������� ������ ��������� �� �����
		if (comand == 1)
		{
			P->LoadFromFile("StudentsIn.txt", *&K);
			cout << "C����� ��������� �������� �� �����" << endl;
		}
		//�������� ������ ��������� � ����
		if (comand == 2)
		{
			P->LoadInFile("StudentsOut.txt");
			cout << "C����� ��������� �������� � ����" << endl;
		}
		//����� ������ ��������� �� �����
		if (comand == 3)
		{
			P->LoadOnScreen();
		}
		//�������� ������ ��������� �� �����
		if (comand == 4)
		{
			cout << "C����� ��������� �������� �� �����" << endl;
		}
		//�������� ������ ��������� � ����
		if (comand == 5)
		{
			K->LoadSubjectsInFile("SubjectsOut.txt");
			cout << "C����� ��������� �������� � ����" << endl;
		}
		//����� ������ ��������� �� �����
		if (comand == 6)
		{
			K->LoadOnScreen();
		}
		//���������� ���������� �� �������� ��� ��������
		if (comand == 7)
		{
			cout << "������� ������� ��������" << endl;
			string ch;
			cin >> ch;
			cout << "������� ����� ��������" << endl;
			int number = 0;
			cin >> number;
			cout << "������� ������" << endl;
			int mark = 0;
			cin >> mark;
			P->AddExamens(ch, number, mark, K);
		}
		//�������� ������ �������������� �� �����
		if (comand == 8)
		{
			L->LoadFromFile("PrepIn.txt");//
            F->LoadFromFile("PrepIn.txt");//
			cout << "C����� �������������� �������� �� �����" << endl;
		}
		//����� ������ �������������� �� �����
		if (comand == 9)
		{
			L->LoadOnScreen();
		}
		//�������� ������ ����� �� ������
		if (comand == 10)
		{
			if ((P->Null() == 0))
			{
				P->LoadFromFile("StudentsIn.txt", *&K);
			}
			if((L->Null() == 0))
			{L->LoadFromFile("PrepIn.txt");}
			
		}
		if (comand == 11)
		{
			if ((T->Null() == 0))
			{
				if (L->Null() != 0)
				{
					if (P->Null() != 0)
					{
						T = (List<People>*)L;
						T->Soedin(P);
					}
					else T = (List<People>*)L;
				}
				else T = (List<People>*)P;
			}
			T->LoadOnScreenPeople();
		}

		if (comand == 12)
		{
			cout << "������� ������� ��������" << endl;
			string ch;
			cin >> ch;
			cout << "������� ����� ��������" << endl;
			int number = 0;
			cin >> number;
			cout << "������� ������" << endl;
			int mark = 0;
			cin >> mark;
			P->AddExamens(ch, number, mark, *&K);
		}
		if (comand == 13)
		{
			cout << "������� ������� ��������" << endl;
			string ch, m, gr;
			int b;
			cin >> ch;
			cout << "������� ��� ��������" << endl;
			cin >> m;
			cout << "������� ������� ��������" << endl;
			cin >> b;
			cout << "������� ������ ��������" << endl;
			cin >> gr;
			P->Dobstudent(ch, m, b, gr, *&K);
		}
		if (comand == 14)
		{
			cout << "������� ������� " << endl;
			string ch, m, gr;
			int b,u;
			cin >> ch;
			cout << "������� ���" << endl;
			cin >> m;
			cout << "������� �������" << endl;
			cin >> b;
			cout << "������� ���������" << endl;
			cin >> gr;
			cout << "������� ��������" << endl;
			cin >> u;
			F->DobPrep(ch, m, b, gr,u, *&K);
			L->DobPrep(ch, m, b, gr, u, *&K);
		}
		if (comand == 15)
		{
			P->Delete();
		}
		if (comand == 16)
		{
			L->Delete();
		}
		cout << "1. ��������� ������ ��������� �� �����" << endl;
		cout << "2. ��������� ������ ��������� � ����" << endl;
		cout << "3. ������� ������ ��������� �� �����" << endl;
		cout << "4. ��������� ������ ��������� �� �����" << endl;
		cout << "5. ��������� ������ ��������� � ����" << endl;
		cout << "6. ������� ������ ��������� �� �����" << endl;
		cout << "7. �������� �������" << endl;
		cout << "8. ��������� ������ �������������� �� �����" << endl;
		cout << "9. ������� ������ �������������� �� �����" << endl;
		cout << "10. ��������� ������ ����� �� ������" << endl;
		cout << "11. ������� ������ ����� �� �����" << endl;
		cout << "12. �������� ������" << endl;
		cout << "13. �������� ��������" << endl;
		cout << "14. �������� �������������" << endl;
		cout << "15. ������� ��������" << endl;
		cout << "16. ������� �������������" << endl;
		cout << "0. �����" << endl;
		cin >> comand;
	}
	system("pause");

}