#include<bits/stdc++.h>
using namespace std;
struct Number {
	int value;
	int index;
} maxNum1,minNum1,maxNum2,minNum2;
int n;
int a[1000003];
int main() {
	cin>>n;
	maxNum1.index = 0;
	maxNum1.value = - 1000000003;
	minNum1.index = 0;
	minNum1.value = 1000000003;
	maxNum2.index = 0;
	maxNum2.value = - 1000000003;
	minNum2.index = 0;
	minNum2.value = 1000000003;
	for(int i = 1;i<=n;i++) {
		cin>>a[i];
		if(a[i] >= maxNum1.value ) {
			maxNum1.value = a[i];
			maxNum1.index = i;
		}
		if(a[i]< minNum1.value ) {
			minNum1.value = a[i];
			minNum1.index = i;
		}
		if(a[i] > maxNum2.value ) {
			maxNum2.value = a[i];
			maxNum2.index = i;
		}
		if(a[i] <= minNum2.value ) {
			minNum2.value = a[i];
			minNum2.index = i;
		}
	}
	long long result1 = abs(a[maxNum1.index] - a[minNum1.index]) + abs(maxNum1.index - minNum1.index);
	long long result2 = abs(a[maxNum2.index] - a[minNum2.index]) + abs(maxNum2.index - minNum2.index);
	long long result = result1 > result2 ? result1 : result2;
	cout<< result;

	return 0;
}
