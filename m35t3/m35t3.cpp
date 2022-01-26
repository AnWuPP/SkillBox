#include <iostream>
#include <string>
#include <filesystem>

auto recursiveGetFileNamesByExtension = [](std::filesystem::path path, const std::string extension) {
    for (auto& file : std::filesystem::recursive_directory_iterator(path)) {
        if (file.path().extension().compare(extension) == 0)
            std::cout << file.path() << std::endl;
    }
};

int main()
{
    std::filesystem::path p{ "D:\\Projects\\SkillBox" };
    recursiveGetFileNamesByExtension(p, ".cpp");
}