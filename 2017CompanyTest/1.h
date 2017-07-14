#ifndef _1_H
#define _1_H
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution
{
private:
	int minVal;
public:
	Solution():minVal(0xffffff){}
public:
	/*
	p个隔板划分n个数的问题,最优划分使得隔板之间的数字之和最小
	*/
	void dfs(vector<int>& nums,int box,int pos,int maxVal)
	{
		int len = nums.size();
		if(pos >= len || box==0)
			return;
		if(box==1)
		{
			int sum = accumulate(nums.begin()+pos,nums.end(),0);
			minVal = min(minVal,max(maxVal,sum));
			return;
		}
		int mv=0;
	    for (int i = pos; i < len;i++)
	    {
			mv += nums[i];
			dfs(nums,box-1,i+1,max(maxVal,mv));
	    }
	}
	int solution(vector<int>& nums,int boxes)
	{
		dfs(nums,boxes,0,0);
		return minVal;
	}
	void static solved()
	{
		int array[]={110,50,70,123000,1,1};
		Solution test;
		vector<int>nums(array,array+6);
		cout<<test.solution(nums,5)<<endl;
	}
};
#endif // _1_H