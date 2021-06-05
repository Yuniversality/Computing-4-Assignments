// Copyright 2021 Ethan Yu

#include "Triangle.h"

void fTree(std::vector<Triangle>& triangle_vector,  // NOLINT
  sf::Vector2f center_coordinates, double length,
  int target_depth, int current_depth);

int main(int argc, char* argv[]) {
    double base_size = atoi(argv[1]);
    int target_depth = atoi(argv[2]);

    // Set up the window and get starting variables
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sierpinski Triangle");
    int screen_x = window.getSize().x;
    int screen_y = window.getSize().y;
    sf::Vector2f starting_center((screen_x / 2), (screen_y / 2));
    std::vector<Triangle> triangle_vector;

    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Call recursive function with starting arguments
        fTree(triangle_vector, starting_center, base_size, target_depth, 0);

        window.clear();  // Clear screen

        // Go through the vector and draw the triangles
        std::vector<Triangle>::iterator iter;
        for (iter = triangle_vector.begin(); iter !=
        triangle_vector.end(); ++iter) {
            window.draw((*iter).get_vertex_array());  // Draw shape
        }
        window.display();  // Update window
    }
    return 0;
}

void fTree(std::vector<Triangle>& triangle_vector,  // NOLINT
  sf::Vector2f center, double length,
  int target_depth, int current_depth) {
    // Calculate the triagle's height
    double height = (sqrt(3) * length)/2;

    // Create and add the current triangle to the vector
    Triangle newTriangle(length, height, center);
    triangle_vector.push_back(newTriangle);

    // Stop iterating
    if (current_depth + 1 > target_depth) {
        return;
    }

    // Calculate the centers for the child triangles
    sf::Vector2f new_center_1(center.x - (length / 2),
     center.y - (2 * height/3));
    sf::Vector2f new_center_2(center.x + (3 * length/4),
     center.y - (height/6));
    sf::Vector2f new_center_3(center.x - (length/4),
     center.y + (5 * height/6));

    // Top triangle
    fTree(triangle_vector, new_center_1,
     length/2, target_depth, current_depth + 1);

    // Right triangle
    fTree(triangle_vector, new_center_2,
     length/2, target_depth, current_depth + 1);

    // Bottom Left triangle
    fTree(triangle_vector, new_center_3,
     length/2, target_depth, current_depth + 1);
}

