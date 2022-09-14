#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int cnt = 0;
int arr[9];
int now[9];
int res[9];
bool visit[9];

void trace(int day) {
	if (day == 0) now[day] = 500;
	if (day >= 1) {
		if ((now[day] - k) < 500) {
			return;
		}
		else {
			now[day] -= k;
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
		now[day + 1] = now[day] + res[day];
		trace(day + 1);
		visit[i] = false;
		if (day == 0) now[day] = 500;
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