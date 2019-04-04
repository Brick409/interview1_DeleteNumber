_// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

using namespace std;

/* m个元素的数组从中选择性删除n个，最终使剩下的数字最大，如何删除 */
/* 其中m为数组的总个数，n为要删除的位数 */
/* 例：45231，删除 2个，最后剩下为531 */
int findMax(int *a, int start, int end, int *pos)
{
	int num = end - start+1;
	int max = a[start];
	*pos = start;
	for (int i=0;i<num;i++)
	{
		if (max<a[start+i])
		{
			max = a[start + i];
			*pos = start + i;
		}
	}
	return max;
}

int findMaxNum(int *a, int m, int n)
{
	int lastNum = 0;
	int searchPos = 0;
	int k = 1;
	int init = 0;
	int lastPos = n;
	int findPos = 0;
	int max = 0;

	int t = 0;

	max = findMax(a, init, lastPos, &findPos);

	if (findPos == n)
	{
		for (int i = findPos; i < m; i++)
		{
			lastNum = a[i] + lastNum * 10;
		}
		return lastNum;
	}

	while (k<(m-n+1))
	{
		lastNum = max + lastNum * 10;
		init = findPos + 1;
		lastPos = n + k;  //搜索下标不能超过还需要的剩余位数，即：lastPos不能超过m-(m-n-k)
		max = findMax(a, init, lastPos, &findPos);
		k++;
	}

	return lastNum;

}

int main()
{

	int a[] = { 4,5,2,3,1,9,6,0,7 };
	int m = sizeof(a)/sizeof(a[0]);
	int n = 0;
	int origin = 0;

	cout <<"数组总长度"<< m << endl;
	
	for (int i = 0; i < m; i++)
	{
		origin = origin * 10 + a[i];
	}
	cout << "数组总长度组成原始值为：" << origin << endl;
	cout << "输入要删除的元素个数n（按回车结束)：" << endl;
	cin >> n;
	cout << "随机删除" << n << "个元素后，剩余最大数：" << endl;
	int last = 0;

	last=findMaxNum(a, m, n);

	cout <<last<<endl;

    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
