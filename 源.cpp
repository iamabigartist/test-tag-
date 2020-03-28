#include <stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;
int get_random_int(int m, int n)
{
	srand((unsigned)time(NULL) ^ rand());
	return rand() % (int)(n - m) + m;
}
void swap_int(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void print_int_array(int* array, int fir_index,int las_index)
{
	for (int i = fir_index; i <= las_index; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}
int quick_sort_single(int *a, int fir_index, int las_index)
{
	cout << "initial tree branch("<<fir_index<<"~"<<las_index<<")"<<":\n";
	print_int_array(a, fir_index, las_index);
	int bechanged_index = fir_index;
	int partition_index = fir_index;
	for (int check_index = fir_index; check_index <= las_index; check_index++)
	{
		if (a[partition_index] >= a[check_index])
		{
			swap_int(&a[bechanged_index], &a[check_index]);
			cout << "调换了 bechanged=" << -(fir_index ) + bechanged_index + 1 << " 和 check=" << (-fir_index )+check_index + 1 << "\n";
			print_int_array(a,fir_index,las_index);
			bechanged_index++;
		}
	}
	swap_int(&a[bechanged_index-1], &a[partition_index]);
	cout << "tree branch("<<fir_index<<"~"<<las_index<<")"<<":\n";
	print_int_array(a, fir_index, las_index);
	cout << "partition=" <<1+( -fir_index)+bechanged_index-1<<"\n";
	cout << "return_index=" << bechanged_index - 1<<"\n";
	return bechanged_index-1;
}
void quick_sort_tree(int* array, int fir_index, int las_index,bool direction)
{
	if (direction) 
	{
		cout << "右侧\n";
	}
	else
	{
		cout << "左侧\n";
	}
	
	if (fir_index == las_index) { cout << "Here is a tip.\n"; }
	else if (fir_index > las_index) { cout << "Here is a NULL tip.\n"; }
	else
	{
		int partition_index = quick_sort_single(array, fir_index, las_index);
		quick_sort_tree(array, fir_index, partition_index - 1,0);//左分支
		quick_sort_tree(array, partition_index + 1, las_index,1);//右分支
	}
}

int main()
{
	cout << "生成一个随机数列:\n";
	const int mysize = 10;
	int array[mysize];
	
	for (int i = 0;i<10;i++)
	{
		array[i] = get_random_int(1,1000);
	}
	print_int_array(array, 0,mysize-1);
	quick_sort_tree(array, 0, mysize-1,0);
	cout << "The tree finally is:\n";
	print_int_array(array, 0,mysize-1);
	string a;
	cout << "input anything to exit.";
	cin >> a;
	return 0;
}
