//Bfs traversal of graph
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    vector<int> bfs(int V,vector<int>adj[])
    {
        int vis[V]={0};
        vis[1]=1;
        queue<int>q;
        q.push(1);
        vector<int>bfs;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it: adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};
int main()
{
     int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];

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
    vector<int>ans;
    Solution obj;
    ans=obj.bfs(n,adj);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
