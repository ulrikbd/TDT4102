#include "iterator.h"



void iterateVector() {
    vector<string> v{"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectur"};
    for (const auto& p: v) {
        cout << p << '\t';
    }
    cout << '\n';
    for (auto i = v.rbegin(); i != v.rend(); ++i){
        cout << *i << '\t';
    }
    cout << '\n';
}

void replace(vector<string>& v, string old, string replacement) {
    for (vector<string>::iterator p{v.begin()}; p != v.end(); ++p) {
        if (*p == old) {
            p = v.erase(p);
            p = v.insert(p, replacement);
        }
    }
}

void iterateSet() {
    set<string> s{"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectur"};
    for (const auto& p: s) {
        cout << p << '\t';
    }
    cout << '\n';
    for (auto i = s.rbegin(); i != s.rend(); ++i) {
        cout  << *i << '\t';
    }
    cout << '\n';
}

void replaceSet(set<string>& s, string old, string replacement) {
    for (set<string>::iterator p{s.begin()}; p != s.end(); ++p) {
        if (*p == old) {
            p = s.erase(p);
            p = s.insert(p, replacement);
        }
    }
}

