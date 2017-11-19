//Patryk Wysocki
//20/11/17
//Animation-FSM

#include <iostream>
#include <SFML/Graphics.hpp>
#include <AnimatedSprite.h>
#include <Player.h>
#include <Input.h>
#include <Debug.h>

using namespace std;

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	// Load a sprite to display
	sf::Texture texture;
	sf::Font font;
	sf::Text helpMessage;
	if (!texture.loadFromFile("assets\\grid.png")) {
		DEBUG_MSG("Failed to load file");
		return EXIT_FAILURE;
	}
	if (!font.loadFromFile("assets\\ariblk.ttf")) {
		DEBUG_MSG("Failed to load font");
		return EXIT_FAILURE;
	}
	helpMessage.setFont(font);
	helpMessage.setPosition(200, 300);
	helpMessage.setCharacterSize(25);
	helpMessage.setColor(sf::Color::Green);
	helpMessage.setString("RIGHTARROW to SHOVELING\nLEFTARROW to SWORDING\n UPARROW to JUMPING\n DOWNARROW to CLIMBING \nSPACE to HAMMERING\n");
	// Setup Players Default Animated Sprite
	AnimatedSprite animated_sprite(texture);

	// Setup the Player
	Player player(animated_sprite);
	Input input;
	
	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				// Close window : exit
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					
					input.setCurrent(Input::Action::SWORDMANSHIP);
					animated_sprite.setAnimation(1);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					
					input.setCurrent(Input::Action::SHOVELING);
					animated_sprite.setAnimation(3);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					
					input.setCurrent(Input::Action::JUMPING);
					animated_sprite.setAnimation(4);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					
					input.setCurrent(Input::Action::CLIMBING);
					animated_sprite.setAnimation(5);
				}
				break;
			default:
				
				input.setCurrent(Input::Action::IDLE);
				animated_sprite.setAnimation(0);
				break;
			case sf::Event::TextEntered:

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{

					input.setCurrent(Input::Action::HAMMERING);
					animated_sprite.setAnimation(2);
				}
			}
		}

		// Handle input to Player
		player.handleInput(input);

		// Update the Player
		player.update();

		// Clear screen
		window.clear();


		// Draw the Players Current Animated Sprite
		window.draw(player.getAnimatedSprite());
		window.draw(helpMessage);

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
};