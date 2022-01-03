#include <iostream>
#include <string>
#include <vector>

struct Contact {
    std::string name = "Unknown";
    std::string phone = "+70000000000";

    bool verify() {
        bool fail = phone.length() != 12 || phone[0] != '+' || phone[1] != '7';
        if (!fail) {
            for (int i = 2; i < 12 && !fail; ++i) {
                fail = phone[i] < '0' || phone[i] > '9';
            }
        }
        return !fail;
    }
};

class Phone {
    std::vector<Contact> contacts;
public:
    void add(std::string phone, std::string name) {
        Contact cnt{ name, phone };
        if (!cnt.verify()) {
            std::cout << "Error phone number" << std::endl;
            return;
        }
        contacts.push_back(cnt);
        std::cout << "Added contact" << std::endl;
    }
    void call(std::string p) {
        if (contacts.empty()) {
            std::cout << "Contact list empty" << std::endl;
            return;
        }

        bool found = false;
        for (auto& cnt : contacts) {
            if (cnt.name == p || cnt.phone == p) {
                std::cout << "Called " << cnt.name << std::endl;
                found = true;
            }
        }
        if (!found)
            std::cout << "Contact not found" << std::endl;
    }
    void sms(std::string p, std::string msg) {
        if (contacts.empty()) {
            std::cout << "Contact list empty" << std::endl;
            return;
        }

        bool found = false;
        for (auto& cnt : contacts) {
            if (cnt.name == p || cnt.phone == p) {
                std::cout << "Sms to " << cnt.name << ": " << msg.substr(1) << std::endl;
                found = true;
            }
        }
        if (!found)
            std::cout << "Contact not found" << std::endl;
    }
};

int main()
{
    Phone phone;
    std::string cmd, p1, p2;

    std::cout << "Enter command: add [phone] [name], call [phone or name], sms [phone or name] [message]" << std::endl;
    while (cmd != "exit") {
        std::cin >> cmd;
        if (cmd == "add") {
            std::cin >> p1 >> p2;
            phone.add(p1, p2);
        }
        else if (cmd == "call") {
            std::cin >> p1;
            phone.call(p1);
        }
        else if (cmd == "sms") {
            std::cin >> p1;
            std::getline(std::cin, p2);
            phone.sms(p1, p2);
        }
    }
}