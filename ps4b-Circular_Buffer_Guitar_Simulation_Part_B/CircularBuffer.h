// Copyright 2021 Ethan Yu

#ifndef _HOME_ETHAN_PS4B_CIRCULARBUFFER_H_
#define _HOME_ETHAN_PS4B_CIRCULARBUFFER_H_

#include <stdint.h>
#include <iostream>
#include <deque>

class CircularBuffer {
 public:
     explicit CircularBuffer(int capacity);
     int size(void);
     bool isEmpty(void);
     bool isFull(void);
     void enqueue(int16_t x);
     int16_t dequeue(void);
     int16_t peek(void);
     inline std::deque<int16_t> getContainer(void) const {
         return container;
     }
     inline unsigned int getMaxContainerSize(void) const {
         return max_container_size;
     }

 private:
     std::deque<int16_t> container;
     unsigned int max_container_size;
};

#endif  // _HOME_ETHAN_PS4B_CIRCULARBUFFER_H_
