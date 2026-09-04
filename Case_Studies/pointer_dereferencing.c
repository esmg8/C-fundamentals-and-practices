#include <stdio.h>

int main() {
	int *xPtr;
	int first=7, second=8;
	xPtr=&first;
	
	printf("%d ", *xPtr);
	
	xPtr=&second;
	printf("\n%d ", *xPtr);

	
	return 0;
}