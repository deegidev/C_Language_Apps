//Brandaija Gibbs
//Lab5: Arrays and File Pointers
//11/8/17

#define _CRT_NO_SECURE_WARNING
#include <stdio.h>
#include <ctype.h>
#define SIZE 20

int HowMany();
void PrintNum(int [], int );
void Sum(int [], int );

int main()
{
	int num, ar[SIZE];
	FILE *inPtr;
	inPtr = fopen("numInput.txt", "r");
	
	//Ask the user how many integers to get from the file<= 20
	num = HowMany();

	//Use a loop to read the integers into the array from the input file
	int i;
	for (i = 0; i < num; i++)
	{
		fscanf(inPtr, "%d", &ar[i]);
	}

	//Use a loop to print the array onto the screen in a column.	
	PrintNum(ar, num);

	//Use a loop to add up all the items in the array and store the sum
	Sum(ar, num);

	fclose(inPtr);
	return 0;
}

//Ask the user how many integers to get from the file <= 20
int HowMany()
{
	int num;
	printf("How many integers (0-20) would you like to get from the file? \n");
	scanf("%d", &num);
	return num;
}

//Use a loop to print the array onto the screen in a column
void PrintNum(int ar1[], int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		printf("%d\n", ar1[i]);
	}
}

/*Use a loop to add up all the items in the array and store the sum
Open a file called resOut.txt
And fprintf to write the sum to the output file*/
void Sum(int ar[], int count)
{
	FILE *outPtr;
	outPtr = fopen("resOut.txt", "w");

	int i, total = 0;
	for (i = 0; i < count; i++)
	{
		total = total + ar[i];
	}
	printf("The total of all these numbers is %d.\n", total);

	fprintf(outPtr, "%d", total);
	fclose(outPtr);
}
