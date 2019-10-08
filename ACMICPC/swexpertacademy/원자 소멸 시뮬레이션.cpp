#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>

#define MAX 4001
using namespace std;

typedef struct {
	int x;
	int y;
	int dir;
	int Energy;
	bool Live;
}Atom_Info;

int N, Total_Energy;
int MAP[MAX][MAX];
vector<Atom_Info> v;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

void Initialize() {
	N = 0;
	Total_Energy = 0;
	v.clear();
	memset(MAP, 0, sizeof(MAP));
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, dir, k;
		cin >> x >> y >> dir >> k;
		x = (x + 1000) * 2;
		y = (y + 1000) * 2;
		v.push_back({ x,y,dir,k,true });
		MAP[x][y] = 1;
	}
}

bool All_Die() {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].Live == true) {
			return false;
		}
	}
	return true;
}

void Move_Atom() {
	while (1) {
		if (All_Die() == true) break;

		for (int i = 0; i < v.size(); i++) {
			if (v[i].Live == false) continue;

			int x = v[i].x;
			int y = v[i].y;
			int dir = v[i].dir;

			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx >= 0 && ny >= 0 && nx < MAX && ny < MAX) {
				MAP[x][y] = 0;
				MAP[nx][ny] = MAP[nx][ny] + 1;
				x = nx;
				y = ny;
				v[i].x = x;
				v[i].y = y;
			}
			else {
				v[i].Live = false;
				MAP[x][y] = 0;
			}
		}

		for (int i = 0; i < v.size(); i++) {
			if (v[i].Live == false) continue;
			int x = v[i].x;
			int y = v[i].y;

			if (MAP[x][y] >= 2) {
				for (int j = 0; j < v.size(); j++) {
					if (i == j) continue;
					if (v[j].Live == false) continue;

					int xx = v[j].x;
					int yy = v[j].y;

					if (x == xx && y == yy) {
						Total_Energy += v[j].Energy;
						v[j].Live = false;
					}
				}

				Total_Energy += v[i].Energy;
				v[i].Live = false;
				MAP[x][y] = 0;
			}
		}
	}
}

void Solution() {
	if (v.size() <= 1) {
		Total_Energy = 0;
		return;
	}
	Move_Atom();
}

void Solve() {
	int Tc; cin >> Tc;
	for (int T = 1; T <= Tc; T++) {
		Initialize();
		Input();
		Solution();

		cout << "#" << T << " " << Total_Energy << "\n";
	}
}

int main(void) {
	//freopen("Text.txt", "r", stdin);
	Solve();

	return 0;
}
