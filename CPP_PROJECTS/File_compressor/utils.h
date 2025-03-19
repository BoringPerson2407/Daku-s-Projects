#ifndef UTILS_H
#define UTILS_H

#include<string>
#include<vector>

//fucntion to read file contents

std::vector<char> readFile(const std::string& filename);

// function to write data to a file
void writeFile(const std::string& filename, const std::vector<char>& data);

#endif