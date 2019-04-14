#pragma once
#ifndef Students
#define Students
#include <iostream>
#include <fstream>
#include <string>
#define NAMESIZE_MAX 225
#define NAMESIZE 20
using namespace std;
class Information;
class GradesForTheExam;
class Subjects;
template <class T>
//������ ������
class List
{
	friend class People;
	friend class List<Information>;
	friend class List<GradesForTheExam>;
	friend class Information;
	friend class GradesForTheExam;
	friend class List<People>;
	friend class Prep;
	List<T> *next;
	T data;
	// �����������
	List(T & v) { data = v; next = NULL; }
public:
	List<T> *get_next() { return next; }
	T get_data() { return data; }
	// ���������e �������� 
	void AddExamens(string ch, int number, int mark, List<Subjects> *);
	void AddExam(string ch, int number, int mark, List<Subjects> *&);
	void LoadInFile(const char *PrepOut);
	void WriteExamens(std::ofstream &f);
	void LoadOnScreen();
	void WriteExamensOnScreen();
	int LoadFromFile(const char *StudentsIn, List<Subjects> *&);
	int LoadFromFile(const char *PrepIn);
	int Dobstudent(string ch, string m, int b, string gr, List<Subjects> *&R);
	int DobPrep(string ch, string m, int b, string gr, int p, List<Subjects> *&R);
	int ReadExamens(int Exames, std::ifstream &f, List<Subjects> *&);
	int LoadSubjectsFromFile(const char *SubjectsIn);
	void LoadSubjectsInFile(const char *SubjectsOut);
	void Delete();
	void LoadOnScreenPeople();
	float Avg();
	int Null() { if (next == NULL) return 0; else return 1; };
	void LoadFromList(List<T> *&H);
	void Soedin(List<Information> *P)
	{
		List<People> *q;
		for (q = this->next; q->next != NULL; q = q->next)
		{
		}
		q->next = (List<People>*)P;
	};
	//�����������
	List()
	{
		next = NULL;
	};
	//����������
	~List()
	{
		//if (next != NULL) delete next;
	};
	//������� ���������� ������� � ������
	void AddElements(T &c)
	{
		List *p, *q;
		p = new List(c);
		q = this;
		p->next = q->next;
		q->next = p;
	};	
};
//����
class People
{
	string Fam;
	string Name;
	int Age;
public:
	int ReadPeople(People *a, std::ifstream &f/*, List<Subjects> *&R*/);
	void  WritePeople(std::ofstream &f);
	string get_Fam() { return Fam; }
	void set_Fam(string name) { Fam = name; }
	string get_Name() { return Name; }
	void set_Name(string nam) { Name = nam; }
	void set_Age(int Agv) { Age = Agv; }
	int get_Age() { return Age; }
	virtual void  WriteOnScreenPeople()
	{
		this->WriteOnScreenPeople();
		if (this->Fam != "NONAME"&& this->Fam != ""&&(this->get_Name().length()) != 0)
		{
			cout << "������� - " << this->Fam << "\n";
			cout << "��� - " << this->Name << "\n";
			cout << "������� - " << this->Age << "\n";
		}
	}
	People()
	{
		string Fam = "NONAME";
		string Name = "NONAME";
		int Age = 0;
	};
	People(string ch, string m, int b)
	{
		set_Fam(ch);
		set_Name(m);
		set_Age(b);
	};
	~People()
	{

	};
};
//���������
class Worker
{
	//��������
	int Salary;
	//���������
	string Post;
public:
	int ReadWorkers(Worker *a, std::ifstream &f);
	string get_Post() { return Post; }
	void set_Post(string P) { Post = P; }
	void set_Salary(int Sal) { Salary = Sal; }
	int get_Salary() { return Salary; }
	 void  WriteOnScreenWorkers()
	{
		if (this->Post != "NONAME"&& this->Post != "" && (this->get_Post().length()) != 0)
		{
			cout << "��������� - " << this->Post << "\n";
			cout << "�������� - " << this->Salary << "\n";
		}
	}
	Worker()
	{
		int Salary = 0;
		string Post = "NONAME";
	}
	Worker(string gr, int s)
	{	
		set_Post(gr);
		set_Salary(s);
	}
	~Worker()
	{

	};
};

//���������� � ��������: ������ � ������� ����
class Information :public People
{
	//string StudentName;
	int  CountOfExam;
	float Avg;
	List<GradesForTheExam> *pass;
	string Group;
public:
	string get_Group() { return Group; }
	void set_Group(string name) { Group = name; }
	List<GradesForTheExam> *get_pass() { return pass; };
	void set_pass(List<GradesForTheExam> *pass) { this->pass = pass; }
	void set_avg(float avg) { Avg = avg; }
	float get_avg() { return Avg; }
	void  WriteOnScreenPeople();
	void WriteStudent(std::ofstream &f);
	void WriteOnScreenStudent();
	void DeleteExams();
	int  ReadStudent(Information *a, std::ifstream &f, List<Subjects> *&);
	//�����������
	Information()
	{
		CountOfExam = 0;
		Avg = 0;
		pass = NULL;
	};
	Information(string ch, string m, int b, string gr) : People(ch, m, b)
	{
		Group = gr;
		CountOfExam = 0;
		Avg = 0;
		pass = NULL;
	};
	//����������
	~Information()
	{
		DeleteExams();
	};
};
//�������������
class Prep :public People, public Worker
{
public:
	void WriteOnScreenPeople();
    Prep()
	{
	
	}
	Prep(string ch, string m, int b, string gr, int s): People (ch,  m,  b), Worker( gr,  s)
	{
		
	}
	~Prep()
	{

	};
};
//������ �� �������� ��� ��������
class GradesForTheExam
{
	int subject;
	List<Subjects> *Sub;
	int mark;
public:
	int get_subject() { return subject; }
	void set_subject(int subject) { this->subject = subject; }
	int get_mark() { return mark; }
	void set_mark(int mark) { this->mark = mark; }
	List<Subjects> *get_sub() { return Sub; }
	void set_sub(List<Subjects> *Sub) { this->Sub = Sub; }
	int  ReadExam(std::ifstream &f, List<Subjects> *&);
	void WriteExam(std::ofstream &f);
	void WriteExamOnScreen();
	GradesForTheExam()
	{
		subject = 0;
		mark = 0;
	};
	~GradesForTheExam()
	{
	};
};

//���������� � ��������: ����� � ��������
class Subjects
{
	friend class List<Information>;
	friend class List<GradesForTheExam>;
	friend class Information;
	friend class GradesForTheExam;
	friend int List<Information>::LoadFromFile(const char *StudentsIn, List<Subjects> *&R);
	friend int Information::ReadStudent(Information *a, std::ifstream &f, List<Subjects> *&R);
	friend int List<GradesForTheExam>::ReadExamens(int Exames, std::ifstream &f, List<Subjects> *&R);
	friend int  GradesForTheExam::ReadExam(std::ifstream &f, List<Subjects> *&R);
public:
	int NumberOfSubject;
	char NameOfSubject[20];
	//�����������
	Subjects()
	{
		NumberOfSubject = 0;
		strcpy_s(NameOfSubject, "NONAME");
	};
	//����������
	~Subjects()
	{
	};
	int ReadSubject(std::ifstream &f);
	void  WriteSubjects(std::ofstream &f);
	void WriteSubjectsOnScreen();
};


//////////////////////������� � ������//////////////////////
//������� �������� ������ ��������� �� �����
template<>
int List<Information>::LoadFromFile(const char *StudentsIn, List<Subjects> *&R)
{
	std::ifstream f_in(StudentsIn);
	int n = 0;//�������� ������� ���������
	while (f_in)//���� ���� ����������
	{
		Information a;
		int flag = this->data.ReadPeople(&a, f_in);
		flag = this->data.ReadStudent(&a, f_in, *&R); //����� ������� ��� ����� ���������� �������� �� �����
		if (!flag) // ��������� ���� �� �������� ���� ��� flag == 0
		{
			this->AddElements(a); n++;
		}
		else break;
	}
	f_in.close();
	return n;
}
//������ ���������� �� ����� ������� �� �����
int People::ReadPeople(People *a, std::ifstream &f)
{
	int flag = 1; //��� ���������� �� �����
	try
	{
		f >> a->Fam;
		if (a->get_Fam().length() == 0) return 1; //��������� ������ ������
		f >> a->Name;
		if (a->get_Name().length() == 0) return 1;
		int n;
		f >> n;
		a->set_Age(n);

	}
	catch (...)
	{
		return 1;
	}

}
//������ ���������� �� ����� �������� �� �����
int Information::ReadStudent(Information *a, std::ifstream &f, List<Subjects> *&R)
{
	int flag = 1; //��� ���������� �� �����
	try
	{
		f >> (a->Group);
		if (a->get_Group().length() == 0) return 1;
		f >> (a->CountOfExam);
		float n = a->CountOfExam;
		List<GradesForTheExam> *b = new List<GradesForTheExam>();
		a->Avg = b->ReadExamens(a->CountOfExam, f, *&R) / n;
		a->pass = b;
		return 0;
	}
	catch (...)
	{
		return 1;
	}
}
//������� ���������� n ��������� � ���������� �� ������ ������
template<>
int List<GradesForTheExam>::ReadExamens(int Exames, std::ifstream &f, List<Subjects> *&R)
{
	int n = 0;
	for (int i = 0; i < Exames; i++)
	{
		GradesForTheExam a;
		int flag = a.ReadExam(f, *&R); //����� ������� ��� ����� � ���������� (�) ���������� �������� �� ����� (f)
		if (flag)
		{
			AddElements(a);
			n += flag;
		}
		else break;
	}
	return n;
}
//������� ���������� ������ ��������
int  GradesForTheExam::ReadExam(std::ifstream &f, List<Subjects> *&R)
{
	f >> (this->subject);//��������� �� ����� f ����� ��������
	f >> (this->mark);//��������� �� ����� f ������
	int n = this->mark;
	List<Subjects> *q = R;
	for (q = R->next; q != NULL; q = q->next)
	{
		//���������� ����� �������� �� ������ ��������� � ������� �������� �� ������ ��������� ��� ������� ��������
		if (this->subject == (q->data).NumberOfSubject)
		{
			this->Sub = q;
		}
	}
	return n;
}
//������� �������� ������ � ����
template<>
void List<Information>::LoadInFile(const char *PrepOut)
{
	std::ofstream f_out;
	f_out.open(PrepOut, std::ios::app);
	f_out << "	������ \n\n������:\n\n";
	List<Information> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		q->data.WritePeople(f_out);
		q->data.WriteStudent(f_out);
	}
	f_out << "\n�����\n\n";
}
//������ � ���� ���������� �� ����� ��������
void   People::WritePeople(std::ofstream &f)
{
	if (this->Fam != "NONAME"&&this->Fam != "")
		//������� ������� ������������ ������� 
	{
		f << "������� - " << this->Fam << "\n";
		f << "��� - " << this->Name << "\n";
		f << "�������- " << this->Age << "\n";
	}
}
//������� ������ � ���� ���������� � ��������
void   Information::WriteStudent(std::ofstream &f)
{
	f << "������- " << this->Group << "\n";
	f << "������� ���� - " << this->Avg << "\n";
	if (this->pass != NULL)
	{
		this->pass->WriteExamens(f);
		f << "\n";
	}
}
//������� ������ � ���� ������ ��������� ��� ������ ��������
template<>
void List<GradesForTheExam>::WriteExamens(std::ofstream &f)
{
	List<GradesForTheExam> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		q->data.WriteExam(f);
	}
}
//������� ������ � ���� ���������� �� ��������
void GradesForTheExam::WriteExam(std::ofstream &f)
{
	Subjects su;
	su = (this->Sub)->data;
	f << this->subject << " {" << su.NameOfSubject << "}(" << this->mark << ");";
}
//������� ������ ������� �� �����
template<>
void List<Information>::LoadOnScreen()
{
	cout << "	������ ���������\n\n������:\n\n";
	List<Information> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		{
			q->data.WriteOnScreenPeople();
			cout << endl;
		}
	}
	cout << "\n�����\n\n";
}
//������� ������ ���������� �� ����� �������� �� �����
void  Information::WriteOnScreenPeople()
{
	if (this->get_Age() != 0)
	{
		cout << "������� - " << this->get_Fam() << "\n";
		cout << "��� - " << this->get_Name() << "\n";
		cout << "������� - " << this->get_Age() << "\n";
		cout << "������ - " << this->Group << "\n";
		cout << "������� ���� - " << this->Avg << "\n";
		if (this->pass != NULL)
		{
			this->pass->WriteExamensOnScreen();
		}
		cout << endl;
	}
}
//����� �� ����� ������ ��������� ��� ���������
template<>
void List<GradesForTheExam>::WriteExamensOnScreen()
{
	List<GradesForTheExam> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		q->data.WriteExamOnScreen();
	}
}
//����� �� ����� ���������� �� ����� ��������
void GradesForTheExam::WriteExamOnScreen()
{
	cout << this->subject << " " << Sub->data.NameOfSubject << " " << "(" << this->mark << ");";
}
//������� �������� ������ ��������� � ����
template<>
void List<Subjects>::LoadSubjectsInFile(const char *SubjectsOut)
{
	std::ofstream f_out;
	f_out.open(SubjectsOut, std::ios::app);
	f_out << "	������ ���������\n\n������:\n\n";
	List<Subjects> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		q->data.WriteSubjects(f_out);
	}
	f_out << "\n�����\n\n";
}
//������� �������� ���������� �� ����� �������� 
void   Subjects::WriteSubjects(std::ofstream &f)
{
	f << "����� - " << this->NumberOfSubject << "\n";
	f << "�������� - " << this->NameOfSubject << "\n";
	f << "\n";
}
//������� ��� ������ ������ ��������� �� �����
template<>
void List<Subjects>::LoadOnScreen()
{
	cout << "	������ ���������\n\n������:\n\n";
	List<Subjects> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		q->data.WriteSubjectsOnScreen();
	}
	cout << "\n�����\n\n";
}
//������� ��� ������ ���������� �� ����� �������� �� �����
void   Subjects::WriteSubjectsOnScreen()
{
	cout << "�������� - " << this->NameOfSubject << " ";
	cout << "����� - " << this->NumberOfSubject << "\n";
	cout << "\n";
}
//���������� �������� ��� ��������
void List<Information>::AddExamens(string ch, int number, int mark, List<Subjects> *L)
{
	List<Information> *q = new List<Information>();
	for (q = this->next; q != NULL; q = q->next)
	{
		if (ch == (q->data).get_Fam())
		{
			List<GradesForTheExam> *b = new List<GradesForTheExam>();
			b = q->data.get_pass();
			int flag = 0;
			if (b != NULL)
			{
	while (b != NULL)
				{
					if (number == b->data.get_subject()) { b->data.set_mark(mark); flag++; };
					b = b->next;
				}
				if (flag == 0)
				{
					q->data.get_pass()->AddExam(ch, number, mark, *&L);
				}
				q->data.set_avg(q->data.get_pass()->Avg());
			}
			else
			{
				b = new List<GradesForTheExam>();
				b->AddExam(ch, number, mark, *&L);
				q->data.set_pass(b);
				q->data.set_avg(q->data.get_pass()->Avg());
			}
		}
	}
}
//���������� ��������
template<>
void List<GradesForTheExam>::AddExam(string ch, int number, int mark, List<Subjects> *&L)
{
	GradesForTheExam W;
	W.set_subject(number);
	W.set_mark(mark);
	List<Subjects> *q = L;
	for (q = L->next; q != NULL; q = q->next)
	{
		//���������� ����� �������� �� ������ ��������� � ������� �������� �� ������ ��������� ��� ������� ��������
		if (number == (q->data).NumberOfSubject)
		{
			W.set_sub(q);
			AddElements(W);
		}
	}
}
//���������� �������� �����
template<>
float List<GradesForTheExam>::Avg()
{
	float  sum = 0;
	int n = 0;
	List<GradesForTheExam> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		sum = sum + q->get_data().get_mark();
		n++;
	}
	sum = sum / n;
	return sum;
}
//������� ��� �������� ������ �������������� �� �����
int List<Prep>::LoadFromFile(const char *PrepIn)
{
	std::ifstream f_in(PrepIn);
	int n = 0;//�������� ������� ���������
	while (f_in)//���� ���� ����������
	{
		Prep a;
		int flag = this->data.ReadPeople(&a, f_in);
		flag = this->data.ReadWorkers(&a, f_in);
		if (!flag) // ��������� ���� �� �������� ���� ��� flag == 0
		{
			this->AddElements(a); n++;
		}
		else break;
	}
	f_in.close();
	return n;
}
//������� ��� �������� ��������� �� ����� ��������� �� �����
int Worker::ReadWorkers(Worker *a, std::ifstream &f)
{
	int flag = 1; //��� ���������� �� �����
	try
	{
		f >> a->Post;
		if (a->get_Post().length() == 0) return 1;//��������� ������ ������
		f >> a->Salary;
		if (a->get_Salary() == 0) return 1;
		return 0;
	}
	catch (...)
	{
		return 1;
	}
}
//������� ��� ������ ������ �������������� �� �����
void List<Prep>::LoadOnScreen()
{
	cout << "	������ ��������������\n\n������:\n\n";
	List<Prep> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		if (((q->data.get_Fam().length()) != 0) && (q->data.get_Post().length()) != 0)
		{
			q->data.WriteOnScreenPeople();
		}
	}
	cout << "\n�����\n\n";
}
//���������� ������ ��������
int List<Information>::Dobstudent(string ch, string m, int b, string gr, List<Subjects> *&R)
{
	int flag = 0;
	List<Information> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		if ((q->data.get_Fam() == ch) && (q->data.get_Name() == m) && (q->data.get_Age() == b) && (q->data.get_Group() == gr))
		{
			cout << "����� ������� ��� ����." << endl;
			flag = 1;
		}
	}
	if (flag == 0)
	{
		int n = 0;//�������� ������� ���������
		Information a(ch, m, b, gr);
		this->AddElements(a); n++;
		return n;
	}
}
//���������� �������������
int List<Prep>::DobPrep(string ch, string m, int b, string gr, int p, List<Subjects> *&R)
{
	int flag = 0;
	List<Prep> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		if ((q->data.get_Fam() == ch) && (q->data.get_Name() == m) && (q->data.get_Age() == b) && (q->data.get_Post() == gr))
		{
			cout << "����� ������������� ��� ����." << endl;
			flag = 1;
		}
	}
	if (flag == 0)
	{
		int n = 0;//�������� ������� ���������
		Prep a(ch, m, b, gr, p);
		this->AddElements(a); n++;
		return n;
	}
}
//��������
template <class T>
void List<T>::Delete()
{
	string s_name;
	cout << "������� ������� " << endl;
	cin >> s_name;
	List<T> *res;
	List<T> *U = this->next;
	while (U != NULL)
	{//�������� ������� ��� ������ �����

		if ((U->data).get_Fam() == s_name)
			break;
		U = U->next;
	}
	res = U;
	if (res == NULL)
	{
		cout << "������� �� ������.\n";
		return;
	}
	List<T> *a, *p;
	for (a = this; (a->next != NULL) && (a->next != res); a = a->next);
	if (a->next == NULL) return;
	p = a->next; a->next = p->next;
	p->next = NULL;
	///p->data.DeleteExams();
	delete p;
}
template<>
void List<People>::LoadOnScreenPeople()
{
	List<People> *q;
	for (q = this->next; q != NULL; q = q->next)
	{
		if ((q->data.get_Fam().length()) != 0)
			q->data.WriteOnScreenPeople();
	}
}

template<>
int List<Subjects>::LoadSubjectsFromFile(const char *SubjectsIn)
{
	std::ifstream fin(SubjectsIn);
	int number = 0;
	while (fin)
	{
		Subjects subject;
		int flag = subject.ReadSubject(fin);
		if (!flag)
		{
			AddElements(subject);
			number++;
		}
		else break;
	}
	return number;
}
//������� �������� ���������� �� ����� �������� 
int  Subjects::ReadSubject(std::ifstream &f)
{
	try
	{
		f >> (NumberOfSubject);
		f >> (NameOfSubject);
		if (strlen(NameOfSubject) == 0) return 1;
		return 0;
	}
	catch (...)
	{
		return 1;
	}
}
void Information::DeleteExams()
{
	pass->~List();
}
void Prep::WriteOnScreenPeople()
{
	if ((this->get_Age() != 0) && (&(this->get_Fam()) != 0))
	{
		cout << "������� - " << this->get_Fam() << "\n";
		cout << "��� - " << this->get_Name() << "\n";
		cout << "������� - " << this->get_Age() << "\n";
		this->WriteOnScreenWorkers();
	}
}
#endif