#include <iostream>
#include <fstream>
#include <random>

int main() {
    // Set up a random number generator engine
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 1e2);  // Change the range as needed

    // Number of random numbers to generate
    const int numRandomNumbers = 10000;

    // Open a file for writing
    std::ofstream weights("weights.txt");

    if (!weights.is_open()) {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    for (int i = 0; i < numRandomNumbers; ++i) {
        int randomNum = dis(gen);
        weights << randomNum;

        // Add space as separator, except for the last number
        if (i < numRandomNumbers - 1) {
            weights << ' ';
        }
    }

    // Close the file
    weights.close();

    std::cout << "Random integers have been stored in weights.txt." << std::endl;

    return 0;
}
