#include <stdio.h>
#include <stdlib.h>

// creates a global array of months from January to December
const char* months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

// initializes the sales array with 12 elements (one for each month)
float sales[12];

// reads the input file and stores the values in the sales array
// returns 1 if the file is not found
int Input_file() {
	FILE *Input_file;
	Input_file = fopen("input.txt", "r");

	if (Input_file == NULL) {
		printf("Error: File not found\n");
		return 1;
	}

	// reads each number and stores it in the sales array starting from 0 to 11
	for (int i = 0; i < 12; i++) {
		fscanf(Input_file, "%f", &sales[i]);
	}
	// closes the file
	fclose(Input_file);
	return 0;
}

// main function that calls the Input_file function and prints the sales report
int main() {
	// checks if the file is not found
	if (Input_file() == 1) {
		return 1;
	}

	// prints the monthly sales in order taken from the input file
	printf("Monthly sales report for 2022:\n\n");
	printf("Month\t\tSales\n");
	for (int i = 0; i < 12; i++) {
		printf("%-10s\t$%.2f\n", months[i], sales[i]);
	}

	// creates float variables to store the minimum, maximum, and average of the monthly sales
	float min = sales[0];
	float max = sales[0];
	float avg = 0;
	// loops thorugh the sales array to and compares each value to find the minimum and maximum
	for (int i = 0; i < 12; i++) {
		if (sales[i] < min) {
			min = sales[i];
		}
		if (sales[i] > max) {
			max = sales[i];
		}
		// 
		avg += sales[i];
	}
	// calculates the average of the monthly sales by dividing the sum of all the sales by 12
	avg /= 12;

	// prints the sales summary using the values we just calculated
	printf("\nSales summary:\n\n");
	printf("Minimum sales: $%.2f (%s)\n", min, months[0]);
	printf("Maximum sales: $%.2f (%s)\n", max, months[11]);
	printf("Average sales: $%.2f\n", avg);

	// prints the six-month moving average report
	printf("\nSix-Month Moving Average Report:\n\n");
	// loops through the sales array to calculate the average of the sales for each 6 months
	for (int i = 0; i < 7; i++) {
		float sum = 0;
		// adds the sales for each month in the 6 month period
		for (int j = i; j < i + 6; j++) {
			sum += sales[j];
		}
		// calculates the average by dividing the sum by 6 and prints the result
		printf("%-10s - %-10s $%.2f\n", months[i], months[i + 5], sum / 6);
	}

	// uses selection sort to sort the sales array from the highest sales month to the lowest
	printf("\nSales Report (Highest to Lowest):\n\n");
	printf("  %-15s %s\n", "Month", "Sales");
	// loops through the sales array to compare each value to the rest of the values and sorts them in descending order
	for (int i = 0; i < 11; i++) {
		for (int j = i + 1; j < 12; j++) {
			// if the value at index j is greater than the value at index i, swap the values
			if (sales[j] > sales[i]) {
				float temp = sales[i];
				sales[i] = sales[j];
				sales[j] = temp;

				// swaps the months in the months array as well
				const char* tempMonth = months[i];
				months[i] = months[j];
				months[j] = tempMonth;
			}
		}
	}

	// once all the values are sorted, prints the months and the sales in descending order and in a tabular format
	for (int i = 0; i < 12; i++) {
		printf("%-10s\t$%.2f\n", months[i], sales[i]);
	}

	// returns 0 if the program runs successfully
	return 0;
}