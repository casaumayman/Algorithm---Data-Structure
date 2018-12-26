#include<bits/stdc++.h>
using namespace std;
int n,tim;
vector <int> a[100001];
struct query{
	int start_time,end_time,idx;
} q[100001];
bool visited[100001];
int cl[100001];
int flat_tree[200002];
int last_visit[200002],bit[200002];
bool cmp(query a,query b)
{
	return (a.end_time<b.end_time);
}
void compressed()
{
	pair <int,int> com[100001];
	for (int i=1;i<=n;i++){
		com[i].first=cl[i];
		com[i].second=i;
	}
	sort(com+1,com+n+1);
	int dem=1;
	com[1].first=1;
	cl[com[1].second]=1;
	for (int i=2;i<=n;i++){
		if (com[i].first!=com[i-1].first) dem++;
		cl[com[i].second]=dem;
	}
}
void Input(){
	cin>>n;
	int u,v;
	for (int i=1;i<n;i++){
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i=1;i<=n;i++){
		cin>>cl[i];
	}
	compressed();
}
void DFS(int u){
	visited[u]=true;
	q[u].start_time=++tim;
	flat_tree[q[u].start_time]=cl[u];
	for (int i=0;i<a[u].size();i++){
		int v=a[u][i];
		if (!visited[v]) DFS(v);
	}
	q[u].end_time=++tim;
	flat_tree[q[u].end_time]=cl[u];
	q[u].idx=u;
}
void update(int index,int value)
{
	while (index<=2*n){
		bit[index]+=value;
		index+=index&(-index);
	}
}
int getsum(int index)
{
	int t=0;
	while (index>0){
		t+=bit[index];
		index-=index&(-index);
	}
	return t;
}
void Process(){
	Input();
	DFS(1);
	sort(q+1,q+n+1,cmp);
	int res[100001],count_query=1;
	memset(last_visit,-1,sizeof(last_visit));
	for (int i=1;i<=2*n;i++){
		if (last_visit[flat_tree[i]]!=-1){
			//cout<<"if update "<<last_visit[flat_tree[i]]<<": -1"<<"\n";
			update(last_visit[flat_tree[i]],-1);
		}
		last_visit[flat_tree[i]]=i;
		update(i,1);
		//cout<<"update "<<i<<": 1"<<"\n";
		if (q[count_query].end_time==i){
			res[q[count_query].idx]=getsum(i)-getsum(q[count_query].start_time-1);
			count_query++;
		}
	}
	for (int i=1;i<=n;i++) cout<<res[i]<<"\n";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("C:\\Users\\Public\\Desktop\\INPUT.txt","r",stdin);
	//freopen("C:\\Users\\Public\\Desktop\\OUTPUT.txt","w",stdout);
	Process();
	return 0;
}
