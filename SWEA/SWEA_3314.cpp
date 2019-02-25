#include <iostream>
#include <string>
using namespace std;
 
typedef struct _node {
    char alph;
    int left, right;
} node;
 
node *nodes;
void printNodes(int idx) {
    if(nodes[idx].left != -1) {
        printNodes(nodes[idx].left-1);
    }
    cout << nodes[idx].alph;
    if(nodes[idx].right != -1) {
        printNodes(nodes[idx].right-1);
    }
}
 
int main(void) {
    int N;
    int tempInt, tempChar;
 
    for(int t_case=0; t_case<10; t_case++) {
        cin >> N;
 
        nodes = (node*)malloc(sizeof(node)*N);
 
        for(int i=0; i<N; i++) {
            cin >> tempInt;
            cin >> nodes[i].alph;
            if(N >= (i+1)*2) {
                cin >> nodes[i].left;
            } else {
                nodes[i].left = -1;
            }
            if(N > (i+1)*2) {
                cin >> nodes[i].right;
            } else {
                nodes[i].right = -1;
            }
        }
 
        cout << "#" << t_case+1 << " ";
        printNodes(0);
        cout << "\n";
 
        free(nodes);
    }
 
    return 0;
}