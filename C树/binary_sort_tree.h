#pragma once
//
// Created by eke_l on 2021/4/21.
//

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int

typedef int ElemType;


typedef struct Node {
    ElemType value;
    struct Node* left, * right;
}Node, * NodePtr;

typedef struct BinarySortTree {
    NodePtr root;
} BinarySortTree, * BinarySortTreePtr;

typedef  struct StackNode
{
    NodePtr data;
    struct StackNode* next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
}LinkStack;


typedef struct QueueNode
{
    NodePtr data;
    struct QueueNode* next; 

} QueueNode;

typedef struct LQueue
{
    QueueNode* front;                   //队头
    QueueNode* rear;                    //队尾
} LQueue;


Status InitLQueue(LQueue* Q);

Status IsEmptyLQueue(LQueue* Q);

Status EnLQueue(LQueue* Q, NodePtr data);

Status DeLQueue(LQueue* Q, NodePtr data);

Status initLStack(LinkStack* s);

Status isEmptyLStack(LinkStack* s);

Status pushLStack(LinkStack* s, NodePtr newNode);

Status popLStack(LinkStack* s, NodePtr data);


/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr T);

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr T, ElemType data);

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr T, ElemType data);

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr T, ElemType data);

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(NodePtr T, void (*visit)(NodePtr));

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(NodePtr T, void (*visit)(NodePtr));

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(NodePtr T, void (*visit)(NodePtr));

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(NodePtr T, void (*visit)(NodePtr));

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(NodePtr T, void (*visit)(NodePtr));

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(NodePtr T, void (*visit)(NodePtr));

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(NodePtr T, void (*visit)(NodePtr));

void visit(NodePtr temp);

//打印菜单
void printMenu();

//输入数据判断
Status charJudge(char* a);

//选择功能
Status funcChoice(char* choice);

//输入数据
int dataJudge();

#endif //BINARYSORTTREE_BINARY_SORT_TREE_H

