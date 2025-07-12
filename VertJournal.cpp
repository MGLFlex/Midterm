#include "VertJournal.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

VertJournal::VertJournal() {
    size = 0;
    capacity = 10;
    entries = new JournalEntry[capacity];
}

VertJournal::~VertJournal() {
    delete[] entries;
}

void VertJournal::resize() {
    capacity *= 2;
    JournalEntry* newEntries = new JournalEntry[capacity];
    for (int i = 0; i < size; ++i) {
        newEntries[i] = entries[i];
    }
    delete[] entries;
    entries = newEntries;
}

void VertJournal::addEntry(const JournalEntry& e) {
    if (size == capacity) resize();
    entries[size++] = e;
    sortEntries();
}

void VertJournal::displayAll() const {
    for (int i = 0; i < size; ++i) {
        entries[i].display();
    }
}

bool VertJournal::binarySearch(const std::string& target) const {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (entries[mid].getDate() == target) {
            entries[mid].display();
            return true;
        } else if (entries[mid].getDate() < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

void VertJournal::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    for (int i = 0; i < size; ++i) {
        out << entries[i].getDate() << "," << entries[i].getHeight() << "\n";
    }
    out.close();
}

void VertJournal::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    std::string line;
    while (getline(in, line)) {
        std::stringstream ss(line);
        std::string date, heightStr;
        getline(ss, date, ',');
        getline(ss, heightStr);
        float height = std::stof(heightStr);
        addEntry(JournalEntry(date, height));
    }
    in.close();
}

void VertJournal::sortEntries() {
    std::sort(entries, entries + size, [](JournalEntry a, JournalEntry b) {
        return a.getDate() < b.getDate();
    });
}