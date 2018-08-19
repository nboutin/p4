#pragma once

#include <array>
#include <memory>
#include <optional>

#include "cell.h"
#include "token.h"

namespace p4
{
class Board
{
public:
    static const auto N_COLUMN = 7;    // X
    static const auto N_ROW    = 6;    // Y

    typedef std::array<std::array<Cell, N_ROW>, N_COLUMN> board_t;

//    Board() = default;
//    Board(const Board& b);

    const board_t& get_board() const { return board; }

    bool play(uint8_t x, std::unique_ptr<p4::Token> token);
    void unplay(uint8_t x);

private:
    std::optional<uint8_t> find_free_row(uint8_t x);

    //   0 1 2 3 4 5 6
    // 0 - - - - - - -
    // 1 - - - - - - -
    // 2 - - - - - - -
    // 3 - - - - - - -
    // 4 - - - - - - -
    // 5 - - - - - - -
    board_t board;
};
}
