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

const int N=1e5+5;
const int BLOCK=sqrt(N)+1;

struct query
{
	int l;
	int r;
	int i;
};

query Q[N];

int ar[N],ans[N];
int fre[10*N];
int po=0,k,res;

bool comp(query a , query b)
{
	if(a.l/BLOCK != b.l/BLOCK)
		return a.l/BLOCK < b.l/BLOCK;

	return a.r < b.r;
}

void add(int pos)
{
	res += fre[pos^k];
	fre[pos]++;
}

void remove(int pos)
{
	fre[pos]--;
	res -= fre[pos^k];
}

int pre[N];

signed main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n , q;
	cin>>n>>q>>k;
	for(int i=0;i<n;i++)
		cin>>ar[i];

	pre[0]=ar[0];
	for(int i=1;i<n;i++)
		pre[i]=pre[i-1]^ar[i];

	for(int i=0;i<q;i++){
		cin>>Q[i].l>>Q[i].r;
		Q[i].i = i , Q[i].l-- , Q[i].r--;
	}
 
	sort(Q , Q+q , comp);

	int ML = 0 , MR = -1;
	for(int i=0;i<q;i++)
	{
		int L = --Q[i].l;
		int R = Q[i].r;

		while(ML < L)
			remove(pre[ML++]);
 
		while(ML > L)
			add(pre[--ML]);
 
		while(MR < R)
			add(pre[++MR]);
 
		while(MR > R)
			remove(pre[MR--]);
 
		ans[Q[i].i] = res;
	}
 
	for(int i=0;i<q;i++)
		cout<<ans[i]<<'\n';

    return 0;
}