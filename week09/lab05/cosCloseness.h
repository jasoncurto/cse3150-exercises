#ifndef _cosCloseness_H
#define _cosCloseness_H

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct VectorPair {
    int indexA;
    int indexB;
    double distance;

    bool operator<(const VectorPair& other) const {
        return distance < other.distance;
    }
};

class cosCloseness {

public:
    static double vectorMag(const vector<double> & dvector);
    static double dotProduct(const vector<double> & dLeft, const vector<double> & dRight);
    static double getAlpha(const vector<double> & dLeft, const vector<double> & dRight);
    static vector<VectorPair> findSortedPairs(const vector<vector<double>>& input);
};

#endif
