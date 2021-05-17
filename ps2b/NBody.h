#ifndef NBODY_H 
#define NBODY_H 

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
//#include <string> //already included in the other header files
//#include <vector>
#include <memory>
#include <cmath>

//gravitational constant G
const double G = 6.67e-11;

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
	
	void setXPosition(double newXPos) {
		xPosition = newXPos;
	}
	
	double getYPosition(void) {
		return yPosition;
	}
	
	void setYPosition(double newYPos) {
		yPosition = newYPos;
	}
	
	double getXVelocity(void) {
		return xVelocity;
	}
	
	void setXVelocity(double newXVel) {
		xVelocity = newXVel;
	}
	
	double getYVelocity(void) {
		return yVelocity;
	}
	
	void setYVelocity(double newYVel) {
		yVelocity = newYVel;
	}
	
	double getMass(void) {
		return bodyMass;
	}
	
	std::string getFileName(void) {
		return fileName;
	}
	
	sf::Sprite getBodySprite(void) {
		return bodySprite;
	}
	
	void setBodySprite(sf::Sprite newSprite)
	{
		bodySprite = newSprite;
	}
	
	double getForceX(void) {
		return forceX;
	}
	
	void setForceX(double newForceX) {
		forceX = newForceX;
	}
	
	double getForceY(void) {
		return forceY;
	}
	
	void setForceY(double newForceY) {
		forceY = newForceY;
	}
	
	double getAccelerationX(void) {
		return accelerationX;
	}
	
	void setAccelerationX(double newAccelerationX) {
		accelerationX = newAccelerationX;
	}
	
	double getAccelerationY(void) {
		return accelerationY;
	}
	
	void setAccelerationY(double newAccelerationY) {
		accelerationY = newAccelerationY;
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
	
	double forceX;
	double forceY;
	double accelerationX;
	double accelerationY;
	
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};


class Universe
{
public:
	Universe();
	
	void step(double deltaTime, std::shared_ptr<CelestialBody> bodyPtr);
	
	double getNumPlanets(void) {
		return numPlanets;
	}
	
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

//Standalone functions

//Function for calculating place on the screen
float calculatePosition(double universeRadius, double position, double screenDimension);

//Functions for calculating components for the physics calculations
double calculateDeltaX(std::shared_ptr<CelestialBody> bodyPtr, 
	std::shared_ptr<CelestialBody> sunPtr);
double calculateDeltaY(std::shared_ptr<CelestialBody> bodyPtr, 
	std::shared_ptr<CelestialBody> sunPtr);
	
double calculateHypotenuseR(double deltaX, double deltaY);

double calculateForce(std::shared_ptr<CelestialBody> bodyPtr, 
	std::shared_ptr<CelestialBody> sunPtr, double hypotenuseR);
double calculateForceX(double totalForce, double deltaX, double hypotenuseR);
double calculateForceY(double totalForce, double deltaY, double hypotenuseR);

#endif


