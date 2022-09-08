/*******************************************************************************
 *                             *
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
class Hanger
{
public:

	/*************************************************************
	* Function: Hanger ()			                             *
	* Date Created: 4/18/2022                                    *
	* Date Last Modified: 4/21/2022                              *
	* Description: This is the Hanger constructor. It sets the   *
	*			   position of each of its parts based on an	 *
	*			   input x and y coordinate.					 *
	* Input parameters: int x and y.		   					 *
	* Returns: Nothing.					                         *
	* Preconditions: None.				   				         *
	* Postconditions: The positions and colors of the data		 *
	*				  members have been set.					 *
	*************************************************************/
	Hanger(const int xPos, const int yPos);


	/*************************************************************
	* Function: getBase ()			                             *
	* Date Created: 4/18/2022                                    *
	* Date Last Modified: 4/21/2022                              *
	* Description: This function returns the RectangleShape 	 *
	*			   representing the base of the hanger.			 *
	* Input parameters: None.				   					 *
	* Returns: RectangleShape.			                         *
	* Preconditions: None.				   				         *
	* Postconditions: A RectangleShape has been returned.		 *
	*************************************************************/
	sf::RectangleShape getBase() const;


	/*************************************************************
	* Function: getTall ()			                             *
	* Date Created: 4/18/2022                                    *
	* Date Last Modified: 4/21/2022                              *
	* Description: This function returns the RectangleShape 	 *
	*			   representing the tall piece of the hanger.	 *
	* Input parameters: None.				   					 *
	* Returns: RectangleShape.			                         *
	* Preconditions: None.				   				         *
	* Postconditions: A RectangleShape has been returned.		 *
	*************************************************************/
	sf::RectangleShape getTall() const;


	/*************************************************************
	* Function: getHort ()			                             *
	* Date Created: 4/18/2022                                    *
	* Date Last Modified: 4/21/2022                              *
	* Description: This function returns the RectangleShape 	 *
	*			   representing the horizontal piece of the		 *
	*			   hanger.										 *
	* Input parameters: None.				   					 *
	* Returns: RectangleShape.			                         *
	* Preconditions: None.				   				         *
	* Postconditions: A RectangleShape has been returned.		 *
	*************************************************************/
	sf::RectangleShape getString() const;


	/*************************************************************
	* Function: getString ()		                             *
	* Date Created: 4/18/2022                                    *
	* Date Last Modified: 4/21/2022                              *
	* Description: This function returns the RectangleShape 	 *
	*			   representing the string of the hanger.		 *
	* Input parameters: None.				   					 *
	* Returns: RectangleShape.			                         *
	* Preconditions: None.				   				         *
	* Postconditions: A RectangleShape has been returned.		 *
	*************************************************************/
	sf::RectangleShape getHort() const;
private:
	sf::RectangleShape base;
	sf::RectangleShape tall;
	sf::RectangleShape string;
	sf::RectangleShape hort;
};
