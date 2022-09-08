/*******************************************************************************
 * Programmers:	Skyllar Estill, Molly Iverson                                  *
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

#include "HardLevel.h"

/*************************************************************
 * Function: Hard ()								         *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: sets the postition, color, and rotation		 *
 *				of the head, body, both arms & legs			 *
 * Input parameters: xPos and yPos (x and y values all	 	 *
 *					drawings are based on)					 *
 * Returns: Nothing.                                         *
 * Preconditions:   none									 *
 * Postconditions:	none									 *
 *								   					         *
 *************************************************************/

Hard::Hard(const int xPos, const int yPos) // 200, 900
{
	head.setPosition(xPos + 405, yPos - 450);

	body.setPosition(xPos + 450, yPos - 350);

	leftLeg.setPosition(xPos + 455, yPos - 210);

	rightLeg.setPosition(xPos + 455, yPos - 200);

	leftLeg.rotate(70);
	rightLeg.rotate(-70);

	rightArm.setPosition(xPos + 460, yPos - 300);
	rightArm.rotate(140);
	leftArm.setPosition(xPos + 460, yPos - 300);
	leftArm.rotate(-140);

}


/*************************************************************
 * Function: getHead ()								         *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: gets the value of the objects's head 		 *
 * Input parameters:none									 *
 * Returns: CircleShape	                                     *
 * Preconditions:   none									 *
 * Postconditions:	none									 *
 *								   					         *
 *************************************************************/
sf::CircleShape Hard::getHead() const
{
	return head;
}


/*************************************************************
 * Function: getBody ()								         *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: gets the value of the objects's body 		 *
 * Input parameters:none									 *
 * Returns: RectangleShape	                                 *
 * Preconditions:   none									 *
 * Postconditions:	none									 *
 *								   					         *
 *************************************************************/
sf::RectangleShape Hard::getBody() const
{
	return body;
}


/*************************************************************
 * Function: getLeftLeg ()								     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: gets the value of the objects's left leg 	 *
 * Input parameters:none									 *
 * Returns: RectangleShape	                                 *
 * Preconditions:   none									 *
 * Postconditions:	none									 *
 *								   					         *
 *************************************************************/
sf::RectangleShape Hard::getLeftLeg() const
{
	return leftLeg;
}


/*************************************************************
 * Function: getLeftArm ()								     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: gets the value of the objects's left arm 	 *
 * Input parameters:none									 *
 * Returns: RectangleShape	                                 *
 * Preconditions:   none									 *
 * Postconditions:	none									 *
 *								   					         *
 *************************************************************/
sf::RectangleShape Hard::getLeftArm() const
{
	return leftArm;
}


/*************************************************************
 * Function: getRightArm()								     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: gets the value of the objects's right arm 	 *
 * Input parameters:none									 *
 * Returns: RectangleShape	                                 *
 * Preconditions:   none									 *
 * Postconditions:	none									 *
 *								   					         *
 *************************************************************/

sf::RectangleShape Hard::getRightArm() const
{
	return rightArm;
}


/*************************************************************
 * Function: getRightLeg ()								     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: gets the value of the objects's right leg 	 *
 * Input parameters:none									 *
 * Returns: RectangleShape	                                 *
 * Preconditions:   none									 *
 * Postconditions:	none									 *
 *								   					         *
 *************************************************************/
sf::RectangleShape Hard::getRightLeg() const
{
	return rightLeg;
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
string Hard::getRandomWord()
{
	string chosenWord;

	srand(time(NULL));
	int i = rand() % 99 + 1;
	chosenWord = sixLetterWords[i];

	return chosenWord;
}



/*************************************************************
 * Function: getHeadDrawn ()							     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: checks if the object's head needs to be drawn*
 * Input parameters: none									 *
 * Returns: bool										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
bool  Hard::getheadDrawn()
{
	return headDrawn;
}

/*************************************************************
 * Function: getBodyDrawn ()							     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: checks if the object's body needs to be drawn*
 * Input parameters: none									 *
 * Returns: bool										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
bool  Hard::getBodyDrawn()
{
	return bodyDrawn;
}

/*************************************************************
 * Function: getRightArmDrawn ()						     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: checks if the object's right arm needs to be *
*				drawn										 *
 * Input parameters: none									 *
 * Returns: bool										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
bool  Hard::getRightArmDrawn()
{
	return rightArmDrawn;
}

/*************************************************************
 * Function: getLeftArmDrawn ()							     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: checks if the object's left arm needs to be  *
*				drawn										 *
 * Input parameters: none									 *
 * Returns: bool										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
bool  Hard::getLeftArmDrawn()
{
	return leftArmDrawn;
}

/*************************************************************
 * Function: getLeftLegDrawn ()							     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: checks if the object's left leg needs to be  *
*				drawn										 *
 * Input parameters: none									 *
 * Returns: bool										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/

bool  Hard::getLeftLegDrawn()
{
	return leftLegDrawn;
}

/*************************************************************
 * Function: getRightLegDrawn ()						     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: checks if the object's right leg needs to be *
*				drawn										 *
 * Input parameters: none									 *
 * Returns: bool										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
bool  Hard::getRightLegDrawn()
{
	return rightLegDrawn;
}





/*************************************************************
 * Function: setFirstLetter ()							     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: set first letter's draw status to value		 *
 *				(t/f)										 *
 * Input parameters: bool									 *
 * Returns: none										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
void Hard::setFirstLetter(bool value)
{
	firstLetter = value;
}

/*************************************************************
 * Function: setSecondLetter ()							     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: set second letter's draw status to value	 *
 *				(t/f)										 *
 * Input parameters: bool									 *
 * Returns: none										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
void Hard::setSecondLetter(bool value)
{
	secondLetter = value;
}
/*************************************************************
 * Function: setThirdLetter ()							     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: set third letter's draw status to value		 *
 *				(t/f)										 *
 * Input parameters: bool									 *
 * Returns: none										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
void Hard::setThirdLetter(bool value)
{
	thirdLetter = value;
}

/*************************************************************
 * Function: setFourthLetter ()							     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: set fourth letter's draw status to value	 *
 *				(t/f)										 *
 * Input parameters: bool									 *
 * Returns: none										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
void Hard::setFourthLetter(bool value)
{
	fourthLetter = value;
}

/*************************************************************
 * Function: setFifthLetter ()							     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: set fifth letter's draw status to value		 *
 *				(t/f)										 *
 * Input parameters: bool									 *
 * Returns: none										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
void Hard::setFifthLetter(bool value)
{
	fifthLetter = value;
}

/*************************************************************
 * Function: setSixthLetter ()							     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: set sixth letter's draw status to value		 *
 *				(t/f)										 *
 * Input parameters: bool									 *
 * Returns: none										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
void Hard::setSixthLetter(bool value)
{
	sixthLetter = value;
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
void Hard::setBoolsToFalse()
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
}

/*************************************************************
 * Function: getFirstLetter ()							     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: checks if the object's first letter needs to *
*				be drawn									 *
 * Input parameters: none									 *
 * Returns: bool										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
bool Hard::getFirstLetter()
{
	return firstLetter;
}

/*************************************************************
 * Function: getSecondLetter ()							     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: checks if the object's second letter needs to*
*				be drawn									 *
 * Input parameters: none									 *
 * Returns: bool										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
bool Hard::getSecondLetter()
{
	return secondLetter;
}

/*************************************************************
 * Function: getThirdLetter ()							     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: checks if the object's third letter needs to *
 *				be drawn									 *
 * Input parameters: none									 *
 * Returns: bool										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
bool Hard::getThirdLetter()
{
	return thirdLetter;
}

/*************************************************************
 * Function: getFourthLetter ()							     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: checks if the object's fourth letter needs to*
*				be drawn									 *
 * Input parameters: none									 *
 * Returns: bool										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
bool Hard::getFourthLetter()
{
	return fourthLetter;
}

/*************************************************************
 * Function: getFifthLetter ()							     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: checks if the object's fifth letter needs to *
*				be drawn									 *
 * Input parameters: none									 *
 * Returns: bool										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
bool Hard::getFifthLetter()
{
	return fifthLetter;
}
/*************************************************************
 * Function: getSixthLetter ()							     *
 * Date Created: 4/18/2022                                   *
 * Date Last Modified: 4/18/2022                             *
 * Description: checks if the object's sixth letter needs to *
*				be drawn									 *
 * Input parameters: none									 *
 * Returns: bool										     *
 * Preconditions:	none									 *
 * Postconditions:											 *
 *								   					         *
 *************************************************************/
bool Hard::getSixthLetter()
{
	return sixthLetter;
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
int Hard::guess(string word, char letter, int correctGuessCount, int guessCount)
{
	int correctTemp = correctGuessCount;
	for (int i = 0; i < 6; i++)
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
			if (i == 5)
			{
				setSixthLetter(true);
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
void Hard::incorrectGuess(int guessCount, int correctGuessCount)
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


}