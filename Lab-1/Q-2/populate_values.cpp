#include <iostream>
#include <fstream>
#include <random>

int main() {
    // Set up a random number generator engine
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 1e5);  // Change the range as needed

    // Number of random numbers to generate
    const int numRandomNumbers = 10000;

    // Open a file for writing
    std::ofstream values("values.txt");

    if (!values.is_open()) {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    for (int i = 0; i < numRandomNumbers; ++i) {
        int randomNum = dis(gen);
        values << randomNum;

        // Add space as separator, except for the last number
        if (i < numRandomNumbers - 1) {
            values << ' ';
        }
    }

    // Close the file
    values.close();

    std::cout << "Random integers have been stored in values.txt." << std::endl;

    return 0;
}
