// Copyright(c) 2022 Evgeny Vovk All rights reserved.
//
// Created by : Evgeny Vovk
// Created on : January 2023
// ICS3U-Unit6-04.cpp File, learning functions with parameters in C++.

#include <array>
#include <iostream>
#include <random>

template <int rows, int cols>
int averageOfNumbers(int (&passedIn2DList)[rows][cols],
                     int rowElement, int columnElement) {
    // this function gets the average

    int total = 0;

    for (size_t rowElement = 0; rowElement < rows; ++rowElement) {
        for (size_t columnElement = 0; columnElement < cols; ++columnElement)
            total += passedIn2DList[rowElement][columnElement];
    }
    total = total / (rowElement * columnElement);

    return total;
}

int main() {
    // this function generates the random numbers

    int aSingleRandomNumber = 0;
    int average = 0;
    const int rows = 3;
    const int columns = 4;
    int a2DArray[rows][columns];
    int indent = 1;

    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(1, 50);

    std::cout << "Rows:" << rows << "\n";
    std::cout << "Columns:" << columns << "\n";

    for (int rowElement = 0; rowElement < rows; rowElement++) {
        for (int columnElement = 0; columnElement < columns; columnElement++) {
            aSingleRandomNumber = idist(rgen);
            a2DArray[rowElement][columnElement] = aSingleRandomNumber;
            if (columnElement % columns == 0) {
                indent += 1;
                if (indent > 0) {
                    std::cout << "\n";
                }
            }
            std::cout << aSingleRandomNumber << " ";
        }
    }

    // calls function
    average = averageOfNumbers(a2DArray, rows, columns);
    std::cout << "\nThe average of all numbers is: " << average;

    std::cout << "\nDone.";
}