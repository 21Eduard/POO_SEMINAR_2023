#include <iostream>
#include <string>

using namespace std;


//clasa

class Carte
{
private:
	char* titlu;
	string autor;
	int nr_pag;
	double pret;
	bool electronica;
	int* nr_cuv;


	//constructor
public:
	Carte() {

	}

	Carte(char* _titlu, string _autor, int _nr_pag, double _pret, bool _electronica, int* _nr_cuv)
	{
		this->titlu = new char[strlen(_titlu) + 1];
		strcpy_s(this->titlu, strlen(_titlu) + 1, _titlu);

		this->nr_cuv = new int[_nr_pag];
		for (int ind = 0; ind < _nr_pag; ind++)
		{
			this->nr_cuv[ind] = _nr_cuv[ind];
		}

		this->autor = _autor;
		this->nr_pag = _nr_pag;
		this->pret = _pret;
	}


	//constructor de copiere

	Carte(const Carte& carte)
	{
		this->titlu = new char[strlen(carte.titlu) + 1];
		strcpy_s(this->titlu, strlen(carte.titlu) + 1, carte.titlu);

		this->nr_cuv = new int[carte.nr_pag];
		for (int ind = 0; ind < carte.nr_pag; ind++)
		{
			this->nr_cuv[ind] = carte.nr_cuv[ind];
		}

		this->autor = carte.autor;
		this->nr_pag = carte.nr_pag;
		this->pret = carte.pret;
	}


	//setteri

	void set_nr_cuv(int* _nr_cuv, int _nr_pag)
	{
		this->nr_pag = _nr_pag;

		this->nr_cuv = new int[nr_pag];
		for (int ind = 0; ind < _nr_pag; ind++)
		{
			this->nr_cuv[ind] = nr_cuv[ind];

		}
	}

	void set_autor(string _autor)
	{
		this->autor = _autor;
	}



	//getteri

	int* nr_cuv() { return this->nr_cuv; }
	string get_autor() { return this->autor; }
	int get_nr_pag() { return this->nr_pag; }


	//destructor

	~Carte()
	{
		delete[] this->titlu;
		delete[] this->nr_cuv;
	}


};

int main()
{
	Carte c0;

	c0.autor = "Feodor Dostoievski";

	c0.titlu = new char[20];
	strcpy_s(c0.titlu, 20, "Fratii Karamazov");

	c0.nr_pag = 10;
	c0.pret = 25;

	c0.electronica = true;

	int nr_cuv[10] = { 200,202,198,200,203,201,196,52,127,98 };
	c0.set_nr_cuv(nr_cuv, 10);

	Carte c1 = Carte((char*)"Amintiri din copilarie", "Ion Creanga", 20, 45, false, nr_cuv);


}
