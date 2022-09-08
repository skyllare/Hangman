/*******************************************************************************
 * Programmers:                                *
 * Class: CptS 122; Lab Section 10                                             *
 * Programming Assignment: 9	                                               *
 * Date: 4/26/2022                                                             *
 *                                                                             *
 * Description: This program stimulates a game of Hangman. There are three     *
 *				levels with varying difficulty (word length and amount of	   *
 *				guesses). The player guesses letters until they run out of	   *
 *				guesses or guess the word correctly.						   *
 *																			   *
 * Relevant Formulas: Refer to each function definition.                       *
 ******************************************************************************/

#include "EasyLevel.h"

/*************************************************************
 * Function: Easy ()								         *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: sets the postition, color, and rotation		 *
 *				of both shoes								 *
 * Input parameters: xPos and yPos (x and y values all	 	 *
 *					drawings are based on)					 *
 * Returns: Nothing.                                         *
 * Preconditions:   none									 *
 * Postconditions:	none									 *
 *								   					         *
 *************************************************************/
Easy::Easy(const int xPos, const int yPos) : Medium(xPos, yPos) // 200, 900
{
	rightShoe.setPosition(xPos + 510, yPos - 175);
	rightShoe.setFillColor(sf::Color(134, 188, 100));
	rightShoe.rotate(-70);

	leftShoe.setPosition(xPos + 390, yPos - 210);
	leftShoe.setFillColor(sf::Color(134, 188, 100));
	leftShoe.rotate(70);
}

/*************************************************************
 * Function: getRightShoe ()							     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: sets the postition, color, and rotation		 *
 *				of both shoes								 *
 * Input parameters: none									 *
 * Returns: RetangleShape is returned					     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
sf::RectangleShape Easy::getRightShoe()
{
	return rightShoe;
}


/*************************************************************
 * Function: getLeftShoe ()								     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: sets the postition, color, and rotation		 *
 *				of both shoes								 *
 * Input parameters: none									 *
 * Returns: RetangleShape is returned					     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
sf::RectangleShape Easy::getLeftShoe()
{
	return leftShoe;
}


/*************************************************************
 * Function: getRandomWord ()							     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: choses a word randomly from word bank		 *
 * Input parameters: none									 *
 * Returns: string										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
string Easy::getRandomWord()
{
	string chosenFourLetterWord;

	srand(time(NULL));
	int i = rand() % 99 + 1;
	chosenFourLetterWord = fourLetterWords[i];

	return chosenFourLetterWord;
}


	
/*************************************************************
 * Function: setBoolsToFalse ()							     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: sets all bool values to false 				 *
 * Input parameters: none									 *
 * Returns: nothing										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
void Easy::setBoolsToFalse()
{
	headDrawn = false;
	bodyDrawn = false;
	rightArmDrawn = false;
	leftArmDrawn = false;
	rightLegDrawn = false;
	leftLegDrawn = false;
	firstLetter = false;
	secondLetter = false;
	thirdLetter = false;
	fourthLetter = false;
	fifthLetter = false;
	sixthLetter = false;

	shirtDrawn = false;
	pantsDrawn = false;

	leftShoeDrawn = false;
	rightShoeDrawn = false;
}


	
/*************************************************************
 * Function: guess ()									     *
 * Date Created: 4/18/2022								     *
 * Date Last Modified: 4/18/2022                             *
 * Description: sets the postition, color, and rotation		 *
 *				of both shoes								 *
 * Input parameters: string for random word, char for		 *
 *					 letter guess, ints	for total and total  *
 *					 correct guesses						 *
 * Returns: int											     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
int Easy::guess(string word, char letter, int correctGuessCount, int guessCount)
{
	int correctTemp = correctGuessCount;
	for (int i = 0; i < 4; i++)
	{
		if (word[i] == letter)
		{

			if (i == 0)
			{

				setFirstLetter(true);
				correctGuessCount++;


			}
			if (i == 1)
			{

				setSecondLetter(true);
				correctGuessCount++;
			}
			if (i == 2)
			{

				setThirdLetter(true);
				correctGuessCount++;
			}
			if (i == 3)
			{

				setFourthLetter(true);
				correctGuessCount++;
			}
		}
	}
	if (correctTemp == correctGuessCount)//this means the guessed letter was not in the word
	{
		incorrectGuess(guessCount, correctGuessCount);
	}
	return correctGuessCount;
}


/*************************************************************
 * Function: incorrectGuess ()							     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: runs when the char is not in the the string  *
 * Input parameters: ints for total guess and correct guess  *
*					 count									 *
 * Returns: nothing.									     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
void Easy::incorrectGuess(int guessCount, int correctGuessCount)
{
	int incorrectGuessCount = guessCount - correctGuessCount;

	if (incorrectGuessCount == 1)
	{
		headDrawn = true;
	}
	if (incorrectGuessCount == 2)
	{
		bodyDrawn = true;
	}
	if (incorrectGuessCount == 3)
	{
		rightArmDrawn = true;
	}
	if (incorrectGuessCount == 4)
	{
		leftArmDrawn = true;
	}
	if (incorrectGuessCount == 5)
	{
		rightLegDrawn = true;
	}
	if (incorrectGuessCount == 6)
	{
		leftLegDrawn = true;
	}
	if (incorrectGuessCount == 7)
	{
		shirtDrawn = true;
	}
	if (incorrectGuessCount == 8)
	{
		pantsDrawn = true;
	}
	if (incorrectGuessCount == 9)
	{
		rightShoeDrawn = true;
	}
	if (incorrectGuessCount == 10)
	{
		leftShoeDrawn = true;
	}
}
/*
lives key:
	1 = head
	2 = body
	3 = right arm
	4 = left arm
	5 = right leg
	6 = left leg
	7 = shirt
	8 = pants
	9 = right shoe
	10 = left shoe
*/



/*************************************************************
 * Function: getRightShoeDrawn ()							 *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: gets if the right shoe needs to be drawn	 *
 * Input parameters: none									 *
 * Returns: Bool										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
bool Easy::getRightShoeDrawn()
{
	return rightShoeDrawn;
}


/*************************************************************
 * Function: getLeftShoeDrawn ()							 *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: gets if the left shoe needs to be drawn	   	 *
 * Input parameters: none									 *
 * Returns: Bool										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
bool Easy::getLeftShoeDrawn()
{
	return leftShoeDrawn;
}



