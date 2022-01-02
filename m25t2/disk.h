#pragma once
#define DATABSE "data.txt"
#include <fstream>
#include <vector>

std::vector<int> load();
void save(std::vector<int>&);