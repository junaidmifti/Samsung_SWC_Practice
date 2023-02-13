#include <iostream>

using namespace std;

int log(long long input) {
	int val = 0;
	double xX = (double)input;
	while (xX >= 2.71828) {
		xX = xX / 2.71828;
		val++;
	}
	return val;
}

int main()
{
	int T;
	cin >> T;
	for (int z = 1; z <= T; z++) {
		long long a, b, c, x;
		long long n;
		cin >> a >> b >> c >> x;
		long long low = 0, mid, high;
		if (c == 0) {
			high = 10000000000000;
		}
		else high = 100000;

		while (low <= high) {
			mid = (low + high) / 2;
			long long result = a * mid + b * log(mid) + c * mid*mid*mid;
			if (x < result) {
				high = mid - 1;
			}
			else if (x > result) {
				low = mid + 1;
			}
			else {
				n = mid;
				break;
			}
		}

		cout << "#" << z << " " << n << endl;
	}

}

