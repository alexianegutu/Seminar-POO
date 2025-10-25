void afisareStudent(char* pnume, char pgen, float pbursa, int* pnote, int pnrNote)// antetul functiei / semnatura functiei / 
{

	cout << "Numele este: " << pnume << endl;
	cout << "Genul este: " << pgen << endl;
	cout << "Bursa este: " << pbursa << endl;
	cout << "Nr note este: " << pnrNote << endl;
	cout << "Notele sunt: ";
	for (int i = 0; i < pnrNote;i++)
	{
		cout << pnote[i] << " ";
	}
	cout << endl;
	cout << endl;

}





//    getMedie(       v,          n  );
float getMedie(int* pnote, int pnrnote)
{

	float m = 0;
	for (int i = 0; i < pnrnote; i++)
	{
		m += pnote[i];
	}
	m /= pnrnote;

	return m;
}



void modificaBursa(float* pbursa, float bursaNoua)
{

	*pbursa = bursaNoua;


}


// modificaBursa prin referinta 
void modificaBursa_ref(float& pbursa, float bursaNoua)
{

	pbursa = bursaNoua;

}




void modificaGen(char* pgen, char genNou)
{

	*pgen = genNou;

}


void modificaNume(char* pNume, const   char* numeNou)
{
	strcpy(pNume, numeNou);
}




void adaugaNota(int* pnote, int* pnrNote, int notaNoua)// antet
{

	pnote[*pnrNote] = notaNoua;
	*pnrNote += 1;

}



void maresteBursa(int* pnote, int pnrnote, float* pbursa)
{


	if (getMedie(pnote, pnrnote) > 9.00)
	{
		*pbursa = 900;
	}

}




class Student
{
public:
	// atributele 
	char* nume;
	char gen;
	bool buget; 
	float bursa; 
	int nrNote; 
	int* note;





	





	void metodaOarecare()
	{
		cout << "Sunt o metoda specifica studentului care nu face nimic" << endl;

		

	}



	// sa se faca o metoda care afiseaza un student.
	void  afisare()
	{

		cout << "Numele este: " << this->nume << endl;
		cout << "gen este: " << this->gen << endl;
		cout << "bursa este: " << this->bursa << " RON" << endl;
		if (this->buget == true)
		{
			cout << "Forma invatamant: BUGET" << endl;
		}
		else {
			cout << "Forma invatamant: TAXA" << endl;
		}
		cout << "NR note: " << this->nrNote << endl;
		cout << "Notele sunt: ";
		for (int i = 0; i < this->nrNote; i++)
		{
			cout << this->note[i] << " ";
		}
		cout << endl << endl;


	}

	void modificaGen(char genNou)
	{
		this->gen = genNou;
	}


	float getMedie()
	{
		float m = 0;
		if (this->nrNote > 0)
		{
			for (int i = 0; i < this->nrNote; i++)
			{
				m += this->note[i];
			}
			m /= this->nrNote;
		}


		return m;
	}





	// Constructorul fara parametri. 
	Student()
	{
		this->bursa = 0;
		this->buget = false;
		this->nrNote = 0;
		this->note = NULL; //nullptr
		this->gen = '-';
		this->nume = new char[strlen("na") + 1];
		strcpy(this->nume, "na");
	}



	// Constructor cu toti parametri
	// Student x(             "Alexia",      'f',   true, 900, 3, new int[3] {9, 8, 10});
	Student(const char* numeDat, char genDat, bool bugetDat, float bursaData, int nrNoteDate, int* noteDate)
	{
		this->gen = genDat;
		this->nume = new char[strlen(numeDat) + 1];
		strcpy(this->nume, numeDat);
		this->buget = bugetDat;
		this->bursa = bursaData;
		this->nrNote = nrNoteDate;
		this->note = new int[nrNoteDate];
		for (int i = 0;i < nrNoteDate; i++)
		{
			this->note[i] = noteDate[i];
		}

	}


	// Student x2("Gigel", 'm'); 
	Student(const char* numeDat, char genDat)
	{
		this->gen = genDat;
		this->nume = new char[strlen(numeDat) + 1];
		strcpy(this->nume, numeDat);
		this->nrNote = 0;
		this->note = NULL;
		this->buget = 0;
		this->bursa = 0;

	}






};



void subprogramOarecare()
{
	cout << "Sunt un subprogram opareacare" << endl;
}






int main()
{
	char sir[10] = { "Alexia" };
	int n = 3;
	int v[5] = { 6,8,4 };
	float b = 900;
	char g = 'f';


	char sir1[10] = { "Cata" };
	int n1 = 3;
	int v1[5] = { 7,6,7 };
	float b1 = 900;
	char g1 = 'f';

	



	// cout << "Numele este: " << sir << endl;
	// cout << "Genul este: " << g << endl;
	// cout << "bursa este : " << b<<" roni" << endl;
	// cout << "Nr de note este: " << n << endl;
	// cout << "Notele sunt: ";
	// for (int i = 0; i < n; i++) {
	// 	cout << v[i] << " ";
	// }
	// cout << endl;
	// cout << endl;
	// 
	// 
	// 
	// cout << "Numele este: " << sir1 << endl;
	// cout << "Genul este: " << g1 << endl;
	// cout << "bursa este : " << b1 << " roni" << endl;
	// cout << "Nr de note este: " << n1 << endl;
	// cout << "Notele sunt: ";
	// for (int i = 0; i < n1; i++) {
	// 	cout << v1[i] << " ";
	// }
	// cout << endl;


	afisareStudent(sir, g, b, v, n); 
	afisareStudent(sir1, g1, b1, v1, n1);
	afisareStudent(new char[10] {"costel"}, 'm', 0, new int[2] {3, 3}, 2);


	// sa se faca un subprogram care returneaza media notelor. 

	float medieAlexia = getMedie(v, n);

	cout << "Alexia are medie: " << medieAlexia << endl;



	// sa se faca un subprogram care schimba valaorea bursei cu alta bursa. 

	modificaBursa(&b, 250);
	modificaGen(&g, 'm');


	modificaNume(sir, "Alex");
	afisareStudent(sir, g, b, v, n);

	modificaBursa_ref(b, 300);



	// un subprogram care adauga o nota studentului. 

	adaugaNota(v, &n, 5);


	// daca media notelor este mai mare decat 9 strict atunci
	// bursa sa se seteze 900. 


	maresteBursa(v, n, &b);


	int note_db[100] = { 9,10,7 };
	int nrNoteDB = 3;



	Student y;// am declarat obiectul 
	Student z;
	z.gen = 'f';



	// am initializat obiectul 
	//y.gen = 'm';
	//y.nume = new char[strlen("Alexia") + 1];
	//strcpy(y.nume, "Alexia");
	//y.buget = true;
	//y.bursa = 900;
	//y.nrNote = nrNoteDB;
	//y.note = new int[y.nrNote];
	//for (int i = 0; i < y.nrNote; i++)
	//{
	//	y.note[i] = note_db[i];
	//}


	// afisareStudent(y.nume, y.gen, y.bursa, y.note, y.nrNote);


	y.metodaOarecare();
	z.metodaOarecare();


	subprogramOarecare();

	y.afisare();
	y.modificaGen('f');
	y.afisare();
	z.afisare();
	z.bursa += 10;

	float medie_y = y.getMedie();

	cout << "Media lu alexia este " << medie_y << endl;

	/*
	Alexia
	f
	true
	900
	3
	9 8 10
	*/

	Student x("Alexia", 'f', true, 900, 3, new int[3] {9, 8, 10});
	Student x1("Cata", 'f', true, 900, 3, note_db);


	Student x2("Gigel", 'm');

	x2.afisare();


	return 0;
}



