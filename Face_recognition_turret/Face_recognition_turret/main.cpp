#include <iostream>
#include <string.h>

using namespace std;

#include <string>
#include <stdlib.h>
#include "SerialPort.h"


char *port = (char*)"\\\\.\\COM3";
SerialPort arduino(port);
void survey(int dataY) {
	string temp;
	
	while (1) {
		for (int i = 0; i <= 180; i += 10) {
			temp = "X" + to_string(i) + "Y" + to_string(dataY);
			char* buff = new char[temp.length() + 1];
			temp.copy(buff, temp.size() + 1);
			buff[temp.size()] = '\0';
			cout << buff <<"\n";
			arduino.writeSerialPort(buff, MAX_DATA_LENGTH);
		}

		for (int i = 180; i >= 0; i -= 10) {
			temp = "X" + to_string(i) + "Y" + to_string(dataY);
			char* buff = new char[temp.length() + 1];
			temp.copy(buff, temp.size() + 1);
			buff[temp.size()] = '\0';
			cout << buff << "\n";
			arduino.writeSerialPort(buff, MAX_DATA_LENGTH);
		}
	}
}

int length_of_string(char* string) {
	int i = 0;
	for (i = 0; string[i] != '\0'; i++) {}

	return i;
}

bool strings_equal(char* string1, char* string2) {
	int strlen1 = length_of_string(string1);
	if (strlen1 != length_of_string(string2)) return false;

	for (int i = 0; i < strlen1; i++) {
		if (string1[i] != string2[i]) return false;
	}
	return true;
}


int main() {
	
	if (arduino.isConnected()) {
		cout << "We are connected\n";
	}
	else {
		cout << "Failed to connect.\n";
		exit(1);
	}

	
	
	string temp;
	int dataX;
	int dataY;
	char* ans = (char*)malloc(sizeof(char) * 30);
	while(1){
		cout << "Enter functionality...\n1. Write\n2. Survey\n";
		cin >> ans;
		if (strings_equal(ans, (char*)"Write")) {
			cout << "Enter X: ";
			cin >> dataX;
			cout << "Enter Y: ";
			cin >> dataY;
			temp = "X" + to_string(dataX) + "Y" + to_string(dataY);
			char* buff = new char[temp.length() + 1];
			temp.copy(buff, temp.size() + 1);
			buff[temp.size()] = '\0';
			cout << buff << "\n";


			arduino.writeSerialPort(buff, MAX_DATA_LENGTH);
		}
		else if (strings_equal(ans, (char*)"Survey")) {
			survey(35);
		}
		
		
	}
	return 0;
}