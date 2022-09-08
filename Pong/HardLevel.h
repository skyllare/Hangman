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
#include <iostream>
#include <string>

using std::string;

class Hard :public sf::ConvexShape
{
public:
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
	Hard(const int xPos, const int yPos);


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
	sf::CircleShape getHead() const;
	
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
	sf::RectangleShape getBody() const;

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
	sf::RectangleShape getLeftLeg() const;
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
	sf::RectangleShape getLeftArm() const;
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
	sf::RectangleShape getRightArm() const;

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
	sf::RectangleShape getRightLeg() const;

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
	virtual string getRandomWord();

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
	bool getheadDrawn();
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
	bool getBodyDrawn();
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
	bool getRightArmDrawn();

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
	bool getLeftArmDrawn();
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
	bool getLeftLegDrawn();

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
	bool getRightLegDrawn();


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
	bool getFirstLetter();
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
	bool getSecondLetter();
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
	bool getThirdLetter();
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
	bool getFourthLetter();

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
	bool getFifthLetter();
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
	bool getSixthLetter();




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
	void setFirstLetter(bool value);
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
	void setSecondLetter(bool value);
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
	void setThirdLetter(bool value);
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
	void setFourthLetter(bool value);

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
	void setFifthLetter(bool value);

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
	void setSixthLetter(bool value);
	

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
	virtual void setBoolsToFalse();

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
	virtual int guess(string word, char letter, int correctGuessCount, int guessCount);

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
	virtual void incorrectGuess(int guessCount, int correctGuessCount);



protected:

	bool headDrawn;
	bool bodyDrawn;
	bool rightArmDrawn;
	bool leftArmDrawn;
	bool rightLegDrawn;
	bool leftLegDrawn;

	bool firstLetter;
	bool secondLetter;
	bool thirdLetter;
	bool fourthLetter;
	bool fifthLetter;
	bool sixthLetter;
	sf::CircleShape head = sf::CircleShape(50);;
	sf::RectangleShape leftArm = sf::RectangleShape(sf::Vector2f(10, 70));
	sf::RectangleShape rightArm = sf::RectangleShape(sf::Vector2f(10, 70));
	sf::RectangleShape rightLeg = sf::RectangleShape(sf::Vector2f(10, 70));
	sf::RectangleShape leftLeg = sf::RectangleShape(sf::Vector2f(10, 70));
	sf::RectangleShape body = sf::RectangleShape(sf::Vector2f(10, 150));

	string* sixLetterWords = new string[101]{
		"better","beyond","border","branch","bright","budget","button","camera","burden","bright",
		"carbon","career","castle","caught","center","chance","change","charge","chosen","church",
		"circle","client","closer","coffee","column","combat","coming","common","copper","costly",
		"damage","danger","dealer","decade","decide","defeat","defend","debate","define","degree",
		"double","driver","eating","easily","enable","ethnic","exceed","excess","expand","fabric",
		"finger","forget","flight","garden","gender","gather","global","health","honest","impact",
		"killed","legacy","leader","lesson","liquid","mainly","making","manage","marked","manual",
		"nature","nearly","option","office","packed","obtain","planet","player","police","phrase",
		"profit","proven","proper","rarely","really","reason","replay","result","secret","select",
		"select","speech","target","unable","valley","yellow","worker","window","volume","visual"

	};
};
