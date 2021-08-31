
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > grid(10,vector<int>(10,0));
int check(int r,int c)
{
	int flag=1,num=grid[r][c];
	for(int i=0;i<9;i++)	if(grid[r][i]==num&&i!=c)	flag=0;
	for(int i=0;i<9;i++)	if(grid[i][c]==num&&i!=r)	flag=0;
		int R=(r/3)*3,C=(c/3)*3;
	for(int i=R;i<R+3;i++)
	{
		for(int j=C;j<C+3;j++)
		{
			if(grid[i][j]==num&&i!=r&&j!=c)	flag=0;
		}
	}		
	return flag;
}
int next(int r,int c,int &r_nxt,int &c_nxt)
{
	if(r==8&&c==8)	return 0;
	c_nxt++;
	if(c_nxt==9)	c_nxt=0,r_nxt++;		
	while(r_nxt<9&&c_nxt<9&&grid[r_nxt][c_nxt]!=0)
	{
		c_nxt++;
	if(c_nxt==9)	c_nxt=0,r_nxt++;

	}
	if(r_nxt==9||c_nxt==9)	return 0;
	return 1;
}
int solve(int r,int c)
{
	if(grid[r][c]!=0)	return 1;	
	int r_nxt=r,c_nxt=c;
	if(next(r,c,r_nxt,c_nxt))
	{
	for(int i=1;i<=9;i++)
	{
		grid[r][c]=i;
		if(check(r,c))
		{
		if(solve(r_nxt,c_nxt))	return 1;
		}
	}
	grid[r][c]=0;
	return 0;
	}
	else
	{
	for(int i=1;i<=9;i++)
	{
		grid[r][c]=i;
		if(check(r,c))	return 1;
	}
	return 0;
	}
	return 0;
}
int main()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cin>>grid[i][j];
		}
	}
	int r=0,c=0;
	if(grid[0][0]!=0) next(r,c,r,c);
	solve(r,c);

for(int i=0;i<9;i++)
	{
			if(i%3==0)	cout<<"\n";
		for(int j=0;j<9;j++)
		{
			if(j%3==0)	cout<<"  ";
			cout<<grid[i][j]<<" ";
			
		}

		cout<<"\n";
	}
	
}