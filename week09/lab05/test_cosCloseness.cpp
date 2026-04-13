#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./include/doctest.h"
#include "cosCloseness.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

TEST_CASE("Import File and Delegate Processing") {
    vector<vector<double>> fileData;
    ifstream file("vectors.txt");

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line); //helps parsing each line
        vector<double> inputVector;
        double value;
        while (ss >> value) inputVector.push_back(value);
        fileData.push_back(inputVector);
    }
    file.close();

    vector<VectorPair> results = cosCloseness::findSortedPairs(fileData);

    CAPTURE(results.size());
    CHECK(results.size() > 0);

    cout << "\n ++++ Pairs Sorted by Closeness ++++ \n";
    for (const auto& p : results) {
        cout << "Vectors (" << p.indexA << ", " << p.indexB << ") Angle: " << p.distance << endl;
    }
}