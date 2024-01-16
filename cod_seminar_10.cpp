#include <iostream>
#include <string>
using namespace std;

class Date {
	int day;
	int month;
	int year;

public:
	Date() : day(0), month(0), year(0) {}
	Date(int d, int m, int y) : day(d), month(m), year(y) {}
};

class Person {
	string name;
	string pin;
	Date birthday;
	string* addresses;
	int addCount;

public:
	Person() {
		this->name = "";
		this->pin = "";
		Date d;
		this->birthday = d;
		this->addresses = nullptr;
		this->addCount = 0;

	}

	Person(string name, string pin, Date birthday, string* addresses, int addCount) :
		addCount(addCount)
	{
		this->name = name;
		this->pin = pin;
		this->birthday = birthday;
		this->addresses = new string[addCount];
		for (int i = 0; i < addCount; i++)
		{
			this->addresses[i] = addresses[i];
		}
	}

	//constr de copiere

	Person(const Person& p) 

	{
		this->name = p.name;
		this->pin = p.pin;
		this->birthday = p.birthday;
		if (p.addresses != nullptr && p.addCount>0)
		{
			this->addCount = p.addCount;
			this->addresses = new string[p.addCount];
			for (int i = 0; i < p.addCount; i++)
			{
				this->addresses[i] = p.addresses[i];
			}
		}
		else
		{
			this->addresses = nullptr;
			this->addCount = 0;
		}

		//this->addresses= new string[p.addCount];
		//for (int i = 0; i < p.addCount; i++)
		//{
		//	this->addresses[i] = p.addresses[i];
		//}
	}


	//op =
	Person& operator=(const Person& p)
	{
		if (this!= &p)
		{
			this->name = p.name;
			this->pin = p.pin;
			this->birthday = p.birthday;
			this->addCount = p.addCount;
			delete[]this->addresses;
			this->addresses = new string[p.addCount];
			for (int i = 0; i < p.addCount; i++)
			{
				this->addresses[i] = p.addresses[i];
			}
		}
		return *this;
	}

	//destructor
	~Person()
	{
		delete[]this-> addresses;
	}
};

class Student:Person {
	int regNum;
	float* grades;
	int gradesCount;
	bool scholarship;

public:
	Student() :Person()
	{
	this->regNum = 0;
	this->grades = nullptr;
	this->gradesCount = 0;
	this->scholarship = false;
	}
	
	Student(string name, string pin, Date birthday, string* addresses, int addCount, int regNum, float* grades, int gradesCount, bool scholarship):
		Person(name, pin, birthday, addresses, addCount), regNum(regNum), gradesCount(gradesCount), scholarship(scholarship)
	{
		this->grades = new float[gradesCount];
		for (int i = 0; i < gradesCount; i++)
		{
			this->grades[i] = grades[i];
		}
	}

	//constr de copiere
	Student(const Student& s)
	{
		this->regNum = s.regNum;
		this->gradesCount = s.gradesCount;
		this->scholarship = s.scholarship;
		this->grades = new float[s.gradesCount];
		for (int i = 0; i < s.gradesCount; i++)
		{
			this->grades[i] = s.grades[i];
		}

	}

	//op=
	Student& operator=(const Student& s)
	{
		if (this != &s)
		{
			this->regNum = s.regNum;
			this->gradesCount = s.gradesCount;
			this->scholarship = s.scholarship;
			this->grades = new float[s.gradesCount];
			for (int i = 0; i < s.gradesCount; i++)
			{
				this->grades[i] = s.grades[i];
			}
		}
		return *this;
	}


	//destructor
	~Student()
	{
		delete[]this-> grades;
	}
};

class University{
	string name = "";
	string address = "";
	Student* students = nullptr;
	int studCount = 0;

public:
	University(string name, string address, Student* students, int studCount)
	{
		this->name = name;
		this->address = address;
		this->studCount = studCount;
		this->students = new Student[studCount];
		for (int i = 0; i < studCount; i++)
		{
			this->students[i] = students[i];
		}
	}

	University(const University& u)
	{
		this->name = u.name;
		this->address = u.address;
		this->studCount = u.studCount;
		this->students = new Student[studCount];
		for (int i = 0; i < u.studCount; i++)
		{
			this->students[i] = u.students[i];
		}
	}

	University& operator=(const University& u)
	{
		if (this != &u)
		{
			this->name = u.name;
			this->address = u.address;
			this->studCount = u.studCount;
			this->students = new Student[studCount];
			for (int i = 0; i < u.studCount; i++)
			{
				this->students[i] = u.students[i];
			}
		}
		return *this;
	}

	~University() {
		delete[]this-> students;
	}
};

int main()
{
	Date d1;
	Date d2(5, 5, 1992);


	Person p1;
	string* addresses = new string[3];
	addresses[0] = "...Bucuresti";
	addresses[1] = "...Arad";
	addresses[2] = "...Galati";

	Person p2("Popescu Andrei", "1920505252516", d2, addresses, 3);

	Student s1;
	float* grades = new float[5];
	grades[0] = 6;
	grades[1] = 7;
	grades[2] = 8;
	grades[3] = 9;
	grades[4] = 5;

	Student s2("Popescu Andrei", "1920505252516", d2, addresses, 3, 123, grades, 5, true);
	Student s3("Andresan Andrei", "1920505252516", d2, addresses, 3, 123, grades, 5, true);

	Student* students= new Student[3];
	students[0] = s1;
	students[1] = s2;
	students[2] = s3;

	University u1("ASE", "Bucuresti", students, 3);
	return 0;
};
