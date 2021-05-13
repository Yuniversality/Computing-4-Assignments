//Author: Ethan Yu

#include <SFML/Graphics.hpp>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("./sprite.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    // Set the initial position of the sprite
    //sprite.setPosition(400,300);

    //Vector2 objects used to adjust sprite properties
    sf::Vector2f newPosition;
    sf::Vector2f newScale;

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

	// Use the arrow keys to move the sprite
	sf::Vector2f newPosition;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		newPosition = sprite.getPosition();
		newPosition.y = newPosition.y - 5;
		sprite.setPosition(newPosition.x, newPosition.y);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		newPosition = sprite.getPosition();
                newPosition.y = newPosition.y + 5;
		sprite.setPosition(newPosition.x, newPosition.y);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		newPosition = sprite.getPosition();
                newPosition.x = newPosition.x - 5;
		sprite.setPosition(newPosition.x, newPosition.y);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		newPosition = sprite.getPosition();
                newPosition.x = newPosition.x + 5;
		sprite.setPosition(newPosition.x, newPosition.y);
	}	

	// Use the Z key to expand the sprite, X key to contract it
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		newScale = sprite.getScale();
		newScale.x = newScale.x * 1.01f;
                newScale.y = newScale.y * 1.01f;
                sprite.setScale(newScale);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		newScale = sprite.getScale();
		newScale.x = newScale.x * .99f;
		newScale.y = newScale.y * .99f;
		sprite.setScale(newScale);
	}	

        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(sprite);
        // Update the window
	window.display();
    }
    return EXIT_SUCCESS;
}

