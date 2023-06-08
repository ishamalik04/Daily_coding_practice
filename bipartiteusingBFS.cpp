// check if a graph is bipartite using BFS
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    bool checkbp(int start,int n,vector<int>adj[],int col[])
    {
        queue<int>q;
        q.push(start);
        col[start]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it: adj[node])
            {
                if(col[it]==-1)
                {
                    col[it]=!col[node];
                    q.push(it);
                }
                else if(col[it]==col[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    int col[n];
    int start=3;
    vector<int>ls;
    for(int i=0;i<n;i++)
    {
        col[i]=-1;
    }
    for(int i=1;i<m+1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n+1;i++)
    {

        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
    Solution obj;
    for(int i=0;i<n;i++)
    {
        if(col[i]==-1)
        {
            if(obj.checkbp(i,n,adj,col)==false)
            {
                cout<<"NOT BIPARTItE";
                return 0;
            }
        }
    }
    cout<<"YES, BIPARTIte";
    return 0;
}
