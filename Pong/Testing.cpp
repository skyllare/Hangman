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

#include "Testing.h"




/*************************************************************
 * Function: testEasyGuessCorrect ()                         *
 * Date Created: 4/26/2022                                   *
 * Date Last Modified: 4/26/2022                             *
 * Description: Makes a word and does the exact amoumt of	 *
 *				correct char guesses						 *
 * Input parameters:										 *
 * Returns: Nothing.                                         *
 * Preconditions:   none									 *
 * Postconditions:	none									 *
 *								   					         *
 *************************************************************/
void testEasyGuessCorrect()
{
	Easy testEasy(100, 600);		//make an Easy object
	string testWord = "real";		//make a word to use for this test
	int correctGuessCountTest = 0;

	//guess the word with no incorrect guesses
	correctGuessCountTest = testEasy.guess(testWord, 'r', correctGuessCountTest, 1);
	correctGuessCountTest = testEasy.guess(testWord, 'e', correctGuessCountTest, 2);
	correctGuessCountTest = testEasy.guess(testWord, 'a', correctGuessCountTest, 3);
	correctGuessCountTest = testEasy.guess(testWord, 'l', correctGuessCountTest, 4);


	//see if the program correctly counts to correct guesses
	if (correctGuessCountTest == 4)
	{
		cout << "Program counting correct guesses for easy - successful" << endl;
	}
	else
	{
		cout << "Program counting correct guesses for easy - not successful" << endl;
	}


	//see if the porgram will set the each letter = to true, 
	//which means the letter will be drawn on the scree 
	if (testEasy.getFirstLetter() == true)
	{
		cout << "First letter drawn to screen" << endl;
	}
	else
	{
		cout << "First letter not drawn to screen" << endl;

	}

	if (testEasy.getSecondLetter() == true)
	{
		cout << "Second letter drawn to screen" << endl;
	}
	else
	{
		cout << "Second letter not drawn to screen" << endl;
	}

	if (testEasy.getThirdLetter() == true)
	{
		cout << "Third letter drawn to screen" << endl;

	}
	else
	{
		cout << "Third letter not drawn to screen" << endl;
	}

	if (testEasy.getFourthLetter() == true)
	{
		cout << "Fourth letter drawn to screen" << endl;
	}
	else
	{
		cout << "Fourth letter not drawn to screen" << endl;
	}
}




/*************************************************************
 * Function: testEasyGuessIncorrect ()                       *
 * Date Created: 4/26/2022                                   *
 * Date Last Modified: 4/26/2022                             *
 * Description: Runs the incorrect function 10 times		 *
 * Input parameters:										 *
 * Returns: Nothing.                                         *
 * Preconditions:   none									 *
 * Postconditions:	none									 *
 *								   					         *
 *************************************************************/
void testEasyGuessIncorrect()
{
	Easy testEasy(100, 600);

	//make all incorrect guess for every life you have in the level
	for (int i = 0; i <= 10; i++)
	{
		testEasy.incorrectGuess(i, 0);
	}
	//test to see if each body part of the hangman will be drawn as all guesses
	//were incorrect, all body parts shoul be drawn.
	if (testEasy.getheadDrawn() == true)
	{
		cout << "Head drawn correctly" << endl;
	}
	else
	{
		cout << "Head not drawn correctly" << endl;
	}

	if (testEasy.getheadDrawn() == true)
	{
		cout << "Body drawn correctly" << endl;
	}
	else
	{
		cout << "Body not drawn correctly" << endl;
	}
	if (testEasy.getRightArmDrawn() == true)
	{
		cout << "Right arm drawn correctly" << endl;
	}
	else
	{
		cout << "Right arm not drawn correctly" << endl;
	}
	if (testEasy.getLeftArmDrawn() == true)
	{
		cout << "Left arm drawn correctly" << endl;
	}
	else
	{
		cout << "Left arm not drawn correctly" << endl;
	}
	if (testEasy.getRightLegDrawn() == true)
	{
		cout << "Right leg drawn correctly" << endl;
	}
	else
	{
		cout << "Right leg not drawn correctly" << endl;
	}
	if (testEasy.getLeftLegDrawn() == true)
	{
		cout << "Left leg drawn correctly" << endl;
	}
	else
	{
		cout << "Left leg not drawn correctly" << endl;
	}
	if (testEasy.getShirtDrawn() == true)
	{
		cout << "Shirt drawn correctly" << endl;
	}
	else
	{
		cout << "Shirt not drawn correctly" << endl;
	}
	if (testEasy.getPantsDrawn() == true)
	{
		cout << "Pants drawn correctly" << endl;
	}
	else
	{
		cout << "Pants not drawn correctly" << endl;
	}
	if (testEasy.getRightShoeDrawn() == true)
	{
		cout << "Right shoe drawn correctly" << endl;
	}
	else
	{
		cout << "Right shoe not drawn correctly" << endl;
	}
	if (testEasy.getLeftShoeDrawn() == true)
	{
		cout << "Left shoe drawn correctly" << endl;
	}
	else
	{
		cout << "Left shoe not drawn correctly" << endl;
	}

}



/*************************************************************
 * Function: testMediumGuessCorrect ()                       *
 * Date Created: 4/26/2022                                   *
 * Date Last Modified: 4/26/2022                             *
 * Description: Makes a word and does the exact amoumt of	 *
 *				correct char guesses						 *
 * Input parameters:										 *
 * Returns: Nothing.                                         *
 * Preconditions:   none									 *
 * Postconditions:	none									 *
 *								   					         *
 *************************************************************/
void testMediumGuessCorrect()
{
	Medium testMedium(100, 600);
	string testWord = "group";
	int correctGuessCountTest = 0;

	correctGuessCountTest = testMedium.guess(testWord, 'g', correctGuessCountTest, 1);
	correctGuessCountTest = testMedium.guess(testWord, 'r', correctGuessCountTest, 2);
	correctGuessCountTest = testMedium.guess(testWord, 'o', correctGuessCountTest, 3);
	correctGuessCountTest = testMedium.guess(testWord, 'u', correctGuessCountTest, 4);
	correctGuessCountTest = testMedium.guess(testWord, 'p', correctGuessCountTest, 5);

	if (correctGuessCountTest == 4)
	{
		cout << "Program counting correct guesses for easy - successful" << endl;
	}
	else
	{
		cout << "Program counting correct guesses for easy - not successful" << endl;
	}



	if (testMedium.getFirstLetter() == true)
	{
		cout << "First letter drawn to screen" << endl;
	}
	else
	{
		cout << "First letter not drawn to screen" << endl;

	}

	if (testMedium.getSecondLetter() == true)
	{
		cout << "Second letter drawn to screen" << endl;
	}
	else
	{
		cout << "Second letter not drawn to screen" << endl;
	}

	if (testMedium.getThirdLetter() == true)
	{
		cout << "Third letter drawn to screen" << endl;

	}
	else
	{
		cout << "Third letter not drawn to screen" << endl;
	}

	if (testMedium.getFourthLetter() == true)
	{
		cout << "Fourth letter drawn to screen" << endl;
	}
	else
	{
		cout << "Fourth letter not drawn to screen" << endl;
	}

	if (testMedium.getFifthLetter() == true)
	{
		cout << "Fifth letter drawn to screen" << endl;
	}
	else
	{
		cout << "Fifth letter not drawn to screen" << endl;
	}
}





/*************************************************************
 * Function: testEasyGuessIncorrect ()                       *
 * Date Created: 4/26/2022                                   *
 * Date Last Modified: 4/26/2022                             *
 * Description: Runs the incorrect function 8 times			 *
 * Input parameters:										 *
 * Returns: Nothing.                                         *
 * Preconditions:   none									 *
 * Postconditions:	none									 *
 *								   					         *
 *************************************************************/
void testMediumGuessIncorrect()
{
	Medium testMedium(100, 600);

	for (int i = 0; i <= 8; i++)
	{
		testMedium.incorrectGuess(i, 0);
	}
	if (testMedium.getheadDrawn() == true)
	{
		cout << "Head drawn correctly" << endl;
	}
	else
	{
		cout << "Head not drawn correctly" << endl;
	}

	if (testMedium.getheadDrawn() == true)
	{
		cout << "Body drawn correctly" << endl;
	}
	else
	{
		cout << "Body not drawn correctly" << endl;
	}
	if (testMedium.getRightArmDrawn() == true)
	{
		cout << "Right arm drawn correctly" << endl;
	}
	else
	{
		cout << "Right arm not drawn correctly" << endl;
	}
	if (testMedium.getLeftArmDrawn() == true)
	{
		cout << "Left arm drawn correctly" << endl;
	}
	else
	{
		cout << "Left arm not drawn correctly" << endl;
	}
	if (testMedium.getRightLegDrawn() == true)
	{
		cout << "Right leg drawn correctly" << endl;
	}
	else
	{
		cout << "Right leg not drawn correctly" << endl;
	}
	if (testMedium.getLeftLegDrawn() == true)
	{
		cout << "Left leg drawn correctly" << endl;
	}
	else
	{
		cout << "Left leg not drawn correctly" << endl;
	}
	if (testMedium.getShirtDrawn() == true)
	{
		cout << "Shirt drawn correctly" << endl;
	}
	else
	{
		cout << "Shirt not drawn correctly" << endl;
	}
	if (testMedium.getPantsDrawn() == true)
	{
		cout << "Pants drawn correctly" << endl;
	}
	else
	{
		cout << "Pants not drawn correctly" << endl;
	}
}



/*************************************************************
 * Function: testHardGuessCorrect ()                         *
 * Date Created: 4/26/2022                                   *
 * Date Last Modified: 4/26/2022                             *
 * Description: Makes a word and does the exact amoumt of	 *
 *				correct char guesses						 *
 * Input parameters:										 *
 * Returns: Nothing.                                         *
 * Preconditions:   none									 *
 * Postconditions:	none									 *
 *								   					         *
 *************************************************************/
void testHardGuessCorrect()
{
	Hard testHard(100, 600);
	string testWord = "combat";
	int correctGuessCountTest = 0;

	correctGuessCountTest = testHard.guess(testWord, 'c', correctGuessCountTest, 1);
	correctGuessCountTest = testHard.guess(testWord, 'o', correctGuessCountTest, 2);
	correctGuessCountTest = testHard.guess(testWord, 'm', correctGuessCountTest, 3);
	correctGuessCountTest = testHard.guess(testWord, 'b', correctGuessCountTest, 4);
	correctGuessCountTest = testHard.guess(testWord, 'a', correctGuessCountTest, 5);
	correctGuessCountTest = testHard.guess(testWord, 't', correctGuessCountTest, 6);

	if (correctGuessCountTest == 4)
	{
		cout << "Program counting correct guesses for easy - successful" << endl;
	}
	else
	{
		cout << "Program counting correct guesses for easy - not successful" << endl;
	}



	if (testHard.getFirstLetter() == true)
	{
		cout << "First letter drawn to screen" << endl;
	}
	else
	{
		cout << "First letter not drawn to screen" << endl;

	}

	if (testHard.getSecondLetter() == true)
	{
		cout << "Second letter drawn to screen" << endl;
	}
	else
	{
		cout << "Second letter not drawn to screen" << endl;
	}

	if (testHard.getThirdLetter() == true)
	{
		cout << "Third letter drawn to screen" << endl;

	}
	else
	{
		cout << "Third letter not drawn to screen" << endl;
	}

	if (testHard.getFourthLetter() == true)
	{
		cout << "Fourth letter drawn to screen" << endl;
	}
	else
	{
		cout << "Fourth letter not drawn to screen" << endl;
	}

	if (testHard.getFifthLetter() == true)
	{
		cout << "Fifth letter drawn to screen" << endl;
	}
	else
	{
		cout << "Fifth letter not drawn to screen" << endl;
	}
	if (testHard.getSixthLetter() == true)
	{
		cout << "Sixth letter drawn to screen" << endl;
	}
	else
	{
		cout << "Sixth letter not drawn to screen" << endl;
	}
}


/*************************************************************
 * Function: testEasyGuessIncorrect ()                       *
 * Date Created: 4/26/2022                                   *
 * Date Last Modified: 4/26/2022                             *
 * Description: Runs the incorrect function 6 times			 *
 * Input parameters:										 *
 * Returns: Nothing.                                         *
 * Preconditions:   none									 *
 * Postconditions:	none									 *
 *								   					         *
 *************************************************************/
void testHardGuessIncorrect()
{

	Hard testHard(100, 600);

	for (int i = 0; i <= 6; i++)
	{
		testHard.incorrectGuess(i, 0);
	}
	if (testHard.getheadDrawn() == true)
	{
		cout << "Head drawn correctly" << endl;
	}
	else
	{
		cout << "Head not drawn correctly" << endl;
	}

	if (testHard.getheadDrawn() == true)
	{
		cout << "Body drawn correctly" << endl;
	}
	else
	{
		cout << "Body not drawn correctly" << endl;
	}
	if (testHard.getRightArmDrawn() == true)
	{
		cout << "Right arm drawn correctly" << endl;
	}
	else
	{
		cout << "Right arm not drawn correctly" << endl;
	}
	if (testHard.getLeftArmDrawn() == true)
	{
		cout << "Left arm drawn correctly" << endl;
	}
	else
	{
		cout << "Left arm not drawn correctly" << endl;
	}
	if (testHard.getRightLegDrawn() == true)
	{
		cout << "Right leg drawn correctly" << endl;
	}
	else
	{
		cout << "Right leg not drawn correctly" << endl;
	}
	if (testHard.getLeftLegDrawn() == true)
	{
		cout << "Left leg drawn correctly" << endl;
	}
	else
	{
		cout << "Left leg not drawn correctly" << endl;
	}
}