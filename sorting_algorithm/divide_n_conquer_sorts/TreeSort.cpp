#include <vector>

using namespace std;

// 이진 탐색 트리의 노드 구조체
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 트리에 새로운 값을 삽입하는 재귀 함수
Node* Insert(Node* node, int data)
{
    if (node == nullptr) return new Node(data);

    // 현재 노드보다 작으면 왼쪽, 크거나 같으면 오른쪽으로 이동
    if (data < node->data)
    {
        node->left = Insert(node->left, data);
    }
    else
    {
        node->right = Insert(node->right, data);
    }
    return node;
}

// 중위 순회를 하며 배열에 값을 덮어쓰는 함수
void StoreSorted(Node* node, vector<int>& arr, int& index)
{
    if (node != nullptr)
    {
        StoreSorted(node->left, arr, index);   // 왼쪽 서브 트리 방문
        arr[index++] = node->data;             // 현재 노드 값 저장
        StoreSorted(node->right, arr, index);  // 오른쪽 서브 트리 방문
    }
}

// 후위 순회하여 자식 노드를 먼저 메모리 해제를 시킨 후, 자신을 메모리 해제하는 함수
void Delete(Node* node)
{
    if (node != nullptr)
    {
        Delete(node->left);
        Delete(node->right);
        delete node;
    }
}

// 트리 정렬 메인 함수
void TreeSort(vector<int>& arr)
{
    if (arr.empty()) return;

    Node* root = nullptr;

    // 1. 배열의 모든 원소를 이진 탐색 트리에 삽입
    for (int val : arr)
    {
        root = Insert(root, val);
    }

    // 2. 트리를 중위 순회하며 원본 배열에 정렬된 값 저장
    int index = 0;
    StoreSorted(root, arr, index);

    // 3. 동적할당된 트리를 메모리 해제하여 메모리 누수 방지
    Delete(root);
}