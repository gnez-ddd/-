#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"binary_sort_tree.h"


//初始化二叉排序树
Status BST_init(BinarySortTreePtr T)
{
    T->root = NULL;
    return succeed;
}

//插入节点
Status BST_insert(BinarySortTreePtr T, ElemType data)
{
    //如果没有这棵树
    if (T == NULL)
    {
        return failed;
    }
    //若该树没有节点
    if (T->root == NULL)
    {
        T->root = (NodePtr)malloc(sizeof(Node));
        if (T->root == NULL)
        {
            return failed;
        }
        T->root->left = NULL;
        T->root->right = NULL;
        T->root->value = data;
        return succeed;
    }
    //创建一个新节点
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return failed;
    }
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->value = data;
    //定义一个指针指针指示位置
    NodePtr temp = T->root;
    //定义一个flag记录是否找到
    Status flag = false;
    while (flag != true)
    {
        //若temp的value等于data，则temp为所求
        if (temp->value == data)
        {
            free(newNode);
            newNode = NULL;
            flag = true;
        }
        //若temp的valued大于data，则指向左孩子
        else if (temp->value > data)
        {
            //若temp的左孩子为空，则temp为所求
            if (temp->left == NULL)
            {
                temp->left = newNode;
                flag = true;
            } 
            else
            {
                temp = temp->left;
            }
        }
        //若temp的value小于data，则指向右孩子
        else if (temp->value < data)
        {
            //若temp的右孩子为空，则temp为所求
            if (temp->right == NULL)
            {
                temp->right = newNode;
                flag = true;
            }
            else
            {
                temp = temp->right;
            }
        }
    }
    return succeed;
}

//删除节点
Status BST_delete(BinarySortTreePtr T, ElemType data)
{
    if (T == NULL||T->root==NULL)
    {
        return failed;
    }
    //定义指针指针指示位置
    NodePtr temp = T->root;
    NodePtr tempParents = NULL;
    //定义一个flag记录是否找到删除的节点
    Status flag = false;

    //寻找被删除的结点
    while (flag != true)
    {
        //如果temp的value等于data，则为所求
        if (temp->value == data)
        {
            flag = true;
        }
        //如果temp的value大于data，则指向左孩子
        else if (temp->value > data)
        {
            //若过temp没有左孩子，则没有该数据，让temp置为空表示没有改数据
            if (temp->left == NULL)
            {
                temp = NULL;
                flag = true;
            }
            else
            {
                tempParents = temp;
                temp = temp->left;
            }
        }
        //如果temp的value小于data，则指向右孩子
        else if (temp->value < data)
        {
            //如果temp没有右孩子，则没有该数据，让temp置为空表示没有该数据
            if (temp->right == NULL)
            {
                temp = NULL;
                flag = true;
            }
            else
            {
                tempParents = temp;
                temp = temp->right;
            }
        }
    }

    //若找不到该节点
    if (temp == NULL)
    {
        return failed;
    }

    //若被删除的结点没有孩子则直接删除
    if (temp->left == NULL && temp->right == NULL)
    {
        //若没有双亲直接删除,为根节点
        if (tempParents == NULL)
        {
            free(temp);
            temp = NULL;
            T->root = NULL;
            return succeed;
        }
        //若删除节点为双亲的左孩子，则将双亲的左孩子置为空
        if (tempParents->left == temp)
        {
            tempParents->left = NULL;
            free(temp);
            temp = NULL;
            return succeed;
        }
        //若删除节点为双亲的右孩子，则将双亲的右孩子置为空
        if (tempParents->right == temp)
        {
            tempParents->right = NULL;
            free(temp);
            temp = NULL;
            return succeed;
        }
    }

    //若被删除的结点只有一个孩子，用该孩子代替该节点
    if ((temp->left == NULL && temp->right != NULL) || (temp->right == NULL && temp->left != NULL))
    {
        //若没有双亲
        if (tempParents == NULL)
        {
            if (temp->left != NULL)
            {
                T->root = temp->left;
                free(temp);
                temp = NULL;
                return succeed;
            }
            if (temp->right != NULL)
            {
                T->root = temp->right;
                free(temp);
                temp = NULL;
                return succeed;
            }
        }
        //若删除的节点为双亲的左孩子,让双亲的左孩子为删除节点的孩子
        if (tempParents->left == temp)
        {
            //若删除节点只有左孩子
            if (temp->left != NULL)
            {
                tempParents->left = temp->left;
                free(temp);
                temp = NULL;
                return succeed;
            }
            //若删除节点只有右孩子
            if (temp->right != NULL)
            {
                tempParents->left = temp->right;
                free(temp);
                temp = NULL;
                return succeed;
            }
        }
        //若删除的节点为双亲的右孩子，让双亲的右孩子为删除节点的孩子
        if (tempParents->right == temp)
        {
            //若删除节点只有左孩子
            if (temp->left != NULL)
            {
                tempParents->right = temp->left;
                free(temp);
                temp = NULL;
                return succeed;
            }
            //若删除节点只有右孩子
            if (temp->right != NULL)
            {
                tempParents->right = temp->right;
                free(temp);
                temp = NULL;
                return succeed;
            }
        }
    }

    //若被删除的节点有两个孩子，则与左孩子族的最右一个节点交换
    if (temp->left != NULL && temp->right != NULL)
    {
        //寻找最左孩子族的最右一个节点
        NodePtr rightMost = T->root->left;
        NodePtr rightMostParents = T->root;
        while (rightMost->right != NULL)
        {
            rightMostParents = rightMost;
            rightMost = rightMost->right;
        }

        //让被删除节点的值与最右节点的值交换
        ElemType change = temp->value;
        temp->value = rightMost->value;
        rightMost->value = change;

        //若最右节点的双亲为根节点
        if (rightMostParents == T->root)
        {
            //如果最有节点有孩子
            if (rightMost->left != NULL)
            {
                rightMostParents->left = rightMost->left;
                free(rightMost);
                rightMost = NULL;
                return succeed;
            }
            if (rightMost->left != NULL)
            {
                rightMostParents->left = NULL;
                free(rightMost);
                rightMost = NULL;
                return succeed;
            }
        }

        //若最右节点有孩子，则让最有节点的双亲指向其孩子，如果没有就双亲指为空
        if (rightMost->left != NULL)
        {
            rightMostParents->right = rightMost->left;
            free(rightMost);
            rightMost = NULL;
            return succeed;
        }
        if (rightMost->left == NULL)
        {
            rightMostParents->right = NULL;
            free(rightMost);
            rightMost = NULL;
            return succeed;
        }
    }
}

//寻找节点
Status BST_search(BinarySortTreePtr T, ElemType data)
{
    if (T == NULL||T->root==NULL)
    {
        return failed;
    }
    //定义一个指针指示节点
    NodePtr temp = T->root;
    //定义一个flag表示是否找到
    Status flag = false;
    while (flag != true)
    {
        //若temp的值为data则找到
        if (temp->value == data)
        {
            flag = true;
        }
        //若temp的值大于data，则在其左孩子寻找
        else if (temp->value > data)
        {
            //若temp没有左孩子，则没有该数据,将temp置为空
            if (temp->left == NULL)
            {
                temp = NULL;
                flag = true;
            }
            else
            {
                temp = temp->left;
            }
        }
        //若temp的值小于data，则在其右孩子寻找
        else if (temp->value < data)
        {
            //若temp没有右孩子，则没有该数据，将temp置为空
            if (temp->right == NULL)
            {
                temp = NULL;
                flag = true;
            }
            else
            {
                temp = temp->right;
            }
        }
    }
    //没有该数据
    if (temp == NULL)
    {
        return failed;
    }
    if (temp != NULL)
    {
        return true;
    }
}

//无递归前序遍历
Status BST_preorderI(NodePtr T, void (*visit)(NodePtr))
{
    if (T == NULL)
    {
        return failed;
    }
    //建立一个链栈并初始化
    LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
    if (s == NULL)
    {
        return failed;
    }
    initLStack(s);
    //将根结点进栈
    pushLStack(s, T);
    //当栈不为空的时候
    while (isEmptyLStack(s) != true)
    {
        NodePtr temp = NULL;
        //将栈顶元素出栈
        popLStack(s, &temp);
        visit(temp);
        //将栈顶元素的右左孩子进栈
        if (temp->right != NULL)
        {
            pushLStack(s, temp->right);
        }
        if (temp->left != NULL)
        {
            pushLStack(s, temp->left);
        }
    }
    free(s);
    s = NULL;
    return succeed;
}

//递归前序遍历
Status BST_preorderR(NodePtr T, void (*visit)(NodePtr))
{
    if (T == NULL)
    {
        return failed;
    }
    //定义一个指针指示
    NodePtr temp = T;
    visit(temp);
    //先遍历左孩子再遍历右孩子
    BST_preorderR(temp->left,visit);
    BST_preorderR(temp->right,visit);
    return succeed;
}

//无递归的中序遍历
Status BST_inorderI(NodePtr T, void (*visit)(NodePtr))
{
    if (T == NULL)
    {
        return failed;
    }
    //建立一个链栈并初始化
    LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
    if (s == NULL)
    {
        return failed;
    }
    initLStack(s);
    //定义一个指针指示
    NodePtr temp = T;
    while (temp != NULL || s->top != NULL)
    {
        //若有左孩子
        while (temp!=NULL)
        {
            pushLStack(s, temp);
            temp = temp->left;
        }
        //打印栈顶元素
        if (s->top != NULL)
        {
            popLStack(s, &temp);
            visit(temp);
            temp = temp->right;
        }
    }
    free(s);
    s = NULL;
    return succeed;
}

//递归的中序遍历
Status BST_inorderR(NodePtr T, void (*visit)(NodePtr))
{
    if (T == NULL)
    {
        return failed;
    }
    //定义一个指针指示
    NodePtr temp = T;
    //先遍历左子树
    BST_inorderR(temp->left, visit);
    visit(temp);
    //后遍历右子树
    BST_inorderR(temp->right, visit);
    return succeed;
}

//无递归的后序遍历
Status BST_postorderI(NodePtr T, void (*visit)(NodePtr))
{
    if (T == NULL )
    {
        return failed;
    }
    //建立两个栈，一个用于存储临时的节点，一个用于存储全部节点
    LinkStack* tempStack = (LinkStack*)malloc(sizeof(LinkStack));
    LinkStack* allStack = (LinkStack*)malloc(sizeof(LinkStack));
    if (tempStack == NULL || allStack == NULL)
    {
        return failed;
    }
    initLStack(tempStack);
    initLStack(allStack);
    NodePtr temp = T;
    while (temp != NULL || isEmptyLStack(tempStack) != true)
    {
        //当temp不为空时进栈，指向右孩子
        while (temp != NULL)
        {
            pushLStack(tempStack, temp);
            pushLStack(allStack, temp);
            temp = temp->right;
        }
        if (temp == NULL && isEmptyLStack(tempStack) != true)
        {
            popLStack(tempStack, &temp);
            temp = temp->left;
        }
    }
    //逐个打印
    while (isEmptyLStack(allStack) != true)
    {
        popLStack(allStack, &temp);
        visit(temp);
    }
    free(tempStack);
    tempStack = NULL;
    free(allStack);
    allStack = NULL;
    return succeed;

}

//递归的后续遍历
Status BST_postorderR(NodePtr T, void (*visit)(NodePtr))
{
    if (T == NULL)
    {
        return failed;
    }
    //定义一个指针指示
    NodePtr temp = T;
    BST_postorderR(temp->left, visit);
    BST_postorderR(temp->right, visit);
    visit(temp);
    return succeed;
}

//层次遍历
Status BST_levelOrder(NodePtr T, void (*visit)(NodePtr))
{
    if (T == NULL )
    {
        return failed;
    }
    //创建一个队列并初始化
    LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
    if (Q == NULL)
    {
        return failed;
    }
    InitLQueue(Q);
    //将根结点进队列
    EnLQueue(Q, T);

    NodePtr temp=NULL;
    //把每一层的结点进队列，
    while (IsEmptyLQueue(Q) != true)
    {
        DeLQueue(Q, &temp);
        visit(temp);
        if (temp->left != NULL)
        {
            EnLQueue(Q, temp->left);
        }
        if (temp->right != NULL)
        {
            EnLQueue(Q, temp->right);
        }
    }
    free(Q->front);
    Q->front = NULL;
    free(Q);
    Q = NULL;
    return succeed;
}

//打印
void visit(NodePtr temp)
{
    printf("%d\t", temp->value);
}

//初始化栈
Status initLStack(LinkStack* s)
{
    if (s == NULL)
    {
        return false;
    }
    s->top = NULL;
    return succeed;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack* s)
{
    //为空
    if (s == NULL||s->top==NULL)
    {
        return true;
    }
    else
    {
        //不为空
        return false;
    }
}

//入栈
Status pushLStack(LinkStack* s, NodePtr data)
{
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL)
    {
        return failed;
    }
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
    return succeed;
}

//出栈
Status popLStack(LinkStack* s, NodePtr* temp)
{
    if (s == NULL||s->top==NULL)
    {
        return failed;
    }
    *temp = s->top->data;
    StackNode* del = s->top;
    s->top = del->next;
    del->data = NULL;
    free(del);
    del = NULL;
    return succeed;
}

//初始化队列
Status InitLQueue(LQueue* Q)
{
    //创建头节点
    QueueNode* hNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (hNode == NULL)
    {
        return failed;
    }
    hNode->next = NULL;
    hNode->data = NULL;
    Q->front = hNode;
    Q->rear = hNode;
    return succeed;
}

//判断队列是否为空
Status IsEmptyLQueue(LQueue* Q)
{
    if (Q->front == Q->rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//入队
Status EnLQueue(LQueue* Q, NodePtr data)
{
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newNode == NULL)
    {
        return failed;
    }
    newNode->data = data;
    newNode->next = NULL;
    Q->rear->next = newNode;
    Q->rear = newNode;
    return succeed;
}

//出队
Status DeLQueue(LQueue* Q,NodePtr* data)
{
    if (Q->front == Q->rear)
    {
        return failed;
    }
    *data = Q->front->next->data;
    QueueNode* temp = Q->front->next;
    Q->front->next = temp->next;
    if (Q->front->next == NULL)
    {
        Q->rear = Q->front;
    }
    temp->data = NULL;
    free(temp);
    temp = NULL;
    return succeed;
}

//打印菜单
void printMenu()
{
    printf("==========hahahahahahahah                ==========\n");
    printf("==========1.插入数据                     ==========\n");
    printf("==========2.删除数据                     ==========\n");
    printf("==========3.寻找数据                     ==========\n");
    printf("==========4.非递归前序遍历               ==========\n");
    printf("==========5.递归前序遍历                 ==========\n");
    printf("==========6.非递归中序遍历               ==========\n");
    printf("==========7.递归中序遍历                 ==========\n");
    printf("==========8.非递归后序遍历               ==========\n");
    printf("==========9.递归后序遍历                 ==========\n");
    printf("==========10.层次遍历                    ==========\n");
    printf("==========0.退出                         ==========\n");
    printf("请输入功能的对应编号:\n");
    return;
}

//输入数据判断
Status charJudge(char* a)
{
    char c;
    int ret;
    ret = gets(a);
    if (ret == 0)
    {
        while ((c = getchar()) != EOF && c != '\n');
        return failed;
    }
    int i = 0;
    if (a[0] == '\0')
    {
        return failed;
    }
    //通过此循环说明全部都是数字
    for (i = 0; a[i] != '\0'; i++)
    {
        //第一位不符合
        if (i == 0 && a[i] != 45 && (a[i] < 48 || a[i]>57))
        {

            return failed;
        }
        if (i != 0 && (a[i] < 48 || a[i] > 57))
        {

            return failed;
        }
    }
    //若位数超过11位
    if (i > 11)
    {
        while ((c = getchar()) != EOF && c != '\n');
        return failed;
    }

    return succeed;
}

//选择功能
Status funcChoice(char* choice)
{

    char c;
    int ret;
    ret = gets(choice);
    if (ret == 0)
    {
        while ((c = getchar()) != EOF && c != '\n');
        return failed;
    }
    int i = 0;
    if (choice[0] == '\0')
    {
        return failed;
    }
    //通过此循环说明全部都是数字
    for (i = 0; choice[i] != '\0'; i++)
    {
        //第一位不符合
        if (i == 0 && choice[i] != 45 && (choice[i] < 48 || choice[i]>57))
        {

            return failed;
        }
        if (i != 0 && (choice[i] < 48 || choice[i] > 57))
        {

            return failed;
        }
    }
    //若位数超过3位
    if (i > 3)
    {
        while ((c = getchar()) != EOF && c != '\n');
        return failed;
    }
    int a = 0;
    a = atoi(choice);
    if (a < 0 || a>10)
    {
        return failed;
    }

    return succeed;


}

//输入数据
int dataJudge()
{
    int d = 0;
    char a[100];
    int ret = 0;
    ret = charJudge(a);
    while (ret == 0)
    {
        printf("输入有误，请重新输入：\n");
        ret = charJudge(a);
    }
    d = atoi(a);
    return d;
}