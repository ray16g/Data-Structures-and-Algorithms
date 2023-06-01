#include <cstdint>
#include <iostream>
#include <vector>

#ifndef BOARD_H
#define BOARD_H

#define POS_MASK 0xFull

const int map[][4]{
    1, 3, -1, -1,
    0, 2, 4, -1,
    1, 5, -1, -1,
    0, 4, 6, -1,
    1, 3, 5, 7,
    2, 4, 8, -1,
    3, 7, -1, -1,
    4, 6, 8, -1,
    5, 7, -1, -1
};

struct Board 
{
    friend std::ostream& operator<<(std::ostream&, const Board&);
    void move(size_t); // param = dst pos
    void swap(size_t, size_t);
    uint64_t get(size_t) const; // param = pos
    std::vector<size_t> transitionMoves();

    uint64_t state{};
    uint64_t blankPos{};
};

#endif
