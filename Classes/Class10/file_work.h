#pragma once
#include "Pair.h"
#include <string>

void createFile(const string& filename) {
    int numObjects;
    cout << "Enter the number of objects to create: ";
    cin >> numObjects;

    ofstream outFile(filename, ios::app);
    if (!outFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    for (int i = 0; i < numObjects; i++) {
        Pair pair;
        cout << "Enter the pair (format: first:second): ";
        cin >> pair;
        outFile << pair << endl;
    }

    outFile.close();
    cout << "Objects saved to file." << endl;
}

void showFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    Pair pair;
    while (inFile >> pair) {
        cout << pair << endl;
    }

    inFile.close();
}

void deleteObjects(const string& filename, const Pair& k1, const Pair& k2) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile) {
        cerr << "Error creating temporary file." << endl;
        inFile.close();
        return;
    }

    Pair pair;
    while (inFile >> pair) {
        if (pair < k1 || pair > k2) {
            tempFile << pair << endl;
        }
    }

    inFile.close();
    tempFile.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());

    cout << "Objects deleted from file." << endl;
}

void doubleObjects(const string& filename, const Pair& value) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file." << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile) {
        cerr << "Error creating temporary file." << endl;
        inFile.close();
        return;
    }

    Pair pair;
    while (inFile >> pair) {
        if (pair == value) {
            pair = pair * 2;
            tempFile << pair << endl;
        }
        else {
            tempFile << pair << endl;
        }
    }

    inFile.close();
    tempFile.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());

    cout << "Objects modified in file." << endl;
}

void addObjects(const string& filename, int K) {
    ofstream outFile("temp.txt");
    if (!outFile) {
        cerr << "Error creating temporary file." << endl;
        return;
    }

    for (int i = 0; i < K; i++) {
        Pair pair;
        cout << "Enter the pair to add at the beginning (format: first:second): ";
        cin >> pair;
        outFile << pair << endl;
    }

    ifstream inFile(filename);
    if (!inFile) {
        outFile.close();
        remove("temp.txt");
        cerr << "Error opening file." << endl;
        return;
    }

    Pair pair;
    while (inFile >> pair) {
        outFile << pair << endl;
    }

    inFile.close();
    outFile.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());

    cout << "Objects added to the beginning of the file." << endl;
}