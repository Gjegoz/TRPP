#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <random>
#include <array> 

#define WIDTH 50
#define HEIGHT 15

using namespace std;

//// task 1
//
//void zad1() {
//	string allNums = "";
//	ofstream file("test.txt");
//	for (int i = 1; i < 11
//		; i++) {
//		int num = 0;
//		cout << "Type " << i << " number" << endl;
//		cin >> num;
//		if (!num) {
//			num = 0;
//		}
//		ostringstream oss;
//		oss << num;
//		allNums += oss.str() + " ";
//
//	}
//	file << allNums;
//	file.close();
//
//	string mystring;
//	string fullString = "";
//	ifstream fin("test.txt");
//	int c = 0; int summ = 0;
//	while (fin >> mystring) {
//		int res;
//
//		istringstream iss(mystring);
//		iss >> res;
//		//cout << mystring << endl;
//		summ += res;
//	}
//	cout << fullString << endl << summ << endl;
//	fin.close();
//}
//
//// task 2
//
//string sign_x(int x) {
//	if (x > 0) return "x > 0";
//	else if (x == 0) return "x = 0";
//	else return "x < 0";
//}
//
//void zad2() {
//	int x;
//	cout << "type number" << endl;
//	cin >> x;
//	cout << sign_x(x) << endl;
//}
//
//// task 3
//
//double a; double b; double h; double r;
//
//double rectangle_calculation(double a, double b) {
//	if (a > 0 and b > 0) return a * b;
//	else return -1;
//}
//
//double triangle_calculation(double b, double h) {
//	if (b > 0 and h > 0) return (b * h) / 2;
//	else return -1;
//}
//
//double circle_calculation(double r) {
//	if (r > 0) return r * 3.14;
//	else return -1;
//}
//
//void zad3() {
//	int variant;
//	cout << "Type number to calculate: 1) rectangle 2) triangle 3) circle" << endl;
//	cin >> variant;
//	switch (variant)
//	{
//	case 1:
//		cout << "Tybe a" << endl;
//		cin >> a;
//		cout << "Tybe b" << endl;
//		cin >> b;
//		cout << rectangle_calculation(a, b) << endl;
//		break;
//	case 2:
//		cout << "Tybe b" << endl;
//		cin >> b;
//		cout << "Tybe h" << endl;
//		cin >> h;
//		cout << triangle_calculation(b, h) << endl;
//		break;
//	case 3:
//		cout << "Tybe r" << endl;
//		cin >> r;
//		cout << circle_calculation(r) << endl;
//		break;
//	default:
//		cout << "You had to type a number, bastard." << endl;
//		break;
//	}
//}

// task 4

//void zad4() {
//	int star = 0; int line = 0;
//	for (int i = 0; i < 8; i++) {
//		for (int j = 0; j < 32; j++) {
//			if (line <= 3) {
//				if (star <= 8) { cout << "*"; star += 1; }
//				else { cout << "_"; }
//			} else {
//				cout << "_";
//			}
//		}
//		star = 0;
//		cout << endl;
//		line += 1;
//	}
//}

//int from_roman(char roman) {
//	switch (roman)
//	{
//	case 'I': return 1;
//	case 'V': return 5;
//	case 'X': return 10;
//	case 'L': return 50;
//	case 'C': return 100;
//	case 'D': return 500;
//	case 'M': return 1000;
//	default:
//		return 0;
//		break;
//	}
//}
//
//void zad6() {
//	string input;
//	int sum = 0; int pastNumber = 0; int c = 1;
//	cout << "Roman nubmer: ";
//	cin >> input;
//	if (input.length() != 1) {
//		for (int i = input.length() - 1; i >= 0; i--) {
//			int left = from_roman(input[i]);
//			int right = pastNumber;
//			if (left < right) {
//				if (left == 5 || left == 50 || left == 500) {
//					cout << "Wrong number" << endl;
//					break;
//				}
//				else {
//					c = 1;
//					sum -= left;
//				}
//				
//			}
//			else if (left == right) {
//				if (c > 2 || from_roman(input[i + 2]) > left || (left == 5 || left == 50 || left == 500)) {
//					cout << "Wrong number" << endl;
//					break;
//				}
//				c += 1;
//				sum += left;
//			}
//			else {
//				c = 1;
//				sum += left;
//			}
//			pastNumber = left;
//		}
//		cout << sum << endl;
//	}
//	else {
//		cout << from_roman(input[0]) << endl;
//	}
//}
//
//void go_to_coords(int x, int y) {
//	COORD pos;
//	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
//	pos.X = x;
//	pos.Y = y;
//	SetConsoleCursorPosition(hCon, pos);
//}
//
//void zad5() {
//	
//	
//	for (double x = 0; x < WIDTH; x += 0.1) {
//		go_to_coords(x * 2, sin(x)*10 + 15);
//		cout << "*";
//	}
//	
//
//	cin.get();
//}

int randInt(int m, int b, int c) {
	//cout << "Print random i:";
	//cin >> ni;
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(1, 100);
	int ni = uni(rng);
	int s1 = 0;
	int s2 = 0;
	for (int i = 0; i < ni - 1; i++) {
		s2 = (m * s1 + b) % c;
		s1 = s2;
	}
	return s2;
}

void zad7() {
	cout << randInt(37, 3, 64) << endl;
	cout << randInt(25173, 13849, 65537) << endl;
}

void zad8() {
	double tableA[3][4] = {
		{5,2,0,10},
		{3,5,2,5},
		{20,0,0,0}
	};
	double tableB[4][2] = {
		{1.2, 0.5},
		{2.8, 0.4}, 
		{5.0, 1.0},
		{2.0, 1.5} 
	};
	double tableC[3][2] = {
		{0, 0},
		{0, 0},
		{0, 0}
	};

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			for (int l = 0; l < 4; l++) {
				tableC[i][j] += tableA[i][l] * tableB[l][j];
			}
		}
	};
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 2; y++) {
			cout << tableC[x][y] << "          ";
		}
		cout << endl;
	}
	
	double maxi = 0; double mini = 100000; double maxiCom = 0; double miniCom = 100000; double sumTovari = 0; double sumCom = 0; double totalSum = 0;

	for (int i = 0; i < 3; i++) {
		maxi = max(maxi, tableC[i][0]);
		mini = min(mini, tableC[i][0]);
		maxiCom = max(maxi, tableC[i][1]);
		miniCom = min(mini, tableC[i][1]);
		sumTovari += tableC[i][0];
		sumCom += tableC[i][1];
		totalSum = sumTovari + sumCom;
	}
	cout << "1) max = " << maxi << "; min = " << mini << endl;
	cout << "2) max = " << maxiCom << "; min = " << miniCom << endl;
	cout << "3) sumTovari = " << sumTovari << endl;
	cout << "4) sumCom = " << sumCom << endl;
	cout << "5) totalSum = " << totalSum << endl;

}

int char_to_int(char symbol) {
	switch (symbol) {
	case '0': return 0; break;
	case '1': return 1; break;
	case '2': return 2; break;
	case '3': return 3; break;
	case '4': return 4; break;
	case '5': return 5; break;
	case '6': return 6; break;
	case '7': return 7; break;
	case '8': return 8; break;
	case '9': return 9; break;
	case 'A': return 10; break;
	case 'B': return 11; break;
	case 'C': return 12; break;
	case 'D': return 13; break;
	case 'E': return 14; break;
	case 'F': return 15; break;
	}
	return -1;
}


string int_to_char(int symbol) {
	switch (symbol) {
	case 0: return "0"; break;
	case 1: return "1"; break;
	case 2: return "2"; break;
	case 3: return "3"; break;
	case 4: return "4"; break;
	case 5: return "5"; break;
	case 6: return "6"; break;
	case 7: return "7"; break;
	case 8: return "8"; break;
	case 9: return "9"; break;
	case 10: return "A"; break;
	case 11: return "B"; break;
	case 12: return "C"; break;
	case 13: return "D"; break;
	case 14: return "E"; break;
	case 15: return "F"; break;
	}
	return "";
}

void zad9() {
	string line; int start_s; int end_s;
	cout << "Number: "; cin >> line;
	cout << "start s: "; cin >> start_s;
	cout << "end s: "; cin >> end_s;
	int line10 = 0;
	for (int i = 0; i < line.size(); i++) {
		int x = char_to_int(line[i]);
		line10 += x * pow(start_s, line.size() - i - 1);
	}
	string line_end_s = "";
	while (line10 != 0) {
		line_end_s = int_to_char(line10 % end_s) + line_end_s;
		line10 = line10 / end_s;
	}
	cout << line_end_s << endl;
}

int main() {
	/*zad1();
	zad2();
	zad3();*/
	//zad5();
	//zad6();
	zad7();
	cout << endl;
	zad8();
	cout << endl;
	zad9();
	return 0;
}
