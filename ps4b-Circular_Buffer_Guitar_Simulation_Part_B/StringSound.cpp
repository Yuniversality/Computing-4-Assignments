// Copyright 2021 Ethan Yu

#include "CircularBuffer.h"
#include "StringSound.h"
#include <random>

#define SAMPLING_RATE 44100
#define ENERGY_DECAY_FACTOR 0.996
#define HALF 0.5

StringSound::StringSound(double frequency) {
    if (frequency <= 0) {
        throw std::runtime_error
        ("StringSound constructor: Can't have 0 or negative frequency");
    } else {
        _cb = new CircularBuffer(std::ceil(SAMPLING_RATE / frequency));
        _time = 0;
    }
}

StringSound::StringSound(std::vector<sf::Int16> init) {
    _cb = new CircularBuffer(init.size());
    unsigned int i = 0;
    while (i < init.size()) {
        (*_cb).enqueue(init[i]);
        ++i;
    }
    _time = 0;
}

// StringSound::StringSound(const StringSound &obj) {} // no copy const

StringSound::~StringSound(void) {
    delete _cb;
    _time = 0;
}

void StringSound::pluck(void) {
    if ((*_cb).isFull()) {
        (*_cb).getContainer().clear();
    }
    auto generateRandomNums = [=] () {
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<int16_t> dist(-32768, 32767);
      while (!(*_cb).isFull()) {
        (*_cb).enqueue(dist(gen));
      }
    };
    generateRandomNums();
}

void StringSound::tic(void) {
    pluck();
    sf::Int16 oldFrontVal = (*_cb).dequeue();
    sf::Int16 newVal = ENERGY_DECAY_FACTOR *
      (HALF * (oldFrontVal + (*_cb).peek()));
    (*_cb).enqueue(newVal);
    _time = _time + 1;
}

sf::Int16 StringSound::sample(void) {
    if ((*_cb).isEmpty()) {
        throw std::runtime_error
        ("StringSound sample: Can't peek at empty container");
        return 0;
    }
    return (*_cb).peek();
}

int StringSound::time(void) {
    return _time;
}
