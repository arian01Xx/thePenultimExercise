#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class neighborSum{
public:
	vector<vector<int>> grid;
	int n;

	neighborSum(vector<vector<int>>& gird){
		grid=gird;
		n=grid.size();
	}

	int adjacentSum(int value){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(grid[i][j]==value){
					int left=(j>0) ?  grid[i][j-1]:0;
					int right=(j<n) ? grid[i][j+1]:0;
					int up=(i>0) ? grid[i-1][j]:0;
					int bottom=(i<n) ? grid[i+1][j]:0;
					return left+right+up+bottom;
				}
			}
		}
		return -1;
	}

	int diagonalSum(int value){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(grid[i][j]==value){
					int sum=0;
					if(i-1>=0 && j-1>=0) sum+=grid[i-1][j-1];  //top-left
					if(i+1<n && j+1<n) sum+=grid[i+1][j+1]; //bottom-right
					if(i+1<n && j-1>=0) sum+=grid[i+1][j-1];  //bottom-left
					if(i-1>=0 && j+1<n) sum+=grid[i-1][j+1];  //top-right
					return sum;
				}
			}
		}
		return -1;
	}
};

#endif // SOLUTION_HPP