#include <iostream>
#include <vector>
#include <memory>
#include <string>

class CalendarItem {
public:
    virtual ~CalendarItem() = default;
    virtual void display() const = 0;
};

class Reminder : public CalendarItem {
public:
    Reminder(const std::string& text, const std::string& time) : text(text), time(time) {}

    void display() const override {
        std::cout << "Reminder: " << text << " at " << time << std::endl;
    }

private:
    std::string text;
    std::string time;
};

class Event : public CalendarItem {
public:
    Event(const std::string& title, const std::string& date) : title(title), date(date) {}

    void display() const override {
        std::cout << "Event: " << title << " on " << date << std::endl;
    }

private:
    std::string title;
    std::string date;
};

class Notification : public CalendarItem {
public:
    Notification(const std::string& message) : message(message) {}

    void display() const override {
        std::cout << "Notification: " << message << std::endl;
    }

private:
    std::string message;
};

class Calendar {
public:
    void addItem(std::shared_ptr<CalendarItem> item) {
        items.push_back(item);
    }

    void displayItems() const {
        std::cout << "Calendar Items:" << std::endl;
        for (const auto& item : items) {
            item->display();
        }
    }

private:
    std::vector<std::shared_ptr<CalendarItem>> items;
};

int main() {
    Calendar myCalendar;

    while (true) {
        std::cout << "JNCT CALENDAR SYSTEM WELCOME YOU:\n"
                  << "Menu Drive System:\n"
                  << "Choose an option:\n"
                  << "1. Add Reminder\n"
                  << "2. Add Event\n"
                  << "3. Add Notification\n"
                  << "4. Display Calendar Items\n"
                  << "5. Exit\n";

        int choice;
        std::cout << "Enter Code:\n";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string text, time;
                std::cout << "Enter reminder text: ";
                std::cin.ignore();
                std::getline(std::cin, text);
                std::cout << "Enter reminder time: ";
                std::getline(std::cin, time);

                myCalendar.addItem(std::make_shared<Reminder>(text, time));
                break;
            }
            case 2: {
                std::string title, date;
                std::cout << "Enter event title: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter event date: ";
                std::getline(std::cin, date);

                myCalendar.addItem(std::make_shared<Event>(title, date));
                break;
            }
            case 3: {
                std::string message;
                std::cout << "Enter notification message: ";
                std::cin.ignore();
                std::getline(std::cin, message);

                myCalendar.addItem(std::make_shared<Notification>(message));
                break;
            }
            case 4:
                myCalendar.displayItems();
                break;
            case 5:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}