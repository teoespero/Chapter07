//  ArraySample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  Teodulfo Espero
//  BS Cloud and Systems Administration
//  BS Software Development
//  Western Governors University

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;



int main() {
	int myarray[] = { 1,2,3,4,5,6,7,8,9,0 };

	for (int ctr : myarray)
		cout << ctr << endl;
}