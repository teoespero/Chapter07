//  ArraySample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  Teodulfo Espero
//  BS Cloud and Systems Administration
//  BS Software Development
//  Western Governors University

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void getdata(string &fname, double &grade){
	cout << "name.....";
	do {
		getline(cin, fname);
	} while (fname.length() == 0);

	cout << "grade.....";
	do {
		cin >> grade;
	} while (grade < 1);
}

void writetofile(ofstream &outfile, string fname, double grade) {
	outfile << fname << "," << grade << endl;
}

void keepgoing(char &keepentering) {
	do {
		cin >> keepentering;
	} while (!(keepentering == 'y' || keepentering == 'n'));
}

bool runagain(char keepentering) {
	if (keepentering != 'y') {
		return false;
	}
}

void printdata(string name1[], double grades[], int ctr) {
	cout << "Fullname" << "\t\t" << "Grade" << endl;
	cout << "-------------------------------------" << endl;
	for (int ptr = 0; ptr < ctr; ptr++)
		cout << name1[ptr] << "\t\t" << grades[ptr] << endl;
}

void readdata(ifstream &infile, string &studentrec) {
	string
		name1[5],
		name2[5],
		fname,
		tempstring;
	int 		
		ctr = 0;

	double
		grades[5];

	while (getline(infile, studentrec)) {
		stringstream ss(studentrec);
		getline(ss, fname, ',');
		getline(ss, tempstring, ',');
		name1[ctr] = fname;
		grades[ctr] = stod(tempstring);
		ctr++;
	}

	printdata(name1, grades, ctr);
}


int main() {
	ifstream infile;
	ofstream outfile;

	int ctr = 0; 

	string
		studentrec = "",
		fname = "";

	double
		grade = 0.00;

	bool again = true;
	char keepentering = 'y';

	outfile.open("mydata.txt");
	if (outfile.fail()) {
		cout << "\t*****File i/o error." << endl;
		exit(1);
	}
	else {
		do {
			do {
				
				getdata(fname, grade);
				writetofile(outfile, fname, grade);
				cout << "enter another [y/n]?.....";
				keepgoing(keepentering);
			} while (keepentering == 'y');
			again = runagain(keepentering);
		} while (again);

		cout << endl;
		grade = 0.00;
		fname = "";
		outfile.close();
	}

	infile.open("mydata.txt");
	if (infile.fail()) {
		cout << "\t*****File i/o error." << endl;
		exit(1);
	}
	else {
		readdata(infile, studentrec);
	}

	infile.close();


}