// Copyright 2021 Ethan Yu

#ifndef _HOME_ETHAN_PS5_TRIANGLE_H_
#define _HOME_ETHAN_PS5_TRIANGLE_H_

#include <iostream>
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Triangle : public sf::Drawable {
 public:
      Triangle(double init_length, int init_height, sf::Vector2f center);
      inline sf::VertexArray get_vertex_array(void) const {
        return vertex_array;
      }
      virtual void draw(sf::RenderTarget &target,  // NOLINT
       sf::RenderStates states) const;

 private:
      double length;
      double height;
      sf::Vector2f center;
      sf::VertexArray vertex_array;
};

#endif  // _HOME_ETHAN_PS5_TRIANGLE_H_
