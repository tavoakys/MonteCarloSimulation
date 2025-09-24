#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <chrono>

#include "matplotlibcpp.h"

using namespace std;

namespace plt = matplotlibcpp;

int main(int argc, char** argv) {

    auto start = chrono::high_resolution_clock::now();

    double S0 = 100; 
    double mu = 0.08;
    double sigma = 0.2;
    double T = 1;
    int steps = 252;
    int paths = 10000;
    unsigned long long seed = random_device{}();
    int maxPaths = 10000;

    if (argc >= 2) {
        S0 = atof(argv[1]);
    }
    if (argc >= 3) {
        mu = atof(argv[2]);
    }
    if (argc >= 4) {
        sigma = atof(argv[3]);
    }
    if (argc >= 5) {
        T = atof(argv[4]);
    }
    if (argc >= 6) {
        steps = atoi(argv[5]);
    }
    if (argc >= 7) {
        paths = atoi(argv[6]);
    }
    if (argc >= 8) {
        seed = (unsigned long long)atoll(argv[7]);
    }

    if (steps < 1) {
        steps = 1;
    }
    if (paths < 1) {
        paths = 1;
    }
    if (sigma < 0) {
        sigma = 0;
    }
    if (T <= 0) {
        T = 1e-6;
    }
    if (S0 <= 0) {
        S0 = 1e-6;
    }

    double dt = T / (double)steps;

    mt19937_64 rng(seed);
    normal_distribution<double> nd(0, 1);

    vector<double> t(steps + 1);
    for (int i = 0; i <= steps; i++) {
        t[i] = i * dt;
    }

    int plotPaths = maxPaths;
    if (plotPaths > paths) plotPaths = paths;

    vector<vector<double>> simulatePaths(plotPaths, vector<double>(steps + 1, 0));

    vector<double> finalPrices(paths, 0);

    for (int i = 0; i < paths; i++) {
        double S = S0;
        if (i < plotPaths) simulatePaths[i][0] = S;

        for (int j = 1; j <= steps; j++) {
            double z = nd(rng);

            S = S * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);
            if (i < plotPaths) simulatePaths[i][j] = S;
        }

        finalPrices[i] = S;
    }

    double avg = 0;
    for (int i = 0; i < paths; i++) {
        avg += finalPrices[i];
    }
    avg /= (double)paths;

    double var = 0;
    for (int i = 0; i < paths; i++) {
        double diff = finalPrices[i] - avg;
        var += diff * diff;
    }
    if (paths > 1) {
        var /= (double)(paths - 1);
    }

    cout << "=== Monte Carlo Simulation ===\n";
    cout << "S0=" << S0 << "  mu=" << mu << "  sigma=" << sigma << "  T=" << T << "  steps=" << steps << "  paths=" << paths << "  seed=" << seed << "\n";
    cout << "Average Final Price=" << avg << "   Variance of Final Price=" << var << "\n";

    plt::figure_size(960, 560);
    for (int i = 0; i < plotPaths; i++) {
        plt::plot(t, simulatePaths[i]);
    }
    plt::title("Monte Carlo Simulation Paths");
    plt::xlabel("Time (years)");
    plt::ylabel("Price");
    plt::grid(true);
    plt::tight_layout();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> timeElapsed = end - start;

    cout << "\nTime elapsed: " << timeElapsed.count() << " ms\n";

    plt::show();

    plt::figure_size(900, 520);
    int bins = 50;
    plt::hist(finalPrices, bins);
    plt::title("Final Price Distribution");
    plt::xlabel("Final Price");
    plt::ylabel("Count");
    plt::grid(true);
    plt::tight_layout();
    plt::show();

    return 0;
}
