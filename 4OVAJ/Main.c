#include "Header.h"

int main() {

	pointer head_1 = createElement(0, 0);
	pointer head_2 = createElement(0, 0);
	pointer result = createElement(0, 0);
	pushFromFile("en_livstid_i_krig.txt", head_1);
	pushFromFile("Soldier_of_heaven.txt", head_2);


	printf("First Polynomial: ");
	printStack(head_1->next);

	printf("\n");

	printf("Second Polynomial: ");
	printStack(head_2->next);

	printf("\n");

	printf("Added: ");
	addPoynomials(head_1, head_2, result);
	printStack(result->next);
	selfRegulate(result);
	printf("\n\t");
	printStack(result->next);

	printf("\n");

	printf("Multiplied: ");


	printf("\n");

	return 0;
}