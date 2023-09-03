// #pragma warning(disable:4996)
#include <iostream>
#include <map>

using namespace std;

struct Node
{
	char left;
	char right;
};

// 맵으로 트리 구현
map<char, Node> m;

// 전위 순회
void preOrder(char node) 
{ 
	// root - left - right
	if (node == '.') return;

	printf("%c", node);
	preOrder(m[node].left);
	preOrder(m[node].right);
}

// 중위 순회
void inOrder(char node) 
{ 
	// left - root - right
	if (node == '.') return;

	inOrder(m[node].left);
	printf("%c", node);
	inOrder(m[node].right);
}

// 후위 순회
void postOrder(char node) 
{ 
	// left - right - root
	if (node == '.') return;

	postOrder(m[node].left);
	postOrder(m[node].right);
	printf("%c", node);
}

int main() {
	int n;
	scanf("%d", &n);

	char node, left, right;
	// 트리 입력받기
	for (int i = 0; i < n; i++) 
	{
		cin >> node >> left >> right;
		m[node].left = left;
		m[node].right = right;
		// m.insert({ node, {left, right} });
	}

	preOrder('A');
	printf("\n");

	inOrder('A');
	printf("\n");

	postOrder('A');

	return 0;
}