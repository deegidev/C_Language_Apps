//Brandaija Gibbs
//Plural Large Program 3
//11/22/2017

#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//greets the user 
void Greeting();
//gets word from the user 
void GetWord(char[]);
//changes word toupper
void WordUpper(char word[]);
//determines which rule applied to word, pass it the original
int WhichRule(char word[]);
//applies rule 1, changes Y to IES
void ApplyRuleOne(char plural[]);
//applies rule 2, adds ES to S,CH,SH 
void ApplyRuleTwo(char plural[]);
//applies rule 3, adds S to end of word
void ApplyRuleThree(char plural[]);
//adds the word to the file 
void AddToFile(FILE *outPtr, char word[], char plural[]);

int main()
{
	char again;
	char word[20]; //original word from user toupper
	char plural[20]; //will hold plural version of word 

	Greeting(); //greet user
	FILE *outPtr = fopen("pluralWords.txt", "w"); //connect to output file

												  //ask and get y/n
	printf("Would you like to enter a word(Y or N)?");
	scanf(" %c", &again);
	again = toupper(again);

	while (again == 'Y')
	{
		GetWord(word);//ask and get word from user
		printf("You entered: %s \n", word);

		WordUpper(word);//change word to upper

		strcpy(plural, word); //make a copy of the word (plural)

		char returned = WhichRule(word); //determine which rule to use, pass it the original
		printf("Applying Rule: %d\n", returned);

		if (returned == 1) //apply rule 1, Y to IES
		{
			ApplyRuleOne(plural);
			printf("Your word is %s. Your new word is %s.\n\n", word, plural);
		}
		else if (returned == 2) //apply rule 2, adds ES to S,CH,SH 
		{
			ApplyRuleTwo(plural);
			printf("Your word is %s. Your new word is %s.\n\n", word, plural);
		}
		else //apply rule 3, add S to end of word
		{
			ApplyRuleThree(plural);
			printf("Your word is %s. Your new word is %s.\n\n", word, plural);
		}


		AddToFile(outPtr, word, plural);//save original(word) and plural to output file
		printf("Adding the words to file...\n");
		printf("----------------------------------------------\n\n");

		printf("Would you like to enter a word(Y or N)?"); //ask and get y/n as update
		scanf(" %c", &again);
		again = toupper(again);
	}

	fclose(outPtr);//close the output file
	printf("\n\n*****Goodbye!*****\n\n"); //say goodbye to user 
	return 0;
}

//greets the user 
void Greeting()
{
	printf("*****WELCOME TO THE PLURALIZER!!!*****\n\n");
}

//gets word from the user 
void GetWord(char word[])
{
	printf("\nEnter a word: ");
	scanf(" %s", word);  //get word from user
}


//changes word toupper
void WordUpper(char word[])
{
	int null = strlen(word);
	int i;
	for (i = 0; i < null; i++)
	{
		word[i] = toupper(word[i]);
	}
}

//determines which rule applied to word, pass it the original
int WhichRule(char word[])
{
	int null = strlen(word);
	if (word[null - 1] == 'Y')
		return 1;
	else if (word[null - 1] == 'H' && word[null - 2] == 'C')
		return 2;
	else if (word[null - 1] == 'H' && word[null - 2] == 'S')
		return 2;
	else if (word[null - 1] == 'S')
		return 2;
	else
		return 3;
}

//applies rule 1, changes Y to I
void ApplyRuleOne(char plural[])
{
	int null = strlen(plural);
	plural[null - 1] = 'I';
	strcat(plural, "ES");
}

//applies rule 2, adds ES to S,CH,SH 
void ApplyRuleTwo(char plural[])
{
	strcat(plural, "ES");
}

//applies rule 3, adds S to end of word
void ApplyRuleThree(char plural[])
{
	strcat(plural, "S");
}

//adds the word to the file 
void AddToFile(FILE *outPtr, char word[], char plural[])
{
	fprintf(outPtr, "Your word is %s. Your new word is %s.\n\n", word, plural);
}