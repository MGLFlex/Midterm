#ifndef VERTJOURNAL_H
#define VERTJOURNAL_H

#include "JournalEntry.h"

class VertJournal {
private:
    JournalEntry* entries;
    int size;
    int capacity;
    void resize();
    void sortEntries();

public:
    VertJournal();
    ~VertJournal();
    void addEntry(const JournalEntry& e);
    void displayAll() const;
    bool binarySearch(const std::string& date) const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif