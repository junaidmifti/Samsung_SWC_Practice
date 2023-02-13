// Sum of Nodes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int maxLevel;
	int currentLevel = -1;
	int ansSum = 0;
	int flag = 0;
	cin >> maxLevel;
	string inputS;
	cin >> inputS;
	for (int i = 0; i < inputS.size(); i++) {
		if (inputS[i] == '(') currentLevel++;
		else if (inputS[i] == ')') currentLevel--;
		
		else if (currentLevel == maxLevel) {
			if (inputS[i] == '-') {
				i++;
				flag = 1;
			}
			int num = inputS[i] - '0';
			i++;
			while (inputS[i] - '0' >= 0 && inputS[i] - '0' <= 9) {
				num = num * 10 + (inputS[i] - '0');
				i++;
			}
			i--;
			if (flag) ansSum -= num;
			else ansSum += num;
		}
	}
	cout << ansSum;
	return 0;
}

