#include <iostream>
#include <array>
#include <string>

class Animal {
protected:
    std::string name = "unk";
    unsigned int age = 0;
public:
    virtual std::string voice() = 0;
    virtual std::string get(Animal*) = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    virtual std::string voice() {
        return "Bark";
    }
    virtual std::string get(Animal* a) {
        return (voice() == a->voice() ? "Woof" : "Bark");
    }
};

class Cat : public Animal {
public:
    virtual std::string voice() {
        return "Meow";
    }
    virtual std::string get(Animal* a) {
        return (voice() == a->voice() ? "Purr" : "Meow");
    }
};

void meeting(Animal* a, Animal* b) {
    std::cout << a->get(b) << " " << b->get(a) << std::endl;
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