#include<iostream>
#include<algorithm>
using namespace std;
// N��° ū ��

int main() {
	int T;
	cin >> T;
	while (T--) {
		int arr[10];
		for (int k = 0; k < 10; k++) cin >> arr[k];
		sort(arr, arr + 10);
		cout << arr[7] << endl;
	}
}