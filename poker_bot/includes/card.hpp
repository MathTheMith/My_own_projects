#ifndef CARD_HPP
#define CARD_HPP

#include <string>

class Card {
public:
    int value;  // 2-14 (14 = As)
    int suit;   // 0=♠, 1=♥, 2=♦, 3=♣

    Card(int v = 2, int s = 0) : value(v), suit(s) {}

    std::string to_string() const {
        std::string values[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
        std::string suits[] = {"♠", "♥", "♦", "♣"};
        
        return values[value - 2] + suits[suit];
    }
};

#endif