#include<iostream>
#include "utils.h"

int main()
{   
    std::string filename;
    std::cout << "Enter a file to read: ";
    std::cin >> filename;

    std::vector<char> data = readFile(filename);
    if (!data.empty())
    {
        std::cout << "File read successfully! Size: " << data.size() << "bytes\n";

        std::string outputFile = "output.bin";
        writeFile(outputFile, data);
        std::cout << "File written to " << outputFile << std::endl;
    }
    
    int choice;
    std::cout << "File compression tool\n";
    std::cout << "1. Compress a file\n";
    std::cout << "2. Decompress a file\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your chocie: \n";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << "Compression selected\n";
        // compression fuction call here
        break;
    case 2:
        std::cout << "Decompression selected\n";
        // decompression fucntionc call here
        break;
    case 3:
        std::cout << "Exiting program\n";
        return 0;
    default:
        std::cout << "Invalid choice!";
        break;
    }
    return 0;
}
