#include "std_lib_facilities.h"

//A
vector<int> caclulateSeries(int totaltL�n, int antallAvdrag, float rente) {
	int gjenst�endeL�n, innbetaling, delbetaling;
	vector<int> payments;

	delbetaling = totaltL�n / antallAvdrag;
	gjenst�endeL�n = totaltL�n;

	for (int avdrag = 1; avdrag <= antallAvdrag; ++avdrag) {
		innbetaling = delbetaling + (rente / 100)*gjenst�endeL�n;
		gjenst�endeL�n -= delbetaling;

		payments.push_back(innbetaling);
	}
	return payments;
}

//B
vector<int> calculateAnnuity(int totaltL�n, int antallAvdrag, float rente) {
	int innbetaling;
	vector<int> payments;

	for (int avdrag = 1; avdrag <= antallAvdrag; ++avdrag) {
		innbetaling = totaltL�n * ((rente / 100) / (1 - pow((1 + rente / 100), -1*antallAvdrag)));
		payments.push_back(innbetaling);
	}
	return payments;
}

//C
void printLoans() {
	int totaltL�n, antallAvdrag;
	float rente;
	const char sep = ' ';
	const int sepWidth = 16;
	const int sepWidthShort = 4;

	cout << "L�n: \n";
	cin >> totaltL�n;
	cout << "Antall avdrag: \n";
	cin >> antallAvdrag;
	cout << "Rente: \n";
	cin >> rente;

	vector<int> serieL�n = caclulateSeries(totaltL�n, antallAvdrag, rente);
	vector<int> annuitetsL�n = calculateAnnuity(totaltL�n, antallAvdrag, rente);

//Overskrift for tabell (sp�rsm�l: er det noen m�te � unng� s� mange "... left << setw() << setfill() ....????")
	cout << left << setw(sepWidthShort) << setfill(sep) << "�r";
	cout << left << setw(sepWidth) << setfill(sep) << "   Annuitet";
	cout << left << setw(sepWidth) << setfill(sep) << "  Serie";
	cout << left << setw(sepWidth) << setfill(sep) << "   Differanse" << endl;

//Generering av tabell
	int totalSumAnnuitet = 0;
	int totalSumSerie = 0;

	unsigned int len = serieL�n.size();

	for (int i = 0; i < len; ++i) {
		int betalingAnnuitet = annuitetsL�n[i];
		int betalingSerie = serieL�n[i];

		//Verdier for annuitetsl�n, seriel�n og differansen, i tabell 
		cout << left << setw(sepWidthShort) << setfill(sep) << i + 1;		//+1 siden i starter p� 0, mens �r starter p� 1
		cout << right << setw(sepWidth) << setfill(sep) << betalingAnnuitet;
		cout << right << setw(sepWidth) << setfill(sep) << betalingSerie;
		cout << right << setw(sepWidth) << setfill(sep) << betalingAnnuitet - betalingSerie << endl;

		//totalsum for kolonne annuitet og serie
		totalSumAnnuitet += betalingAnnuitet;
		totalSumSerie += betalingSerie;
	}
//sum av annuitet serie, og endelig differanse
	cout << left << setw(sepWidth) << setfill(sep) << "Totalt";
	cout << left << setw(sepWidth) << setfill(sep) << totalSumAnnuitet;
	cout << left << setw(sepWidth) << setfill(sep) << totalSumSerie;
	cout << left << setw(sepWidth) << setfill(sep) << totalSumAnnuitet - totalSumSerie << endl;
}