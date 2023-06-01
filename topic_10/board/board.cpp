#include "board.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const Board& b)
{
    
    for (size_t i{0}; i < 3; ++i)
    {
        out << "----------------\n";
        out << "| ";
        for (size_t j{0}; j < 3; ++j)
        {
            out << b.get(i * 3 + j) << " | ";           
        }
        out << std::endl;
    }
    out << "----------------\n";
    
    return out;
}

void Board::move(size_t pos)
{
    swap(pos, blankPos);
    blankPos = pos;
}

std::vector<size_t> Board::transitionMoves()
{
    std::vector<size_t> moves;
    for (size_t i = 0; i < 4 && map[blankPos][i] >= 0; ++i)
    {
        moves.push_back(map[blankPos][i]);
    }

    return moves;
    
}

void Board::swap(size_t pos1, size_t pos2)
{
    uint64_t tmp{get(pos1)};
    pos1 <<= 2;

    state &= ~(POS_MASK << pos1);
    state |= (get(pos2) << pos1);

    pos2 <<= 2;
    state &= ~(POS_MASK << pos2);
    state |= (tmp << pos2);
}

uint64_t Board::get(size_t pos) const
{
    pos <<= 2;
    return (((POS_MASK << pos) & state) >> pos); 
} 

