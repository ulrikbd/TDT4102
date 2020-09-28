#include "templates.h"


template<class T>
T maximum(T x, T y) {
    return (x > y ? x: y);
}

void testMaximum() {
    int a = 1;
    int b = 2;
    std::cout << maximum(a, b) << '\n';

    double d = 2.4;
    double e = 3.2;
    std::cout << maximum(d, e) << '\n';
}

template<class T>
void shuffleVector(std::vector<T>& v) {
     int n = v.size();
     for (int i = 0; i < n - 1; ++i) {
         int j = rand() % (n) + 1;
         std::swap(v[i], v[j]);
     }
}

void testShuffle() {
    std::vector<int> a{1, 2, 3, 4, 5, 6, 7};
    shuffleVector(a); // Resultat, rekkefølgen i a er endret.
    for (const auto& p: a) std::cout << p << "\t";
    std::cout << '\n';
    std::vector<double> b{1.2, 2.2, 3.2, 4.2};
    shuffleVector(b);
    for (const auto& p: b) std::cout << p << "\t";
    std::cout << '\n';
    std::vector<std::string> c{"one", "two", "three", "four"};
    shuffleVector(c); // Resultat, rekkefølgen i c er endret.
    // for (const auto& p: c) std::cout << p << "\t";
    // std::cout << '\n';
}