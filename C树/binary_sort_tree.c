#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"binary_sort_tree.h"


//��ʼ������������
Status BST_init(BinarySortTreePtr T)
{
    T->root = NULL;
    return succeed;
}

//����ڵ�
Status BST_insert(BinarySortTreePtr T, ElemType data)
{
    //���û�������
    if (T == NULL)
    {
        return failed;
    }
    //������û�нڵ�
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
    //����һ���½ڵ�
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return failed;
    }
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->value = data;
    //����һ��ָ��ָ��ָʾλ��
    NodePtr temp = T->root;
    //����һ��flag��¼�Ƿ��ҵ�
    Status flag = false;
    while (flag != true)
    {
        //��temp��value����data����tempΪ����
        if (temp->value == data)
        {
            free(newNode);
            newNode = NULL;
            flag = true;
        }
        //��temp��valued����data����ָ������
        else if (temp->value > data)
        {
            //��temp������Ϊ�գ���tempΪ����
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
        //��temp��valueС��data����ָ���Һ���
        else if (temp->value < data)
        {
            //��temp���Һ���Ϊ�գ���tempΪ����
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

//ɾ���ڵ�
Status BST_delete(BinarySortTreePtr T, ElemType data)
{
    if (T == NULL||T->root==NULL)
    {
        return failed;
    }
    //����ָ��ָ��ָʾλ��
    NodePtr temp = T->root;
    NodePtr tempParents = NULL;
    //����һ��flag��¼�Ƿ��ҵ�ɾ���Ľڵ�
    Status flag = false;

    //Ѱ�ұ�ɾ���Ľ��
    while (flag != true)
    {
        //���temp��value����data����Ϊ����
        if (temp->value == data)
        {
            flag = true;
        }
        //���temp��value����data����ָ������
        else if (temp->value > data)
        {
            //����tempû�����ӣ���û�и����ݣ���temp��Ϊ�ձ�ʾû�и�����
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
        //���temp��valueС��data����ָ���Һ���
        else if (temp->value < data)
        {
            //���tempû���Һ��ӣ���û�и����ݣ���temp��Ϊ�ձ�ʾû�и�����
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

    //���Ҳ����ýڵ�
    if (temp == NULL)
    {
        return failed;
    }

    //����ɾ���Ľ��û�к�����ֱ��ɾ��
    if (temp->left == NULL && temp->right == NULL)
    {
        //��û��˫��ֱ��ɾ��,Ϊ���ڵ�
        if (tempParents == NULL)
        {
            free(temp);
            temp = NULL;
            T->root = NULL;
            return succeed;
        }
        //��ɾ���ڵ�Ϊ˫�׵����ӣ���˫�׵�������Ϊ��
        if (tempParents->left == temp)
        {
            tempParents->left = NULL;
            free(temp);
            temp = NULL;
            return succeed;
        }
        //��ɾ���ڵ�Ϊ˫�׵��Һ��ӣ���˫�׵��Һ�����Ϊ��
        if (tempParents->right == temp)
        {
            tempParents->right = NULL;
            free(temp);
            temp = NULL;
            return succeed;
        }
    }

    //����ɾ���Ľ��ֻ��һ�����ӣ��øú��Ӵ���ýڵ�
    if ((temp->left == NULL && temp->right != NULL) || (temp->right == NULL && temp->left != NULL))
    {
        //��û��˫��
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
        //��ɾ���Ľڵ�Ϊ˫�׵�����,��˫�׵�����Ϊɾ���ڵ�ĺ���
        if (tempParents->left == temp)
        {
            //��ɾ���ڵ�ֻ������
            if (temp->left != NULL)
            {
                tempParents->left = temp->left;
                free(temp);
                temp = NULL;
                return succeed;
            }
            //��ɾ���ڵ�ֻ���Һ���
            if (temp->right != NULL)
            {
                tempParents->left = temp->right;
                free(temp);
                temp = NULL;
                return succeed;
            }
        }
        //��ɾ���Ľڵ�Ϊ˫�׵��Һ��ӣ���˫�׵��Һ���Ϊɾ���ڵ�ĺ���
        if (tempParents->right == temp)
        {
            //��ɾ���ڵ�ֻ������
            if (temp->left != NULL)
            {
                tempParents->right = temp->left;
                free(temp);
                temp = NULL;
                return succeed;
            }
            //��ɾ���ڵ�ֻ���Һ���
            if (temp->right != NULL)
            {
                tempParents->right = temp->right;
                free(temp);
                temp = NULL;
                return succeed;
            }
        }
    }

    //����ɾ���Ľڵ����������ӣ����������������һ���ڵ㽻��
    if (temp->left != NULL && temp->right != NULL)
    {
        //Ѱ���������������һ���ڵ�
        NodePtr rightMost = T->root->left;
        NodePtr rightMostParents = T->root;
        while (rightMost->right != NULL)
        {
            rightMostParents = rightMost;
            rightMost = rightMost->right;
        }

        //�ñ�ɾ���ڵ��ֵ�����ҽڵ��ֵ����
        ElemType change = temp->value;
        temp->value = rightMost->value;
        rightMost->value = change;

        //�����ҽڵ��˫��Ϊ���ڵ�
        if (rightMostParents == T->root)
        {
            //������нڵ��к���
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

        //�����ҽڵ��к��ӣ��������нڵ��˫��ָ���亢�ӣ����û�о�˫��ָΪ��
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

//Ѱ�ҽڵ�
Status BST_search(BinarySortTreePtr T, ElemType data)
{
    if (T == NULL||T->root==NULL)
    {
        return failed;
    }
    //����һ��ָ��ָʾ�ڵ�
    NodePtr temp = T->root;
    //����һ��flag��ʾ�Ƿ��ҵ�
    Status flag = false;
    while (flag != true)
    {
        //��temp��ֵΪdata���ҵ�
        if (temp->value == data)
        {
            flag = true;
        }
        //��temp��ֵ����data������������Ѱ��
        else if (temp->value > data)
        {
            //��tempû�����ӣ���û�и�����,��temp��Ϊ��
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
        //��temp��ֵС��data���������Һ���Ѱ��
        else if (temp->value < data)
        {
            //��tempû���Һ��ӣ���û�и����ݣ���temp��Ϊ��
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
    //û�и�����
    if (temp == NULL)
    {
        return failed;
    }
    if (temp != NULL)
    {
        return true;
    }
}

//�޵ݹ�ǰ�����
Status BST_preorderI(NodePtr T, void (*visit)(NodePtr))
{
    if (T == NULL)
    {
        return failed;
    }
    //����һ����ջ����ʼ��
    LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
    if (s == NULL)
    {
        return failed;
    }
    initLStack(s);
    //��������ջ
    pushLStack(s, T);
    //��ջ��Ϊ�յ�ʱ��
    while (isEmptyLStack(s) != true)
    {
        NodePtr temp = NULL;
        //��ջ��Ԫ�س�ջ
        popLStack(s, &temp);
        visit(temp);
        //��ջ��Ԫ�ص������ӽ�ջ
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

//�ݹ�ǰ�����
Status BST_preorderR(NodePtr T, void (*visit)(NodePtr))
{
    if (T == NULL)
    {
        return failed;
    }
    //����һ��ָ��ָʾ
    NodePtr temp = T;
    visit(temp);
    //�ȱ��������ٱ����Һ���
    BST_preorderR(temp->left,visit);
    BST_preorderR(temp->right,visit);
    return succeed;
}

//�޵ݹ���������
Status BST_inorderI(NodePtr T, void (*visit)(NodePtr))
{
    if (T == NULL)
    {
        return failed;
    }
    //����һ����ջ����ʼ��
    LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
    if (s == NULL)
    {
        return failed;
    }
    initLStack(s);
    //����һ��ָ��ָʾ
    NodePtr temp = T;
    while (temp != NULL || s->top != NULL)
    {
        //��������
        while (temp!=NULL)
        {
            pushLStack(s, temp);
            temp = temp->left;
        }
        //��ӡջ��Ԫ��
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

//�ݹ���������
Status BST_inorderR(NodePtr T, void (*visit)(NodePtr))
{
    if (T == NULL)
    {
        return failed;
    }
    //����һ��ָ��ָʾ
    NodePtr temp = T;
    //�ȱ���������
    BST_inorderR(temp->left, visit);
    visit(temp);
    //�����������
    BST_inorderR(temp->right, visit);
    return succeed;
}

//�޵ݹ�ĺ������
Status BST_postorderI(NodePtr T, void (*visit)(NodePtr))
{
    if (T == NULL )
    {
        return failed;
    }
    //��������ջ��һ�����ڴ洢��ʱ�Ľڵ㣬һ�����ڴ洢ȫ���ڵ�
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
        //��temp��Ϊ��ʱ��ջ��ָ���Һ���
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
    //�����ӡ
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

//�ݹ�ĺ�������
Status BST_postorderR(NodePtr T, void (*visit)(NodePtr))
{
    if (T == NULL)
    {
        return failed;
    }
    //����һ��ָ��ָʾ
    NodePtr temp = T;
    BST_postorderR(temp->left, visit);
    BST_postorderR(temp->right, visit);
    visit(temp);
    return succeed;
}

//��α���
Status BST_levelOrder(NodePtr T, void (*visit)(NodePtr))
{
    if (T == NULL )
    {
        return failed;
    }
    //����һ�����в���ʼ��
    LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
    if (Q == NULL)
    {
        return failed;
    }
    InitLQueue(Q);
    //������������
    EnLQueue(Q, T);

    NodePtr temp=NULL;
    //��ÿһ��Ľ������У�
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

//��ӡ
void visit(NodePtr temp)
{
    printf("%d\t", temp->value);
}

//��ʼ��ջ
Status initLStack(LinkStack* s)
{
    if (s == NULL)
    {
        return false;
    }
    s->top = NULL;
    return succeed;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s)
{
    //Ϊ��
    if (s == NULL||s->top==NULL)
    {
        return true;
    }
    else
    {
        //��Ϊ��
        return false;
    }
}

//��ջ
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

//��ջ
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

//��ʼ������
Status InitLQueue(LQueue* Q)
{
    //����ͷ�ڵ�
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

//�ж϶����Ƿ�Ϊ��
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


//���
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

//����
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

//��ӡ�˵�
void printMenu()
{
    printf("==========hahahahahahahah                ==========\n");
    printf("==========1.��������                     ==========\n");
    printf("==========2.ɾ������                     ==========\n");
    printf("==========3.Ѱ������                     ==========\n");
    printf("==========4.�ǵݹ�ǰ�����               ==========\n");
    printf("==========5.�ݹ�ǰ�����                 ==========\n");
    printf("==========6.�ǵݹ��������               ==========\n");
    printf("==========7.�ݹ��������                 ==========\n");
    printf("==========8.�ǵݹ�������               ==========\n");
    printf("==========9.�ݹ�������                 ==========\n");
    printf("==========10.��α���                    ==========\n");
    printf("==========0.�˳�                         ==========\n");
    printf("�����빦�ܵĶ�Ӧ���:\n");
    return;
}

//���������ж�
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
    //ͨ����ѭ��˵��ȫ����������
    for (i = 0; a[i] != '\0'; i++)
    {
        //��һλ������
        if (i == 0 && a[i] != 45 && (a[i] < 48 || a[i]>57))
        {

            return failed;
        }
        if (i != 0 && (a[i] < 48 || a[i] > 57))
        {

            return failed;
        }
    }
    //��λ������11λ
    if (i > 11)
    {
        while ((c = getchar()) != EOF && c != '\n');
        return failed;
    }

    return succeed;
}

//ѡ����
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
    //ͨ����ѭ��˵��ȫ����������
    for (i = 0; choice[i] != '\0'; i++)
    {
        //��һλ������
        if (i == 0 && choice[i] != 45 && (choice[i] < 48 || choice[i]>57))
        {

            return failed;
        }
        if (i != 0 && (choice[i] < 48 || choice[i] > 57))
        {

            return failed;
        }
    }
    //��λ������3λ
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

//��������
int dataJudge()
{
    int d = 0;
    char a[100];
    int ret = 0;
    ret = charJudge(a);
    while (ret == 0)
    {
        printf("�����������������룺\n");
        ret = charJudge(a);
    }
    d = atoi(a);
    return d;
}