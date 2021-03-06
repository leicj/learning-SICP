// 有序单链表的实现
// 实现插入/删除/打印
// 增加链表长度的计算,以及查找节点

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct NODE {
    struct NODE *next;
    int value;
} Node;

void insert(Node *node, int val);

void del(Node *node, int val);

void print(Node *node);

int len(Node *node);

Node *search(Node *node, int val);

int main(void)
{
    Node *root = (Node *)malloc(sizeof(Node));
    Node *searchnode = NULL;
    root->next = NULL;
    root->value = INT_MIN;

    insert(root, 2);
    insert(root, 9);
    insert(root, 3);
    insert(root, 0);
    insert(root, 4);
    insert(root, 6);
    insert(root, 1);
    insert(root, 3);
    print(root->next);

    printf("len is: %d\n", len(root->next));

    searchnode = search(root->next, 4);
    if (searchnode) {
        print(searchnode);
    }
    return 0;
}


void insert(Node *node, int val)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    Node *prevnode = node;
    newnode->next = NULL;
    newnode->value = val;
    node = node->next;

    if (NULL == node) {
        prevnode->next = newnode;
        return;
    }

    while (node && node->value < val) {
        prevnode = node;
        node = node->next;
    }

    prevnode->next = newnode;
    newnode->next = node;
}


void del(Node *node, int val)
{
    Node *prevnode = node;
    node = node->next;

    while (node && node->value != val) {
        prevnode = node;
        node = node->next;
    }
    if (node && node->value == val) {
        prevnode->next = node->next;
    }
}


void print(Node *node)
{
    while (node) {
        printf("%d->", node->value);
        node = node->next;
    }
    printf("NULL\n");
}


int len(Node *node)
{
    int len = 0;
    while (node) {
        len++;
        node = node->next;
    }

    return len;
}


Node *search(Node *node, int val)
{
    Node *searchnode = NULL;
    while (node && node->value < val) {
        node = node->next;
    }
    if (node->value == val) {
        searchnode = node;
    }
    return searchnode;
}
