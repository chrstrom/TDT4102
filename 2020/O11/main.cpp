
#include "iterators.h"
#include "orderedList.h"

int main() {
	//print_using_iterator();

	// std::vector<std::string> vec{"Lorem", "Ipsum", "Dolor", "Lorem"};
	// std::set<std::string> s{"Lorem", "Ipsum", "Dolor", "Lorem"};
	// replace_vec(vec, "Lorem", "Latin");
	// replace_set(s, "Lorem", "Latin");

	// for(auto se : s) {
	// 	std::cout << se << '\n';
	// }

	Person p1{"A", "A"};
	Person p2{"B", "B"};
	Person p3{"A", "B"};
	Person p4{"D", "D"};
	Person p5{"D", "B"};

	std::list<Person> ls;
	insertOrdered(ls, p1);
	insertOrdered(ls, p2);
	insertOrdered(ls, p3);
	insertOrdered(ls, p4);
	insertOrdered(ls, p5);

	for(auto& l: ls) {
		std::cout << l << '\n';
	}

	return 0;
}