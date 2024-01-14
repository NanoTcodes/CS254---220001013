#include <iostream>
#include <fstream>
#include <random>

int main() {
    // Set up a random number generator engine
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 1e9);  // Change the range as needed

    // Number of random numbers to generate
    const int numRandomNumbers = 10000000;

    // Open a file for writing
    std::ofstream outputFile("input.txt");

    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    // Generate and write random integers to the file
    for (int i = 0; i < numRandomNumbers; ++i) {
        int randomNum = dis(gen);
        outputFile << randomNum;

        // Add space as separator, except for the last number
        if (i < numRandomNumbers - 1) {
            outputFile << ' ';
        }
    }

    // Close the file
    outputFile.close();

    std::cout << "Random integers have been stored in input.txt." << std::endl;

    return 0;
}
