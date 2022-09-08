/*******************************************************************************
\                            *
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

#include "EasyLevel.h"

using std::endl;
using std::cout;


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
void testEasyGuessCorrect();

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
void testEasyGuessIncorrect();


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
void testMediumGuessCorrect();

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

void testMediumGuessIncorrect();


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
void testHardGuessCorrect();

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
void testHardGuessIncorrect();
