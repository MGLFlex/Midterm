#ifndef JOURNALENTRY_H
#define JOURNALENTRY_H

#include <string>

class JournalEntry {
private:
    std::string date;
    float jumpHeight;

public:
    JournalEntry();
    JournalEntry(std::string d, float h);
    std::string getDate() const;
    float getHeight() const;
    void display() const;
};

#endif
