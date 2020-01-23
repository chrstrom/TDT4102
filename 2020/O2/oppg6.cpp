#include "headers/oppg6.h"

vector<int> calculateSeries(double amt, double interest, int yrs) {
    vector<int> payments;
    for(int i = 0; i < yrs; i++) {
        payments.push_back(static_cast<int>(amt/yrs + (interest/100)*(amt - i * amt/yrs)));
    }
    return payments;
}

vector<int> calculateAnnuity(double amt, double interest, int yrs) {
    vector<int> payments;
    for(int i = 0; i < yrs; i++) {
        payments.push_back(amt*(interest/100)/(1-pow(1+interest/100, -yrs)));
    }
    
    return payments;
}

void differenceSeriesAnnuity(double amt, double interest, int yrs) {
    constexpr int sepW = 16;
    constexpr char sep = ' ';
    int totalSeries = 0; 
    int totalAnnuity = 0;
    int totalDifference = 0;

    vector<int> series = calculateSeries(amt, interest, yrs);
    vector<int> annuity = calculateAnnuity(amt, interest, yrs);

    // cout formatting
    cout.setf(ios_base::left);
    cout.fill(sep);

    // Title
    cout << setw(sepW) << "År";
	cout << setw(sepW) << "Annuitet";
	cout << setw(sepW) << "Serie" << "Differanse\n"; ;

    // Print table contents
    for(int i = 0; i < series.size(); i++) {
        int currentSeries = series[i];
        int currentAnnuity = annuity[i];
        int currentDifference = currentAnnuity - currentSeries;
        
        cout << setw(sepW) << i+1;
        cout << setw(sepW) << currentAnnuity;
        cout << setw(sepW) << currentSeries;
        cout << setw(sepW) << currentDifference << '\n';

        totalSeries += currentSeries;
        totalAnnuity += currentAnnuity;
        totalDifference += currentDifference;
    }
    
    // Print totals
    cout << setw(sepW) << "Total";
	cout << setw(sepW) << totalAnnuity;
	cout << setw(sepW) << totalSeries;
	cout << setw(sepW) << totalDifference; 
}