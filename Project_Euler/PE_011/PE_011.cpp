// ProjectEuler011.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <string>
#include "math.h"

int readBlock(int grid[20][20]);	// read the block of text.
long findMax(int ar[20][20]);		// finds the max vertically, horizontally, or diagonally.


int main()
{
	int block[20][20];				// Establish the 20 by 20 grid.
	readBlock(block);				// Array name used as pointer. Pass through file read.
	long num = findMax(block);
	std::cout << "The solution to problem #11 is: " << num << "\n" << "End";
	std::cin.get();
}


int readBlock(int grid[20][20]){
	std::string buf[20][20];
	std::ifstream myFile("nums.txt");
	if (myFile.is_open()){
		for (int i = 0; i < 20; i++){
			for (int j = 0; j < 20; j++){
				myFile >> buf[i][j];

			}
		}
		myFile.close();
		for (int i = 0; i < 20; i++){
			for (int j = 0; j < 20; j++){
				grid[i][j] = stoi(buf[i][j]);
				// std::cout << grid[i][j] << "\n";
			}
		}
	}
	else{
		std::cout << "Failed to open File" << "\n";
	}
	return grid[20][20];
}

long findMax(int ar[20][20]){
	long product = 0;
	long max = 0;
	for (int i = 0; i < 20; i++){
		for (int j = 0; j < 17; j++){
			product = ar[i][j] * ar[i][j + 1] * ar[i][j + 2] * ar[i][j + 3];
			if (product >= max){
				max = product;
			}
		}
	}
	for (int i = 0; i < 17; i++){
		for (int j = 0; j < 20; j++){
			product = ar[i][j] * ar[i + 1][j] * ar[i + 2][j] * ar[i + 3][j];
			if (product >= max){
				max = product;
			}
		}
	}
	for (int i = 0; i <= 16; i++){
		for (int j = 0; j <= 16; j++){
			product = ar[i][j] * ar[i + 1][j + 1] * ar[i + 2][j + 2] * ar[i + 3][j + 3];
			if (product >= max){
				max = product;
			}
		}
	}
	for (int i = 0; i <= 16; i++){
		for (int j = 19; j >= 3; j--){
			product = ar[i][j] * ar[i + 1][j - 1] * ar[i + 2][j - 2] * ar[i + 3][j - 3];
			if (product >= max){
				max = product;
			}
		}
	}
	return max;
}
