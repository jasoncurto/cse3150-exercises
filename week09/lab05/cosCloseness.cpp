#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "cosCloseness.h"
using namespace std;

double cosCloseness::vectorMag(const vector<double> & dvector) {
    double mag = 0.0;
    for (int i=0 ; i < dvector.size(); i++) {
        mag += dvector[i]*dvector[i];
    }

    return sqrt(mag);
}

double cosCloseness::dotProduct(const vector<double> & dLeft, const vector<double> & dRight) {
    double sumSquares = 0.0;
    for (int i=0; i < dLeft.size(); i++) {
        sumSquares += dLeft[i] * dRight[i];
    }

    return sumSquares;
}

double cosCloseness::getAlpha(const vector<double> & dLeft, const vector<double> & dRight) {
    double alpha = 0.0;

    double dotProd = dotProduct(dLeft, dRight);
    double productOfMags = vectorMag(dLeft) * vectorMag(dRight);

    alpha = acos(dotProd/productOfMags);
    return alpha;
}

vector<VectorPair> cosCloseness::findSortedPairs(const vector<vector<double>>& input) {
    vector<VectorPair> pairs;
    int n = input.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i == j) continue;
            double angle = cosCloseness::getAlpha(input[i], input[j]);
            pairs.push_back({i, j, angle});
        }
    }
    sort(pairs.begin(), pairs.end());
    return pairs;
}