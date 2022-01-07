#include <iostream>
#include <vector>
#include <string>

class Tree {
    Tree* parent = nullptr;
    std::vector<Tree*> childs;
    std::string elf = "None";
public:
    Tree(Tree* ptr) : parent(ptr) {};
    ~Tree() {
        for (auto ch : childs) {
            delete ch;
        }
    }

    void addBranchs(int c) {
        for (int i = 0; i < c; ++i) {
            childs.push_back(new Tree(this));
        }
    }

    Tree* childAt(int index) {
        return childs[index];
    }

    std::string getElf() {
        return elf;
    }

    void printChilds() {
        if (childs.empty())
            return;
        for (auto ch : childs) {
            if (ch->getElf() != "None")
                std::cout << ch->getElf() << std::endl;
        }
    }

    void printNeighbor() {
        if (parent == nullptr)
            return;
        parent->printChilds();
    }

    bool empty() {
        return childs.empty();
    }

    int countChild() {
        return (int)childs.size();
    }

    void fill() {
        std::cin >> elf;
    }
};

int main()
{
    std::string buf;
    std::vector<Tree*> forest(5);

    for (int f = 0, fe = forest.size(); f != fe; ++f) {
        forest[f] = new Tree(nullptr);
        Tree* tree = forest[f];
        tree->addBranchs(std::rand() % 2 + 2);
        std::cout << "Enter elfs for " << tree->countChild() << " big branch" << std::endl;
        for (int i = 0, ie = tree->countChild(); i != ie; ++i) {
            Tree* it = tree->childAt(i);
            std::cout << "big brach #" << i << ": ";
            it->fill();
            it->addBranchs(std::rand() % 2 + 2);
            std::cout << "Enter elfs for " << it->countChild() << " middle branch" << std::endl;
            for (int j = 0, je = it->countChild(); j != je; ++j) {
                Tree* jt = it->childAt(j);
                std::cout << "middle brach #" << j << ": ";
                jt->fill();
            }
        }
    }

    std::cout << "Generate finished. Enter name for search:" << std::endl;
    std::cin >> buf;
    std::cout << "Searching..." << std::endl;

    bool found = false;
    for (int f = 0, fe = forest.size(); f != fe; ++f) {
        Tree* tree = forest[f];
        for (int i = 0, ie = tree->countChild(); i != ie && !found; ++i) {
            Tree* it = tree->childAt(i);
            if (buf == it->getElf() && it->getElf() != "None")
            {
                std::cout << "Founded:" << std::endl;
                it->printNeighbor();
                found = true;
            }
            for (int j = 0, je = it->countChild(); j != je && !found; ++j) {
                Tree* jt = it->childAt(j);
                if (buf == jt->getElf() && jt->getElf() != "None")
                {
                    std::cout << "Founded:" << std::endl;
                    jt->printNeighbor();
                    found = true;
                }
            }
        }
    }

    if (!found)
        std::cout << "Elf not found!" << std::endl;

    for (auto tree : forest) {
        delete tree;
    }
}