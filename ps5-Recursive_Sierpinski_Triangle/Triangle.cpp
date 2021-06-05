// Copyright 2021 Ethan Yu

#include "Triangle.h"

// Triangle Value Constructor
Triangle::Triangle(double init_length, int init_height,
 sf::Vector2f init_center) {
    length = init_length;
    height = init_height;
    sf::Vector2f center(init_center);

    // You need 4 points for the trianle's lines
    // 3 for the triangle's vertices, 1 wrap around
    // back to the initial vertice
    // Line sequence: 0 -> 1, 1 -> 2, 2 -> 3 (3 = 0)
    vertex_array = sf::VertexArray(sf::LineStrip, 4);

    // Top Left Vertice
    vertex_array[0].position = sf::Vector2f(center.x - (length/2),
    center.y - (height/3));

    // Top Right Vertice
    vertex_array[1].position = sf::Vector2f(center.x + (length/2),
    center.y - (height/3));

    // Bottom Vertice
    vertex_array[2].position = sf::Vector2f(center.x, center.y +
    (2 * height/3));

    // Back to Top Left Vertice
    vertex_array[3].position = sf::Vector2f(center.x - (length / 2),
    center.y - (height/3));

    // Set the colors for each vertice
    // Will create a gradient in the line
    vertex_array[0].color = sf::Color::Red;
    vertex_array[1].color = sf::Color::Blue;
    vertex_array[2].color = sf::Color::Green;
    vertex_array[3].color = sf::Color::Red;
}

// Triangle Draw Function
void Triangle::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(vertex_array, states);
}


