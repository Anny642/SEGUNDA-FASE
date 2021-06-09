#include <iostream>
#include <string>
#include <stdlib.h>
#include "SerialPort.h"

using namespace std;

char output[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];


char commport[] = "COM7";
char* port = commport;

int main() {
	SerialPort arduino(port);
	if (arduino.isConnected()) {
		cout << "----------------------------------------------" <<  endl;

		cout << " CONEXION REALIZADA CON EXITO " << endl << endl;

		cout << "------------------------------------------------" << endl;
	}
	else {
	
		cout << "------------------------------------------------" << endl;

		cout << "Error al realizar la conexion" << endl << endl;

		cout << "------------------------------------------------" << endl;
	}
	while (arduino.isConnected()) {


		cout << "------BIENVENIDO------ " << endl;
		
		string data;
		cin >> data;

		char* charArray = new char[data.size()+1];
		copy(data.begin(), data.end(), charArray);
		charArray[data.size()] = '\n';

		arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
		arduino.readSerialPort(output, MAX_DATA_LENGTH);

		cout << ">> " << output << endl;

		delete[] charArray;
	}
	return 0;
}