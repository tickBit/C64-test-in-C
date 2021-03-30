#include <conio.h>
#include <stdlib.h>
#include <peekpoke.h>
#include <cc65.h>
#include <cbm.h>
#include <6502.h>

int x[12], y[12], dx[12], dy[12];
int i;

void routine(void);


int main (void)
{
	clrscr();
	for (i = 0; i < 12; i++) {
		x[i] = i+2; y[i] = i+2; dx[i] = 1; dy[i] = 1;
	}

	while (0 == 0) {
		waitvsync();
		routine();
		if (PEEK(197) == 60) return EXIT_SUCCESS;
	}
	
	return EXIT_SUCCESS;
}

void routine(void) {

		for (i = 0; i < 12; i++) {
			POKE(1024+x[i]+y[i]*40,42);
			POKE(1024+x[0]+y[0]*40,32);
		
			if (x[i] < 1 || x[i] > 38) dx[i] =-dx[i];
			if (y[i] < 1 || y[i] > 23) dy[i] =-dy[i];
	
			x[i] = x[i] + dx[i];
			y[i] = y[i] + dy[i];

		}		
}