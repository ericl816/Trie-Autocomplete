#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "autocomplete.h"
#include <bits/stdc++.h>
using namespace std;

int main () {
    trieNode* root=getnode();
    ifstream inFile;
    cout << "Enter file to read from: ";
    string file = "";
    cin >> file;
    file = "/Users/ericliu/Downloads/autocomplete/dictionary.txt";
    inFile.open(file);
    if (!inFile) {
        cout << "Failed to read file" << endl;
        exit(1);
    }
    cout << "Inserting keys from dictionary...\n";
    string keys = "";
    while (inFile >> keys) {
        // cout << keys << " ";
        insert(root, keys);
    }
    int n;
    cout << "Enter the number of queries: ";
    cin >> n;
    while (n--) {
        string pre;
        cout << "Enter the prefix to be looked for: ";
        cin >> pre;
        int comp = printSuggestions(root, pre);
        if (comp == -1) cout << "No other strings found with this prefix\n";
        else if (comp == 0) cout << "No string found with this prefix\n";
    }
}