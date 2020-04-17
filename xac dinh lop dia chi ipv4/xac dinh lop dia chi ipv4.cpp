
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <math.h>
using namespace std;
int getOctetsIP(string ip, vector<int>& octetsIP)
{		
	stringstream sip(ip);								
	string temp;
	octetsIP.clear();									
	vector<bool> ipInRange;
	while (getline(sip, temp, '.'))						
		octetsIP.push_back(atoi(temp.c_str()));			
	if (octetsIP.size() == 4) {
		for (int i = 0; i < octetsIP.size(); i++) {
			if (octetsIP[i] >= 0 && octetsIP[i] <= 255)
				ipInRange.push_back(true);
			else
				ipInRange.push_back(false);
		}
		if (ipInRange[0] == true && ipInRange[1] == true && ipInRange[2] == true && ipInRange[3] == true) {
			return 0;
		}
		else {
			cout << endl << "There are only 255 bits per octet. Please re-enter IP." << endl << endl;
			return 1;
		}
	}
	else {
		cout << endl << "Please enter four octets in dot notation." << endl << endl;
		return 1;
	}
}

int calcClass(vector<int>& octetsIP) {
	if (octetsIP[0] == 10) {
		return 1;	// Class A Private address blocks //
	}
	else if (octetsIP[0] == 172 && octetsIP[1] >= 16 && octetsIP[1] <= 31) {
		return 2;	// Class B Private address blocks //
	}
	else if (octetsIP[0] == 192 && octetsIP[1] == 168) {
		return 3;	// Class C Private address blocks //
	}
	else if (octetsIP[0] == 127) {
		return 4;	// Loopback Address Reserved address blocks //
	}
	else if (octetsIP[0] >= 0 && octetsIP[0] < 127) {
		return 5;
	}
	else if (octetsIP[0] > 127 && octetsIP[0] < 192) {
		return 6;
	}
	else if (octetsIP[0] > 191 && octetsIP[0] < 224) {
		return 7;
	}
	else if (octetsIP[0] > 223 && octetsIP[0] < 240) {
		return 8;
	}
	else if (octetsIP[0] > 239 && octetsIP[0] <= 255) {
		return 9;
	}
	else {
		return 0;	// Out of Range //
	}
}
int main() {

	// Give details, given an IP and Subnet Mask //
	char resp = 'y';
	while (resp == 'y') {

		// Get IP address octets //
		string ip;
		vector<int> octetsIP;
		while (getOctetsIP(ip, octetsIP) == 1) {
			cout << "Nhap IPv4 Address -> ";
			(getline(cin, ip));		
		}
		// Print IP Class
		cout << "------------------------------------------" << endl;
		cout << "    Class Information   " << endl;
		cout << "------------------------------------------" << endl;
		int classResult = calcClass(octetsIP);
		int ipClass = 0;
		switch (classResult) {
		case 1:
			cout << "IP Class: Private block, Class 'A' " << endl;
			ipClass = 1;
			break;
		case 2:
			cout << "IP Class: Private block, Class 'B'" << endl;
			ipClass = 2;
			break;
		case 3:
			cout << "IP Class: Private block, Class 'C'" << endl;
			ipClass = 3;
			break;
		case 4:
			cout << "IP Class: Reserved block, System Loopback Address" << endl;
			ipClass = 1;
			break;
		case 5:
			cout << "IP Class: A" << endl;
			ipClass = 1;
			break;
		case 6:
			cout << "IP Class: B" << endl;
			ipClass = 2;
			break;
		case 7:
			cout << "IP Class: C" << endl;
			ipClass = 3;
			break;
		case 8:
			cout << "IP Class: D" << endl;
			ipClass = 4;
			cout << "!! This is a reserved Class D Multicast IP Address Block" << endl;
			break;
		case 9:
			cout << "IP Class: E" << endl;
			ipClass = 5;
			cout << "!! This is a reserved Class E Multicast IP Address Block" << endl;
			break;
		default:
			cout << "Not in Range" << endl;
			break; 
		}
		
		cout << "Would you like to enter another IP Address to subnet? (y or n): ";
		cin >> resp;
		cout << endl << endl << endl << endl;
	}
	return 0;
}