/*******************************************************************************
 *                                 *
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

#include "Hanger.h"


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
Hanger::Hanger(const int xPos, const int yPos)
{
	sf::Color hanger(105, 105, 105);

	base = sf::RectangleShape(sf::Vector2f(300, 50));
	base.setPosition(xPos, yPos);
	tall = sf::RectangleShape(sf::Vector2f(20, 550)); // vertical piece of wood
	tall.setPosition(xPos + 145, yPos - 550);
	hort = sf::RectangleShape(sf::Vector2f(300, 20)); // horizontal piece of wood
	hort.setPosition(xPos + 150, yPos - 550);
	string = sf::RectangleShape(sf::Vector2f(5, 100));
	string.setPosition(650, 350);
	string.setPosition(xPos + 450, yPos - 550);

	string.setFillColor(sf::Color(118, 117, 114));
	hort.setFillColor(hanger);
	base.setFillColor(hanger);
	tall.setFillColor(hanger);
}


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
sf::RectangleShape Hanger::getBase() const
{
	return base;
}


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
sf::RectangleShape Hanger::getTall() const
{
	return tall;
}


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
sf::RectangleShape Hanger::getHort() const
{
	return hort;
}


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
sf::RectangleShape Hanger::getString() const
{
	return string;
}
