#include "VertJournal.h"
#include <iostream>

int main() {
    VertJournal journal;
    journal.loadFromFile("vert_log.txt");

    int choice;
    do {
        std::cout << "\nVertical Leap Journal\n";
        std::cout << "1. Add new entry\n";
        std::cout << "2. Display all entries\n";
        std::cout << "3. Search by date\n";
        std::cout << "4. Save & Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string date;
            float height;
            std::cout << "Enter date (YYYY-MM-DD): ";
            std::getline(std::cin, date);
            std::cout << "Enter vertical leap (in inches): ";
            std::cin >> height;
            std::cin.ignore();
            journal.addEntry(JournalEntry(date, height));
            std::cout << "Your result has been recorded.\n";
        } else if (choice == 2) {
            journal.displayAll();
        } else if (choice == 3) {
            std::string date;
            std::cout << "Enter date to search: ";
            std::getline(std::cin, date);
            if (!journal.binarySearch(date)) {
                std::cout << "Entry not found.\n";
            }
        }
    } while (choice != 4);

    journal.saveToFile("vert_log.txt");
    std::cout << "Data saved.\n";
    return 0;
}