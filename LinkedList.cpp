#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
typedef struct SinhVien{
	char MSSV[16],Ten[30],XepLoai;
	float Toan,Ly,Hoa;
} SV;
typedef struct Node{
	SV data;
	Node *next;
} *List;
Node* Create(SV data){
	Node *p=new Node;
	p->data=data;
	p->next=NULL;
	return p;
}
void Init(List &L){
	L=NULL;
}
SV Nhap_Mot_SV(){
	SV t;
	printf("Nhap ma so sinh vien: ");
	gets(t.MSSV);
	gets(t.MSSV);
	printf("Nhap ten sinh vien: ");
	gets(t.Ten);
	printf("Nhap diem mon toan: ");
	scanf("%f",&t.Toan);
	printf("Nhap diem mon Ly: ");
	scanf("%f",&t.Ly);
	printf("Nhap diem mon Hoa: ");
	scanf("%f",&t.Hoa);
	float DTB=(t.Toan+t.Ly+t.Hoa)/3;
	if (DTB>=9.0) t.XepLoai='X';
	else if (DTB>=8) t.XepLoai='G';
	else if (DTB>=7) t.XepLoai='K';
	else if (DTB>=4) t.XepLoai='T';
	else t.XepLoai='Y';
	return t;
}
void Xuat_Mot_SV(SV t){
	printf("Ma so sinh vien: %s\n",t.MSSV);
	printf("Ho Va Ten: %s\n",t.Ten);
	printf("Diem mon Toan: %.2f\n",t.Toan);
	printf("Diem mon Ly: %.2f\n",t.Ly);
	printf("Diem mon Hoa: %.2f\n",t.Hoa);
	printf("\n");
}
void Xuat_DS(List L){
	system("cls");
	Node *p=L;
	if (p==NULL){
		printf("Danh sach rong!\n");
		return;
	}
	while (p!=NULL){
		Xuat_Mot_SV(p->data);
		p=p->next;
	}
	system("pause");
}
void Insert_First(List &L){
	Node *p;
	p=Create(Nhap_Mot_SV());
	p->next=L;
	L=p;
}
Node* Search(List L,char s[]){
	Node *p=L;
	SV t;
	while (p!=NULL){
		t=p->data;
		if (strcmp(t.MSSV,s)==0) return p;
		p=p->next;
	}
	return NULL;
}
void Sap_Xep(List &L){
	Node *i,*j;
	for (i=L;i->next->next!=NULL;i=i->next)
		for (j=i->next;j->next!=NULL;j=j->next)
			if (strcmp(i->data.Ten,j->data.Ten)>0){
				SV t;
				t=i->data;
				i->data=j->data;
				j->data=t;
			}
}
int main(){
 	List l;
 	Init(l);
 	int Lua_Chon;
 	do{
 		system("cls");
    	printf("1: Chen them 1 sinh vien\n");
    	printf("2: Xuat danh sach sinh vien\n");
    	printf("3: Tim kiem sinh vien theo MSSV\n");
    	printf("4: Sap xep danh sach theo ten sinh vien\n");
    	printf("5: Thoat\n");
    	printf("Moi ban nhap lua chon: ");
    	scanf("%d",&Lua_Chon);
    	switch (Lua_Chon){
    		case 1:{
    			Insert_First(l);
    			break;
    		}
    		case 2:{
    			Xuat_DS(l);
    			break;
    		}
    		case 3:{
    			char c[16];
    			printf("Nhap ma so sinh vien can tim: ");
    			gets(c);
    			gets(c);
    			Node *t=Search(l,c);
    			if (t==NULL) printf("Khong tim thay!\n");
    			else Xuat_Mot_SV(t->data);
    			break;
    		}
    		case 4:{
    			Sap_Xep(l);
    			break;
    		}
    		case 5: break;
    	}
    } while (Lua_Chon!=5);
	return 0;
}

