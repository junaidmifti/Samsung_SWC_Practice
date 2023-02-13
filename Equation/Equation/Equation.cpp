#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
long long a, b, c, x;
long long n;

int log(long long x) {
	double xX = double(x);
	int value = 0;
	while (xX >= 2.71828) {
		xX = xX / 2.71828;
		value++;
	}
	return value;
}

void solve() {
	long long low, mid, high, result;
	if (c == 0) {
		high = 10000000000000;
	}
	else {
		high = 100000;
	}
	low = 0;
	while (low <= high) {
		mid = (high + low) / 2;
		result = a * mid + b * log(mid) + c * mid*mid*mid;
		if (x < result) {
			high = mid - 1;
		}
		else if (x > result) {
			low = mid + 1;
		}
		else {
			n = mid;
			return;
		}
	}
}

int main()
{
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> a >> b >> c >> x;
		solve();
		cout << "#" << i << " " << n << endl;
	}
}
