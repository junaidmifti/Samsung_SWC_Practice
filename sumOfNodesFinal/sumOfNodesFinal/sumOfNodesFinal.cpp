#include <iostream>
#include<string>

using namespace std;

int main()
{
	int k;
	cin >> k;
	string input;
	cin >> input;
	int level = -1;
	int flag = 0;
	int sum = 0;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(') level++;
		else if (input[i] == ')') level--;
		else if (level == k) {
			if (input[i] == '-') {
				flag = 1;
				i++;
			}
			int num = input[i] - '0';
			i++;
			while (input[i] - '0' >= 0 && input[i] - '0' <= 9) {
				num = num * 10 + input[i] - '0';
				i++;
			}
			i--;
			if (flag) {
				sum -= num;
			}
			else {
				sum += num;
			}
		}
	}
	cout << sum << endl;
}
