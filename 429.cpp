/*Program Developed By oculto*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<utility>
#include<string.h>
#include<cstdio>
#include<queue>

#define MOD 1000000007
#define rep(i,a,n) for(i=a;i<n;i++)
#define nl printf("\n")
#define MAX_INT 2147483647
using namespace std;


vector< vector<int> > E;
queue<int> Q;
vector<int> d;

void addEdge(int i,int j)
{
	E[i].push_back(j);
}

int diff(string a,string b)
{
	if(a.size()!=b.size())
	return 0;
	int total=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=b[i])
		total++;
	}
	if(total==1)
	return 1;
	return 0;
	
}


int bfs(int x, int y)
{  while(!Q.empty())
	Q.pop();
	
	int i;
	for(i=0;i<d.size();i++)
		d[i]=MAX_INT;
	d[x]=0;
	Q.push(x);
	
	while(!Q.empty())
	{
		i=Q.front();

		Q.pop();
		for(int j=0;j<E[i].size();j++)
		{
			if(d[E[i][j]]==MAX_INT)
			{  
				d[E[i][j]]=d[i]+1;
				Q.push(E[i][j]);	
			}	
		}	
	}
	if(d[y]==MAX_INT)
	return -1;	

	return d[y];
}



int main()
{
   string dict[202],temp,start,end;
   int i,j,t,x,y,ans,n;
   
   cin>>t;
   
   
   do{ n=0; 
   		E.clear();
   	
   	cin>>dict[n];
  
   	while(dict[n]!="*")
   	{
   		n++;
   		cin>>dict[n];
		
	}
	d.resize(n);
	E.resize(n);
   		for(i=0;i<n;i++)
		   {
		   		for(j=i+1;j<n;j++)
		   		{
		   			if(diff(dict[i],dict[j]))
					   {
					   addEdge(i,j);
					   addEdge(j,i);
						}
				}
			}

	cin.ignore();
	
	
	while(getline(cin,temp))
	{
		if(temp.empty())
		break;
		start=end="";
		int flag=0;
		i=0;
		for(i=0;i<temp.size();i++)
			{	if(flag)
				end+=temp[i];
				
				else if(temp[i]==' ')
					flag=1;
				else
				start+=temp[i];
				
				
			}
		
	for(i=0;i<n;i++)
	{
		
		
	if(dict[i]==start)
		x=i;
	else if(dict[i]==end)
		y=i;
	}

	
	
	ans=bfs(x,y);
	cout<<start<<" "<<end<<" "<<ans<<"\n";
	
	
	}
    if(t>1)
	cout<<"\n";

   }while(--t);
   
return 0;
}
