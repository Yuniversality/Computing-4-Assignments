#include "NBody.h"

//CelestialBody value constructor (not used)
CelestialBody::CelestialBody(double xPos, double yPos, 
	double xVel, double yVel, double mass,
	std::string name)
{
	xPosition = xPos;
	yPosition = yPos;
	xVelocity = xVel;
	yVelocity = yVel;
	bodyMass = mass;
	fileName = name;
	
	if (!bodyImage.loadFromFile(fileName))
	{
		exit(1);
	}
	
	bodyTexture.loadFromImage(bodyImage);
	bodySprite.setTexture(bodyTexture);
	
}

//CelestialBody Default Constructor
CelestialBody::CelestialBody()
{
	xPosition = 0;
	yPosition = 0;
	xVelocity = 0;
	yVelocity = 0;
	bodyMass = 0;
	fileName = "";
}

//CelestialBody's draw function
void CelestialBody::draw(sf::RenderTarget &target, sf::RenderStates states) const
{	
	target.draw(bodySprite, states);
}

//The insertion operator will automatically set all the CelestialBody's values
//And create the image, texture, and sprite
std::istream &operator>> (std::istream &in, CelestialBody &body)
{
	in >> body.xPosition >> body.yPosition >> 
		body.xVelocity >> body.yVelocity >> 
		body.bodyMass >> body.fileName;

	body.bodyImage.loadFromFile(body.fileName);
	body.bodyTexture.loadFromImage(body.bodyImage);
	body.bodySprite.setTexture(body.bodyTexture);
	
	return in;
}

Universe::Universe()
{	
	std::cin >> numPlanets >> universeRadius;
	for (int i = 0; i < numPlanets; i++)
	{	
		//Make a new shared_ptr and add it to the back of the vector
		std::shared_ptr<CelestialBody> celestialBodyPtr(new CelestialBody);
		bodyVector.push_back(celestialBodyPtr);
		
		//Use the overloaded insertion (>>) operator to create the CelestialBody
		std::cin >> *bodyVector.back();
	}
}

//Since we want (0,0) to be in the middle, we do + (screenDimension / 2)
//We do (position / universeRadius) * (screenDimension / 2) to get the 
//offset of the planets from the middle
float calculatePosition(double universeRadius, double position, double screenDimension)
{
	
	float newPosition = (position / universeRadius) * (screenDimension / 2) + (screenDimension / 2);
	return newPosition;
}


