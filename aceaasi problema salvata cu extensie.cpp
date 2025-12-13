#include<iostream>
using namespace std;



class Sejur
{
private:
	const int id = 0;
	string destinatie;
	float pretBaza;
	int nrExcursiiOptionale;
	float* pretExcursie;
	int durataZile;
	bool allInclusive; // 0 normal 1 all 



public:

	Sejur(int idDat) :id(idDat >= 0 ? idDat : 0)
	{
		this->destinatie = "na";
		this->pretBaza = 0;
		this->nrExcursiiOptionale = 0;
		this->pretExcursie = NULL;
		this->durataZile = 0;
		this->allInclusive = false;
	}


	Sejur(int idDat, string destinatieDat, bool allDat, int durataData, float pretBazaDat, int nrOptionaleDate, float* excursiiDate) :id(idDat >= 0 ? idDat : 0)
	{
		this->destinatie = destinatieDat;
		this->pretBaza = pretBazaDat;
		this->nrExcursiiOptionale = nrOptionaleDate;
		this->pretExcursie = new float[nrOptionaleDate];
		for (int i = 0; i < nrOptionaleDate; i++) {
			if (excursiiDate[i] >= 0) {
				this->pretExcursie[i] = excursiiDate[i];
			}
			else {
				this->pretExcursie[i] = 0;
			}
		}
		this->durataZile = durataData;
		this->allInclusive = allDat;
	}





	bool getAllInclusive() {
		return this->allInclusive;
	}


	int getDurataZile() {
		return this->durataZile;
	}


	void setAllInclusive(bool allNou) {
		this->allInclusive = allNou;// nu prea ai ce conditie sa pui ca naiba e bool doar 0 1 si altceva e unu default.
	}


	void setDurataZile(int durNou) {
		if (durNou >= 0) {
			this->durataZile = durNou;
		}
	}


	~Sejur() {
		delete[] this->pretExcursie;
	}





	Sejur(const Sejur& sursa) :id(sursa.id)
	{
		this->destinatie = sursa.destinatie;
		this->pretBaza = sursa.pretBaza;
		this->nrExcursiiOptionale = sursa.nrExcursiiOptionale;
		this->pretExcursie = new float[sursa.nrExcursiiOptionale];
		for (int i = 0; i < sursa.nrExcursiiOptionale; i++) {
			this->pretExcursie[i] = sursa.pretExcursie[i];
		}
		this->durataZile = sursa.durataZile;
		this->allInclusive = sursa.allInclusive;
	}



	Sejur& operator=(const Sejur& sursa)
	{
		if (this != &sursa) {
			delete[] this->pretExcursie;
			this->destinatie = sursa.destinatie;
			this->pretBaza = sursa.pretBaza;
			this->nrExcursiiOptionale = sursa.nrExcursiiOptionale;
			this->pretExcursie = new float[sursa.nrExcursiiOptionale];
			for (int i = 0; i < sursa.nrExcursiiOptionale; i++) {
				this->pretExcursie[i] = sursa.pretExcursie[i];
			}
			this->durataZile = sursa.durataZile;
			this->allInclusive = sursa.allInclusive;
		}


		return *this;
	}

	void afisare() {
		cout << "ID: " << this->id << endl;
		cout << "destinatie: " << this->destinatie << endl;
		cout << "pret baza: " << this->pretBaza << endl;
		cout << "nr op: " << this->nrExcursiiOptionale << endl;
		cout << "preturi: ";
		for (int i = 0; i < this->nrExcursiiOptionale; i++) {
			cout << this->pretExcursie[i] << "  ";
		}
		cout << endl;
		cout << "allInclusive: " << this->allInclusive << endl;
		cout << "durata: " << this->durataZile << endl;
		cout << endl;

	}

};







int main()
{

	Sejur s(1);


	s.setAllInclusive(true);
	s.setDurataZile(14);
	cout << s.getAllInclusive() << endl;
	cout << s.getDurataZile() << endl;

	Sejur s1(2, "Dubai", true, 14, 2000, 3, new float[3] {25, 50, 30});

	Sejur s2(s1);

	s = s1;


	s1.afisare();


	return 0;
}