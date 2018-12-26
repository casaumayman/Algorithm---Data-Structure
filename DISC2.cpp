#include<bits/stdc++.h>
using namespace std;
struct List
{
	int key;
	List *next,*back;
};
List *Create(int k)
{
	List *l=new List;
	l->key=k;
	l->next=l->back=NULL;
	return l;
}
List *k[100001];
int n,m;
void Process()
{
	cin>>n>>m;
	k[n]=Create(n);
	List *head=k[n];
	for (int i=n-1;i>=1;i--)
	{
		k[i]=Create(i);
		k[i]->back=k[i+1];
		k[i+1]->next=k[i];
	}
	k[n]->back=k[1];
	k[1]->next=k[n];
	int x;
	for (int i=1;i<=m;i++)
	{
		cin>>x;
		if (x==head->key) head=head->next;
		else if (x==head->back->key);
		else
		{
			int B=k[x]->back->key;
			int N=k[x]->next->key;
			k[B]->next=k[N];
			k[N]->back=k[B];
			B=head->back->key;
			k[x]->back=k[B];
			k[x]->next=head;
			head->back=k[x];
			k[B]->next=k[x];
		}
		//cout<<k[x]->back->key<<" "<<x<<" "<<k[x]->next->key<<" head: "<<head->key<<"\n";
		//cout<<head->key<<" ";
	}
	head=head->back;
	cout<<head->key<<" ";
	for (List *i=head->back;i!=head;i=i->back)
		cout<<i->key<<" ";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("C:\\Users\\ADMIN\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\ADMIN\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}

