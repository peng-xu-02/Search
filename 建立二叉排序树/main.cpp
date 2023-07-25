//����������������˳��Ķ��������ٶ����������У����ڵ���������ϵ�Ԫ�ض�С�ڸ��ڵ㣬�������ϵ����ݶ����ڸ��ڵ㡣
//����ʱ��Ҳ��ѭ���������������ʡ��������������ʱ�������������У� 
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef int Elemtype;

typedef struct Binarysorttree{      //�����������ṹ 
	Elemtype data;
	struct Binarysorttree *lchild,*rchild;
}Sorttree,*Bsorttree;

Sorttree *SearchTree(Bsorttree &T,Elemtype e){   //�������������ң������ҵ��Ķ������ڵ㣻 
	if(T==NULL) return NULL;
	Sorttree *p=T;
	while(p){
		if(e == p->data)  return p;
		else if(e<p->data) p=p->lchild;
		else p=p->rchild;
	}
	return NULL;
	
}

Sorttree *SearchTree1(Bsorttree &T,Elemtype e){       //�ݹ���Ҷ����������� 
	if(T==NULL) return NULL;
	if(e==T->data)   return T;
	if(e<T->data) return SearchTree(T->lchild,e);
	else return SearchTree(T->rchild,e);
}

void creatsorttree(Bsorttree &T,Elemtype data){ //�ǵݹ齨������������ 
	if(T==NULL){        //�����Ϊ�գ���ô�²���Ľڵ���Ǹ��ڵ㣻 
		T=new Sorttree;
		T->data=data;
		T->lchild=NULL;
		T->rchild=NULL;
	}
	Sorttree *p=SearchTree1(T,data);  //���Ҳ���Ľڵ��Ƿ��Լ����ڣ��Ѿ����ھ������ٲ��룻 
	if(p==NULL){
		Sorttree *q=T;
		bool flag=true;
		while(flag){
			flag=false;
			if(data<q->data &&q->lchild){  //����²����ֵС�ڵ�ǰ�ڵ㣬���ҵ�ǰ�ڵ�����Ӳ�Ϊ�գ��ͱȽ��������ӽڵ㣻 
				q=q->lchild;
				flag=true;
				
			} 
			if(data>q->data && q->rchild){   // ����²����ֵ���ڵ�ǰ�ڵ㣬���ҵ�ǰ�ڵ���Һ��Ӳ�Ϊ�գ��ͱȽ������Һ��ӽڵ㣻 
				q=q->rchild;
				flag=true;
				
			} 
		}
		//�ҵ�Ҫ��������ݵ�˫�׽ڵ㣬Ȼ���ٿ����뵽�������ӻ����Һ��ӣ� 
		if(data<q->data){   
			Sorttree *m=new Sorttree;
			m->data=data;
			m->lchild=NULL;
			m->rchild=NULL;
			q->lchild=m;
		}
		else{
			Sorttree *m=new Sorttree;
			m->data=data;
			m->lchild=NULL;
			m->rchild=NULL;
			q->rchild=m;
			
		}
		
	}
	
}

void creattree(Bsorttree &T,Elemtype e){       //�ݹ齨�������������� 
	if(T==NULL) {         //��Ϊ�ջ��ߺ����ҵ�Ҫ�����λ���ˣ��Ͳ���ڵ㣻 
		T=new Sorttree;
		T->data=e;
		T->lchild=NULL;
		T->rchild=NULL;
		return;
	}
	if(e<T->data){
		creattree(T->lchild,e);
	}
	else{
		creattree(T->rchild,e);
	}
}



void display(Bsorttree &T){   //�������������������������������У� 
	if(T==NULL)  return;
	display(T->lchild);
	cout<<T->data<<' ';
	display(T->rchild);
}


int main(){
	Bsorttree T;
	cout<<"������Ҫ�����������������ܽڵ�����"<<endl;
	int total;
	cin>>total;
    for(int i=0;i<total;i++){
    	cout<<"�������"<<i+1<<"�����ݣ�"<<endl;
    	Elemtype data;
    	cin>>data;
    	creatsorttree(T,data);
    	//creattree(T,data);
	}
	display(T);

	
	return 0;
}
