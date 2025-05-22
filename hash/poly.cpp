#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MOD 1000000007

unsigned long long hashFunction(const string& str, int length) {
    unsigned long long hash = 0;
    unsigned long long p = 31; // A prime number
    unsigned long long p_pow = 1; // p^0
    for (int i = 0; i < length; ++i) {
        hash = (hash + (str[i] - 'a' + 1) * p_pow) % MOD;
        p_pow = (p_pow * p) % MOD; // Update p^i
    }
    return hash;
}

vector<int> RabinKarp(const string& str, const string& pattern) {
    unsigned long long patternHash = hashFunction(pattern, pattern.size());
    unsigned long long strHash = hashFunction(str.substr(0, pattern.size()), pattern.size());
    vector<int> result;

    unsigned long long p = 31;
    unsigned long long p_pow = 1; // p^0
    for (int i = 0; i < pattern.size()-1; ++i) {
        p_pow = (p_pow * p) % MOD; // Update p^i
    }

    for (int i = 0; i <= str.size() - pattern.size(); ++i) {
        if (strHash == patternHash) {
            result.push_back(i);
        }
        if (i < str.size() - pattern.size()) {
            strHash = (strHash - (str[i] - 'a' + 1)) % MOD;
            strHash = (strHash + MOD) % MOD; // Ensure non-negative
            strHash = (strHash / p) % MOD;
            strHash = (strHash + p_pow*(str[i + pattern.size()] - 'a' + 1)) % MOD;
        }
    }
    return result;
}

int main() {
    string str, pattern;
    cin >> str >> pattern;
    vector<int> result = RabinKarp(str, pattern);
    if (result.empty()) {
        cout << "No match found" << endl;
    } else {
        cout << "Pattern found at indices: ";
        for (unsigned long long index : result) {
            cout << index << " ";
        }
        cout << endl;
    }
    return 0;
}