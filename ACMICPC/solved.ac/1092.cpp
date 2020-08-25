#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> cranes;
int m;
vector<int> boxes;
int answer;

bool comp(int a, int b){
	return a > b;
}

int main(){
	freopen("input.txt","r",stdin);

	cin >> n;
	for(int i=0;i<n;i++){
		int num; cin >> num;
		cranes.push_back(num);
	}

	cin >> m;
	for(int i=0;i<m;i++){
		int num; cin >> num;
		boxes.push_back(num);
	}

	sort(cranes.begin(), cranes.end(), comp);
	sort(boxes.begin(), boxes.end(), comp);

	if(cranes[0] < boxes[0]){
		cout << -1;
		return 0;
	}

	while(boxes.size()){
		int idx = 0;
		for(int i=0;i<boxes.size();i++){
			if(idx == cranes.size()){
				break;
			}
			if(cranes[idx] >= boxes[i]){
				idx++;
				boxes.erase(boxes.begin() + i);
				i = i - 1;
			}
		}
		answer++;
	}

	cout << answer;

	return 0;
}
