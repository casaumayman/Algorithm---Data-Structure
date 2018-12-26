#include<bits/stdc++.h>
using namespace std;
const long long BASE=1e14;
class Trie
{
	private:
		Trie *foot[4];
		int dem;
	public:	
		Trie()
		{
			for (int i=0;i<4;i++) foot[i]=NULL;
			dem=0;
		}
		void INSERT(long long x)
		{
			Trie *t=this;
			int ind;
			for (int i=62;i>=0;i-=2)
			{
				ind=(x>>i)&3;
				if (!t->foot[ind]) t->foot[ind]=new Trie();
				t->foot[ind]->dem++;
				t=t->foot[ind];
			}
		}
		int LOWER(long long k)
		{
			Trie *t=this;
			int ind,sum=0;
			for (int i=62;i>=0;i-=2)
			{
				ind=(k>>i)&3;
				for (int u=0;u<ind;u++)
					if (t->foot[u]) sum+=t->foot[u]->dem;
				if (!t->foot[ind] || t->foot[ind]->dem==0) break;
				t=t->foot[ind];
			}
			return sum;
		}
};
long long L,R;
int n;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	cin>>n>>L>>R;
	long long x,y,res=0,sum=BASE;
	Trie tree;
	tree.INSERT(sum);
	for (int j=1;j<=n;j++)
	{
		cin>>x;
		sum+=x;
		x=tree.LOWER(sum-L+1);
		y=tree.LOWER(sum-R);
		tree.INSERT(sum);
		//cout<<x<<" "<<y<<" "<<i+1<<"\n";
		res+=(x>y)?(x-y):0;
	}
	cout<<res;
	return 0;
}

