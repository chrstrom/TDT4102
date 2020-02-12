#include "std_lib_facilities.h"
#include "CourseCatalog.h"
#include "fileUtil.h"
#include "Temps.h"
#include "TempsGraph.h"

int main() {
    string txtFolder = "txtfiles/";

    charStats(txtFolder + "grunnlov.txt");
    vector<Temps> temps = readTempsFromFile(txtFolder + "temperatures.txt");

    for(const auto& t : temps) {
        cout << t.max << " " << t.min << '\n';
    }

    drawTempGraph(temps);

    return 0;
}