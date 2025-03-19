#include "utils.h"
#include<fstream>
#include<iostream>

// read file contents into a charvector
std::vector<char> readFile(const std::string& filename)
{
    std::ifstream file(filename, std::ios::binary);
    std::vector<char> data;

    if(!file)
    {
        std::cerr << "Error: unable to open file " << filename << std::endl;
        return data;
    }

    // read file into vector
    file.seekg(0, std::ios::end);
    size_t filesize = file.tellg();
    file.seekg(0, std::ios::beg);

    data.resize(filesize);
    file.read(data.data(), filesize);
    file.close();
    return data;

}

// write data to a file

void writeFile(const std::string& filename, const std::vector<char>& data)
{
    std::ofstream file(filename, std::ios::binary);

    if (!file)
    {
        std::cerr << "Error: Unable to write to file " << filename << std::endl;
        return;
    }
    file.write(data.data(), data.size());
    file.close();
}