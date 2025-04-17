#include "includes/HandEvaluator.hpp"
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

bool checkFlush(const std::vector<Card>& cards) {
    if (cards.size() < 5) return false;
    std::map<int, int> suitCount;
    for (const auto& card : cards)
        suitCount[card.suit]++;
    for (const auto& entry : suitCount)
        if (entry.second >= 5)
            return true;
    return false;
}

int findDominantSuit(const std::vector<Card>& cards) {
    if (cards.size() < 5) return 0;
    std::map<int, int> suitCount;
    for (const auto& card : cards)
        suitCount[card.suit]++;
    int dominantSuit = -1, maxCount = 0;
    for (const auto& entry : suitCount) {
        if (entry.second >= 5 && entry.second > maxCount) {
            maxCount = entry.second;
            dominantSuit = entry.first;
        }
    }
    return dominantSuit;
}

bool checkStraight(const std::vector<Card>& cards) {
    if (cards.size() < 5) return false;
    std::set<int> valueSet;
    for (const auto& card : cards)
        valueSet.insert(card.value);
    std::vector<int> values(valueSet.begin(), valueSet.end());
    std::sort(values.begin(), values.end(), std::greater<int>());
    if (valueSet.count(14) && valueSet.count(2) && valueSet.count(3) && valueSet.count(4) && valueSet.count(5))
        return true;
    for (size_t i = 0; i <= values.size() - 5; ++i) {
        bool straight = true;
        for (int j = 0; j < 4; ++j) {
            if (values[i + j] != values[i + j + 1] + 1) {
                straight = false;
                break;
            }
        }
        if (straight)
            return true;
    }
    return false;
}

std::vector<Card> getCardsOfSuit(const std::vector<Card>& cards, int suit) {
    std::vector<Card> result;
    for (const auto& card : cards)
        if (card.suit == suit)
            result.push_back(card);
    std::sort(result.begin(), result.end(), [](const Card& a, const Card& b) {
        return a.value > b.value;
    });
    return result;
}
