#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    hanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    hanoi(n - 1, aux, to, from);
}
int main(int argc, char *argv[]) {
	   int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    hanoi(n, 'A', 'C', 'B');

	return 0;
}
