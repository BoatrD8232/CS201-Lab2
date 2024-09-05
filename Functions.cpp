#include "Functions.h"

char displayMenuAndGetSelection() {
	char input = '1';
	while (input < 'a' || input > 'f') {
		cout << "a.Convert from binary to decimal" << endl;
		cout << "b.Convert from binary to another base" << endl;
		cout << "c.Convert a decimal number into binary" << endl;
		cout << "d.Convert another base value into binary" << endl;
		cout << "e.Convert from any base to any base" << endl;
		cout << "f.Exit" << endl;
		cin >> input;
		if (input < 'a' || input > 'f')
			cout << "Invalid input." << endl;
	}
	return input;
}

int binToDec() {
	string str;
	int deci = 0;
	cout << "Enter the binary number: ";
	cin >> str;
	if (str.find_first_not_of("01") == string::npos) {
		for (int i = str.size() - 1; i >= 0; i--) {
			deci += (str.at(i) - '0') * pow(2, str.size() - 1 - i);
		}
		cout << "Original binary: " << str << endl;
		cout << "As a decimal: " << deci << endl;
		return 1;
	}
	else {
		cout << "Not a binary number." << endl;
		return -1;
	}
}

int binToBase() {
	string binStr;
	string baseStr = "";
	int deci = 0;
	int base = 0;
	cout << "Enter the binary number: ";
	cin >> binStr;
	if (binStr.find_first_not_of("01") != string::npos) {
		cout << "Not a binary number." << endl;
		return -1;
	}
	cout << "Enter the base: ";
	cin >> base;
	if (base < 2 || base > 16) {
		cout << "Invalid Base" << endl;
		return -1;
	}
	for (int i = binStr.size() - 1; i >= 0; i--) {
			deci += (binStr.at(i) - '0') * pow(2, binStr.size() - 1 - i);
	}
	if (deci > 0) {
		if (base / 10 > 0) {
			while (deci > 0) {
				if (deci % base < 10) {
					baseStr = to_string(deci % base) + baseStr;
					deci /= base;
				}
				else {
					baseStr = char(deci % base + 55) + baseStr;
					deci /= base;
				}
			}
		}
		else {
			while (deci > 0) {
				baseStr = to_string(deci % base) + baseStr;
				deci /= base;
			}
		}
	}
	else {
		baseStr = '0';
	}
	cout << "Original binary: " << binStr << endl;
	cout << "As a base " << base << " number: " << baseStr << endl;
	return 1;
}

int deciToBin() {
	string binary = "";
	string deciStr;
	int deci;
	cout << "Enter the decimal number: ";
	cin >> deciStr;
	if (deciStr.find_first_not_of("0123456789") == string::npos) {
		deci = stoi(deciStr);
	}
	else {
		cout << "Not a decimal number." << endl;
		return -1;
	}
	if (deci == 0) {
		binary = '0' + binary;
	}
	while (deci > 0) {
		binary = to_string(deci % 2) + binary;
		deci /= 2;
	}
	cout << "Original decimal: " << deciStr << endl;
	cout << "As a binary: " << binary << endl;
	return 1;
}

int baseToBin() {
	string baseStr;
	string binary = "";
	int deci = 0;
	int base;
	cout << "Enter the number to be converted: ";
	cin >> baseStr;
	cout << "Enter the base: ";
	cin >> base;
	if (base < 2 || base > 16) {
		cout << "Invalid Base" << endl;
		return -1;
	}
	if (base / 10 > 0) {
		for (int i = baseStr.size() - 1; i >= 0; i--) {
			if (isdigit(baseStr.at(i))) {
				deci += (baseStr.at(i) - '0') * pow(base, baseStr.size() - 1 - i);
			}
			else {
				deci += (baseStr.at(i) - 55) * pow(base, baseStr.size() - 1 - i);
			}
		}
	}
	else {
		for (int i = baseStr.size() - 1; i >= 0; i--) {
			deci += (baseStr.at(i) - '0') * pow(base, baseStr.size() - 1 - i);
		}
	}
	while (deci > 0) {
		binary = to_string(deci % 2) + binary;
		deci /= 2;
	}
	cout << "The original number: " << baseStr << endl;
	cout << "The number as a binary: " << binary << endl;
	return 1;
}

int baseToBase() {
	string inputBaseStr;
	string outputBaseStr = "";
	int deci = 0;
	int inputBase, outputBase;
	cout << "Enter the number to be converted: ";
	cin >> inputBaseStr;
	cout << "Enter the base: ";
	cin >> inputBase;
	if (inputBase < 2 || inputBase > 16) {
		cout << "Invalid Base" << endl;
		return -1;
	}
	cout << "Enter the base to convert into: ";
	cin >> outputBase;
	if (outputBase < 2 || outputBase > 16) {
		cout << "Invalid Base" << endl;
		return -1;
	}
	if (inputBase / 10 > 0) {
		for (int i = inputBaseStr.size() - 1; i >= 0; i--) {
			if (isdigit(inputBaseStr.at(i))) {
				deci += (inputBaseStr.at(i) - '0') * pow(inputBase, inputBaseStr.size() - 1 - i);
			}
			else {
				deci += (inputBaseStr.at(i) - 55) * pow(inputBase, inputBaseStr.size() - 1 - i);
			}
		}
	}
	else {
		for (int i = inputBaseStr.size() - 1; i >= 0; i--) {
			deci += (inputBaseStr.at(i) - '0') * pow(inputBase, inputBaseStr.size() - 1 - i);
		}
	}
	if (outputBase / 10 > 0) {
		while (deci > 0) {
			if (deci % outputBase < 10) {
				outputBaseStr = to_string(deci % outputBase) + outputBaseStr;
				deci /= outputBase;
			}
			else {
				outputBaseStr = char(deci % outputBase + 55) + outputBaseStr;
				deci /= outputBase;
			}
		}
	}
	else {
		while (deci > 0) {
			outputBaseStr = to_string(deci % outputBase) + outputBaseStr;
			deci /= outputBase;
		}
	}
	cout << "The original number in base " << inputBase << ": " << inputBaseStr << endl;
	cout << "The converted number in base " << outputBase << ": " << outputBaseStr << endl;
	return 1;
}
