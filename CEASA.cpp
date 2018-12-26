int k;
string s;
char parse(char c)
{
	int i=c-k;
	if (i<97) i+=123-97;
	return char(i);
}
int main()
{
	cin>>s>>k;
	for (int i=0;i<s.size();i++)
		s[i]=parse(s[i]);
	cout<<s;
	return 0;
}
