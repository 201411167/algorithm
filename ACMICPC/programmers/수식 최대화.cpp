#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<long long > nums;
vector<char> opers;
bool operChk[3];
vector<char> opersBeforeComb;
vector<char> combList;

long long answer;

void getAnswer(){
	vector<long long> tnums;
	for(int i=0;i<nums.size();i++){
		tnums.push_back(nums[i]);
	}

	vector<char> topers;
	for(int i=0;i<opers.size();i++){
		topers.push_back(opers[i]);
	}

	for(char o : combList){
		for(int i=0;i<topers.size();i++){
			if(o == topers[i]){
				if(o == '-'){
					tnums[i] = tnums[i] - tnums[i+1];
				}
				if(o == '+'){
					tnums[i] = tnums[i] + tnums[i+1];
				}
				if(o == '*'){
					tnums[i] = tnums[i] * tnums[i+1];
				}
				tnums.erase(tnums.begin()+i+1);
				topers.erase(topers.begin()+i);
				i--;
			}
		}
	}

	answer = max(answer, abs(tnums[0]));
}

bool chk[3];
void comb(int idx, int cnt, int size) {
	if(cnt == size){
		getAnswer();
		
		return;
	}else{
		for(int i=0;i<opersBeforeComb.size();i++){
			if(chk[i])continue;
			chk[i]=true;
			combList.push_back(opersBeforeComb[i]);
			// if(i==0) combList.push_back('+');
			// if(i==1) combList.push_back('-');
			// if(i==2) combList.push_back('*');

			comb(i, cnt + 1, size);

			chk[i]=false;
			combList.pop_back();
		}
	}
}

long long solution(string exp){
	string s;
	for(int i=0;i<exp.size()+1;i++){
		if(exp[i] == '-' || exp[i] == '+' || exp[i] == '*' || exp[i] == '\0'){
			int a = std::stoi(s);
			nums.push_back(a);
			opers.push_back(exp[i]);
			if(exp[i] == '-' && !operChk[0]){
				operChk[0]=true;
				opersBeforeComb.push_back('-');
			}
			if(exp[i] == '+' && !operChk[1]){
				operChk[1]=true;
				opersBeforeComb.push_back('+');
			}
			if(exp[i] == '*' && !operChk[2]){
				operChk[2]=true;
				opersBeforeComb.push_back('*');
			}
			s="";
		}else{
			s+=exp[i];
		}
	}
	opers.pop_back();

	comb(0, 0, opersBeforeComb.size());

	return answer;
}