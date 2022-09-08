/*******************************************************************************                             *
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

#pragma once

#include "MediumLevel.h"


class Easy : public Medium
{
public:
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
	Easy(const int xPos, const int yPos);

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
	sf::RectangleShape getRightShoe();

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
	sf::RectangleShape getLeftShoe();


	
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
	string getRandomWord();


	
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
	void setBoolsToFalse();

	
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
	int guess(string word, char letter, int correctGuessCount, int guessCount);

	
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
	void incorrectGuess(int guessCount, int correctGuessCount);


	
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
	bool getRightShoeDrawn();
	
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
	bool getLeftShoeDrawn();

private:
	sf::RectangleShape rightShoe = sf::RectangleShape(sf::Vector2f(40, 10));
	sf::RectangleShape leftShoe = sf::RectangleShape(sf::Vector2f(40, 10));



	
	bool leftShoeDrawn;
	bool rightShoeDrawn;

	//word bank
	string* fourLetterWords = new string[101]
	{ "tree","rice","beam","bake","word","list","four","five","nine","good",
		"best","cute","zero","huge","cool","tree","race","keep","lace","beam",
		"game","mars","tide","ride","hide","exit","hope","cold","from","need",
		"stay","come","jazz","jump","cozy","quip","foxy","jaws","maze","jell",
		"coax","waxy","aqua","daze","join","mock","pick","puck","pump","puff",
		"camp","jets","much","size","wimp","zest","data","deaf","earn","each",
		"fade","iced","jade","lack","mace","oaks","oars","pace","rack","sack",
		"wade","oath","oily","laid","lamb","lamp","lame","lava","haze","what",
		"adds","baby","ball","balm","barn","bark","case","cash","date","dawn",
		"edgy","feet","fees","fawn","jazz","jibe","pelt","melt","hemp","malt"
	};
};
