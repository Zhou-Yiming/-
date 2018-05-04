#include "stdafx.h"
using namespace std;
#define swap(a,b){int temp;temp = a;a=b;b=temp;}
int partition(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp = arr[left];
    while (i < j) {
        while (i < j && arr[j] < tmp)
            j--;
        if (i < j) {
            arr[i] = arr[j];
            i++;
        }
        while (i < j && arr[i] > tmp)
            i++;
        if (i < j) {
            arr[j] = arr[i];
            j--;
        }
    }
    arr[i] = tmp;
    return i;
}
void quick_sort(int arr[], int left, int right) {
    if(left > right)
        return;
    int j = partition(arr, left, right);
    quick_sort(arr, left, j - 1);
    quick_sort(arr, j + 1, right);
}
float greedy(int* a,int k){
	int *p = new int[k] ;
	int n = (k-1)/2 ; //数组中点,放置最大的概率值
	p[n] = a[0];
	for(int i = n+1;i<k;i++)
		p[i] = a[2*(i-n)];
	for(int i = n-1;i>=0;i--)
		p[i] = a[2*(n-i)-1];
	float all_pro = 0,sum = 0;
	for(int i=0;i<k;i++){
		all_pro += a[i];
		for(int j = i+1;j<k;j++)
			sum += p[i]*p[j]* abs(j-i);
	}
	return sum/all_pro/all_pro;
}
int main(){
	ofstream outf;
	ifstream inf;
	outf.open("output.txt");
	inf.open("input.txt");
	int k ;
	inf >> k;
	int *a = new int[k];

	cout << "the probability of each file is : \n";
	for(int i=0;i<k;i++){
		inf >> a[i];
		cout << a[i] <<' ';
	}
	cout << endl;
	quick_sort(a,0,k-1);
	cout << "After sorting,the probability of each file is : \n";
	for(int i=0;i<k;i++){
		inf >> a[i];
		cout << a[i] <<' ';
	}
	cout << endl;
	float sum = greedy(a,k);
	outf << sum;
	cout << sum;
	inf.close();
	outf.close();
	getchar();
	return 0;
}
