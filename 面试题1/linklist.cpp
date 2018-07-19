#include <iostream>

using namespace std;

/*  Project 1

    定义一个单向链表node, 每个节点值为int.
    定义函数void create_linklist(…, int n)来生成链表，链表长度由参数n传入,生成的链表要作为参数返回，而不是当初函数返回值返回，链表节点值为1,2,3...n。
    定义函数reverse_linklist(...),　对参数传入的链表进行逆转。
    定义函数insert_node(node *pHead, int Index, int Value ), 在指定链表位置Index插入指定Value
    定义函数delete_node(node *pHead,  int Index),删除链表位置Index所在的节点
    定义函数delete_linklist(),　删除整个链表


    main()函数：
    １．调用create_linklist()生成链表
    ２．调用insert_node()插入节点
    ３．调用delete_node()删除节点
    ４．调用reverse_linklist()逆转
    ５．打印链表所有值
    ６．结束程序工作
*/

struct node
{
    int v;
    node* n;
};
typedef struct node *linklist;

/* 链表长度由参数n传入,生成的链表要作为参数返回，而不是当初函数返回值返回，
   链表节点值为1,2,3...n
   (头插法)
*/
void create_linklist(linklist *L, int n)
{
    int i;
    linklist p;

    *L = (linklist)malloc(sizeof(node)) // 产生头结点,并使L指向此头结点
    (*L)->n = NULL;
    for(i = n; i > 0; i--)
    {
        p = (linklist)malloc(sizeof(node));
        p->v = n;
        p->n = (*L)->n;
        (*L)->n = p;
        n--;
    }
}


//对参数传入的链表进行逆转
void reverse_linklist(linklist *L)
{
    linklist pcurrent, pnext, prev;

    if((*L)->n == NULL)
        std::cout << "链表节点数不足，无法逆转！" << std::endl;
    
    pcurrent = (*L)->n;
    pnext = pcurrent->n;
    pcurrent->n = NULL;
    while(pnext)
    {
        prev = pnext->n;
        pnext->n = pcurrent;
        pcurrent = pnext;
        pnext = prev;
    }
    (*L)->n = pcurrent;
}

//在指定链表位置Index插入指定Value
void insert_node(linklist *L, int Index, int Value)
{
    int j = 1;
    linklist p,s;
    p = *L;

    while(p && j < Index) // 寻找index处的节点
    {
        p = p->n;
        ++j;
    }
    if(!p || j > Index)
        std::cout << "该元素不存在" << std::endl;

    s = (linklist)malloc(sizeof(node));
    s->v = Value;
    s->n = p->n;
    p->n = s;
}

//删除链表位置Index所在的节点
void delete_node(linklist *L, int Index)
{
    int j = 1;
    linklist p, q;
    p = *L;
    
    while(p->n && j < Index)
    {
        p = p->n;
        ++j;
    }
    if(!(p->n) || j > Index)
        std::cout << "该元素不存在" << std::endl;

    q = p->n;
    p->n = q->n;
    free(q)
}

//删除整个链表
void delete_linklist(linklist *L)
{
    linklist p, q;
    p = (*L)->n; // p指向第一个结点 
    while(p)
    {
        q = p->n;
        free(p);
        p = q;
    }
    (*L)->n = NULL; // 头结点指针为空
}

/* Project 2
  编写一个函数int Calculate(node *pHead, int k);在链表数字之间插入+ 、- 或者什么都不插入,使得计算结果等于
  给定的整数 K,返回所有可能性的个数。例如链表有数字 1, 2, 3, ..., 9 并且给
  定的整数为 100,那么其中的一种可能性是: 1 + 2 + 34 – 5 + 67 – 8 + 9 = 100。
  (不允许开辟额外的字符串空间,假设链表所有数字都大于 0 并且小于 10)
*/
int Calculate(node *pHead, int k)
{
    int i = 0;
    int A[20] = 0;
    node *p = pHead->n;
    while(p)
    {
        A[i] = (*p)->v;
        i++;
        p = p->n;
    }

    if(i == 1) // 数组长度
    {

    }



}

/*  Project 3

    定义一个聚类函数 cluster(int data[], int len, int radius)；
    data中的值没有重复，长度为len,
    把按照数值的聚类进行分为n组，
    对于组G中任意一个数值a,总是能在本组G中找到一个数值b,　使　|a-b| < radius　　.
    在函数内部打印出所有n个组成员，分成n行输出

    (要求：不能使用数组排序操作)
*/
void cluster(int data[], int len, int radius)
{
    int i, j, k;
    for (i = 0; i < len; i++)
    {
        std::cout << data[i] << " ";
        for(j = 1; j < len-i; j++)
        {
            if(abs(data[i+j] - data[i]) < radius)
            {
                std::cout << data[i+j] << " ";
                for(k = i+j; k < len; k++) // 后面的元素往前移
                {
                    data[k] = data[k+1];
                }
                len--;
                j--;
            }
        }
        std::cout << std::endl;
    }
    std::cout << "分组数目： " << len << std::endl;
}


int main()
{
    cout << "Hello World!" << endl;

    // Project 3
    int data[] = { 1, 20, 89, 22, 72, 2,39, 3,56,86, 5, 93,13, 15, 18, 73, 79, 81,25, 38, 43, 83,48, 52,  59,92,84,95,87 };
    cluster(data, sizeof(data)/sizeof(int), 5);
    return 0;
}

