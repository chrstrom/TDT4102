#include "Graph.h"
#include "Emoji.h"
#include "Emojis.h"
#include "Simple_window.h" 

int main() {
	Simple_window win{ Point{400, 400} ,1200, 600, "Øving 7" };

	//drawEmojis(win);
	win.wait_for_button();

	Vector_ref<Emoji> vec;
	vec = initVector();

	for (const auto& emoji : vec) {

		emoji->attachTo(win);

	}
	win.wait_for_button();

	return 0;
}

