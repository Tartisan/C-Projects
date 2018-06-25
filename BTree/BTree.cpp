#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef char ElemType;

struct BTreeNode {
    ElemType data;
    BTreeNode *left;
    BTreeNode *right;
};

void InitBTree(BTreeNode *BT){ // 初始化二叉树
    BT = NULL;
}

void CreateBTree(BTreeNode *BT, char *a){ // 建立二叉树
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
                if(top == MaxSize - 1){
                    std::cout << "栈的空间太小，请增加MaxSize的值\n" << std::endl;
                    exit(1);
                }
                top ++;
                s[top] = p;
                k = 1;
                break;
            case ',':
                k = 2;
                break;
            default:
                p = new BTreeNode;
                p -> data = a[i];
                p -> left = p -> right = NULL;
                if(BT == NULL)
                    BT = p;
                else{
                    if(k == 1)
                        s[top] -> left = p;
                    else
                        s[top] -> right = p;
                }
        }
        i++;
    }
}

bool EmptyBTree(BTreeNode *BT){ // 判断二叉树是否为空
    return BT = NULL
}