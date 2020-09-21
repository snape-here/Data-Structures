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

const int maxSize = 2e5+5;

int size;
int H[maxSize];    // H is the array to store the Tree.
vector<pi> v;

int cnt = 0;

int parent(int i)
{
    return (i-1)/2;
}

int left_child(int i)
{
    return 2*i+1;
}

int right_child(int i)
{
    return 2*i+2;
}

void ShiftUp(int i)
{
    while(i>0 && H[parent(i)] > H[i])
    {
        swap(H[parent(i)],H[i]);
        v.pb({i,parent(i)});
        cnt++;
        i = parent(i);
    }
}

void ShiftDown(int i)
{
    int maxIndex = i;
    int l = left_child(i);
    if (l < size && H[l] < H[maxIndex])
        maxIndex = l;
    int r = right_child(i);
    if (r < size && H[r] < H[maxIndex])
        maxIndex = r;
    if(i != maxIndex)
    {
        swap(H[i],H[maxIndex]);
        v.pb({i,maxIndex});
        cnt++;
        ShiftDown(maxIndex);
    }
}

void Insert(int i)
{
    size += 1;
    H[size] = i;
    ShiftUp(size);
}

int ExtractMin()
{
    int res = H[0];
    H[0] = H[size-1];
    size -= 1;
    ShiftDown(1);

    return res;
}

void remove(int i)
{
    H[i] = inf;
    ShiftUp(i);
    ExtractMin();
}

void Change_Priority(int i, int p)
{
    int oldp = H[i];
    H[i] = p;
    if (p < oldp)
        ShiftUp(i);
    else
        ShiftDown(i);
}

void BuildHeap(int arr[], int n)
{
    size = n;
    for(int i=size/2 ; i>=0 ; i--)
        ShiftDown(i);
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);


    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>H[i];

    BuildHeap(H,n);

    cout<<cnt<<endl;
    for(auto it: v)
        cout<<it.ff<<" "<<it.ss<<endl;
 
    return 0;
   
}