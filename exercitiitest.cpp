#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/*
* sa se faca o aplicatie care gestioneaza locurile unui tren si cursa trenului: id-constant intreg ce reprez id ul trenului; pretKm-intreg,static ce reprez pretul pt 
* un km din cursa trenului; destinatie-sir de caractere ce reprez destinatia trenului; plecare-pointer la char ce va gest adresa unui vect dinamic de caractere ce 
* reprez locul din care pleaca trenul; nrKmparcursiincursa-intreg,int; nrlocuri-int ce reprez nr de locuri totale din tren; 
* locuri-pointer la bool ce reprez un vector dinamic de locuri 1-ocupat, 0-liber; tipTren-enumeratie ce reprez tipul trenului personal rapid,accelerat,
* intercity;
* 1.sa se implementeze un constr fara param
* 2.sa se implementeze un constr cu toti param
* 3.sa se implementeze constr de copiere
* 4.sa se implementeze op=
* 5.sa se implementeze destructor
* 6.sa se implementeze un setter si un getter pt un camp aloc dinamic la alegere
* 7.sa se faca o fct de afisare

*/
enum tipTren {
	personal, rapid, accelerat, intercity
};

class Tren {
private:
	const int id = 0;
	static float pretKm;
	string destinatie;
	char* plecare;
	int nrKmParcursi;
	int nrLocuri;
	bool* locuri;
	tipTren tip;

public:
	//constructor fara param
	Tren():id(0)
	{
		this->destinatie = "na";
		this->plecare =new char[strlen("na")+1];
		strcpy(this->plecare, "na");
		this->nrKmParcursi = 0;
		this->nrLocuri = 0;
		this->locuri = NULL;
		this->tip =personal;
		
	}




	//Tren t1(2,       "Bucuresti",              "Brasov",           350,           50,           false, personal);

	//constructor cu toti parametrii
	Tren(int idDat, const char* plecareDat, string destinatieDat, int kmDat, int nrLocuriDat, bool*locuriDat, tipTren tipDat ) :id(idDat)
	{
		
		this->destinatie = destinatieDat;
		this->plecare = new char[strlen(plecareDat) + 1];
		strcpy(this->plecare, plecareDat);
		this->nrKmParcursi =kmDat;
		this->nrLocuri = nrLocuriDat;
		this->locuri = new bool[nrLocuriDat];
		for (int i = 0; i < nrLocuriDat;i++)
		{
			this->locuri[i] = locuriDat[i];
		}
		this->tip = tipDat;

	}


	//constructor de copiere
	Tren(const Tren& sursa):id(sursa.id)
	{

		this->destinatie = sursa.destinatie;
		this->plecare = new char[strlen(sursa.plecare) + 1];
		strcpy(this->plecare, sursa.plecare);
		this->nrKmParcursi = sursa.nrKmParcursi;
		this->nrLocuri = sursa.nrLocuri;
		this->locuri = new bool[sursa.nrLocuri];
		for (int i = 0; i < sursa.nrLocuri;i++)
		{
			this->locuri[i] = sursa.locuri[i];
		}
		this->tip = sursa.tip;

	}




	//operator=
	Tren&operator=(const Tren& sursa)
	{
		if (this != &sursa) {
			delete[] this->plecare;
			delete[] this->locuri;
			this->destinatie = sursa.destinatie;
			this->plecare = new char[strlen(sursa.plecare) + 1];
			strcpy(this->plecare, sursa.plecare);
			this->nrKmParcursi = sursa.nrKmParcursi;
			this->nrLocuri = sursa.nrLocuri;
			this->locuri = new bool[sursa.nrLocuri];
			for (int i = 0; i < sursa.nrLocuri;i++)
			{
				this->locuri[i] = sursa.locuri[i];
			}
			this->tip = sursa.tip;

		}
		return *this;

	}


	//destructor

	~Tren() {
		delete[] this->plecare;
		delete[] this->locuri;
	}


	//getter plecare

	char* getPlecare() {
		char* v;
		v = new char[strlen(this->plecare) + 1];
		strcpy(v, this->plecare);
		return v;//am returnat o copie a plecarii ob
	 }


	//setter

	void setnume(const char* plecareDat) {
		if (strlen(plecareDat) > 2) {
			delete[]this->plecare;
			this->plecare = new char[strlen(plecareDat) + 1];
			strcpy(this->plecare, plecareDat);
			
		}
	}





};
float Tren::pretKm = 2.50;






int main() {

	Tren t1(2, "Bucuresti", "Brasov", 350, 50, new bool[3]{1,0,0}, personal);//cu toti param
	Tren t;
	Tren t2(t1);//constr de copiere   t2 pt care s a apelat fct si t1 ob din care copiem inf
	t1.setnume("Banat");//setter
	char* plecaret2 = t1.getPlecare();//getter ne ajuta sa obt date din zona priv
	cout << plecaret2 << endl;
	delete[] plecaret2;





	return 0;
}