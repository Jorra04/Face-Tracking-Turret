#include <iostream>
#include <string.h>

using namespace std;

#include <string>
#include <stdlib.h>
#include "SerialPort.h"


char *port = (char*)"\\\\.\\COM3";

int main() {
	SerialPort arduino(port);
	if (arduino.isConnected()) {
		cout << "We are connected\n";
	}
	else {
		cout << "Failed to connect.\n";
	}
	char* data = (char*)malloc(sizeof(char) * 50);
	string temp;
	int dataX;
	int dataY;
	
	while(1){
		cout << "Enter X: ";
		cin >> dataX;
		cout << "Enter Y: ";
		cin >> dataY;
		temp = "X" + to_string(dataX) + "Y" + to_string(dataY);
		for (int i = 0; temp[i] != '\0'; i++) {
			data[i] = temp[i];
		}
		arduino.writeSerialPort(data, MAX_DATA_LENGTH);
	}
	return 0;
}