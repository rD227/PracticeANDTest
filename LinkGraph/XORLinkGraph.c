#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

typedef struct Node {
    int value;
    uintptr_t xorn; // XOR of next and previous node addresses
} Node;

Node* XOR(Node* a, Node* b) {
    return (Node*)((uintptr_t)a ^ (uintptr_t)b);
}

typedef struct {
    Node* begin;
    Node* end;
} XORLinkedList;

Node* CreateNode(int value) {
    Node* node = (Node*)calloc(1, sizeof(Node));
    node->value = value;
    node->xorn = 0;
    return node;
}

void ll_append(XORLinkedList* ll,int value){
    if(ll->begin == NULL){
        assert(ll->end == NULL);
        Node *node = CreateNode(value);
        ll->begin = node;
        ll->end = node;
        return;
    }
    Node *node = CreateNode(value);
    ll->end->xorn ^= (uintptr_t)node;
    node->xorn = (uintptr_t)ll->end;
    ll->end = node;
}

void ll_detach_end(XORLinkedList* ll){
    if (ll->end == NULL){
        assert(ll->begin == NULL);
        return;
    }
    
    if (ll->begin == ll->end) {//Only one node
        free(ll->end);
        ll->begin = NULL;
        ll->end = NULL;
        return;
    }
    Node* old_end = ll->end;
    Node* new_end = (Node*)(old_end->xorn); // old_end 的前一个节点的地址转换为节点指针
    //NULL<->...<->new_end<->old_end<->NULL
    //                                        ↑xorn of it ==addresses of new_end ^ NULL

    new_end->xorn ^= (uintptr_t)old_end;  // 异或掉 old_end
    
    ll->end = new_end;
    free(old_end);
}

Node* NodeNext(Node* node,uintptr_t * prev ){
    Node *next = (Node*)(node->xorn ^ *prev);
    //Node *next = (Node* )((Node*).xorn ^ (Node*)prev);
    *prev = (uintptr_t)node;
    return next;
}
/*
//DEL NODE (AI generated code)
//considering three cases: head, tail, middle
// 删除中间节点：需要知道 prev 和 current
// prev <-> current <-> next  ===>  prev <-> next
void ll_detach_node(XORLinkedList* ll, Node* current, Node* prev) {
    if (current == NULL) return;
    
    // 边界情况：删的是头
    if (current == ll->begin) {
        Node* next = (Node*)(current->xorn ^ (uintptr_t)prev);  // prev 应该是 NULL(0)
        if (next != NULL) {
            next->xorn ^= (uintptr_t)current;  // 去掉指向 current 的部分
        }
        ll->begin = next;
        if (ll->begin == NULL) ll->end = NULL;
        free(current);
        return;
    }
    
    // 边界情况：删的是尾
    if (current == ll->end) {
        ll_detach_end(ll);
        return;
    }
    
    // 中间节点: prev <-> current <-> next
    Node* next = (Node*)(current->xorn ^ (uintptr_t)prev);
    
    // 更新 prev 的 xorn: 原来是 prev_prev ^ current，要变成 prev_prev ^ next
    prev->xorn ^= (uintptr_t)current;  // 去掉 current
    prev->xorn ^= (uintptr_t)next;     // 加上 next
    
    // 更新 next 的 xorn: 原来是 current ^ next_next，要变成 prev ^ next_next
    next->xorn ^= (uintptr_t)current;  // 去掉 current
    next->xorn ^= (uintptr_t)prev;     // 加上 prev
    
    free(current);
}

// 按值删除（需要遍历查找）
int ll_remove_by_value(XORLinkedList* ll, int value) {
    Node* current = ll->begin;
    Node* prev = NULL;
    
    while (current != NULL) {
        if (current->value == value) {
            ll_detach_node(ll, current, prev);
            return 1;  // 删除成功
        }
        Node* next = (Node*)(current->xorn ^ (uintptr_t)prev);
        prev = current;
        current = next;
    }
    return 0;  // 没找到
}

*/

int main(){
    XORLinkedList ll = {0};
    ll_append(&ll, 10);
    ll_append(&ll, 20);
    ll_append(&ll, 30);

    Node* current = ll.begin;
    uintptr_t prev = 0;
    Node* next;

    while (current != NULL) {
        printf("%d ", current->value);
        next = XOR((Node*)prev, (Node*)current->xorn);
        prev = (uintptr_t) current;
        current = next;
    }
    printf("\n");
    XORLinkedList eg = {0};
    for(int i=0;i<10;i++){
        ll_append(&eg, i);
    }
    prev = 0;  // Reset prev for new traversal
    for(Node* iter = eg.end; iter != NULL;iter = NodeNext(iter, &prev)) {
        printf("%d ", iter->value);
    }
    printf("\n");

    printf("After detach end: ");
    ll_detach_end(&eg);
    ll_detach_end(&eg);
    prev = 0;
    for(Node* iter = eg.begin; iter != NULL; iter = NodeNext(iter, &prev)) {
        printf("%d ", iter->value);
    }
    printf("\n");
    /*
    printf("Remove value 5: ");
    ll_remove_by_value(&eg, 5);
    */
    prev = 0;
    for(Node* iter = eg.begin; iter != NULL; iter = NodeNext(iter, &prev)) {
        printf("%d ", iter->value);
    }
    printf("\n");
    /*
    printf("Remove value 0 (head): ");
    ll_remove_by_value(&eg, 0);
    */
    prev = 0;
    for(Node* iter = eg.begin; iter != NULL; iter = NodeNext(iter, &prev)) {
        printf("%d ", iter->value);
    }
    printf("\n");
}
