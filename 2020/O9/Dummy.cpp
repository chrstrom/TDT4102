#include "Dummy.h"
#include <memory>


void dummyTest() {
    Dummy a;
    *a.num = 4;


    Dummy b{a};
    Dummy c;
    c = a;

    std::cout << "a: " << *a.num << '\n';
    std::cout << "b: " << *b.num << '\n';
    std::cout << "c: " << *c.num << '\n';

    *b.num = 3;
    *c.num = 5;

    std::cout << "a: " << *a.num << '\n';
    std::cout << "b: " << *b.num << '\n';
    std::cout << "c: " << *c.num << '\n';

}

// Linje 20 er siste gang vi bruker objektet Dummy a.
// Siden b er konstruert vha a, vil int* i objekt b peke til samme int som
// int* i objekt a. På lik måte vil pekeren til objekt c henge.

// Den mest sannsynlige forklaringen her er at siden vi har UB, så klarer
// programmet å innhente seg med blind flaks.

// Et mindre sannsynlig alternativ er at det har med paging å gjøre.
// Så lenge vi akksesserer minne innenfor gjeldende page, får vi ingen problemer,
// selv om vi teknisk sett tar på minne som ikke er allokert.