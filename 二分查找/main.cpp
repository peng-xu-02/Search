#include<iostream>
using namespace std;

typedef int Elemtype;

typedef struct Searchtable{   //定义查找表； 
	Elemtype *data;
	int length;
	
}Stable;

void creatSearchtable(Stable &T,int m){   //建立表； 
	if(m<1) return;
	T.data=new Elemtype[m];
	T.length=0;
	for(int i=0;i<m;i++){
		cout<<"请输入第"<<i+1<<"个数据："<<endl;
		cin>>T.data[i];
		T.length++;
	}	
}

void sort(Stable &T){               //排序； 
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

int Binarysearch(Stable &T,Elemtype data){   //二分法查找； 
	int low=0,high=T.length-1;     //定义二分法的查找范围； 
	while(low<=high){
		int mid=(low+high)/2;
		if(T.data[mid]==data) return mid;
		if(T.data[mid]<data) low=mid+1;
		else  high=mid-1;
	}
	
	return -1;
}

void display(Stable &T){         //打印查找表 
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
	cout<<"请输入要查找的数："<<endl;
	cin>>data;
	int k=Binarysearch(T,data);
	if(k==-1) cout<<"表中没有这个数"<<data;
	else cout<<data<<"是表中第"<<k+1<<"个数";
	
	
	return 0;
} 
