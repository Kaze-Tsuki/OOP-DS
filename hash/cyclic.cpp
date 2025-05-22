#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unsigned int hashFunction(const string& str, int mod) {
    unsigned int hash = 0;
    for (char c : str) {
        hash = (hash << 5) | (hash >> 27); // Left shift and wrap around
        hash ^= c; // XOR with the character
    }
    return hash;
}

int main() {
    int n;
    cin >> n;
    unordered_map<unsigned int, string> hashTable;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        unsigned int hashValue = hashFunction(str, n);
        hashTable[hashValue] = str;
    }
    for (const auto& pair : hashTable) {
        cout << "Hash: " << pair.first << ", String: " << pair.second << endl;
    }
    return 0;
}