#include <iostream>
#include <array>
#include <string>

class Animal {
protected:
    std::string name = "unk";
    unsigned int age = 0;
    int id = 0;
public:
    virtual int get() = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    Dog() {
        id = 0;
    }
    virtual int get() {
        return id;
    }
};

class Cat : public Animal {
public:
    Cat() {
        id = 1;
    }
    virtual int get() {
        return id;
    }
};

void meeting(Animal* a, Animal* b) {
    std::array<std::string, 4> meetings{ "Woof Woof", "Bark Meow", "Meow Bark", "Purr Purr" };
    std::size_t index = (a->get() << 1) | b->get();
    std::cout << meetings[index] << std::endl;
}

int main()
{
    Animal* d = new Dog();
    Animal* c = new Cat();

    meeting(d, d);
    meeting(d, c);
    meeting(c, d);
    meeting(c, c);

    delete d;
    delete c;
}