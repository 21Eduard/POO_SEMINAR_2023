#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string grupa = "1234";
	int nr_matricol;
	int* note;
	int nr_note;
	char* adresa = nullptr;
	const int aniDeStudiu;
	static string universitate;

public:
	string nume;
	int varsta;

	Student() : aniDeStudiu(3)
	{
		nume = "anonim";
		varsta = 18;
		nr_matricol = 0;
		note = nullptr;
		nr_note = 0;
	}

	Student(string n, int v, string g, int aniDeStudiu) : note(nullptr), nr_note(0), aniDeStudiu(aniDeStudiu)
	{
		nume = n;
		grupa = g;
		if (v > 0)
		{
			varsta = v;
		}
		else
		{
			varsta = 18;
		}
	}

	Student(string nume, const char* adresa) :Student()
	{
		this->nume = nume;
		this->adresa = new char[strlen(adresa) + 1];
		strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
	}

	Student(string nume, int* note, int nr_note) :Student()
	{
		this->nume = nume;
		if (note != nullptr && nr_note > 0)
		{
			this->nr_note = nr_note;
			this->note = new int[nr_note];
			for (int i = 0; i < nr_note; i++)
			{
				this->note[i] = note[i];
			}
		}

	}

	Student(const Student& s) : aniDeStudiu(s.aniDeStudiu)
	{
		this->nume = s.nume;
		this->varsta = s.varsta;
		this->nr_matricol = s.nr_matricol;
		this->grupa = s.grupa;
		if (s.note != nullptr && s.nr_note != 0)
		{
			this->nr_note = s.nr_note;
			this->note = new int[s.nr_note];
			for (int i = 0; i < s.nr_note; i++)
			{
				this->note[i] = s.note[i];
			}
		}
		else
		{
			this->note = nullptr;
			this->nr_note = 0;
		}
		if (s.adresa != nullptr)
		{
			this->adresa = new char[strlen(s.adresa) + 1];
			strcpy_s(this->adresa, strlen(s.adresa) + 1, s.adresa);
		}
		else
		{
			this->adresa = nullptr;
		}
	}

	///supraincarcare operator =
	Student& operator=(const Student& s)
	{
		if (note != nullptr)
		{
			delete[] note;
		}
		if (adresa != nullptr)
		{
			delete[] adresa;
		}
		this->nume = s.nume;
		this->varsta = s.varsta;
		this->nr_matricol = s.nr_matricol;
		this->grupa = s.grupa;
		if (s.note != nullptr && s.nr_note != 0)
		{
			this->nr_note = s.nr_note;
			this->note = new int[s.nr_note];
			for (int i = 0; i < s.nr_note; i++)
			{
				this->note[i] = s.note[i];
			}
		}
		else
		{
			this->note = nullptr;
			this->nr_note = 0;
		}
		if (s.adresa != nullptr)
		{
			this->adresa = new char[strlen(s.adresa) + 1];
			strcpy_s(this->adresa, strlen(s.adresa) + 1, s.adresa);
		}
		else
		{
			this->adresa = nullptr;
		}
		return *this;
	}

	~Student()
	{
		if (note != nullptr)
		{
			delete[] note;
		}
		if (adresa != nullptr)
		{
			delete[] adresa;
		}
	}

	//are nota -> fiecare nota se modifica prin nota = 10 - nota, return true
	// nu are note, return false
	//exemplificam in main

	bool operator!() {
		if (nr_note <= 0)
			return false;

		for (int i = 0; i < this->nr_note; i++) {
			this->note[i] = 10 - this->note[i];
		}
		return true;

	}

	//operatorul de negatie
	/*
	bool operator!()
	{
	return nr_note > 0;
	}
	*/

	//operatorul de preincrementare
	Student operator++()
	{
		this->varsta++;
		return *this;
	}

	//operatorul de postincrementare
	Student operator++(int i)
	{
		Student copie = *this;
		this->varsta += i;//nu e implementata bine, i trebuie sa fie 1
		return copie;
	}

	//operator +
	Student operator+(int valoare)
	{
		Student copie = *this;
		copie.varsta += valoare;
		return copie;
	}

	//operator index cu rol de citire-scriere
	int& operator[](int index)
	{
		if (index >= 0 && index < nr_note)
		{
			return note[index];
		}
		throw exception("index invalid");
	}

	//operator de cast la int explicit
	explicit operator int()
	{
		return varsta;
	}

	//operator functie ce returneaza lungimea adresei
	int operator()()
	{
		if (adresa != nullptr)
		{
			return strlen(adresa);
		}
		else
		{
			return 0;
		}
	}

	string getGrupa()
	{
		return grupa;
	}

	int getMatricol()
	{
		return nr_matricol;
	}

	void setMatricol(int nr_matricol)
	{
		if (nr_matricol > 0)
		{
			this->nr_matricol = nr_matricol;
		}
	}

	int* getNote()
	{
		if (note != nullptr)
		{
			int* copie = new int[nr_note];
			for (int i = 0; i < nr_note; i++)
			{
				copie[i] = note[i];

			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}

	int getNote(int index)
	{
		if (index >= 0 && index < nr_note && note != nullptr)
		{
			return note[index];
		}
	}

	int getNrNote()
	{
		return nr_note;
	}

	void setNote(int* note, int nr_note)
	{
		if (note != nullptr && nr_note != 0)
		{
			this->nr_note = nr_note;
			if (this->note != nullptr)
			{
				delete[] this->note;

			}
			this->note = new int[nr_note];
			for (int i = 0; i < nr_note; i++)
			{
				this->note[i] = note[i];
			}
		}
	}

	//getter si setter pentru campul static

	static string getUniversitate()
	{
		return universitate;
	}

	static void setUniversitate(string universitate)
	{
		Student::universitate = universitate;
	}

	//metodele statice nu il pot prelucra pe this
	//cu toate acestea au acces la membrii privati
	//fiind membre ale clasei
	static float medieSerie(Student* studenti, int nrStudenti)
	{
		float suma = 0;
		int nr = 0;
		if (studenti != nullptr && nrStudenti > 0)
		{
			for (int i = 0; i < nrStudenti; i++)
			{
				if (studenti[i].note != nullptr)
				{
					for (int j = 0; j < studenti[i].nr_note; j++)
					{
						suma += studenti[i].note[j];
						nr++;
					}
				}
			}
			if (nr > 0)
			{
				return suma / nr;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}

	//functiile friend pot accesa membrii private sau protected ai clasei
	friend ostream& operator<<(ostream&, Student);
	friend istream& operator>>(istream&, Student&);
};
string Student::universitate = "ASE";

//conservarea comutativitatii operatorului +
Student operator+(int valoare, Student s)
{
	//nu este nevoie sa facem o copie locala
	//deoarece s este transmis prin valoare
	s.varsta += valoare;
	return s;
}

//operator de afisare
ostream& operator<<(ostream& out, Student s)
{
	out << "nume: " << s.nume << endl;
	out << "varsta: " << s.varsta << endl;
	out << "matricol: " << s.nr_matricol << endl;
	out << "grupa: " << s.grupa << endl;
	out << "ani de studiu: " << s.aniDeStudiu << endl;
	out << "adresa: ";
	if (s.adresa != nullptr)
	{
		out << s.adresa;
	}
	out << endl;
	out << "numar note: " << s.nr_note << endl;
	out << "note: ";
	if (s.note != nullptr)
	{
		for (int i = 0; i < s.nr_note; i++)
		{
			out << s.note[i] << " ";
		}
	}
	return out;
}

//operator de citire
istream& operator>>(istream& in, Student& s)
{
	cout << "nume = ";
	in >> s.nume;
	cout << "varsta = ";
	in >> s.varsta;
	cout << "numar matricol = ";
	in >> s.nr_matricol;
	cout << "grupa = ";
	in >> s.grupa;
	string buffer;
	cout << "adresa: ";
	in >> buffer;
	if (s.adresa != nullptr)
	{
		delete[] s.adresa;
	}
	s.adresa = new char[buffer.length() + 1];
	strcpy_s(s.adresa, buffer.length() + 1, buffer.c_str());
	cout << "numar note = ";
	in >> s.nr_note;
	if (s.note != nullptr)
	{
		delete[] s.note;
	}
	if (s.nr_note > 0)
	{
		s.note = new int[s.nr_note];
		for (int i = 0; i < s.nr_note; i++)
		{
			cout << "note[" << i << "] = ";
			in >> s.note[i];
		}
	}
	else
	{
		s.nr_note = 0;
		s.note = nullptr;
	}
	return in;
}


class MyString
{
	char* str;
public:
	MyString(const char* str)
	{
		this->str = new char[strlen(str) + 1];
		strcpy_s(this->str, strlen(str) + 1, str);

	}

	char* getStr()
	{
		char* tmp = new char[strlen(this->str) + 1];
		strcpy_s(tmp, strlen(this->str) + 1, this->str);
		return tmp;
	}
};

int main()
{
	MyString s1("Testare pointer char");
	char* x = s1.getStr();

	strcpy_s(x, 5, "aaaa");

	return 0;

	Student s;  ///obiect de tip student
	s.nume = "Ion Popescu";
	cout << s.nume << endl;
	cout << s.varsta << endl;

	Student* ps;  ///pointer la obiect de tip student
	ps = &s;  /// & de referentiere, * de dereferentiere

	cout << (*ps).nume << endl; ///retine adresa la care e stocat s
	cout << ps->nume << endl;
	cout << sizeof(s) << endl;

	Student s2 = s;
	cout << sizeof(s2) << endl;

	ps = new Student();
	cout << ps->nume << endl;
	delete ps;

	Student s3("Maria Popescu", 20, "1050", 2);
	cout << s3.nume << endl;

	Student s4("Vasile Musat", "Str Ion Creanga, nr 8");
	cout << s4.nume << endl;

	Student vector[3];

	Student* ps2 = new Student("Marcel Ionascu", "Str Avionului, nr 4");
	cout << ps2->nume << endl;

	delete ps2;

	int note[] = { 7,4,9 };

	Student s5("Dan", note, 3);

	Student s6(s5); ///se apeleaza constructorul de copiere

	cout << s.getGrupa() << endl;

	s6.setMatricol(5);
	cout << s6.getMatricol() << endl;

	int z[] = { 1,2,3,4,5 };
	s6.setNote(z, 5);
	int* n = s6.getNote();

	for (int i = 0; i < s6.getNrNote(); i++)
	{
		cout << n[i] << " ";
	}
	cout << endl;

	delete[] n;
	n = nullptr;

	Student::setUniversitate("Politehnica");
	cout << s.getUniversitate() << endl;
	cout << s5.getUniversitate() << endl;
	cout << Student::getUniversitate() << endl;

	Student studenti[] = { s5, s6 };
	float medie = Student::medieSerie(studenti, 2);
	cout << medie << endl;

	//apel constructor de copiere
	Student s7 = s5;
	//apel operator=
	s = s6;
	//apel operator= in cascada
	s = s5 = s6;
	//apel operator negatie
	bool areNote = !s5;
	cout << areNote << endl;
	//apel preincrementare
	Student s8 = ++s5;
	//apel postincrementare
	Student s9 = s6++;

	//apel operator + din clasa
	s8 = s5 + 7;
	//apel operator + global
	s9 = 3 + s5;

	cout << s5 << endl;
	Student s10;
	//apel operator de citire
	cin >> s10;
	//apel operator de afisare
	cout << s10 << endl;
	//apel operator index in mod scriere
	s5[1] = 10;
	//apel operator index in mod citire
	cout << s5[1] << endl;

	//apel operator de cast la int explicit
	int varsta = (int)s9;
	cout << varsta << endl;
	//apel operator functie
	cout << s10();

}
