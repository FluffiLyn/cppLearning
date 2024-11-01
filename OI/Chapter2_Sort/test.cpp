#include <iostream>

using namespace std;

//二元关系 
typedef struct 
{
	char a;
	char b;
}BR;

int n, m; //n表示A集合中元素个数，m表示二元关系R中元素个数 

//创建集合A并完成初始化 
void init_aggregation(char* &A)
{
	cout << "请输入A集合中的元素个数：" << endl;
	cin >> n;
	A = new char [n];
	cout << "请依次输入A集合中元素：" << endl;
	for(int i = 0; i < n; i++) {
		cin >> A[i];
		getchar();
	}
}

//创建A集合的二元关系R的集合并完成初始化 
void init_BinaryRelation(BR* &R)
{
	cout << "请输入R中的元素个数：" << endl;
	cin >> m;
	R = new BR [n];
	cout << "请依次输入R中元素：" << endl;
	for(int i = 0; i < m; i++) {
		cin >> R[i].a;
		getchar();
		cin >> R[i].b;
	}
}

int fun(char ch,char* &A)
{
	for(int i = 0; i < n; i++) {
		if(ch == A[i]) {
			return i;
		}
	}
	return -1;
}

//核心算法 
void Warshall(char* &A,BR* &R,bool** &tR)
{
	int i, j, k;
	int x, y;
	
	//将二元关系R用关系矩阵表示 
	for(i = 0; i < m; i++) {
		x = fun(R[i].a,A);
		y = fun(R[i].b,A);
		tR[x][y] = 1;
	}
	
	//传递包闭计算过程 
	for(i = 0; i < n; i++) { //检索列 
		for(j = 0; j < n; j++) { //检索行 
			if(tR[j][i] == 1) {
				for(k = 0; k < n; k++) {
					tR[j][k] += tR[i][k]; 
				}
			}
		}
	}
}

//将传递包闭t(R)的关系矩阵表示转为集合表示 
void translation_output(char* &A,bool** &tR)
{
	cout << "求得R的传递闭包为：" << endl;
	cout << "t(R) = { "; 
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(tR[i][j] == 1) {
				cout << "(" << A[i] << "," << A[j] << ") ";
			}
		}
	}
	cout << "}" << endl;
}

int main()
{
	char *A;
	init_aggregation(A); //初始化A集合
	
	BR* R;
	init_BinaryRelation(R); //初始化二元关系
	
	bool** tR; //传递闭包矩阵
	 
	 //动态开辟bool类型的二维数组
	tR = new bool* [n];
	for(int i = 0; i < n; i++) {
		tR[i] = new bool [n*n];
	}
	
	//初始化（全赋值0）
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
		{
			tR[i][j] = 0;
		}
	}
	
	Warshall(A,R,tR);//调用Warshall算法函数
	
	translation_output(A,tR); //转译输出 
	
	return 0;
} 
