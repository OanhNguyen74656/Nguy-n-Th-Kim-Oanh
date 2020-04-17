#include<iostream>
#include<math.h>
#include<string.h>
#include<sstream>
using namespace std;

bool kiemtranhiphan(string strBit) {
	for (int i = 0; i < strBit.length(); i++)
		if (strBit[i] != '0' && strBit[i] != '1') return false;
	return true;
}

int cast2to10(string strBit) {
	int iResult = 0;
	for (int i = 0; i < strBit.length(); i++)
		if (strBit[i] == '1') iResult += pow(2, strBit.length() - 1 - i);
	return iResult;
}

string DoiDiaChiIP(string strDiaChiIP) {
	string strResult = string();

	if ((strDiaChiIP.length() != 32) || (!kiemtranhiphan(strDiaChiIP))) {
		cout << "Dia chi nhap khong dung";
		return string();
	}

	for (int i = 0; i < 4; i++) {
		stringstream strg;
		string strBitIP = strDiaChiIP.substr(8 * i, 8);
		int iBitIP = cast2to10(strBitIP);
		string strBit;
		strg << iBitIP;
		strg >> strBit;
		strResult += strBit;
		if (i < 3) strResult += ".";
	}

	return strResult;
}

int main() {
	string strBit;
	cout << "Nhap dia chi IP dang nhi phan:";
	cin >> strBit;
	cout << endl << "Dang doi dia chi IP ve dang thong thuong...";
	cout << endl << "---------------------------------";
	cout << endl << "Ket qua: " << DoiDiaChiIP(strBit);
	return 0;
}