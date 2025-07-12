#include "JournalEntry.h"
#include <iostream>

JournalEntry::JournalEntry() {
    date = "";
    jumpHeight = 0.0;
}

JournalEntry::JournalEntry(std::string d, float h) {
    date = d;
    jumpHeight = h;
}

std::string JournalEntry::getDate() const {
    return date;
}

float JournalEntry::getHeight() const {
    return jumpHeight;
}

void JournalEntry::display() const {
    std::cout << "Date: " << date << ", Vertical Leap: " << jumpHeight << " inches" << std::endl;
}