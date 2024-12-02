#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double extractNumeric(const string& str) {
	bool decimal = false; //Tracks if there's already a decimal point
	bool sign = false; //Tracks if there's already a sign
	bool hasDigit = false; //Tracks if the string is not empty and has digits/nums
	string num;
	
	//If statement checks if the string length is greater than 20
	if (str.length() > 20) {
		return -999999.99; }

	for (size_t i = 0; i < str.length(); i++) {
		char c = str[i];
		
		if (isdigit(c)) {
			hasDigit = true; }

		//If statement to check if we already have a sign appear
		else if (c == '+' || c == '-') {
			if (!sign && i == 0) {
				sign = true; }

			else {
				return -999999.99; }
		}
		//If statement to check if a decimal has already appeared
		else if (c == '.') {
			if (decimal) {
				return -999999.99; }
			decimal = true; }

		//If statement to check if the current character is a digit
		else if (!isdigit(c)) {
			return -999999.99; } 

		num += c;
	}
	//Ensures that there is at least one digit in the string
	if (!hasDigit) {
		return -999999.99; }	

	return stod(num);
}
int main() {
	string input;

	while (true) {
		cout << "Enter a string (or 'END' to quit): ";
		cin >> input;

		if (input == "END") {
			break; }

		double number = extractNumeric(input);

		if (number != -999999.99) {
			cout << "The input is: " << fixed << setprecision(4)
				<< number << endl;}
		else {
			cout << "The input is invalid." << endl; }
	}
	return 0;
}
