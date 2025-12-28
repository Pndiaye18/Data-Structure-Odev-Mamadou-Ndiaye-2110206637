#include <stdio.h>

int main() {
    int tree[15];
    int i;

    // Initialize tree with -1 (empty)
    for (i = 0; i < 15; i++)
        tree[i] = -1;

    // Creating tree manually
    tree[0] = 1;   // root
    tree[1] = 2;   // left child of root
    tree[2] = 3;   // right child of root
    tree[3] = 4;   // left child of 2
    tree[4] = 5;   // right child of 2
    tree[5] = 6;   // left child of 3

    // Display tree
    printf("Binary Tree (Array Representation):\n");
    for (i = 0; i < 15; i++) {
        if (tree[i] != -1)
            printf("Index %d : %d\n", i, tree[i]);
    }

    return 0;
}
