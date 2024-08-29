#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 100000

struct Node {
    int key;
    int left;
    int right;
};

struct Node tree[MAX_NODES];

bool isBST(int node_index, int min_key, int max_key) {
    if (node_index == -1) {
        return true;
    }
    
    struct Node node = tree[node_index];
    
    if (node.key < min_key || node.key > max_key) {
        return false;
    }
    
    return isBST(node.left, min_key, node.key - 1) && 
           isBST(node.right, node.key, max_key);
}

bool isBinarySearchTree(int n) {
    return isBST(0, INT_MIN, INT_MAX);
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &tree[i].key, &tree[i].left, &tree[i].right);
    }
    
    if (n == 0 || isBinarySearchTree(n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
