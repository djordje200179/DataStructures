#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

void ll_test();
void bt_test();

int main() {
	ll_test();
	bt_test();

	_CrtDumpMemoryLeaks();

	return 0;
}