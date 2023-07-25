//二叉排序树，即有顺序的二叉数。再二叉排序树中，根节点的左子树上的元素都小于根节点，右子树上的数据都大于根节点。
//插入时，也遵循二叉排序树的性质。其中序遍历序列时递增的有序序列； 
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef int Elemtype;

typedef struct Binarysorttree{      //二叉排序树结构 
	Elemtype data;
	struct Binarysorttree *lchild,*rchild;
}Sorttree,*Bsorttree;

Sorttree *SearchTree(Bsorttree &T,Elemtype e){   //二叉排序树查找，返回找到的二叉树节点； 
	if(T==NULL) return NULL;
	Sorttree *p=T;
	while(p){
		if(e == p->data)  return p;
		else if(e<p->data) p=p->lchild;
		else p=p->rchild;
	}
	return NULL;
	
}

Sorttree *SearchTree1(Bsorttree &T,Elemtype e){       //递归查找二叉排序树； 
	if(T==NULL) return NULL;
	if(e==T->data)   return T;
	if(e<T->data) return SearchTree(T->lchild,e);
	else return SearchTree(T->rchild,e);
}

void creatsorttree(Bsorttree &T,Elemtype data){ //非递归建立二叉排序树 
	if(T==NULL){        //如果树为空，那么新插入的节点就是根节点； 
		T=new Sorttree;
		T->data=data;
		T->lchild=NULL;
		T->rchild=NULL;
	}
	Sorttree *p=SearchTree1(T,data);  //查找插入的节点是否以及存在，已经存在就无需再插入； 
	if(p==NULL){
		Sorttree *q=T;
		bool flag=true;
		while(flag){
			flag=false;
			if(data<q->data &&q->lchild){  //如果新插入的值小于当前节点，并且当前节点的左孩子不为空，就比较它的左孩子节点； 
				q=q->lchild;
				flag=true;
				
			} 
			if(data>q->data && q->rchild){   // 如果新插入的值大于当前节点，并且当前节点的右孩子不为空，就比较它的右孩子节点； 
				q=q->rchild;
				flag=true;
				
			} 
		}
		//找到要插入的数据的双亲节点，然后再看插入到它的左孩子还是右孩子； 
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

void creattree(Bsorttree &T,Elemtype e){       //递归建立二叉排序树； 
	if(T==NULL) {         //树为空或者后续找到要插入的位置了，就插入节点； 
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



void display(Bsorttree &T){   //中序遍历二叉排序树，结果是有序序列； 
	if(T==NULL)  return;
	display(T->lchild);
	cout<<T->data<<' ';
	display(T->rchild);
}


int main(){
	Bsorttree T;
	cout<<"请输入要建立二叉排序树的总节点数："<<endl;
	int total;
	cin>>total;
    for(int i=0;i<total;i++){
    	cout<<"请输入第"<<i+1<<"个数据："<<endl;
    	Elemtype data;
    	cin>>data;
    	creatsorttree(T,data);
    	//creattree(T,data);
	}
	display(T);

	
	return 0;
}
