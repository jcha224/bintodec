// John Chang
/* Converts binary to decimal and completes math operations */
#include <stdio.h>

float binToDec(char theBin[]);
float doMath(float theVal1, char theSym[], float theVal2);
void decToBin(double val);
void printBin(char input[]);
int main(void) {
	int bool = 0;
	float val1 = 0, val2 = 0, total = 0;
	char input1[15], input2[15], input3[15];
	setvbuf(stdout, NULL, _IONBF, 0);
	while (bool == 0) {
		printf("Enter an expression using binary numbers or Q to quit: ");
		scanf("%s", input1);
		if (input1[0] == 'q' || input1[0] == 'Q') {
			bool = 1;
		} else {
			scanf("%s%s", input2, input3);
			val1 = binToDec(input1);
			val2 = binToDec(input3);
			total = doMath(val1, input2, val2);
			printf("%.10f %c %.10f ", val1, input2[0], val2);
			printf("= %.10f\n", total);
			printBin(input1);
			printf("%c ", input2[0]);
			printBin(input3);
			printf("= ");
			decToBin((double) total);
		}
	}
	return 0;
}
float binToDec(char theBin[]) {
	int period = 0;
	float total = 0, dec1 = 0.5;
	for (int i = 0; theBin[i] != '\0'; i++) {
		if (theBin[i] == '.') {
			period = 1;
		} else if (period == 0) {
			total = total * 2;
			if (theBin[i] == '1') {
				total = total + 1;
			}
		} else {
			if (theBin[i] == '1') {
				total = total + dec1;
			}
			dec1 = dec1 * (float) .5;
		}
	}
	return total;
}
float doMath(float theVal1, char theSym[], float theVal2) {
	float total;
	if (theSym[0] == '/') {
		total = theVal1 / theVal2;
	} else if (theSym[0] == '+') {
		total = theVal1 + theVal2;
	} else if (theSym[0] == '-') {
		total = theVal1 - theVal2;
	} else if (theSym[0] == '*') {
		total = theVal1 * theVal2;
	}
	return total;
}
void printThis(char bin[]) {
	for (int i = 0; bin[i] != '\0'; i++) {
		if (bin[0] == '.') {
			printf("0");
		}
		printf("%c", bin[i]);
	}
	printf("\n");
}
void decToBin(double val) {
	char bin[15];
	double current = .5;
	int power = 0, temp = 1;
	for (; temp < val; power++) {
		temp = temp * 2;
	}
	bin[power] = '.';
	for (int i = 0; i < power; i++) {
		temp = temp / 2;
		if (temp < val) {
			val = val - temp;
			bin[i] = '1';
		} else {
			bin[i] = '0';
		}
	}
	power++;
	for (int i = 0; val > 0 && i < 20; i++) {
		if (current <= val) {
			val = val - current;
			bin[power] = '1';
		} else {
			bin[power] = '0';
		}
		power++;
		current = current * .5;
	}
	printThis(bin);
}
void printBin(char input[]) {
	for (int i = 0; input[i] != '\0'; i++) {
		printf("%c", input[i]);
	}
	printf(" ");
}
