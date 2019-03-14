#include "std_lib_facilities.h"

//A
vector<int> caclulateSeries(int totaltLån, int antallAvdrag, float rente) {
	int gjenståendeLån, innbetaling, delbetaling;
	vector<int> payments;

	delbetaling = totaltLån / antallAvdrag;
	gjenståendeLån = totaltLån;

	for (int avdrag = 1; avdrag <= antallAvdrag; ++avdrag) {
		innbetaling = delbetaling + (rente / 100)*gjenståendeLån;
		gjenståendeLån -= delbetaling;

		payments.push_back(innbetaling);
	}
	return payments;
}

//B
vector<int> calculateAnnuity(int totaltLån, int antallAvdrag, float rente) {
	int innbetaling;
	vector<int> payments;

	for (int avdrag = 1; avdrag <= antallAvdrag; ++avdrag) {
		innbetaling = totaltLån * ((rente / 100) / (1 - pow((1 + rente / 100), -1*antallAvdrag)));
		payments.push_back(innbetaling);
	}
	return payments;
}

//C
void printLoans() {
	int totaltLån, antallAvdrag;
	float rente;
	const char sep = ' ';
	const int sepWidth = 16;
	const int sepWidthShort = 4;

	cout << "Lån: \n";
	cin >> totaltLån;
	cout << "Antall avdrag: \n";
	cin >> antallAvdrag;
	cout << "Rente: \n";
	cin >> rente;

	vector<int> serieLån = caclulateSeries(totaltLån, antallAvdrag, rente);
	vector<int> annuitetsLån = calculateAnnuity(totaltLån, antallAvdrag, rente);

//Overskrift for tabell (spørsmål: er det noen måte å unngå så mange "... left << setw() << setfill() ....????")
	cout << left << setw(sepWidthShort) << setfill(sep) << "År";
	cout << left << setw(sepWidth) << setfill(sep) << "   Annuitet";
	cout << left << setw(sepWidth) << setfill(sep) << "  Serie";
	cout << left << setw(sepWidth) << setfill(sep) << "   Differanse" << endl;

//Generering av tabell
	int totalSumAnnuitet = 0;
	int totalSumSerie = 0;

	unsigned int len = serieLån.size();

	for (int i = 0; i < len; ++i) {
		int betalingAnnuitet = annuitetsLån[i];
		int betalingSerie = serieLån[i];

		//Verdier for annuitetslån, serielån og differansen, i tabell 
		cout << left << setw(sepWidthShort) << setfill(sep) << i + 1;		//+1 siden i starter på 0, mens år starter på 1
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