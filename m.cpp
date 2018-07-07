/* ����� ���������� ���������� ���������:
1. ��������� ���������.
2. �������� ��������� � ��������� ������� � ������ ��������. ��� ��� ��������� �������������, �� ��� ������������� �������� �����
"������" � ��� ������ (������ - ������ (1, 6, 5, 3, 1, 3) ������ (1, 1, 3, 3, 5, 6)
*/

#include <string>
#include <iostream>
#include <fstream>
#include <locale>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

int random(int min, int max) {
	return min + rand() % (max + 1 - min);
}

string PuncDel(string str) {
	while (str.find('.') != -1) 
		str.erase(str.find('.'), 1);
	while (str.find(',') != -1)
		str.erase(str.find(','), 1);
	while (str.find('!') != -1)
		str.erase(str.find('!'), 1);
	while (str.find('?') != -1)
		str.erase(str.find('?'), 1);
	while (str.find('(') != -1)
		str.erase(str.find('('), 1);
	return str;
}

int main() {
	string FilePathIn, FilePathOut;
	int NumWords;
	char SelectInput;
	bool TextOut;
	setlocale(LC_ALL, "Russian");
	cout << "���� ����� �������" << endl;
	cout << "�������� ���� ������, �� ������� �� ������ ������� ������� ����� ����� � ���������� ����." << endl << "���� �� ����� �� �������: ";
	cin >> FilePathIn;
	cout << endl;
	ifstream FileIn(FilePathIn);
	if (!FileIn.is_open()) {
		cout << "���! ������ �������� ��������� ������, ��� ������ ��� ������ ������ �����! ���� �� ������!";
		cin >> FilePathIn;
		exit(1);
	}
	cout << "�������� ���� ��� ��������� ����� �� ������� ����." << endl << "���� �� ����� � ��������� �������: ";
	cin >> FilePathOut;
	ofstream FileOut(FilePathOut, ios::app);
	cout << "� ������� ����� ������������ ����� ���� ���� � ������ ����� �����?" << endl << "������� ����� ����: ";
	cin >> NumWords;
	cout << "<�������> ���� ����� ����� �����? (���������� �� ��������� ������ ����� � ������ � ���������?)" << endl << "�������:  \'y\' - �� \'n\' - ���:   ";
	cin >> SelectInput;
	if (SelectInput == 'y') TextOut = true; else TextOut = false;
	//�������� ����� �����

	//������ � �������� ���� ���������, �� �������� ���� ����� �����.
	multimap<int, string> MultiWords;
	map<int, string> MapWords;
	string TestStr;
	while (!FileIn.eof()) {
		FileIn >> TestStr;
		TestStr = PuncDel(TestStr);
		MultiWords.insert(pair<int, string>(TestStr.size(), TestStr));
		FileOut << TestStr;
		cout << TestStr << ' ';
	}
	FileIn.seekg(0);
	while (!FileIn.eof()) {
		FileIn >> TestStr;
		TestStr = PuncDel(TestStr);
		MapWords.insert(set<pair<int, string>>(TestStr.size(), TestStr));
		FileOut << TestStr;
		cout << TestStr << ' ';
	}
	cin >> TestStr;
	
	for (int i = 0; i < MultiWords.size(); i++)
	{
	}
	FileOut.close();
}
