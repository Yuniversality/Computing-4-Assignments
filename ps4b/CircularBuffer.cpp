// Copyright 2021 Ethan Yu

#include "CircularBuffer.h"
#include <stdexcept>

const int ERROR_VAL = 1337;

// Value constructor for CircularBuffer
CircularBuffer::CircularBuffer(int capacity) {
        auto checkBadInput = [=]() {
        if (capacity > 0) {
            max_container_size = capacity;
        } else {
            throw std::invalid_argument
            ("CircularBuffer constructor: capacity must be greater than zero.");
        }
    };

    checkBadInput();
}

// Returns the current size of the container
int CircularBuffer::size(void) {
    return container.size();
}

// Returns status reflecting if container is empty (true) or not (false)
bool CircularBuffer::isEmpty(void) {
    return container.empty();
}

// Returns status reflecting if container is full (true) or not (false)
bool CircularBuffer::isFull(void) {
    return (container.size() == max_container_size);
}

// Adds value to back of container (unless it's full, then it throws an error)
void CircularBuffer::enqueue(int16_t x) {
    if (!isFull()) {
        container.push_back(x);
    } else {
        throw std::runtime_error("Enqueue: can't enqueue to a full ring.");
    }
}

// Returns and removes the first element of container
// (or if empty, throws an error)
int16_t CircularBuffer::dequeue(void) {
    int16_t frontVal = 0;
    if (!isEmpty()) {
        frontVal = container.front();
        container.pop_front();
    } else {
        throw std::runtime_error("Dequeue: can't dequeue from an empty ring.");
        frontVal = ERROR_VAL;
    }

    return frontVal;
}

// Returns the first element of the container
// (or if container is empty, throws an error)
int16_t CircularBuffer::peek(void) {
    if (!isEmpty()) {
        return container.front();
    } else {
        throw std::runtime_error("Peek: can't peek at an empty ring.");
        return ERROR_VAL;
    }
}

