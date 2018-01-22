/*
VMWare Codehouse Question:
Two Arrays:
1. Ops: Operation(insert, delete) to be done in step i
2. Data: Number to be inserted or deleted in step i

At each step, print the product of maximum and minimum in the dataset after the operation op[i].

Approach:
Use a sorted doubly linked list.
*/

#include <iostream>
#include <string>
using namespace std;

typedef struct node {
    int data;
    struct node * next;
    struct node * prev;
}Node;

typedef struct dll {
    struct node *head;
    struct node *tail;
    int count;
}Dll;

void insertElem(int d, Dll* ll) {
    Node* node =  (Node*)malloc(sizeof(Node)); 
    node->data = d;
    if (!ll->head) {
        ll->head = node;
        node->next = node;
        node->prev = node;
        ll->count++;
        return;
    }
    
    Node* cur = ll->head;
    if (cur->data > d) {
        node->next = cur;
        cur->prev = node;
        cur->next = node;
        node->prev = cur;
        ll->head = node;
    }
    else {
        while (cur->next != cur && cur->next->data < d) {
            cur = cur->next;
        }
        
        Node *temp = cur->next;
        cur->next = node;
        node->prev = cur;
        node->next = temp;
        temp->prev = node;
    }
    
    ll->count++;
}

void deleteElem(int d, Dll *ll) {
    Node *cur = ll->head;
    while (cur->next != cur) {
        if (cur->data == d) {
            cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
            if (cur == ll->head)
                ll->head = cur->next;
            free(cur);
            return;
        }
        cur = cur->next;
    }
}

void printlist(Dll *ll) {
        //cout << ll->count;
    Node *cur = ll->head;
    for (int i=0;i<ll->count;i++) {
        cout << cur->data << " ";
        cur = cur->next;
    }
}

int main() {
    Dll* ll = (Dll*)malloc(sizeof(Dll));
    ll->count = 0;
    ll->head = NULL, ll->tail = NULL;
    string ops[] = {"i", "i", "d", "i"};
    int d[] = {2, 5, 2, 3};
    
    for (int i=0;i<4;i++) {
        if (ops[i] == "i") {
            insertElem(d[i], ll);
        }
        else {
            deleteElem(d[i], ll);
        }
        int min = ll->head->data;
        int max = ll->head->prev->data;
        cout << "product of max*min = " <<  min*max << endl;
    }
    

}
