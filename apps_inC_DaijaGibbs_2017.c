//Brandaija Gibbs
//Large Program 2: Apps
//11/1/17


#define _CRT_NO_SECURE_WARNING
#include <stdio.h>
#include <ctype.h>

// Displays the list of apps available
//prompts for the user’s selection and sets the value of the selection
void DisplayApps(char *selectionPtr);
//sets the cost of the item based on value stored in purchase
void SetCost(char selection, double *costPtr);
//Displays the codes for the user to input money - gets user input amounts
//compares the cash amount codes and updates the deposit amount
void PaymentOptions(double *depositPtr, double cost);
//Asks the user if they want another app
//compares the amount the user has in deposits to the price of app selected.
//It returns 1 if the amount is enough to cover the cost, 0 if there is not enough.
int Compare(double deposit, double choiceCost);
//uses PaymentOptions function to display and collect dollar amounts from the user
//uses Compare function to keep comparing the added deposited amount to the item cost.
void Pay(double *depositPtr, double choiceCost);
//calculates the amount of leftover from your deposits
void GetChange(double *depositPtr, double choiceCost);
void DoItAgain(char *quitPtr);

int main()
{
	char again, selection;
	double cost, deposit = 0.00;


	//Greet 
	printf("Hello. Welcome to App World.\n\n");
	//Display amount of money
	printf("You have $%.2f in your account.\n", deposit);
	printf("__________________________________\n\n\n");

	do
	{

		//Present the app choices
		DisplayApps(&selection);
		printf("You selected %c.\n\n", selection);

		//use char value of character to set value of selection to value of cost
		SetCost(selection, &cost);
		printf("The cost of your item is $%.2f.\n", cost);

	
		//Present, get and add money selection + Check if enough 
		//Pay func = PaymentOptions + Compare functions
		Pay(&deposit, cost);

		GetChange(&deposit, cost);
		printf("   & you have purchased %c.\n", selection);
		printf("__________________________________\n\n\n");

		//Last Function in Do While 
		DoItAgain(&again);
		printf("You selected:  %c \n", again);
		printf("__________________________________");

	} while (again == 'Y');





	return 0;
}





// Displays the list of apps available
//prompts for the user’s selection and sets the value of the selection
void DisplayApps(char *selectionPtr)
{
	printf("HERE ARE APP THE SELECTIONS: \n\n");
	printf("L : LogMeIn          $1399.99\n");
	printf("V : VIP Black        $999.99\n");
	printf("F : Facetune         $3.99\n");
	printf("T : Tap Menu         $399.99\n");
	printf("M : Minecraft        $6.99\n\n");

	printf("Please enter a selection:  ");
	scanf(" %c", selectionPtr);
	*selectionPtr = toupper(*selectionPtr);

}

//sets the cost of the item based on value stored in purchase
void SetCost(char selection, double *costPtr)
{
	if (selection == 'L')
	{
		*costPtr = 1399.99;
	}
	if (selection == 'V')
	{
		*costPtr = 999.99;
	}
	if (selection == 'F')
	{
		*costPtr = 3.99;
	}
	if (selection == 'T')
	{
		*costPtr = 399.99;
	}
	else if (selection == 'M')
	{
		*costPtr = 6.99;
	}
}


//Displays the codes for the user to input money - gets user input amounts
//compares the cash amount codes and updates the deposit amount
void PaymentOptions(double *depositPtr, double cost)
{

	int input;
	
		printf("Please credit your money by selection.\n\n");
		printf("---- 1     $1000.00\n");
		printf("---- 2     $500.00\n");
		printf("---- 3     $100.00\n");
		printf("---- 4     $10.00\n");
		scanf("%d", &input);


		if (input == 1)
		{
			*depositPtr = *depositPtr + 1000.00;
		}
		if (input == 2)
		{
			*depositPtr = *depositPtr + 500.00;
		}
		if (input == 3)
		{
			*depositPtr = *depositPtr + 100.00;
		}
		if (input == 4)
		{
			*depositPtr = *depositPtr + 10.00;
		}
		


}

//compares the amount the user has in deposits to the price of app selected.
//It returns 1 if the amount is enough to cover the cost, 0 if there is not enough.
int Compare(double deposit, double choiceCost)
{

	//run cost = choiceCost
	//run deposit = 0.00

	if (deposit >= choiceCost)
	{
		return 1; // is enough 
	}
	else if (deposit < choiceCost)
	{
		return 0; // is not enough 
	}
	

}

//call PaymentOptions to display and collect dollar amounts from the user // void PaymentOptions(double *depositPtr, double cost);
//call Compare function to keep comparing the added deposited amount to the item cost. //int Compare(double deposit, double choiceCost);
// Pay(&deposit, cost);
void Pay(double *depositPtr, double choiceCost)
{
	
	int returnit; 

	returnit = Compare(*depositPtr, choiceCost);



	while (returnit == 0)
	{//call pay options fucntion to update bank 
		PaymentOptions(depositPtr, choiceCost);
		printf("\nCurrent value of deposit is %.2f.\n", *depositPtr);

		returnit = Compare(*depositPtr, choiceCost);
		printf("You returned a:  %d. (1 ENOUGH, 0 NOT ENOUGH):\n\n", returnit);
	}

}



//calculates the amount of leftover from your deposits
void GetChange(double *depositPtr, double choiceCost)
{
	double leftover;
	leftover = *depositPtr - choiceCost; 
	printf("\nCongrats, you now have $%.2f left in your account.\n", leftover);
}

//Asks the user if they want another app
// Function for starting game over
void DoItAgain(char *quitPtr)
{

	printf("\nWould you like to make another purchase (Y/N)?   ");
	scanf(" %c", quitPtr);
	*quitPtr = toupper(*quitPtr);

}

