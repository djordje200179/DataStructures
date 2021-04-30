#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "tests.h"

int main() {
	ll_test();
	pq_test();

	bt_test();

	_CrtDumpMemoryLeaks();

	return 0;
}