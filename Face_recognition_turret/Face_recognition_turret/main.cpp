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
	
	string temp;
	int dataX;
	int dataY;
	
	while(1){
		cout << "Enter X: ";
		cin >> dataX;
		cout << "Enter Y: ";
		cin >> dataY;
		temp = "X" + to_string(dataX) + "Y" + to_string(dataY);
		char* buff = new char[temp.length()+1];
		temp.copy(buff, temp.size() + 1);
		buff[temp.size()] = '\0';
		cout << buff << "\n";
		
		
		arduino.writeSerialPort(buff, MAX_DATA_LENGTH);
		
	}
	return 0;
}