#include<iostream>

using namespace std;

int success = 0;

void solution(int count, int x, int y, int** desk, int n) {
	if (((0 <= x) && (x < n)) && ((0 <= y) && (y < n)) && (desk[x][y] == 0)) {
		//cout << x << " " << y << " " << count << "\n";
		if (count == n * n) {
			success = 1;
			desk[x][y] = count;
			return;
		}
		desk[x][y] = count;
		//if (success == 1) return;
		solution(count + 1, x + 2, y + 1, desk, n);
		if (success == 1) return;
		solution(count + 1, x + 2, y - 1, desk, n);
		if (success == 1) return;
		solution(count + 1, x - 2, y + 1, desk, n);
		if (success == 1) return;
		solution(count + 1, x - 2, y - 1, desk, n);
		if (success == 1) return;
		solution(count + 1, x + 1, y + 2, desk, n);
		if (success == 1) return;
		solution(count + 1, x + 1, y - 2, desk, n);
		if (success == 1) return;
		solution(count + 1, x - 1, y + 2, desk, n);
		if (success == 1) return;
		solution(count + 1, x - 1, y - 2, desk, n);
		if (success == 1) return;
		desk[x][y] = 0;
	}
}

void create_desk(int** desk, int n) {
	for (int i = 0; i < n; i++) {
		desk[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			desk[i][j] = 0;
		}
	}
}

void print_desk(int** desk, int n) {
	if (success == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (desk[i][j] > 9) {
					cout << desk[i][j] << "  ";
				}
				else {
					cout << desk[i][j] << "   ";
				}
			}
			cout << endl;
		}
	}
	else {
		cout << "No solution!\n";
	}
}

void delete_desk(int** desk, int n) {
	for (int i = 0; i < n; i++) {
		delete[] desk[i];
	}
	delete[] desk;
}

int main() {
	int n = 8, count = 1, x = 3, y = 4;
	int** desk = new int* [n];
		
	create_desk(desk, n);
	solution(count, x, y, desk, n);
	print_desk(desk, n);
	delete_desk(desk, n);

	return 0;
}