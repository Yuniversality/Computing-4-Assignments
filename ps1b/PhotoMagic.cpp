#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.h"

void transform(sf::Image& sourceImage, FibLFSR* seed);

void transform(sf::Image& sourceImage, FibLFSR* seed)
{
	//get the size of the image
	sf::Vector2u size = sourceImage.getSize();
	unsigned int imageWidth = size.x;
	unsigned int imageHeight = size.y;

	sf::Color color;
	
	unsigned int randomNum, redComponent, greenComponent, blueComponent, redXORResult, greenXORResult, blueXORResult;
	
	for (unsigned int i = 0; i < imageWidth; i++)
	{
		for (unsigned int j = 0; j < imageHeight; j++)
		{
			//extract red and XOR with random number
			color = sourceImage.getPixel(i, j);
			randomNum = seed->generate(8);
			redComponent = color.r;
			redXORResult = redComponent ^ randomNum;

			//extract green and XOR with random number
			randomNum = seed->generate(8);
			greenComponent = color.g;
			greenXORResult = greenComponent ^ randomNum;

			//extract blue and XOR with random number
			randomNum = seed->generate(8);
			blueComponent = color.b;
			blueXORResult = blueComponent ^ randomNum;

			//set the pixel to the new color
			sourceImage.setPixel(i, j, sf::Color(redXORResult, greenXORResult, blueXORResult));
		}
	}
}

int main(int argc, char* argv[])
{
	//arg[0] = name of executable, arg[1] = inputfile, arg[2] = outputFile, arg[3] = seed
	const std::string inputFile = argv[1];
	const std::string outputFile = argv[2];

	sf::Image image;
	if (!image.loadFromFile(inputFile))
	{
		return -1;
	}
	
	// p is for pixelimage.getPixel(x, y);
	sf::Color p;
	
	// get the size (width, height) of the image
	sf::Vector2u size = image.getSize();

	// make a FibLFSR object to pass into transform()
	FibLFSR seed(argv[3]);

	// create photographic negative image
	for (unsigned int x = 0; x < size.x; x++) 
	{
		for (unsigned int y = 0; y < size.y; y++) 
		{
			p = image.getPixel(x, y);
			p.r = 255 - p.r;
			p.g = 255 - p.g;
			p.b = 255 - p.b;
			image.setPixel(x, y, p);
		}
	}
	
	//encrypt the file using the seed
	transform(image, &seed);
	
	//set up and display the encrypted image
	sf::RenderWindow window(sf::VideoMode(size.x, size.y), outputFile);
	
	sf::Texture texture;
	texture.loadFromImage(image);
	
	sf::Sprite sprite;
	sprite.setTexture(texture);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		window.draw(sprite);
		window.display();
	}

	//   write the file
	if (!image.saveToFile(outputFile))
	{
		return -1;
	}
		
	return 0;
}


