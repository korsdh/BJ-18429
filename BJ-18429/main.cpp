#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int cnt = 0;
int arr[9];
int now = 500;
int res[9];
bool visit[9];

void trace(int day) {
	if (day >= 1) {
		if ((now - k) < 500) return;
		else {
			now = now - k;
		}
	}
	if (day == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visit[i] == true) continue;
		visit[i] = true;
		res[day] = arr[i];
		now += res[day];
		trace(day + 1);
		visit[i] = false;
	}
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	trace(0);
	cout << cnt << endl;
	return 0;
}