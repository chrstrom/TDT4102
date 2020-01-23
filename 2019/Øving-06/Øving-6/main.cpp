#include "std_lib_facilities.h"
#include "Oppg 1.h"
#include "Oppg 2.h"
#include "Oppg 3.h"
#include "Oppg 4.h"

int main(){
	setlocale(LC_ALL, "norwegian");
	CourseCatalog catalog;
	vector<Temps> temperatures;

	int choice;
	cout << "Menu: \n"
		 << "1: oppg1\n"
		 << "2: oppg2\n"
		 << "3: oppg3\n"
		 << "4: oppg4\n";

	cin >> choice;
	switch (choice) {
	case 1:
		cout << "1: inputWordToFile(); \n";
		inputWordToFile();

		cout << "2: addNumberCopyFile(); \n";
		addNumberCopyFile();
		break;
	case 2:
		countChars("grunnlov");
		break;
	case 3:
		
		cout << "Uten innlasting: \n";
		cout << catalog <<'\n';

		test(catalog);							//Oppretter fil for avlesning
		catalog.saveData("oppg3");
		cout << "Med innlasting: \n";
		catalog.loadData("oppg3");
		cout << catalog << '\n';

		break;
	case 4:
		temperatures = readTemps("temperatures");
		printTemps(temperatures);
		break;

	default:
		cout << "Invalid choice\n";
	}

	return 0;
}



/*int testInt;
cout << "Enter int: " << endl;

while (!(cin >> testInt)) {

	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Not an int, try again!" << endl;
	}
}

cout << testInt;*/