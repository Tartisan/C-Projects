#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

typedef char ElemType;

struct BTreeNode{
	ElemType data;
    BTreeNode *left;
	BTreeNode *right;
};

/*
初始化二叉树
*/
void InitBTree(BTreeNode*& BT){
	BT = NULL;
}

/*
根据广义表表示的二叉树建立对应的存储结构
*/
void CreateBTree(BTreeNode*& BT, char* a){
	const int MaxSize = 10;
	BTreeNode *s[MaxSize];
	int top = -1;
	BT = NULL;
	BTreeNode *p;
	int k;
	int i = 0;
	while(a[i]){
		switch(a[i]){
		case ' ':
			break;
		case '(':
			if(top == MaxSize-1){
				printf("栈的空间太小，请增加MaxSize的值\n");
				exit(1);
			}
			top++;
			s[top] = p;
			k = 1;
			break;
		case ')':
			if(top == -1){
				printf("二叉树广义表字符串错！\n");
				exit(1);
			}
			top--;
			break;
		case ',':
			k = 2;
			break;
		default:
			p = new BTreeNode;
			p->data = a[i];
			p->left = p->right = NULL;
			if(BT == NULL)
				BT = p;
			else{
				if(k == 1)
					s[top]->left = p;
				else
					s[top]->right = p;
			}
		}
		i++;
	}
}

/*
判断一棵二叉树是否为空，若是则返回ture，否则返回false
*/
bool EmptyBTree(BTreeNode* BT){
	return BT = NULL;
}

int DepthBTree(BTreeNode* BT){
	if(BT == NULL)
		return 0;
	else{
		int dep1 = DepthBTree(BT->left);
		int dep2 = DepthBTree(BT->right);
		if(dep1 > dep2)
			return dep1 + 1;
		else
			return dep2 + 1;
	}
}

/*
从二叉树中查找值为x的结点，若存在该结点则由x带回它的完整值
*/
bool FindBTree(BTreeNode* BT,ElemType &x){   
	if(BT == NULL)
		return false;
	else{
		if(BT->data == x){
			x = BT->data;
			return true;
		}
		else{
			if(FindBTree(BT->left, x))
				return true;
            if(FindBTree(BT->right, x))
                return true;
			    return false;
		}
	}
}

/*
按照树的一种表示方法输出一棵二叉树
*/
void PrintBTree(BTreeNode*BT){
	if(BT != NULL){
		std::cout << BT->data;
		if(BT->left != NULL || BT->right != NULL){
			std::cout << '(';
			PrintBTree(BT->left);
			if(BT->right != NULL)
				std::cout << ',';
			PrintBTree(BT->right);
			std::cout << ')';
		}
	}
}

/*
清除二叉树中的所有结点，使之变为一棵空树
*/
void ClearBTree(BTreeNode* &BT){
	if(BT != NULL){
		ClearBTree(BT->left);
		ClearBTree(BT->right);
		delete BT;
		BT = NULL;
	}
}

void PreOrder(BTreeNode*BT){
	if(BT != NULL){
		std::cout << BT->data << ' ';
		PreOrder(BT->left);
		PreOrder(BT->right);
	}
}

void InOrder(BTreeNode*BT){
	if(BT != NULL){
		InOrder(BT->left);
		std::cout << BT->data << ' ';
		InOrder(BT->right);
	}
}

void PostOrder(BTreeNode*BT){
	if(BT != NULL){
		PostOrder(BT->left);
		PostOrder(BT->right);
		std::cout << BT->data << ' ';
	}
}

/*
按层遍历由BT指针所指向的二叉树
*/
void LevelOrder(BTreeNode*BT){
	const int MaxSize=30;        //定义用于存储队列的数组长度
	BTreeNode*q[MaxSize];        //定义队列所使用的数组空间
	int front=0, rear=0;         //定义队首指针和队尾指针，初始为空队
	BTreeNode*p;
	if(BT!=NULL){                //将树根指针进队
		rear=(rear+1)%MaxSize;
		q[rear]=BT;
	}
	while(front!=rear){          //当队列非空时执行循环
		front=(front+1)%MaxSize;  //使队首指针指向队首元素
		p=q[front];                //删除队首元素
		cout<<p->data<<' ';       //输出队首元素所指结点的值
		if(p->left!=NULL){
			rear=(rear+1)%MaxSize;
			q[rear]=p->left;
		}
		if(p->right!=NULL){
			rear=(rear+1)%MaxSize;
			q[rear]=p->right;
		}
	}   //while end//
}

void main(){
	system("color 75");   //设置颜色以美观
	BTreeNode* bt;
	InitBTree(bt);
	char b[999];
	printf("输入二叉树广义表字符串:\n");
	std::cin.getline(b,sizeof(b));
	CreateBTree(bt,b);
	PrintBTree(bt);
	std::cout << std::endl;
	printf("递归算法遍历：\n");
	std::cout << "前序遍历为：";
	PreOrder(bt);
	std::cout << std::endl;
    std::cout << "中序遍历为：";
	InOrder(bt);
	std::cout << std::endl;
	std::cout << "后序遍历为：";
	PostOrder(bt);
	std::cout << std::endl;
	printf("非递归算法遍历：\n");
	std::cout << "按层遍历为：";
	LevelOrder(bt);
	std::cout << std::endl;
	ElemType x;
	printf("请输入待查字符:");
	scanf("%c",&x);
	if(FindBTree(bt,x))
		printf("查找字符%c成功",x);
	else
		printf("查找字符%c失败",x);
	printf("\n");
	std::cout << " 树的深度为:";
	std::cout << DepthBTree(bt) << std::endl;
	ClearBTree(bt);
}
