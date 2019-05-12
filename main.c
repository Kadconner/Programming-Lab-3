#include <stdio.h>
#include <stdlib.h>

int Fib_rec(int size) {
	if (size == 0) return 0;

	if (size == 1) return 1;

	return Fib_rec(size - 2) + Fib_rec(size - 1);
}

int Fib_iter(int el1, int el2, int size, int counter) {
	if (counter == size) {
		return el1;
	}
	return Fib_iter(el1 + el2, el1, size, counter + 1);
}

int Fib_it(int size) { return Fib_iter(0, 1, size, 0); }

int Sum_rec(int array[], int size) {
	if (size <= 0) return 0;
	return (Sum_rec(array, size - 1) + array[size - 1]);
}

int Sum_iter(int sum, int counter, int size, int array[]) {
	if (counter == size) {
		return sum;
	}
	return Sum_iter(sum + array[counter], counter + 1, size, array);
}

int Sum(int array[], int size) { return Sum_iter(0, 0, size, array); }

void itc(int num, char *a) {
	int i = 0, t = 10, j;
	char c;
	while (num != 0) {
		a[i] = ((num % t) + '0');
		t *= 10;
		num /= 10;
		i++;
	}
	for (j = i - 1, i = 0; i < j; i++, j--) {
		c = a[i];
		a[i] = a[j];
		a[j] = c;
	}
}
int main() {
	char a[10] = "";
	int size, i;
	printf("Enter size array ");
	scanf("%d", &size);
	int array[size];
	for (i = 0; i < size; i++) {
		array[i] = i;
	}
	printf("Array: ");
	for (i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	printf("Sum_rec = ");
	printf("%d\n", Sum_rec(array, size));
	printf("Sum_iter = ");
	printf("%d\n", Sum(array, size));
	printf("Fib_rec = ");
	printf("%d\n", Fib_rec(size));
	printf("Fib_iter = ");
	printf("%d\n", Fib_it(size));
	itc(size, a);
	printf("Converting a number(%d) to a string: ", size);
	puts(a);
	return 0;
}
