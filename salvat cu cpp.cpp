#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//destructor, constructor de copiere, op = pt atribute dinamice
//op de afisare, op <<


enum SursaEnergie { verde, eoliana, solara };

class Client {
	//client la reteaua electrica

private:
	SursaEnergie sursaEn;
	int consumEstimatLunar; //110
	int nrLuni;//nr de luni de cand esti conectat la reteaua electrica
	int* kwh;//kwh/ora 100,50,60
	static float pretkwh;//descrie ca furnizorul vinde la toti clientii cu acelasi pret

public:





	//constr fara param
	Client()
	{
		this->sursaEn = verde;
		this->consumEstimatLunar = 100;
		this->nrLuni = 0;
		this->kwh = nullptr;
	}








	//constr cu toti param
	Client(SursaEnergie sursaData, int costEstimatDat, int nrLuniDate, int* kwhDati)
	{
		this->sursaEn = sursaData;//se seteaza in sursa c1, c1 a intrat in this, this retine c1,eoliana s a initializat in c1
		this->consumEstimatLunar = costEstimatDat;
		this->nrLuni = nrLuniDate;
		this->kwh = new int[nrLuniDate];
		for (int i = 0;i < nrLuniDate; i++)
		{
			this->kwh[i] = kwhDati[i];
		}


	}






	//constr de copiere cand zicem this-c2, sursa-c1; sursa lui this c2 sa primeasca sursa.sursa
	Client(const Client& sursa)//sursa se transfera cu referinta si cu const
	{
		this->sursaEn = sursa.sursaEn;
		this->consumEstimatLunar = sursa.consumEstimatLunar; //costul lui c2 este costul lui sursa.consum estimat
		this->nrLuni = sursa.nrLuni;
		this->kwh = new int[sursa.nrLuni];
		for (int i = 0;i < sursa.nrLuni; i++)
		{
			this->kwh[i] = sursa.kwh[i];
		}

	}






	//destructor 
	~Client()
	{
		delete[] this->kwh;
	}






	//op=   

	Client& operator= (const Client& sursa)
	{
		//test de autoasignare
		if (this != &sursa) {



			delete[] this->kwh;//delete la vectorul dinamic, altfel memory leaks
			this->sursaEn = sursa.sursaEn;
			this->consumEstimatLunar = sursa.consumEstimatLunar;
			this->nrLuni = sursa.nrLuni;
			this->kwh = new int[sursa.nrLuni];
			for (int i = 0;i < sursa.nrLuni; i++) {
				this->kwh[i] = sursa.kwh[i];
			}
		}
		return *this;

	}




	friend ostream& operator<< (ostream& out, Client sursa);


	//op functie()
	void operator () (int nrLunaCautata, int valoareLunaNoua)
	{
		if (nrLunaCautata >= 0 && nrLunaCautata < this->nrLuni)//this e ob c1
		{
			this->kwh[nrLunaCautata] = valoareLunaNoua;
		}
	}




	//op de conversie la double
	explicit operator double()
	{
		double t = 0; //suma dif =0, totalul dif
		//vreau sa trec pe la fiecare val din vector
		for (int i = 0;i < this->nrLuni;i++)
		{
			if (this->consumEstimatLunar - this->kwh[i] >= 0)
			{
				t += (this->consumEstimatLunar - this->kwh[i]);//t ul se mareste cu acea diferenta 
			}
			else {
				t += ((this->consumEstimatLunar - this->kwh[i]) * (-1));
			}
		}
		return t;
	}




};
float Client::pretkwh = 1.5;






ostream& operator<< (ostream& out, Client sursa) //in sursa intra c1 
{
	out << "Sursa energie: " << sursa.sursaEn << endl;
	out << "Consum estimat:  " << sursa.consumEstimatLunar << endl;
	out << "Nr luni:  " << sursa.nrLuni << endl;
	out << "kwh lista:  ";
	for (int i = 0;i < sursa.nrLuni; i++)
	{
		out << sursa.kwh[i] << " ";
	}
	out << endl << endl;


	return out; //ajuta la apel in cascada cout<<c1<<c2<<c3<<endl 
}






int main() {

	Client c;//constr fara param

	Client c1(eoliana, 100, 3, new int[3] {80, 110, 90});//ce sursa vrei tu sa bagi in c1

	Client c2(c1);//constr de copiere 

	c = c1;//op=  

	//c1(1, 120); apel op functie()

		cout << c1; //op de afisare

	cout << c1 << c2 << endl;


	cout << "Totalul dif lunare: " << (double)c1 << endl;


	return 0;
}