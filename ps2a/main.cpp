#include "NBody.h"

int main(int argc, char* argv[])
{
	//Check to see if we have the background file
	sf::Image background;
	if (!background.loadFromFile("starfield.jpg"))
	{
		return -1;
	}
	
	//Set up the window and its dimensions
	sf::Vector2u size = background.getSize();
	sf::RenderWindow window(sf::VideoMode(size.x, size.y), "Solar System");
	
	//Make a Universe object which will read from file upon creation
	Universe universe;
	
	//Set up variables for when we draw the CelestialBodies
	sf::Sprite tempPlanetSprite;
	float newXPosition;
	float newYPosition;
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);
		
		//Set up the Background
		sf::Texture backgroundTexture;
		backgroundTexture.loadFromImage(background);
		
		//Draw the background
		sf::Sprite backgroundSprite;
		backgroundSprite.setTexture(backgroundTexture);
		window.draw(backgroundSprite);
		
		//Draw the CelestialBodies
		std::vector<std::shared_ptr<CelestialBody>> temp = universe.getVector();
		for (auto bodyPtr : temp)
		{
			//Create a temp CelestialBody sprite, modify it, then set it back
			tempPlanetSprite = (*bodyPtr).getBodySprite();
			newXPosition = calculatePosition(universe.getUniverseRadius(), (*bodyPtr).getXPosition(), size.x);
			newYPosition = calculatePosition(universe.getUniverseRadius(), (*bodyPtr).getYPosition(), size.y);
			tempPlanetSprite.setPosition(newXPosition, newYPosition);
			(*bodyPtr).setBodySprite(tempPlanetSprite);
			
			//Actually draw the CelestialBody
			window.draw(*bodyPtr);
		}
		
		//Display the screen		
		window.display();
	}
	
	return 0;
}


