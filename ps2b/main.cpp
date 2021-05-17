#include "NBody.h"

int main(int argc, char* argv[])
{
	//Set up the font for displaying the time
	sf::Font font;
	if (!font.loadFromFile("OpenSans-Regular.ttf"))
	{
		return -1;
	}
	
	//Set up the text used to display the time
	sf::Text elapsedTimeText;
	elapsedTimeText.setFont(font);
	elapsedTimeText.setCharacterSize(16);
	elapsedTimeText.setFillColor(sf::Color::Yellow);
	
	//Check to see if we have the background file
	sf::Image background;
	if (!background.loadFromFile("starfield.jpg"))
	{
		return -1;
	}
	
	//Set up and play the music
	sf::Music music;
	if (!(music.openFromFile("Worship_the_Endless.ogg")))
	{
		return -1;
	}
	music.setVolume(100);
	music.play();
	
	//Set up the window and its dimensions
	sf::Vector2u size = background.getSize();
	sf::RenderWindow window(sf::VideoMode(size.x, size.y), "Solar System");
	
	//Set the time variables by converting the command line arguments into doubles
	double maxTime = std::stod(argv[1]);
	double deltaTime = std::stod(argv[2]);
	double timePassed = 0; //Elapsed simulated time of the program
	
	//Make a Universe object which will read from file upon creation
	Universe universe;
	
	//Set up variables for when we draw the CelestialBodies
	sf::Sprite tempPlanetSprite;
	std::vector<std::shared_ptr<CelestialBody>> temp = universe.getVector();
	
	//Set up the time and clock
	sf::Clock clock;
	sf::Time elapsedTimeIRL = clock.restart();
	
	//Get the sun's mass
	std::shared_ptr<CelestialBody> sunPtr(nullptr);
	for (auto sunFinderPtr : temp)
	{
		if ((*sunFinderPtr).getFileName() == "sun.gif")
		{
			sunPtr = sunFinderPtr;
			break;
		}
	}
	
	while (window.isOpen() && (timePassed < maxTime))
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
		
		//Draw CelestialBodies
		for (auto bodyPtr : temp)
		{	
			if (!((*bodyPtr).getFileName() == "sun.gif"))
			{
				
				double deltaX = calculateDeltaX(bodyPtr, sunPtr);
				double deltaY = calculateDeltaY(bodyPtr, sunPtr);
				
				double hypotenuseR = calculateHypotenuseR(deltaX, deltaY);
				double totalForce = calculateForce(bodyPtr, sunPtr, hypotenuseR);
				double newForceX = calculateForceX(totalForce, deltaX, hypotenuseR);
				double newForceY = calculateForceY(totalForce, deltaY, hypotenuseR);
				
				(*bodyPtr).setForceX(newForceX);
				(*bodyPtr).setForceY(newForceY);
			
				universe.step(deltaTime, bodyPtr);
				
			}
			
			//Create a temp CelestialBody sprite, modify it, then set it back
			tempPlanetSprite = (*bodyPtr).getBodySprite();
			float newXPosition = calculatePosition(universe.getUniverseRadius(), (*bodyPtr).getXPosition(), size.x);
			float newYPosition = calculatePosition(universe.getUniverseRadius(), (*bodyPtr).getYPosition(), size.y);
			tempPlanetSprite.setPosition(newXPosition, newYPosition);
			(*bodyPtr).setBodySprite(tempPlanetSprite);
			
			//Actually draw the CelestialBody
			window.draw(*bodyPtr);
			
			//Update the time label
			elapsedTimeIRL = clock.getElapsedTime();
			std::string timeText = std::to_string(elapsedTimeIRL.asSeconds());
			elapsedTimeText.setString(timeText);
			window.draw(elapsedTimeText);
		}
		
		//Display the screen		
		window.display();
		timePassed = timePassed + deltaTime;
		
		
		
	}

	//Ending print statements for the state of universe
	std::cout << universe.getNumPlanets() << std::endl << 
		universe.getUniverseRadius() << std::endl;
	
	std::cout.precision(4);
	//std::vector<std::shared_ptr<CelestialBody>> temp = universe.getVector();
	for (auto bodyPtr : temp)
	{
		std::cout << std::scientific << (*bodyPtr).getXPosition() << "\t" <<
		 (*bodyPtr).getYPosition() << "\t" << (*bodyPtr).getXVelocity() << 
		 "\t" << (*bodyPtr).getYVelocity() << "\t" << (*bodyPtr).getMass() << 
		 "\t" << (*bodyPtr).getFileName() << std::endl;
	}
	
	return 0;
}


