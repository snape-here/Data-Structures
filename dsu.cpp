#include<bits/stdc++.h> 
using namespace std;
 
#define ull unsigned long long
#define int long long
#define ld long double
#define pb push_back
#define pi  pair< int,int >
#define ff first
#define ss second
#define mod 1000000007
#define inf 300000000000000007
#define endl "\n"

const int N=5e5+5;

int n,a,b;

int parent[N];

int Rank[N];
int sz[N];

int find(int n)
{
    if(n != parent[n])
        parent[n] = find(parent[n]);
    return parent[n];
}

void make_set(int v)
{
    parent[v] = v;
    Rank[v] = 0;
    sz[v] = 1;
}

void Union(int a, int b)
{
    int i = find(a);
    int j = find(b);
    if (i == j)
        return;
    if (Rank[i] > Rank[j])
    {
        parent[j] = i;
        sz[i] += sz[j];
    }
    else
    {
        parent[i] = j;
        if (Rank[i] == Rank[j])
            Rank[j] += 1;
        sz[j] += sz[i];
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int m,k,x,y;
 
    cin>>n>>m;
 
    for(int i=1;i<=n;i++)
        make_set(i);
    
    for(int i=0;i<m;i++)
    {
        cin>>k;
        if(k)
        {
            cin>>x;
            for(int i=1;i<k;i++)
            {
                cin>>y;
                Union(x,y);
            }
        }
    }
 
    for(int i=1;i<=n;i++)
        cout<<sz[find(i)]<<" ";
 
    return 0;
   
}