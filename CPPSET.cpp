#include<bits/stdc++.h>
#define BASE 1000000000
using namespace std;
int mins=INT_MAX,maxs=INT_MIN,dem_zero=0;
class Trie
{
	public:
		Trie *foot[4],*parent;
		int dem,value;
		Trie()
		{
			foot[3]=foot[2]=foot[1]=foot[0]=NULL;
			parent=NULL;
			dem=value=0;
		}
		void ADD(int x)
		{
			if (x>maxs) maxs=x;
			if (x<mins) mins=x;
			if (x==0) dem_zero++;
			Trie *t=this;
			int ind,c;
			for (int i=30;i>=0;i-=2)
			{
				c=x;
				ind=(c>>i)&3;
				if (t->foot[ind]==NULL) t->foot[ind]=new Trie();
				t->foot[ind]->dem++;
				t->foot[ind]->parent=t;
				t->foot[ind]->value=ind;
				t=t->foot[ind];
			}
		}
		bool EMPTY()
		{
			Trie *t=this;
			for (int i=0;i<4;i++)
				if (t->foot[i]!=NULL && t->foot[i]->dem!=0) return false;
			return true;
		}
		bool SEARCH(int x)
		{
			if (EMPTY()) return false;
			Trie *t=this;
			int ind,c;
			for (int i=30;i>=0;i-=2)
			{
				c=x;
				ind=(c>>i)&3;
				if (t->foot[ind]==NULL) return false;
				t=t->foot[ind];
				if (t->dem==0) return false;
			}
			return true;
		}
	private:
		int MINIMUM()
		{
			if (EMPTY()) return INT_MAX;
			Trie *t=this;
			int ind,sum=0;
			for (int i=30;i>=0;i-=2)
			{
				for (ind=0;ind<4;ind++)
					if (t->foot[ind] && t->foot[ind]->dem)
					{
						sum=(sum<<2)|ind;
						t=t->foot[ind];
						break;
					}
			}
			return sum;
		}
		int MAXIMUM()
		{
			if (EMPTY()) return INT_MIN;
			Trie *t=this;
			int ind,sum=0;
			for (int i=30;i>=0;i-=2)
			{
				for (ind=3;ind>=0;ind--)
					if (t->foot[ind] && t->foot[ind]->dem)
					{
						sum=(sum<<2)|ind;
						t=t->foot[ind];
						break;
					}
			}
			return sum;
		}
	public:
		void DELETE(int x)
		{
			if (!SEARCH(x)) return;
			if (x==0) dem_zero--;
			Trie *t=this;
			int ind,c;
			for (int i=30;i>=0;i-=2)
			{
				c=x;
				ind=(c>>i)&3;
				t=t->foot[ind];
				t->dem--;
			}
			if (x==mins) mins=MINIMUM();
			if (x==maxs) maxs=MAXIMUM();
		}
		int Find_Upper(Trie *t,int x)
		{
			for (int i=x+1;i<4;i++)
				if (t->foot[i] && t->foot[i]->dem) return i;
			return -1;
		}
		int Find_Lower(Trie *t,int x)
		{
			for (int i=x-1;i>=0;i--)
				if (t->foot[i] && t->foot[i]->dem) return i;
			return -1;
		}
		int UPPER(int x)
		{
			Trie *t=this;
			int ind,sum=0;
			if (x==0 && dem_zero) return x;
			if (x==0) x++;
			if (x>maxs) return -1;
			for (int i=30;i>=0;i-=2)
			{
				ind=(x>>i)&3;
				if (t->foot[ind]==NULL || t->foot[ind]->dem==0) break;
				t=t->foot[ind];
				sum=(sum<<2)|ind;
			}
			if (sum==x) return x;
			int c=Find_Upper(t,ind);
			while (c==-1)
			{
				int stt=t->value;
				t=t->parent;
				sum=(sum>>2);
				c=Find_Upper(t,stt);
			}
			t=t->foot[c];
			sum=(sum<<2)|c;
			bool loop=true;
			while (loop)
			{
				loop=false;
				for (int i=0;i<4;i++)
				{
					if (t->foot[i] && t->foot[i]->dem)
					{
						t=t->foot[i];
						sum=(sum<<2)|i;
						loop=true;
						break;
					}
				}
			}
			return sum;
		}
		int LOWER(int x)
		{
			Trie *t=this;
			int ind,sum=0;
			if (x==0 && dem_zero) return x;
			if (x==0 || x<mins) return -1;
			for (int i=30;i>=0;i-=2)
			{
				ind=(x>>i)&3;
				if (t->foot[ind]==NULL || t->foot[ind]->dem==0) break;
				t=t->foot[ind];
				sum=(sum<<2)|ind;
			}
			if (sum==x) return x;
			int c=Find_Lower(t,ind);
			while (c==-1)
			{
				int stt=t->value;
				t=t->parent;
				sum=(sum>>2);
				c=Find_Lower(t,stt);
			}
			t=t->foot[c];
			sum=(sum<<2)|c;
			bool loop=true;
			while (loop)
			{
				loop=false;
				for (int i=3;i>=0;i--)
				{
					if (t->foot[i] && t->foot[i]->dem)
					{
						t=t->foot[i];
						sum=(sum<<2)|i;
						loop=true;
						break;
					}
				}
			}
			return sum;
		}
};
int n;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	int x,res;
	Trie tree;
	do
	{
		cin>>n;
		switch (n)
		{
			case 1:
				cin>>x;
				x+=BASE;
				tree.ADD(x);
				break;
			case 2:
				cin>>x;
				x+=BASE;
				tree.DELETE(x);
				break;
			case 3:
				if (tree.EMPTY()) cout<<"empty\n"; else
				cout<<mins-BASE<<"\n";
				break;
			case 4:
				if (tree.EMPTY()) cout<<"empty\n"; else
				cout<<maxs-BASE<<"\n";
				break;
			case 5:
				cin>>x;
				x+=BASE;
				if (tree.EMPTY()) cout<<"empty\n";
				else
				{
					res=tree.UPPER(x+1);
					if (res==-1) cout<<"no\n";
					else cout<<res-BASE<<"\n";
				}
				break;
			case 6:
				cin>>x;
				x+=BASE;
				if (tree.EMPTY()) cout<<"empty\n";
				else
				{
					res=tree.UPPER(x);
					if (res==-1) cout<<"no\n";
					else cout<<res-BASE<<"\n";
				}
				break;
			case 7:
				cin>>x;
				x+=BASE;
				if (tree.EMPTY()) cout<<"empty\n";
				else
				{
					res=tree.LOWER(x-1);
					if (res==-1) cout<<"no\n";
					else cout<<res-BASE<<"\n";
				} break;
			case 8:
				cin>>x;
				x+=BASE;
				if (tree.EMPTY()) cout<<"empty\n";
				else
				{
					res=tree.LOWER(x);
					if (res==-1) cout<<"no\n";
					else cout<<res-BASE<<"\n";
				}
				break;
		}
	} while (n!=0);
	return 0;
}
