/* Copyright 2015 Fred Martin, Y. 
  Rykalova, 2020
  Ethan Yu, 2021
*/

#include "CircularBuffer.h"
#include "StringSound.h"

#include <limits.h>

#include <string>
#include <exception>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
// #include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

// #include <math.h>


// #include <iostream>

// #include <stdexcept>
// #include <vector>
// #include <unordered_map>

#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100

std::vector<sf::Int16> makeSamples(StringSound& gs) {
  std::vector<sf::Int16> samples;

  gs.pluck();
  int duration = 8;  // seconds
  int i;
  for (i = 0; i < SAMPLES_PER_SEC * duration; i++) {
    gs.tic();
    samples.push_back(gs.sample());
  }
  return samples;
}

int main() {
  sf::RenderWindow window(sf::VideoMode(300, 200),
  "SFML Plucked String Sound Lite");
  sf::Event event;
  std::vector<sf::Int16> samples;
  double freq = CONCERT_A;
  StringSound gs1(freq);
  sf::Sound sound1;
  sf::SoundBuffer buf1;
  samples = makeSamples(gs1);
  if (!buf1.loadFromSamples(&samples[0], samples.size(), 2, SAMPLES_PER_SEC))
      throw std::runtime_error("sf::SoundBuffer: failed to load from samples.");
  sound1.setBuffer(buf1);

  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;

      case sf::Event::KeyPressed:
        switch (event.key.code) {
        case sf::Keyboard::Q:
        case sf::Keyboard::Num2:
        case sf::Keyboard::W:
        case sf::Keyboard::E:
        case sf::Keyboard::Num4:
        case sf::Keyboard::R:
        case sf::Keyboard::Num5:
        case sf::Keyboard::T:
        case sf::Keyboard::Y:
        case sf::Keyboard::Num7:
        case sf::Keyboard::U:
        case sf::Keyboard::Num8:
        case sf::Keyboard::I:
        case sf::Keyboard::Num9:
        case sf::Keyboard::O:
        case sf::Keyboard::P:
        case sf::Keyboard::Hyphen:
        case sf::Keyboard::LBracket:
        case sf::Keyboard::Equal:
        case sf::Keyboard::Z:
        case sf::Keyboard::X:
        case sf::Keyboard::D:
        case sf::Keyboard::C:
        case sf::Keyboard::F:
        case sf::Keyboard::V:
        case sf::Keyboard::G:
        case sf::Keyboard::B:
        case sf::Keyboard::N:
        case sf::Keyboard::J:
        case sf::Keyboard::M:
        case sf::Keyboard::K:
        case sf::Keyboard::Comma:
        case sf::Keyboard::Period:
        case sf::Keyboard::Semicolon:
        case sf::Keyboard::Slash:
        case sf::Keyboard::Quote:
        case sf::Keyboard::Space:
          sound1.play();
          break;
        default:
          break;
        }
      default:
        break;
      }
      window.clear();
      window.display();
    }
  }
  return 0;
}
