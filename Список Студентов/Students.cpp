//Подключаем библиотеку и заголовочный файл
#include <iostream>
#include "Students.h"
using namespace std;
int main()
{
	//Используем русскую раскладку
	setlocale(LC_ALL, "Russian");
	//Команда пользователя
	int comand = -1;
	cout << "1. Загрузить список студентов из файла" << endl;
	cout << "2. Загрузить список студентов в файл" << endl;
	cout << "3. Вывести список студентов на экран" << endl;
	cout << "4. Загрузить список предметов из файла" << endl;
	cout << "5. Загрузить список предметов в файл" << endl;
	cout << "6. Вывести список предметов на экран" << endl;
	cout << "7. Добавить экзамен" << endl;
	cout << "8. Загрузить список преподавателей из файла" << endl;
	cout << "9. Вывести список преподавателей на экран" << endl;
	cout << "10. Загрузить список людей из файлов" << endl;
	cout << "11. Вывести список людей на экран" << endl;
	cout << "12. Изменить оценку" << endl;
	cout << "13. Добавить студента" << endl;
	cout << "14. Добавить преподавателя" << endl;
	cout << "15. Удалить студента" << endl;
	cout << "16. Удалить преподавателя" << endl;
	cout << "0. Выйти" << endl;
	//Пользоватедль вводит команду
	cin >> comand;
	//Инициализируем списки
	List<Information> *P = new List<Information>();
	List<Prep> *F = new List<Prep>();
	List<Prep> *L = new List<Prep>();
	List<People> *T = new List<People>();
	List<Subjects> *K = new List<Subjects>();
	K->LoadSubjectsFromFile("SubjectsIn.txt");
	while (comand != 0)
	{
		//Загрузка списка студентов из файла
		if (comand == 1)
		{
			P->LoadFromFile("StudentsIn.txt", *&K);
			cout << "Cписок студентов загружен из файла" << endl;
		}
		//Загрузка списка студентов в файл
		if (comand == 2)
		{
			P->LoadInFile("StudentsOut.txt");
			cout << "Cписок студентов загружен в файл" << endl;
		}
		//Вывод списка студентов на экран
		if (comand == 3)
		{
			P->LoadOnScreen();
		}
		//Загрузка списка предметов из файла
		if (comand == 4)
		{
			cout << "Cписок предметов загружен из файла" << endl;
		}
		//Загрузка списка предметов в файл
		if (comand == 5)
		{
			K->LoadSubjectsInFile("SubjectsOut.txt");
			cout << "Cписок предметов загружен в файл" << endl;
		}
		//Вывод списка предметов на экран
		if (comand == 6)
		{
			K->LoadOnScreen();
		}
		//Добавление информации об экзамене для студента
		if (comand == 7)
		{
			cout << "Введите фамилию студента" << endl;
			string ch;
			cin >> ch;
			cout << "Введите номер предмета" << endl;
			int number = 0;
			cin >> number;
			cout << "Введите оценку" << endl;
			int mark = 0;
			cin >> mark;
			P->AddExamens(ch, number, mark, K);
		}
		//Загрузка списка преподавателей из файла
		if (comand == 8)
		{
			L->LoadFromFile("PrepIn.txt");//
            F->LoadFromFile("PrepIn.txt");//
			cout << "Cписок преподавателей загружен из файла" << endl;
		}
		//Вывод списка преподавателей на экран
		if (comand == 9)
		{
			L->LoadOnScreen();
		}
		//Загрузка списка людей из файлов
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
			cout << "Введите фамилию студента" << endl;
			string ch;
			cin >> ch;
			cout << "Введите номер предмета" << endl;
			int number = 0;
			cin >> number;
			cout << "Введите оценку" << endl;
			int mark = 0;
			cin >> mark;
			P->AddExamens(ch, number, mark, *&K);
		}
		if (comand == 13)
		{
			cout << "Введите фамилию студента" << endl;
			string ch, m, gr;
			int b;
			cin >> ch;
			cout << "Введите имя студента" << endl;
			cin >> m;
			cout << "Введите возраст студента" << endl;
			cin >> b;
			cout << "Введите группу студента" << endl;
			cin >> gr;
			P->Dobstudent(ch, m, b, gr, *&K);
		}
		if (comand == 14)
		{
			cout << "Введите фамилию " << endl;
			string ch, m, gr;
			int b,u;
			cin >> ch;
			cout << "Введите имя" << endl;
			cin >> m;
			cout << "Введите возраст" << endl;
			cin >> b;
			cout << "Введите должность" << endl;
			cin >> gr;
			cout << "Введите зарплату" << endl;
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
		cout << "1. Загрузить список студентов из файла" << endl;
		cout << "2. Загрузить список студентов в файл" << endl;
		cout << "3. Вывести список студентов на экран" << endl;
		cout << "4. Загрузить список предметов из файла" << endl;
		cout << "5. Загрузить список предметов в файл" << endl;
		cout << "6. Вывести список предметов на экран" << endl;
		cout << "7. Добавить экзамен" << endl;
		cout << "8. Загрузить список преподавателей из файла" << endl;
		cout << "9. Вывести список преподавателей на экран" << endl;
		cout << "10. Загрузить список людей из файлов" << endl;
		cout << "11. Вывести список людей на экран" << endl;
		cout << "12. Изменить оценку" << endl;
		cout << "13. Добавить студента" << endl;
		cout << "14. Добавить преподавателя" << endl;
		cout << "15. Удалить студента" << endl;
		cout << "16. Удалить преподавателя" << endl;
		cout << "0. Выйти" << endl;
		cin >> comand;
	}
	system("pause");

}