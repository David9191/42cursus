#include <stdio.h>

int a = 10;

void sub() {

	printf("sub()==>a=%d \n", a);

}

int main() {
	switch (1) {
		case 1:
		case 2: printf("case 1, case 2 \n");
		case 3:
		case 4: printf("case 3, case 4 \n");
	}
}
