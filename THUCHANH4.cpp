#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct SV
{
	char ma[10];
	char ten[40];
	float diem;
};
struct Node
{
	SV info;
	Node *next;
};
Node *CreateNode(SV a)
{
	Node *p=new Node;
	p->info=a;
	p->next=NULL;
	return p;
}
void init(Node* &phead)
{
	phead=NULL;
}
void Nhap1sv(SV &a)
{
	printf("Nhap ma sinh vien: ");
	fflush(stdin);
	gets(a.ma);
	printf("Nhap ten sinh vien: ");
	fflush(stdin);
	gets(a.ten);
	printf("Nhap diem trung binh: ");
	scanf("%f",&a.diem);
}
void Xuat1sv(SV a)
{
	printf("%s\t%s\t%.2f\n",a.ma,a.ten,a.diem);
}
int isEmpty(Node* phead)
{
	return (phead==NULL);
}
void InsertFirst(Node* &phead,SV a)
{
	if (isEmpty(phead))
		phead=CreateNode(a);
	else
	{
		Node *p=CreateNode(a);
		p->next=phead;
		phead=p;
	}
}
void InsertLast(Node* &phead,SV a)
{
	if (isEmpty(phead))
		phead=CreateNode(a);
	else
	{
		Node *p=phead;
		while (p->next) p=p->next;
		p->next=CreateNode(a);
	}
}
void InsertAfter(Node* &phead,SV a)
{
	if (!phead->next)
		phead->next=CreateNode(a);
	else
	{
		Node *p=CreateNode(a);
		p->next=phead->next;
		phead->next=p;
	}
}
void ShowList(Node* phead)
{
	if (isEmpty(phead))
		printf("Danh sach rong!\n");
	else
	{
		Node *p=phead;
		printf("MaSV	TenSV	DiemTB\n");
		while (p)
		{
			Xuat1sv(p->info);
			p=p->next;
		}
	}
}
void ShowListDTB(Node *phead)
{
	if (isEmpty(phead))
		printf("Danh sach rong!\n");
	else
	{
		Node *p=phead;
		printf("MaSV	TenSV	DiemTB\n");
		while (p)
		{
			SV a=(p->info);
			if (a.diem>5) Xuat1sv(a);
			p=p->next;
		}
	}
}
void SinhDS(Node* &phead)
{
	SV DS[5]={{"10","Huynh",9},
		{"02","Huy",5},
		{"07","Tuan",7},
		{"05","Phuong",2},
		{"46","Tuan",8}
	};
	for (int i=0;i<5;i++) InsertLast(phead,DS[i]);
}
void NhapDS(Node* &phead,int &n)
{
	SV x;
	printf("Nhap so luong sinh vien: ");
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		Nhap1sv(x);
		InsertLast(phead,x);
	}
}
void NhapDSMenu(Node* &phead)
{
	int chon;
	SV x;
	do
	{
		system("cls");
		printf("1: Them 1 sinh vien vao dau\n");
		printf("2: Them 1 sinh vien vao cuoi\n");
		printf("3: Xuat danh sach\n");
		printf("0: Thoat\n");
		printf("Hay chon cong viec: "); scanf("%d",&chon);
		switch (chon)
		{
			case 1:
				printf("Nhap thong tin sinh vien can chen\n");
				Nhap1sv(x);
				InsertFirst(phead,x);
				break;
			case 2:
				printf("Nhap thong tin sinh vien can chen\n");
				Nhap1sv(x);
				InsertLast(phead,x);
				break;
			case 3:
				ShowList(phead);
				getch();
				break;
			default: chon=0; break;
		}
	} while (chon);
}
Node *TimsvX(Node* phead,char x[])
{
	Node *p=phead;
	while (p)
	{
		if (!strcmp(x,(p->info).ma))
			return p;
		p=p->next;
	}
	return NULL;
}
void InsertAfterX(Node* &phead,char x[])
{
	SV a;
	printf("Nhap thong tin sinh vien can chen:\n");
	Nhap1sv(a);
	Node *p=TimsvX(phead,x);
	InsertAfter(p,a);
}
void swap(SV &a,SV &b)
{
	SV t=a;
	a=b;
	b=t;
}
void InterchangeSort(Node* phead)//Sap xep theo diem trung binh
{
	for (Node *p=phead;p->next;p=p->next)
		for (Node *k=p->next;k;k=k->next)
			if ((p->info).diem>(k->info).diem) swap(p->info,k->info);
}
void DeleteFirst(Node* &phead)
{
	if (isEmpty(phead)) return;
	Node *p=phead;
	phead=phead->next;
	delete p;
}
void DeleteLast(Node* &phead)
{
	if (isEmpty(phead)) return;
	Node *p=phead,*back=NULL;
	while (p->next)
	{
		back=p;
		p=p->next;
	}
	if (back) back->next=NULL;
	delete p;
}
void DeleteList(Node* &phead)
{
	while (!isEmpty(phead)) DeleteFirst(phead);
}
void DeletesvX(Node* &phead,char x[])
{
	if (!strcmp((phead->info).ma,x))
	{
		DeleteFirst(phead);
		return;
	}
	Node *p=phead,*back=NULL;
	while (p->next)
	{
		back=p;
		p=p->next;
		if (!strcmp((p->info).ma,x))
		{
			back->next=p->next;
			delete p;
			return;
		}
	}
}
void DeletesvAfterX(Node* &phead,char x[])
{
	Node *p=TimsvX(phead,x);
	if (p)
	{
		Node *t=p->next;
		if (t)
		{
			p->next=t->next;
			delete t;
		}
		else return;
	}
	return;
}
void DeleteAllsvX(Node* &phead,char x[])
{
	while (!strcmp((phead->info).ten,x)) DeleteFirst(phead);
	Node *p=phead->next,*back=phead;
	while (p)
	{
		if (!strcmp((p->info).ten,x))
		{
			back->next=p->next;
			delete p;
			p=back;
		}
		back=p;
		p=p->next;
	}
}
void SortTheoMa(Node* phead)
{
	for (Node *p=phead;p->next;p=p->next)
		for (Node *k=p->next;k;k=k->next)
			if (strcmp((p->info).ma,(k->info).ma)>0) swap(p->info,k->info);
}
void DSsvKha(Node* phead)
{
	printf("MaSV	TenSV	DiemTB\n");
	for (Node *p=phead;p;p=p->next)
		if ((p->info).diem>6.5 && (p->info).diem<8) Xuat1sv(p->info);
}
void MaxDTB(Node* phead)
{
	Node *pmax=phead;
	for (Node *p=phead->next;p;p=p->next)
		if ((p->info).diem>(pmax->info).diem) pmax=p;
	printf("MaSV	TenSV	DiemTB\n"); Xuat1sv(pmax->info);
}
int Gioi(Node *p)
{
	int x=(p->info).diem;
	if (x>=8 && x<=10) return 1;
	return 0;
}
void MinDTBGioi(Node *phead)
{
	Node *pmin=(Gioi(phead))?phead:NULL;
	for (Node *p=phead->next;p;p=p->next)
		if ((p->info).diem<(pmin->info).diem && Gioi(p)) pmin=p;
	printf("MaSV	TenSV	DiemTB\n"); Xuat1sv(pmin->info);
}
void main()
{
	Node *phead;
	init(phead);
	int n;
	SinhDS(phead);
	ShowList(phead);
	MinDTBGioi(phead);
//	char x[10];
//	printf("Nhap ma sinh vien can tim: ");
//	fflush(stdin);
//	gets(x);
//	DeleteAllsvX(phead,x);
//	ShowList(phead);
	_getch();
}
