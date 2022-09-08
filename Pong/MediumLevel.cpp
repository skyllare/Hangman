/*******************************************************************************
                                *
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

#include "MediumLevel.h"



 /*************************************************************
  * Function: Medium ()		                                  *
  * Date Created: 4/18/2022                                   *
  * Date Last Modified: 4/18/2022                             *
  * Description: This function initiates the position of each *
  *				 body part of the Hangman.					  *
  * Input parameters: two ints representing the x and y       *
  *					  position of the hanger.				  *
  * Returns: Nothing.				                          *
  * Preconditions: None.								      *
  * Postconditions: All the positions and colors of the body  *
  *					part shapes have been initialized.		  *
  *************************************************************/
Medium::Medium(const int xPos, const int yPos) : Hard(xPos, yPos)
{
	shirtBody.setPosition(xPos + 448, yPos - 335);
	shirtBody.setFillColor(sf::Color(231, 121, 141));

	rightSleeve.setPosition(xPos + 460, yPos - 306);
	rightSleeve.rotate(140);
	rightSleeve.setFillColor(sf::Color(231, 121, 141));

	leftSleeve.setPosition(xPos + 460, yPos - 300);
	leftSleeve.rotate(-140);
	leftSleeve.setFillColor(sf::Color(231, 121, 141));

	pants.setPosition(xPos + 448, yPos - 260);
	pants.setFillColor(sf::Color(94, 97, 139));

	rightPantLeg.setPosition(xPos + 455, yPos - 200);
	rightPantLeg.setFillColor(sf::Color(94, 97, 139));
	rightPantLeg.rotate(-70);

	leftPantLeg.setPosition(xPos + 455, yPos - 215);
	leftPantLeg.setFillColor(sf::Color(94, 97, 139));
	leftPantLeg.rotate(70);
}


/*************************************************************
 * Function: getShirtBody ()	                             *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: This function returns the RectangleShape     *
 *				representing the hangman's shirt.			 *
 * Input parameters: None.				   					 *
 * Returns: RectangleShape.			                         *
 * Preconditions: None.				   				         *
 * Postconditions: A RectangleShape has been returned.		 *
 *************************************************************/
sf::RectangleShape Medium::getShirtBody()
{
	return shirtBody;
}


/*************************************************************
 * Function: getRightSleeve ()	                             *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: This function returns the RectangleShape     *
 *				representing the hangman's right sleeve.	 *
 * Input parameters: None.				   					 *
 * Returns: RectangleShape.			                         *
 * Preconditions: None.				   				         *
 * Postconditions: A RectangleShape has been returned.		 *
 *************************************************************/
sf::RectangleShape Medium::getRightSleeve()
{
	return rightSleeve;
}


/*************************************************************
 * Function: getLeftSleeve ()	                             *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: This function returns the RectangleShape     *
 *				representing the hangman's left sleeve.		 *
 * Input parameters: None.				   					 *
 * Returns: RectangleShape.			                         *
 * Preconditions: None.				   				         *
 * Postconditions: A RectangleShape has been returned.		 *
 *************************************************************/
sf::RectangleShape Medium::getLeftSleeve()
{
	return leftSleeve;
}


/*************************************************************
 * Function: getPants ()		                             *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: This function returns the RectangleShape     *
 *				representing the torso of the pants.		 *
 * Input parameters: None.				   					 *
 * Returns: RectangleShape.			                         *
 * Preconditions: None.				   				         *
 * Postconditions: A RectangleShape has been returned.		 *
 *************************************************************/
sf::RectangleShape Medium::getPants()
{
	return pants;
}


/*************************************************************
 * Function: getLeftPantLeg ()	                             *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: This function returns the RectangleShape     *
 *				representing the hangman's left pant leg.	 *
 * Input parameters: None.				   					 *
 * Returns: RectangleShape.			                         *
 * Preconditions: None.				   				         *
 * Postconditions: A RectangleShape has been returned.		 *
 *************************************************************/
sf::RectangleShape Medium::getLeftPantLeg()
{
	return leftPantLeg;
}



/*************************************************************
 * Function: getRightPantLeg ()	                             *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: This function returns the RectangleShape     *
 *				representing the hangman's right pant leg.	 *
 * Input parameters: None.				   					 *
 * Returns: RectangleShape.			                         *
 * Preconditions: None.				   				         *
 * Postconditions: A RectangleShape has been returned.		 *
 *************************************************************/
sf::RectangleShape Medium::getRightPantLeg()
{
	return rightPantLeg;
}


/*************************************************************
 * Function: getRandomWord ()							     *
 * Date Created: 4/20/2022                                   *
 * Date Last Modified: 4/20/2022                             *
 * Description: Gets a random word from the Medium level 	 *
 *				word bank.									 *
 * Input parameters: None									 *
 * Returns: string										     *
 * Preconditions: None										 *
 * Postconditions: A string has been returned.				 *
 *************************************************************/
string Medium::getRandomWord()
{
	string chosenWord;

	srand(time(NULL));
	int i = rand() % 99 + 1;
	chosenWord = fiveLetterWords[i];

	return chosenWord;
}


/*************************************************************
 * Function: getShirtDrawn ()	                             *
 * Date Created: 4/20/2022                                   *
 * Date Last Modified: 4/20/2022                             *
 * Description: This function returns a bool representing	 *
 *				if the hangman's shirt was drawn.			 *
 * Input parameters: None.				   					 *
 * Returns: bool.					                         *
 * Preconditions: None.				   				         *
 * Postconditions: A bool has been returned.				 *
 *************************************************************/
bool Medium::getShirtDrawn()
{
	return shirtDrawn;
}


/*************************************************************
 * Function: getPantsDrawn ()	                             *
 * Date Created: 4/20/2022                                   *
 * Date Last Modified: 4/20/2022                             *
 * Description: This function returns a bool representing	 *
 *				if the hangman's pants were drawn.			 *
 * Input parameters: None.				   					 *
 * Returns: bool.					                         *
 * Preconditions: None.				   				         *
 * Postconditions: A bool has been returned.				 *
 *************************************************************/
bool Medium::getPantsDrawn()
{
	return pantsDrawn;
}


/*************************************************************
 * Function: setBoolsToFalse ()							     *
 * Date Created: 4/20/2022                                   *
 * Date Last Modified: 4/20/2022                             *
 * Description: sets all bool values to false 				 *
 * Input parameters: None									 *
 * Returns: Nothing										     *
 * Preconditions: None										 *
 * Postconditions: All bool values representing if body		 *
 *				   parts were drawn have been set to false.	 *						   					        
 *************************************************************/
void Medium::setBoolsToFalse()
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
}


/*************************************************************
 * Function: guess ()									     *
 * Date Created: 4/20/2022                                   *
 * Date Last Modified: 4/20/2022                             *
 * Description: This function checks if a character is part  *
 *				of the word to guess. It will call a function*
 *				to draw the next body part if the guess is   *
 *				wrong.										 *
 * Input parameters: string word, char letter, int correct 	 *
 *					 and total guess count.					 *
 * Returns: int											     *
 * Preconditions: word has at least 5 characters			 *
 * Postconditions: An int has been returned. The same correct*
 *				   guess count as before or one higher.		 *
 *************************************************************/
int Medium::guess(string word, char letter, int correctGuessCount, int guessCount)
{
	int correctTemp = correctGuessCount;
	for (int i = 0; i < 5; i++)
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
			if (i == 4)
			{
				setFifthLetter(true);
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
 * Date Created: 4/20/2022                                   *
 * Date Last Modified: 4/20/2022                             *
 * Description: This sets the next body part to be drawn	 *
 *				depending on how many incorrect guesses there*
 *				have been.									 *
 * Input parameters: int correct and total guess counts.	 *
 * Returns: Nothing.									     *
 * Preconditions: None.										 *
 * Postconditions: None.									 *
 *************************************************************/
void Medium::incorrectGuess(int guessCount, int correctGuessCount)
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

}
