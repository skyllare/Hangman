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

#pragma once
#include <SFML/Graphics.hpp>
#include "HardLevel.h"

class Medium : public Hard
{
public:

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
	Medium(const int xPos, const int yPos);


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
	sf::RectangleShape getShirtBody();


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
	sf::RectangleShape getRightSleeve();


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
	sf::RectangleShape getLeftSleeve();


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
	sf::RectangleShape getPants();


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
	sf::RectangleShape getLeftPantLeg();


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
	sf::RectangleShape getRightPantLeg();


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
	bool getShirtDrawn();


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
	bool getPantsDrawn();



	/*************************************************************
	 * Function: setBoolsToFalse ()							     *
	 * Date Created: 4/20/2022                                   *
	 * Date Last Modified: 4/20/2022                             *
	 * Description: sets all bool values to false 				 *
	 * Input parameters: None									 *
	 * Returns: Nothing										     *
	 * Preconditions: None										 *
	 * Postconditions: All bool values representing if body		 *
	 *				   parts were drawn have been set to false.	 *						   					         *
	 *************************************************************/
	virtual void setBoolsToFalse();


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
	virtual int guess(string word, char letter, int correctGuessCount, int guessCount);


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
	virtual void incorrectGuess(int guessCount, int correctGuessCount);


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
	virtual string getRandomWord();

protected:

	bool shirtDrawn;
	bool pantsDrawn;
	sf::RectangleShape shirtBody = sf::RectangleShape(sf::Vector2f(15, 80));
	sf::RectangleShape rightSleeve = sf::RectangleShape(sf::Vector2f(15, 40));
	sf::RectangleShape leftSleeve = sf::RectangleShape(sf::Vector2f(15, 40));
	sf::RectangleShape leftPantLeg = sf::RectangleShape(sf::Vector2f(15, 60));
	sf::RectangleShape rightPantLeg = sf::RectangleShape(sf::Vector2f(15, 60));
	sf::RectangleShape pants = sf::RectangleShape(sf::Vector2f(15, 60));

	string* fiveLetterWords = new string[101]
	{ "abuse","adult","agent","anger","apple","award","basis","beach","birth","block",
		"blood","board","brain","bread","break","brown","buyer","cause","chain","chair",
		"chest","cheif","child","china","claim","class","clock","coach","coast","court",
		"cover","cream","crime","cross","crowd","crown","cycle","dance","death","depth",
		"doubt","draft","drama","dream","dress","drink","drive","earth","enemy","entry",
		"error","event","faith","fault","field","fight","final","floor","focus","force",
		"frame","front","fruit","glass","green","group","guide","heart","horse","hotel",
		"house","index","input","knife","judge","issue","level","limit","march","major",
		"north","nurse","order","offer","other","panel","party","peace","phase","phone",
		"queen","ratio","reply","right","scale","shape","share","table","union","youth"
	};
};
