#include<iostream>
using namespace std;

typedef int Elemtype;

typedef struct Searchtable{   //������ұ� 
	Elemtype *data;
	int length;
	
}Stable;

void creatSearchtable(Stable &T,int m){   //������ 
	if(m<1) return;
	T.data=new Elemtype[m];
	T.length=0;
	for(int i=0;i<m;i++){
		cout<<"�������"<<i+1<<"�����ݣ�"<<endl;
		cin>>T.data[i];
		T.length++;
	}	
}

void sort(Stable &T){               //���� 
	for(int i=0;i<T.length-1;i++){
		for(int j=0;j<T.length-i-1;j++){
			if(T.data[j]>T.data[j+1]){
				int data=T.data[j];
				T.data[j]=T.data[j+1];
				T.data[j+1]=data;
			}           
		}
	}
}

int Binarysearch(Stable &T,Elemtype data){   //���ַ����ң� 
	int low=0,high=T.length-1;     //������ַ��Ĳ��ҷ�Χ�� 
	while(low<=high){
		int mid=(low+high)/2;
		if(T.data[mid]==data) return mid;
		if(T.data[mid]<data) low=mid+1;
		else  high=mid-1;
	}
	
	return -1;
}

void display(Stable &T){         //��ӡ���ұ� 
	for(int i=0;i<T.length;i++){
		cout<<T.data[i]<<" ";
	}
}



int main(){
	Stable T;
	creatSearchtable(T,6);
	display(T);
	sort(T);
	cout<<endl;
	display(T);
	int data;
	cout<<"������Ҫ���ҵ�����"<<endl;
	cin>>data;
	int k=Binarysearch(T,data);
	if(k==-1) cout<<"����û�������"<<data;
	else cout<<data<<"�Ǳ��е�"<<k+1<<"����";
	
	
	return 0;
} 
