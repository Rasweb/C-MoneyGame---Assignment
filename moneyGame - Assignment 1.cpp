#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 
	Shows player balance.
	Asks for a valid bet amount.
	Returns if bet is below balance and not negative.
*/

int getPlayerBet(int playerBalance){
	int betAmount;
	do
	{
		printf("You have %d SEK. How much would you like to bet? ", playerBalance);
		scanf_s("%d", &betAmount);

	} while (betAmount > playerBalance || betAmount < 0);
	return betAmount;
}

/*
	Asks user to chose a coin side.
	Prevents multiple characters.
	Returns if the desired characters are entered.
*/
char getPlayerGuess() {
	char coinFlipChoice;
	do
	{
		printf("What do you bet on (h/t): ");
		scanf_s(" %c", &coinFlipChoice);
		while (getchar() != '\n');
	
	} while (coinFlipChoice != 't' && coinFlipChoice != 'h');
	return coinFlipChoice;
}
/*
	Limits the rand between 1 - 100.
	Returns one side if below 53 or the other if above
*/
char getCoinToss(){
	int x = 1 + rand() % 100;
	if(x < 53 ){
		return 't';
	}
	else {
		return 'h';
	}
}

int main()
{
	// For better randomizing
	srand(time(0));

	// Outside loop to prevent reset
	int playerBalance = 100;

	/*
		Continues the gambling session
		Quits if player is broke or if bet is 0
	*/ 
	while (1) {
		if (playerBalance == 0) {
			printf("You are broke.");
			break;
		}
		int playerBet = getPlayerBet(playerBalance);
		if(playerBet == 0){
			printf("You left the table with %d SEK.", playerBalance);
			break;
		} 
		char playerChoice = getPlayerGuess();
		char tossResult = getCoinToss();

		printf("Tossing the coin...\n");
		if (tossResult == 't') {
			printf("It is tails.\n");
		}

		else {
			printf("It is heads.\n");
		}

		if (tossResult == playerChoice) {
			playerBalance = playerBalance + playerBet;
			printf("You have won %d SEK\n", playerBet);
		}
		else {
			playerBalance = playerBalance - playerBet;
			printf("You have lost %d SEK\n", playerBet);
		}
	}








}