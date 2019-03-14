#include <iostream>
#include <climits>
#include "Car.h"
#include "Person.h"
#include "Meeting.h"

/*DRØFTEOPPGAVE 2d)

 Burde deklareres med const Person& p siden vi kun ønsker å skrive ut informasjonen, ikke endre på den. Det er
 teknisk sett ikke nødvendig, med foretrukket å ha med, da man kan unngå potensielle bugs ved å bruke det.


Dersom intensjonen er å endre på variable etter de først er gitt verdier, kan man ikke sette const foran.
*/


ostream& operator<< (ostream& os, Meeting& m);
ostream& operator<< (ostream& os, const Person& person);

#include "myGUI.h"
int main() {
	using namespace Graph_lib;

	MeetingWindow mWin{ Point{20, 20}, winX, winY, "test" };

	gui_main();
	
	mWin.printPeople();

	cout << "Press enter to exit...";
	cin.get();
	return 0;
}

//
//ostream& operator<< (ostream& os, Meeting& m);
//ostream& operator<< (ostream& os, const Person& person);
//
//int main() {
//	int choice{ -1 };
//
//	Car carB{ 0 };
//	Car carC{ 3 };
//	Car* carBptr{ &carB };
//	Car* carCptr{ &carC };
//
//	Person personA{ "Jasse", "Jasse@StroustrupWorshippers.com" };
//	Person personB{ "Kasse", "Kasse@StroustrupWorshippers.com", carBptr };
//	Person personC{ "Lasse", "Lasse@StroustrupWorshippers.com", carCptr };
//	Person* personAptr{ &personA };
//	Person* personBptr{ &personB };
//	Person* personCptr{ &personC };
//
//	Meeting m{ 1, 1, 1, Campus::Trondheim, "test" , personCptr };
//
//	/////////////////////////////////////////////////////////////////////////////////////////
//	//TEST FOR POTENTIAL CODRIVING
//
//	Car carM2{ 3 }; Car* carM2ptr{ &carM2 };
//	Car carM3{ 3 }; Car* carM3ptr{ &carM3 };
//	Car carM4{ 3 }; Car* carM4ptr{ &carM4 };
//	Car carM5{ 3 }; Car* carM5ptr{ &carM5 };
//	Car carM6{ 3 }; Car* carM6ptr{ &carM6 };
//	Car carM7{ 3 }; Car* carM7ptr{ &carM7 };
//	Car carM8{ 3 }; Car* carM8ptr{ &carM8 };
//	Car carM9{ 3 }; Car* carM9ptr{ &carM9 };
//
//	Person leaderM2{ "leaderM2", "leaderM2@example.com", carM2ptr }; Person* leaderM2ptr{ &leaderM2 };
//	Person leaderM3{ "leaderM3", "leaderM3@example.com", carM3ptr }; Person* leaderM3ptr{ &leaderM3 };
//	Person leaderM4{ "leaderM4", "leaderM4@example.com", carM4ptr }; Person* leaderM4ptr{ &leaderM4 };
//	Person leaderM5{ "leaderM5", "leaderM5@example.com", carM5ptr }; Person* leaderM5ptr{ &leaderM5 };
//	Person leaderM6{ "leaderM6", "leaderM6@example.com", carM6ptr }; Person* leaderM6ptr{ &leaderM6 };
//	Person leaderM7{ "leaderM7", "leaderM7@example.com", carM7ptr }; Person* leaderM7ptr{ &leaderM7 };
//	Person leaderM8{ "leaderM8", "leaderM8@example.com", carM8ptr }; Person* leaderM8ptr{ &leaderM8 };
//	Person leaderM9{ "leaderM9", "leaderM9@example.com", carM9ptr }; Person* leaderM9ptr{ &leaderM9 };
//
//	Meeting m2{ 1,  9, 11, Campus::Trondheim, "Meeting2", leaderM2ptr };
//	Meeting m3{ 3, 10, 12, Campus::Trondheim, "Meeting3", leaderM3ptr };
//	Meeting m4{ 1, 10, 12, Campus::Trondheim, "Meeting4", leaderM4ptr };
//	Meeting m5{ 1, 14, 12, Campus::Trondheim, "Meeting5", leaderM5ptr };
//	Meeting m6{ 1, 10, 12, Campus::Trondheim, "Meeting6", leaderM6ptr };
//	Meeting m7{ 1,  9, 13, Campus::Trondheim, "Meeting7", leaderM7ptr };
//	Meeting m8{ 1,  7, 12, Campus::Trondheim, "Meeting8", leaderM8ptr };
//	Meeting m9{ 1,  8, 12, Campus::Trondheim, "Meeting9", leaderM9ptr };
//
//	vector<const Person*> potentialCoDriversM2{ m2.findPotentialCoDriving() };
//	vector<const Person*> potentialCoDriversM9{ m9.findPotentialCoDriving() };
//	vector<const Person*> potentialCoDriversM5{ m5.findPotentialCoDriving() };
//
//	for (const auto& drivers : potentialCoDriversM2) { cout << *drivers; }
//	cout << "-------------------------------------------------------------------------------\n\n";
//	for (const auto& drivers : potentialCoDriversM9) { cout << *drivers; }
//	cout << "-------------------------------------------------------------------------------\n\n";
//	for (const auto& drivers : potentialCoDriversM5) { cout << *drivers; }
//	///////////////////////////////////////////////////////////////////////////////////////
//
//
//	while (choice != 0) {
//		cout << "\nTests: \n"
//			<< "1: Person uten bil.\n"
//			<< "2: Person med bil, uten ledig seter.\n"
//			<< "3: Person med bil, med ledig seter.\n"
//			<< "4: Test for operator<< Meeting\n"
//			<< "0: Quit.\n";
//
//		cout << "Choice: \n";
//		cin >> choice;
//
//		while (cin.fail()) {
//			cin.clear();
//			cin.ignore(INT64_MAX, '\n');
//
//			cout << "Please input a number\n";
//
//			cout << "Choice: \n";
//			cin >> choice;
//		}
//
//
//		switch (choice) {
//
//		case 1:
//			cout << personA;
//
//			if (personA.hasAvailableSeats()) {
//				cout << "Available seats\n";
//			}
//			else {
//				cout << "No available seats\n";
//			}
//			break;
//
//		case 2:
//			cout << personB;
//
//			if (personB.hasAvailableSeats()) {
//				cout << "Available seats\n";
//			}
//			else {
//				cout << "No available seats\n";
//			}
//
//			break;
//
//		case 3:
//			cout << personC;
//
//			if (personC.hasAvailableSeats()) {
//				cout << "Available seats\n";
//			}
//			else {
//				cout << "No available seats\n";
//			}
//
//			break;
//
//		case 4:
//			m.addParticipants(personAptr);
//			m.addParticipants(personBptr);
//
//			cout << m;
//			break;
//
//		case 0:
//			cout << "Avslutter... \n";
//			break;
//
//		default:
//			cout << "Invalid choice. Try again. \n";
//		}
//	}
//	return 0;
//}

