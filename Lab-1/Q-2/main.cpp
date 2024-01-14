#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream weightsFile("weights.txt");
    vector<int> weights;
    if (!weightsFile.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }
    int x;
    while (weightsFile >> x) weights.push_back(x);
    weightsFile.close();

    ifstream valuesFile("values.txt");
    vector<int> values;
    if (!valuesFile.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }
    int y;
    while (valuesFile >> y) values.push_back(y);
    valuesFile.close();

    int n = weights.size();
    int W = 500;
    vector<vector<int>> dp(n+2, vector<int>(W+2, 0));
    for(int i = 1; i <= n; ++i) {
        for(int w = 1; w <= W; ++w) {
            if(weights[w-1] <= w)
                dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], dp[i-1][w]);
            else 
                dp[i][w] = dp[i-1][w];
        }
    }

    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }
    outputFile << dp[n][W] << endl;
    outputFile.close();
    cout << "Data has been written to output.txt." << endl;

    return 0;
}