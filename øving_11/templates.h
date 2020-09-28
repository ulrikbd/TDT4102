#pragma once
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <string>


template<class T>
T maximum(T x, T y);

void testMaximum();

template<class T>
void shuffleVector(std::vector<T>& v);

void testShuffle();