#include "Interface.h"

using namespace std;

int main()
{
	welcome();
	TelDir *dir = init();

	while (1) {
		mainLoop(dir);
	}
}