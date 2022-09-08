/*******************************************************************************
\                          *
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


#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <Windows.h>

#include "Hanger.h"
#include "HardLevel.h"
#include "MediumLevel.h"
#include "EasyLevel.h"

#define LETTERS_CHOSEN 1
#define LETTERS_REMAINING 0

using std::string;
using std::cout;
using std::endl;
using std::cin;

using sf::Color;
using sf::RectangleShape;
using sf::Event;
using sf::Mouse;
using sf::Keyboard;
using sf::RenderWindow;
using sf::Vector2f;
using sf::Font;
using sf::Text;



/*************************************************************
* Function: isMouseTouchingRectangle ()	                     *
* Date Created: 4/20/2022                                    *
* Date Last Modified: 4/20/2022                              *
* Description: This function determines whether the mouse is *
*			   touching a RectangleShape object.			 *
* Input parameters: A RectangleShape and the window.		 *
* Returns: bool.					                         *
* Preconditions: None.				   				         *
* Postconditions: A bool is returned.						 *
*************************************************************/
bool isMouseTouchingRectangle(RectangleShape& rect, sf::RenderWindow &window);


int main()
{
	sf::RenderWindow window(sf::VideoMode(1500, 1000), "Hangman works!");

	// SETTING WINDOW LOCATION
	window.setPosition(sf::Vector2i(700, 0));
	RECT r;
	HWND console = GetConsoleWindow();
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 700, 700, TRUE);
	

	int xStartGame = window.getSize().x / 10, yStartGame = (5 * window.getSize().y) / 8; // 150, 625
	int xHangerPos = 100, yHangerPos = 600;

	Easy* e1 = new Easy(xHangerPos, yHangerPos);
	Medium* m1 = new Medium(xHangerPos, yHangerPos);
	Hard* h1 = new Hard(xHangerPos, yHangerPos);
	Hanger* hanger = new Hanger(xHangerPos, yHangerPos);


	Font* font = new Font();
	if (!(*font).loadFromFile("Fonts/SourceSansPro-Bold.otf"))
	{
		std::cout << "Could not load font" << std::endl;
		return 0;
	}

	// Start Game Button
	RectangleShape* startGame = new RectangleShape(Vector2f(500, 200));
	Color lightPink(243, 153, 203);
	startGame->setFillColor(lightPink);
	startGame->setPosition(Vector2f(xStartGame, yStartGame));
	startGame->setOutlineThickness(10);
	startGame->setOutlineColor(Color::White);


	// Help Button
	RectangleShape* helpButton = new RectangleShape(Vector2f(540, 200));
	helpButton->setFillColor(lightPink);
	helpButton->setPosition(Vector2f(xStartGame + 660, yStartGame));
	helpButton->setOutlineThickness(10);
	helpButton->setOutlineColor(Color::White);


	// Start Game Text
	Text* startGameText = new Text();
	startGameText->setCharacterSize(80);
	startGameText->setPosition(Vector2f(xStartGame + 40, yStartGame + 50));
	startGameText->setString("Start Game!");
	startGameText->setFillColor(Color::Black);
	startGameText->setFont(*font);



	// Help Text
	Text* helpText = new Text();
	helpText->setCharacterSize(80);
	helpText->setPosition(Vector2f(xStartGame + 700, yStartGame + 50));
	helpText->setString("How To Play!");
	helpText->setFillColor(Color::Black);
	helpText->setFont(*font);


	// Hangman Text
	Text* hangmanTitle = new Text();
	hangmanTitle->setCharacterSize(200);
	hangmanTitle->setPosition(Vector2f(xStartGame + 150, yStartGame - 425));
	hangmanTitle->setString("HANGMAN");
	hangmanTitle->setFillColor(Color::White);
	hangmanTitle->setFont(*font);


	// How to Play Text
	Text* rulesText = new Text();
	rulesText->setCharacterSize(80);
	rulesText->setPosition(Vector2f(10, 10));
	rulesText->setString("Rules:\nA random word will be chosen.\nYour job is to guess the word letter "
		"by \nletter. \nA blank line represents each letter \nin the word. \nYou have a certain amount "
		"of tries to \nguess the word before you lose. \nGood luck!\n");
	rulesText->setFillColor(Color::White);
	rulesText->setFont(*font);


	// Back to Main Menu Button
	RectangleShape* returnToMainButton = new RectangleShape(Vector2f(500, 120));
	returnToMainButton->setFillColor(lightPink);
	returnToMainButton->setPosition(Vector2f(xStartGame + 780, yStartGame + 230));
	returnToMainButton->setOutlineThickness(10);
	returnToMainButton->setOutlineColor(Color::White);

	// Back to Main Menu Text
	Text* returnToMainText = new Text();
	returnToMainText->setCharacterSize(50);
	returnToMainText->setPosition(Vector2f(xStartGame + 800, yStartGame + 250));
	returnToMainText->setString("Return to Main Menu");
	returnToMainText->setFillColor(Color::Black);
	returnToMainText->setFont(*font);


	// Easy Button
	RectangleShape* easyButton = new RectangleShape(Vector2f(500, 200));
	easyButton->setFillColor(lightPink);
	easyButton->setPosition(Vector2f(xStartGame + 350, yStartGame - 500));
	easyButton->setOutlineThickness(10);
	easyButton->setOutlineColor(Color::White);

	//Easy Text
	Text* easyText = new Text();
	easyText->setCharacterSize(100);
	easyText->setPosition(Vector2f(xStartGame + 490, yStartGame - 460));
	easyText->setString("EASY");
	easyText->setFillColor(Color::Black);
	easyText->setFont(*font);

	// Medium Button
	RectangleShape* mediumButton = new RectangleShape(Vector2f(500, 200));
	mediumButton->setFillColor(lightPink);
	mediumButton->setPosition(Vector2f(xStartGame + 350, yStartGame - 200));
	mediumButton->setOutlineThickness(10);
	mediumButton->setOutlineColor(Color::White);

	//Medium Text
	Text* mediumText = new Text();
	mediumText->setCharacterSize(100);
	mediumText->setPosition(Vector2f(xStartGame + 420, yStartGame - 170));
	mediumText->setString("MEDIUM");
	mediumText->setFillColor(Color::Black);
	mediumText->setFont(*font);

	// Hard Button
	RectangleShape* hardButton = new RectangleShape(Vector2f(500, 200));
	hardButton->setFillColor(lightPink);
	hardButton->setPosition(Vector2f(xStartGame + 350, yStartGame + 100));
	hardButton->setOutlineThickness(10);
	hardButton->setOutlineColor(Color::White);

	//Hard Text
	Text* hardText = new Text();
	hardText->setCharacterSize(100);
	hardText->setPosition(Vector2f(xStartGame + 480, yStartGame + 140));
	hardText->setString("HARD");
	hardText->setFillColor(Color::Black);
	hardText->setFont(*font);

	//Four Letter Word Lines
	RectangleShape* easyLine1 = new RectangleShape(sf::Vector2f(100, 5));
	RectangleShape* easyLine2 = new RectangleShape(sf::Vector2f(100, 5));
	RectangleShape* easyLine3 = new RectangleShape(sf::Vector2f(100, 5));
	RectangleShape* easyLine4 = new RectangleShape(sf::Vector2f(100, 5));
	RectangleShape* easyLine5 = new RectangleShape(sf::Vector2f(100, 5));
	RectangleShape* easyLine6 = new RectangleShape(sf::Vector2f(100, 5));
	easyLine1->setPosition(Vector2f(xStartGame + 50, yStartGame + 200));
	easyLine2->setPosition(Vector2f(xStartGame + 200, yStartGame + 200));
	easyLine3->setPosition(Vector2f(xStartGame + 350, yStartGame + 200));
	easyLine4->setPosition(Vector2f(xStartGame + 500, yStartGame + 200));
	easyLine5->setPosition(Vector2f(xStartGame + 650, yStartGame + 200));
	easyLine6->setPosition(Vector2f(xStartGame + 800, yStartGame + 200));


	//Generates a random word for the easy level
	string easyRandomWord;
	easyRandomWord = e1->getRandomWord();

	//easy level letter one
	Text* easyLetter1 = new Text();
	easyLetter1->setCharacterSize(100);
	easyLetter1->setPosition(Vector2f(xStartGame + 60, yStartGame + 80));
	easyLetter1->setString(easyRandomWord[0]);
	easyLetter1->setFillColor(Color::White);
	easyLetter1->setFont(*font);

	//easy level letter two
	Text* easyLetter2 = new Text();
	easyLetter2->setCharacterSize(100);
	easyLetter2->setPosition(Vector2f(xStartGame + 210, yStartGame + 80));
	easyLetter2->setString(easyRandomWord[1]);
	easyLetter2->setFillColor(Color::White);
	easyLetter2->setFont(*font);

	//easy level letter three
	Text* easyLetter3 = new Text();
	easyLetter3->setCharacterSize(100);
	easyLetter3->setPosition(Vector2f(xStartGame + 370, yStartGame + 80));
	easyLetter3->setString(easyRandomWord[2]);
	easyLetter3->setFillColor(Color::White);
	easyLetter3->setFont(*font);

	//easy level letter four
	Text* easyLetter4 = new Text();
	easyLetter4->setCharacterSize(100);
	easyLetter4->setPosition(Vector2f(xStartGame + 510, yStartGame + 80));
	easyLetter4->setString(easyRandomWord[3]);
	easyLetter4->setFillColor(Color::White);
	easyLetter4->setFont(*font);

	//Generates a random word for the medium level
	string mediumRandomWord;
	mediumRandomWord = m1->getRandomWord();

	//medium level letter one
	Text* mediumLetter1 = new Text();
	mediumLetter1->setCharacterSize(100);
	mediumLetter1->setPosition(Vector2f(xStartGame + 60, yStartGame + 80));
	mediumLetter1->setString(mediumRandomWord[0]);
	mediumLetter1->setFillColor(Color::White);
	mediumLetter1->setFont(*font);

	//medium level letter two
	Text* mediumLetter2 = new Text();
	mediumLetter2->setCharacterSize(100);
	mediumLetter2->setPosition(Vector2f(xStartGame + 210, yStartGame + 80));
	mediumLetter2->setString(mediumRandomWord[1]);
	mediumLetter2->setFillColor(Color::White);
	mediumLetter2->setFont(*font);

	//medium level letter three
	Text* mediumLetter3 = new Text();
	mediumLetter3->setCharacterSize(100);
	mediumLetter3->setPosition(Vector2f(xStartGame + 370, yStartGame + 80));
	mediumLetter3->setString(mediumRandomWord[2]);
	mediumLetter3->setFillColor(Color::White);
	mediumLetter3->setFont(*font);

	//medium level letter four
	Text* mediumLetter4 = new Text();
	mediumLetter4->setCharacterSize(100);
	mediumLetter4->setPosition(Vector2f(xStartGame + 510, yStartGame + 80));
	mediumLetter4->setString(mediumRandomWord[3]);
	mediumLetter4->setFillColor(Color::White);
	mediumLetter4->setFont(*font);

	//medium level letter five
	Text* mediumLetter5 = new Text();
	mediumLetter5->setCharacterSize(100);
	mediumLetter5->setPosition(Vector2f(xStartGame + 680, yStartGame + 80));
	mediumLetter5->setString(mediumRandomWord[4]);
	mediumLetter5->setFillColor(Color::White);
	mediumLetter5->setFont(*font);

	//Generates a random word for the hard level
	string hardRandomWord;
	hardRandomWord = h1->getRandomWord();

	//hard level letter one
	Text* hardLetter1 = new Text();
	hardLetter1->setCharacterSize(100);
	hardLetter1->setPosition(Vector2f(xStartGame + 60, yStartGame + 80));
	hardLetter1->setString(hardRandomWord[0]);
	hardLetter1->setFillColor(Color::White);
	hardLetter1->setFont(*font);

	//hard level letter two
	Text* hardLetter2 = new Text();
	hardLetter2->setCharacterSize(100);
	hardLetter2->setPosition(Vector2f(xStartGame + 210, yStartGame + 80));
	hardLetter2->setString(hardRandomWord[1]);
	hardLetter2->setFillColor(Color::White);
	hardLetter2->setFont(*font);

	//hard level letter three
	Text* hardLetter3 = new Text();
	hardLetter3->setCharacterSize(100);
	hardLetter3->setPosition(Vector2f(xStartGame + 370, yStartGame + 80));
	hardLetter3->setString(hardRandomWord[2]);
	hardLetter3->setFillColor(Color::White);
	hardLetter3->setFont(*font);

	//hard level letter four
	Text* hardLetter4 = new Text();
	hardLetter4->setCharacterSize(100);
	hardLetter4->setPosition(Vector2f(xStartGame + 510, yStartGame + 80));
	hardLetter4->setString(hardRandomWord[3]);
	hardLetter4->setFillColor(Color::White);
	hardLetter4->setFont(*font);

	//hard level letter five
	Text* hardLetter5 = new Text();
	hardLetter5->setCharacterSize(100);
	hardLetter5->setPosition(Vector2f(xStartGame + 680, yStartGame + 80));
	hardLetter5->setString(hardRandomWord[4]);
	hardLetter5->setFillColor(Color::White);
	hardLetter5->setFont(*font);


	//hard level letter six
	Text* hardLetter6 = new Text();
	hardLetter6->setCharacterSize(100);
	hardLetter6->setPosition(Vector2f(xStartGame + 820, yStartGame + 80));
	hardLetter6->setString(hardRandomWord[5]);
	hardLetter6->setFillColor(Color::White);
	hardLetter6->setFont(*font);


	// Win or Lose Text
	Text* gameResults = new Text();
	gameResults->setCharacterSize(180);
	gameResults->setFillColor(Color::White);
	gameResults->setFont(*font);
	gameResults->setPosition(Vector2f(xStartGame + 200, yStartGame - 500));
	
	// Word to Guess Text
	Text* wordReveal = new Text();
	wordReveal->setCharacterSize(100);
	wordReveal->setFillColor(Color::White);
	wordReveal->setFont(*font);
	wordReveal->setPosition(Vector2f(xStartGame + 300, yStartGame - 50));

	// Guesses Left Text
	Text* guessesLeft = new Text();
	guessesLeft->setFont(*font);
	guessesLeft->setColor(lightPink);
	guessesLeft->setCharacterSize(60);
	guessesLeft->setPosition(Vector2f(xStartGame + 850, yStartGame + 200));


	// guess counts for loop
	int guessCount = 0, correctGuessCount = 0;

	// bools representing the states of the game
	bool inMainMenu = true, inGame = false, inHelpScreen = false, inPickLevel = false,
		inHardLevel = false, inMediumLevel = false, inEasyLevel = false, inEndGame = false;


	// array representing what letters have been chosen
	int alphabet[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	// Word Bank Letters Text
	Text* letters[26];
	int xPosLetter = xStartGame + 700;
	int yPosLetter = yStartGame - 550;
	for (int i = 0; i < 26; ++i)
	{
		if (i % 6 == 0 && i != 0)
		{
			yPosLetter += 100;
			xPosLetter = xStartGame + 700;
		}
		else if (i != 0)
		{
			xPosLetter += 100;
		}
		letters[i] = new Text();
		letters[i]->setCharacterSize(90);
		char letter = 'A';
		letter = letter + i;
		letters[i]->setString(letter);
		letters[i]->setFillColor(Color::White);
		letters[i]->setPosition(Vector2f(xPosLetter, yPosLetter));
		letters[i]->setFont(*font);
	}
	Color purple(208, 98, 255); // letter has been chosen color


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (inMainMenu)
		{
			if (Mouse::isButtonPressed(Mouse::Right) || Mouse::isButtonPressed(Mouse::Left))
			{
				if (isMouseTouchingRectangle(*startGame, window))
				{
					inMainMenu = false;
					inPickLevel = true;
				}

				if (isMouseTouchingRectangle(*helpButton, window))
				{
					inMainMenu = false;
					inHelpScreen = true;
				}
			}
		}
		else if (inHelpScreen)
		{
			if (Mouse::isButtonPressed(Mouse::Right) || Mouse::isButtonPressed(Mouse::Left))
			{
				if (isMouseTouchingRectangle(*returnToMainButton, window))
				{
					inMainMenu = true;
					inHelpScreen = false;
				}
			}
		}

		else if (inPickLevel)
		{
			if (Mouse::isButtonPressed(Mouse::Right) || Mouse::isButtonPressed(Mouse::Left))
			{
				if (isMouseTouchingRectangle(*easyButton, window)) // Easy Level selected
				{
					// Resets all variables for the level
					inPickLevel = false;
					inEasyLevel = true;
					easyRandomWord = e1->getRandomWord();
					easyLetter1->setString(easyRandomWord[0]);
					easyLetter2->setString(easyRandomWord[1]);
					easyLetter3->setString(easyRandomWord[2]);
					easyLetter4->setString(easyRandomWord[3]);
					guessCount = 0;
					correctGuessCount = 0;
					e1->setBoolsToFalse();
					guessesLeft->setString("Guesses Left: 10");
				}

				if (isMouseTouchingRectangle(*mediumButton, window)) // Medium Level selected
				{
					inPickLevel = false;
					inMediumLevel = true;
					mediumRandomWord = m1->getRandomWord();
					mediumLetter1->setString(mediumRandomWord[0]);
					mediumLetter2->setString(mediumRandomWord[1]);
					mediumLetter3->setString(mediumRandomWord[2]);
					mediumLetter4->setString(mediumRandomWord[3]);
					mediumLetter5->setString(mediumRandomWord[4]);
					guessCount = 0;
					correctGuessCount = 0;
					m1->setBoolsToFalse();
					guessesLeft->setString("Guesses Left: 8");
				}
				if (isMouseTouchingRectangle(*hardButton, window)) // Hard Level selected
				{
					inPickLevel = false;
					inHardLevel = true;
					hardRandomWord = h1->getRandomWord();
					hardLetter1->setString(hardRandomWord[0]);
					hardLetter2->setString(hardRandomWord[1]);
					hardLetter3->setString(hardRandomWord[2]);
					hardLetter4->setString(hardRandomWord[3]);
					hardLetter5->setString(hardRandomWord[4]);
					hardLetter6->setString(hardRandomWord[5]);
					guessCount = 0;
					correctGuessCount = 0;
					h1->setBoolsToFalse();
					guessesLeft->setString("Guesses Left: 6");
				}
			}
		}

		else if (inEasyLevel) 
		{
			cout << "Enter letter guess:" << endl;
			char letterGuess;
			cin >> letterGuess;
			letterGuess = tolower(letterGuess); // converts the letter to lower case
			if (letterGuess <= 122 && letterGuess >= 97)
			{
				// is a lowercase letter
				if (alphabet[letterGuess - 97] == 1)
				{
					// already guessed this letter
					cout << "You already guessed this letter. Guess again!" << endl;
				}
				else
				{
					alphabet[letterGuess - 97] = 1;
					letters[letterGuess - 97]->setColor(purple);
					guessCount++;
					correctGuessCount = e1->guess(easyRandomWord, letterGuess, correctGuessCount, guessCount);
					string guessStr = "Guesses Left: " + std::to_string(10 - (guessCount - correctGuessCount));
					guessesLeft->setString(guessStr);

				}
			}
			else
			{
				// is not a letter
				cout << "Enter a valid letter a-z" << endl;
			}
		}
		else if (inMediumLevel)
		{
			cout << "Enter letter guess:" << endl;
			char letterGuess;
			cin >> letterGuess;
			letterGuess = tolower(letterGuess); // converts the letter to lower case
			if (letterGuess <= 122 && letterGuess >= 97)
			{
				// is a lowercase letter
				if (alphabet[letterGuess - 97] == 1)
				{
					// already guessed this letter
					cout << "You already guessed this letter. Guess again!" << endl;
				}
				else
				{
					alphabet[letterGuess - 97] = 1;
					letters[letterGuess - 97]->setColor(purple);
					guessCount++;
					correctGuessCount = m1->guess(mediumRandomWord, letterGuess, correctGuessCount, guessCount);
					guessesLeft->setString("Guesses Left: " + std::to_string(8 - (guessCount - correctGuessCount)));
				}
			}
			else
			{
				// is not a letter
				cout << "Enter a valid letter a-z" << endl;
			}
		}
		else if (inHardLevel)
		{
			cout << "Enter letter guess:" << endl;
			char letterGuess;
			cin >> letterGuess;
			letterGuess = tolower(letterGuess); // converts the letter to lower case
			if (letterGuess <= 122 && letterGuess >= 97)
			{
				// is a lowercase letter
				if (alphabet[letterGuess - 97] == 1)
				{
					// already guessed this letter
					cout << "You already guessed this letter. Guess again!" << endl;
				}
				else
				{
					alphabet[letterGuess - 97] = 1;
					letters[letterGuess - 97]->setColor(purple);
					guessCount++;
					correctGuessCount = h1->guess(hardRandomWord, letterGuess, correctGuessCount, guessCount);
					guessesLeft->setString("Guesses Left: " + std::to_string(6 - (guessCount - correctGuessCount)));
				}
			}
			else
			{
				// is not a letter
				cout << "Enter a valid letter a-z" << endl;
			}
		}
		else if (inEndGame)
		{
			if (Mouse::isButtonPressed(Mouse::Right) || Mouse::isButtonPressed(Mouse::Left))
			{
				if (isMouseTouchingRectangle(*returnToMainButton, window))
				{
					inMainMenu = true;
					inEndGame = false;
					// Resets letters after each round
					for (int i = 0; i < 26; ++i)
					{
						alphabet[i] = 0;
						letters[i]->setColor(Color::White);
					}
				}
			}
		}

		// IF-STATEMENTS DRAWING ALL THE SHAPES AND TEXT

		window.clear();
		if (inMainMenu) // Main Menu Screen
		{
			window.draw(*startGame);
			window.draw(*startGameText);
			window.draw(*helpButton);
			window.draw(*helpText);
			window.draw(*hangmanTitle);
		}
		else if (inHelpScreen) // Rules to Hangman Screen
		{
			window.draw(*rulesText);
			window.draw(*returnToMainButton);
			window.draw(*returnToMainText);
		}
		else if (inPickLevel) // PICK LEVEL SCREEN
		{
			window.draw(*easyButton);
			window.draw(*mediumButton);
			window.draw(*hardButton);
			window.draw(*easyText);
			window.draw(*mediumText);
			window.draw(*hardText);
		}
		else if (inEasyLevel) // EASY LEVEL
		{
			window.draw(hanger->getBase());
			window.draw(hanger->getTall());
			window.draw(hanger->getHort());
			window.draw(hanger->getString());

			if (e1->getFirstLetter() == true)
			{

				window.draw(*easyLetter1);
			}
			if (e1->getSecondLetter() == true)
			{

				window.draw(*easyLetter2);
			}
			if (e1->getThirdLetter() == true)
			{

				window.draw(*easyLetter3);
			}
			if (e1->getFourthLetter() == true)
			{

				window.draw(*easyLetter4);
			}
			if (e1->getheadDrawn() == true)
			{
				window.draw(e1->getHead());
			}
			if (e1->getBodyDrawn() == true)
			{
				window.draw(e1->getBody());
			}
			if (e1->getRightArmDrawn() == true)
			{
				window.draw(e1->getRightArm());
			}
			if (e1->getLeftArmDrawn() == true)
			{
				window.draw(e1->getLeftArm());
			}
			if (e1->getRightLegDrawn() == true)
			{
				window.draw(e1->getRightLeg());
			}
			if (e1->getLeftLegDrawn() == true)
			{
				window.draw(e1->getLeftLeg());
			}
			if (e1->getShirtDrawn() == true)
			{
				window.draw(e1->getShirtBody());
				window.draw(e1->getRightSleeve());
				window.draw(e1->getLeftSleeve());
			}
			if (e1->getPantsDrawn() == true)
			{
				window.draw(e1->getPants());
				window.draw(e1->getRightPantLeg());
				window.draw(e1->getLeftPantLeg());
			}
			if (e1->getRightShoeDrawn() == true)
			{
				window.draw(e1->getRightShoe());
			}
			if (e1->getLeftShoeDrawn() == true)
			{
				window.draw(e1->getLeftShoe());
			}

			window.draw(*easyLine1);
			window.draw(*easyLine2);
			window.draw(*easyLine3);
			window.draw(*easyLine4);

			if (correctGuessCount == 4 || guessCount - correctGuessCount == 10) // game is over
			{
				if (correctGuessCount == 4)
				{
					gameResults->setString("You win!");
				}
				else
				{
					gameResults->setString("You lose...");
				}
				wordReveal->setString("Word: " + easyRandomWord);
				inEasyLevel = false;
				inEndGame = true;
				system("cls");
			}
			
			for (int i = 0; i < 26; i++) // draw the letters of the letter bank
			{
				window.draw(*letters[i]);
			}
			window.draw(*guessesLeft);
		}
		else if (inMediumLevel) // MEDIUM LEVEL
		{
			window.draw(hanger->getBase());
			window.draw(hanger->getTall());
			window.draw(hanger->getHort());
			window.draw(hanger->getString());

			if (m1->getFirstLetter() == true)
			{

				window.draw(*mediumLetter1);
			}
			if (m1->getSecondLetter() == true)
			{

				window.draw(*mediumLetter2);
			}
			if (m1->getThirdLetter() == true)
			{

				window.draw(*mediumLetter3);
			}
			if (m1->getFourthLetter() == true)
			{
				window.draw(*mediumLetter4);
			}
			if (m1->getFifthLetter() == true)
			{
				window.draw(*mediumLetter5);
			}
			if (m1->getheadDrawn() == true)
			{
				window.draw(m1->getHead());
			}
			if (m1->getBodyDrawn() == true)
			{
				window.draw(m1->getBody());
			}
			if (m1->getRightArmDrawn() == true)
			{
				window.draw(m1->getRightArm());
			}
			if (m1->getLeftArmDrawn() == true)
			{
				window.draw(m1->getLeftArm());
			}
			if (m1->getRightLegDrawn() == true)
			{
				window.draw(m1->getRightLeg());
			}
			if (m1->getLeftLegDrawn() == true)
			{
				window.draw(m1->getLeftLeg());
			}
			if (m1->getShirtDrawn() == true)
			{
				window.draw(m1->getShirtBody());
				window.draw(m1->getRightSleeve());
				window.draw(m1->getLeftSleeve());
			}
			if (m1->getPantsDrawn() == true)
			{
				window.draw(m1->getPants());
				window.draw(m1->getRightPantLeg());
				window.draw(m1->getLeftPantLeg());
			}
			window.draw(*easyLine1);
			window.draw(*easyLine2);
			window.draw(*easyLine3);
			window.draw(*easyLine4);
			window.draw(*easyLine5);

			if (correctGuessCount == 5 || guessCount - correctGuessCount == 8) // game is over
			{
				if (correctGuessCount == 5)
				{
					gameResults->setString("You win!");
				}
				else
				{
					gameResults->setString("You lose...");
				}
				wordReveal->setString("Word: " + mediumRandomWord);
				inMediumLevel = false;
				inEndGame = true;
				system("cls");
			}
			for (int i = 0; i < 26; i++) // draw letters of the letter box
			{
				window.draw(*letters[i]);
			}
			window.draw(*guessesLeft);
		}
		else if (inHardLevel) // HARD LEVEL
		{
			window.draw(hanger->getBase());
			window.draw(hanger->getTall());
			window.draw(hanger->getHort());
			window.draw(hanger->getString());

			if (h1->getFirstLetter() == true)
			{
				window.draw(*hardLetter1);
			}
			if (h1->getSecondLetter() == true)
			{
				window.draw(*hardLetter2);
			}
			if (h1->getThirdLetter() == true)
			{
				window.draw(*hardLetter3);
			}
			if (h1->getFourthLetter() == true)
			{
				window.draw(*hardLetter4);
			}
			if (h1->getFifthLetter() == true)
			{
				window.draw(*hardLetter5);
			}
			if (h1->getSixthLetter() == true)
			{
				window.draw(*hardLetter6);
			}

			if (h1->getheadDrawn() == true)
			{
				window.draw(h1->getHead());
			}
			if (h1->getBodyDrawn() == true)
			{
				window.draw(h1->getBody());
			}
			if (h1->getRightArmDrawn() == true)
			{
				window.draw(h1->getRightArm());
			}
			if (h1->getLeftArmDrawn() == true)
			{
				window.draw(h1->getLeftArm());
			}
			if (h1->getRightLegDrawn() == true)
			{
				window.draw(h1->getRightLeg());
			}
			if (h1->getLeftLegDrawn() == true)
			{
				window.draw(h1->getLeftLeg());
			}

			window.draw(*easyLine1);
			window.draw(*easyLine2);
			window.draw(*easyLine3);
			window.draw(*easyLine4);
			window.draw(*easyLine5);
			window.draw(*easyLine6);

			if (correctGuessCount == 6 || guessCount - correctGuessCount == 6) // game is over
			{
				if (correctGuessCount == 6)
				{
					gameResults->setString("You win!");
				}
				else
				{
					gameResults->setString("You lose...");
				}
				wordReveal->setString("Word: " + hardRandomWord);
				inHardLevel = false;
				inEndGame = true;
				system("cls");
			}
			for (int i = 0; i < 26; i++) // draw letters of the letter box
			{
				window.draw(*letters[i]);
			}
			window.draw(*guessesLeft);
		}
		else if (inEndGame) // ENDING SCREEN
		{
			// draws the results of the game
			window.draw(*gameResults);
			window.draw(*wordReveal);
			window.draw(*returnToMainButton);
			window.draw(*returnToMainText);
		}
		window.display();

	}

	// deletes everything off the heap
	delete font, startGame, startGameText, helpButton, helpText, hangmanTitle, rulesText;
	delete returnToMainButton, returnToMainText, easyButton, easyText, mediumButton, mediumText;
	delete hardButton, hardText, easyLine1, easyLine2, easyLine3, easyLine4, easyLine5, easyLine6;
	delete easyLetter1, easyLetter2, easyLetter3, easyLetter4, gameResults;
	delete mediumLetter1, mediumLetter2, mediumLetter3, mediumLetter4, mediumLetter5;
	delete hardLetter1, hardLetter2, hardLetter3, hardLetter4, hardLetter5, hardLetter6;
	delete[] letters;
	delete e1, hanger, m1, h1, wordReveal, guessesLeft;

	return 0;
}


/*************************************************************
* Function: isMouseTouchingRectangle ()	                     *
* Date Created: 4/20/2022                                    *
* Date Last Modified: 4/20/2022                              *
* Description: This function determines whether the mouse is *
*			   touching a RectangleShape object.			 *
* Input parameters: A RectangleShape and the window.		 *
* Returns: bool.					                         *
* Preconditions: None.				   				         *
* Postconditions: A bool is returned.						 *
*************************************************************/
bool isMouseTouchingRectangle(RectangleShape& rect, RenderWindow &window)
{
	return Mouse::getPosition(window).x >= rect.getPosition().x
		&& Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x
		&& Mouse::getPosition(window).y >= rect.getPosition().y
		&& Mouse::getPosition(window).y <= rect.getPosition().y + rect.getSize().y;
}


