#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

class LRUCache{
private:
    struct node {
        int key;
        int value;
        node *pre, *next;
        node(int x, int y) : key(x), value(y), pre(NULL), next(NULL) {}
    };
    
    int capa;
    map<int, node*> m;
    node *head, *tail;
public:
    LRUCache(int capacity) {
        capa = capacity;
        m.clear();
        head = new node(0, 0);
        tail = new node(0, 0);
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if (m.count(key)) {
            node *tmp = m[key];
            tmp->pre->next = tmp->next;
            tmp->next->pre = tmp->pre;
            tmp->next = head->next;
            tmp->pre = head;
            head->next->pre = tmp;
            head->next = tmp;
            return tmp->value;
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        if (m.count(key)) {
            node *tmp = m[key];
            tmp->pre->next = tmp->next;
            tmp->next->pre = tmp->pre;
            head->next->pre = tmp;
            tmp->next = head->next;
            head->next = tmp;
            tmp->pre = head;
            tmp->value = value;
        } else if (capa) {
            node *tmp = new node(key, value);
            tmp->pre = head; tmp->next = head->next;
            head->next->pre = tmp;
            head->next = tmp;
            m.insert(make_pair(key, tmp));
            capa--;
        } else {
            node *tmp = new node(key, value);
            head->next->pre = tmp;
            tmp->next = head->next;
            head->next = tmp;
            tmp->pre = head;
            
            m.erase(tail->pre->key);
            tail->pre->pre->next = tail;
            tail->pre = tail->pre->pre;
            m.insert(make_pair(key, tmp));
        }
    }
};

int main() {
    LRUCache lru = LRUCache(2);
    
    while (true) {
        int k;
        scanf("%d", &k);
        if (k == 0) {
            int x;
            scanf("%d", &x);
            printf("...%d\n", lru.get(x));
        } else {
            int x, y;
            scanf("%d%d", &x, &y);
            lru.set(x, y);
        }
    }
    
    return 0;
}