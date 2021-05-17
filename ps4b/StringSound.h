// Copyright 2021 Ethan Yu

#ifndef _HOME_ETHAN_PS4B_STRINGSOUND_H_
#define _HOME_ETHAN_PS4B_STRINGSOUND_H_

#include "CircularBuffer.h"
#include <math.h>
#include <vector>
#include <SFML/Audio.hpp>

class StringSound {
 public:
    explicit StringSound(double frequency);
    explicit StringSound(std::vector<sf::Int16> init);
    // StringSound (const StringSound &obj) {}; // no copy const
    ~StringSound(void);
    void pluck(void);
    void tic(void);
    sf::Int16 sample(void);
    int time(void);
 private:
    CircularBuffer* _cb;
    int _time;
};

#endif  // _HOME_ETHAN_PS4B_STRINGSOUND_H_


