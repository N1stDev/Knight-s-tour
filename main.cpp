#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int success = 0;

int find_turnes(int x, int y, int ** desk, int n) {
	int count = 0;
	if ((x < n) && (x >= 0) && (y < n) && (y >= 0)) {
		if ((x + 2 < n) && (x + 2 >= 0) && (y + 1 < n) && (y + 1 >= 0) && (desk[x + 2][y + 1] != 1)) {
			count++;
		}
		if ((x + 2 < n) && (x + 2 >= 0) && (y - 1 < n) && (y - 1 >= 0) && (desk[x + 2][y - 1] != 1)) {
			count++;
		}
		if ((x - 2 < n) && (x - 2 >= 0) && (y + 1 < n) && (y + 1 >= 0) && (desk[x - 2][y + 1] != 1)) {
			count++;
		}
		if ((x - 2 < n) && (x - 2 >= 0) && (y - 1 < n) && (y - 1 >= 0) && (desk[x - 2][y - 1] != 1)) {
			count++;
		}
		if ((x + 1 < n) && (x + 1 >= 0) && (y + 2 < n) && (y + 2 >= 0) && (desk[x + 1][y + 2] != 1)) {
			count++;
		}
		if ((x + 1 < n) && (x + 1 >= 0) && (y - 2 < n) && (y - 2 >= 0) && (desk[x + 1][y - 2] != 1)) {
			count++;
		}
		if ((x - 1 < n) && (x - 1 >= 0) && (y + 2 < n) && (y + 2 >= 0) && (desk[x - 1][y + 2] != 1)) {
			count++;
		}
		if ((x - 1 < n) && (x - 1 >= 0) && (y - 2 < n) && (y - 2 >= 0) && (desk[x - 1][y - 2] != 1)) {
			count++;
		}
	}
	
	if (count == 0) {
		count = 9;
	}
	return count;
}

void solution(int count, int x, int y, int** desk, int n) {
	if (((0 <= x) && (x < n)) && ((0 <= y) && (y < n)) && (desk[x][y] == 0)) {
		//cout << x << " " << y << " " << count << "\n";
		if (count == n * n) {
			success = 1;
			desk[x][y] = count;
			return;
		}
		desk[x][y] = count;

		vector<int> vec1 = { 1 }, vec2 = { 2 }, vec3 = { 3 }, vec4 = { 4 };
		vector<int> vec5 = { 5 }, vec6 = { 6 }, vec7 = { 7 }, vec8 = { 8 };
		vec1.push_back(find_turnes(x + 2, y + 1, desk, n));
		vec2.push_back(find_turnes(x + 2, y - 1, desk, n));
		vec3.push_back(find_turnes(x - 2, y + 1, desk, n));
		vec4.push_back(find_turnes(x - 2, y - 1, desk, n));
		vec5.push_back(find_turnes(x + 1, y + 2, desk, n));
		vec6.push_back(find_turnes(x + 1, y - 2, desk, n));
		vec7.push_back(find_turnes(x - 1, y + 2, desk, n));
		vec8.push_back(find_turnes(x - 1, y - 2, desk, n));
		vector<vector<int>> vec = { vec1, vec2, vec3, vec4, vec5, vec6, vec7, vec8 };
		sort(vec.begin(), vec.end(), [](vector<int> first, vector<int> second) {
			return first[1] < second[1];
			});
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i][0] == 1) {
				solution(count + 1, x + 2, y + 1, desk, n);
			}
			else if (vec[i][0] == 2) {
				solution(count + 1, x + 2, y - 1, desk, n);
			}
			else if (vec[i][0] == 3) {
				solution(count + 1, x - 2, y + 1, desk, n);
			}
			else if (vec[i][0] == 4) {
				solution(count + 1, x - 2, y - 1, desk, n);
			}
			else if (vec[i][0] == 5) {
				solution(count + 1, x + 1, y + 2, desk, n);
			}
			else if (vec[i][0] == 6) {
				solution(count + 1, x + 1, y - 2, desk, n);
			}
			else if (vec[i][0] == 7) {
				solution(count + 1, x - 1, y + 2, desk, n);
			}
			else if (vec[i][0] == 8) {
				solution(count + 1, x - 1, y - 2, desk, n);
			}
			if (success == 1) return;
		}
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
	int n = 8, count = 1, x = 2, y = 4;
	int** desk = new int* [n];

	create_desk(desk, n);
	solution(count, x, y, desk, n);
	print_desk(desk, n);
	delete_desk(desk, n);

	return 0;
}