#ifndef NBODY_H 
#define NBODY_H 

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class CelestialBody : public sf::Drawable
{
public:
	CelestialBody();
	
	CelestialBody(double xPos, double yPos, 
	double xVel, double yVel, double mass,
	std::string name);
	
	double getXPosition(void) {
		return xPosition; 
	}
	
	double getYPosition(void) {
		return yPosition;
	}
	
	sf::Sprite getBodySprite(void) {
		return bodySprite;
	}
	
	void setBodySprite(sf::Sprite newSprite)
	{
		bodySprite = newSprite;
	}
	
	friend std::istream &operator>> (std::istream &in, CelestialBody &body);
	
private:
	double xPosition;
	double yPosition;
	double xVelocity;
	double yVelocity;
	double bodyMass;
	std::string fileName;
	sf::Image bodyImage;
	sf::Texture bodyTexture;
	sf::Sprite bodySprite;
	
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};


class Universe
{
public:
	Universe();
	
	double getUniverseRadius(void) {
		return universeRadius; 
	}
	
	void setUniverseRadius(double newRadius) {
		universeRadius = newRadius;
	}
	
	std::vector<std::shared_ptr<CelestialBody>> getVector(void)
	{
		return bodyVector;
	}
	
private:
	std::vector<std::shared_ptr<CelestialBody>> bodyVector;
	
	int numPlanets;
	double universeRadius;

};

//Stand-alone function for calculating place on the screen
float calculatePosition(double universeRadius, double position, double screenDimension);

#endif


