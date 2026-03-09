#include <vector>
#include <algorithm> // swap 함수 사용

using namespace std;

// 주어진 노드(i)를 루트로 하는 서브 트리를 최대 힙 구조로 만드는 함수
void Heapify(vector<int>& arr, int n, int i) {
    int largest = i;       // 루트 노드
    int left = 2 * i + 1;  // 왼쪽 자식 노드의 인덱스
    int right = 2 * i + 2; // 오른쪽 자식 노드의 인덱스

    // 왼쪽 자식이 트리의 크기(n) 범위 내에 있고, 루트보다 크다면 갱신
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // 오른쪽 자식이 트리의 크기(n) 범위 내에 있고, 현재 가장 큰 노드보다 크다면 갱신
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // 루트 노드가 가장 큰 값이 아니라면 자식과 교환하고, 
    // 교환되어 내려간 자식 노드에 대해 재귀적으로 Heapify 호출
    if (largest != i) {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

// 힙 정렬 메인 함수
void HeapSort(vector<int>& arr) {
    int n = arr.size();

    // 1. 초기 배열을 최대 힙(Max Heap)으로 구성
    // 자식이 있는 마지막 부모 노드(n/2 - 1)부터 역순으로 루트(0)까지 진행
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(arr, n, i);
    }

    // 2. 힙에서 요소를 하나씩 추출하여 정렬
    for (int i = n - 1; i > 0; i--) {
        // 현재 최대 힙의 루트(최댓값)를 배열의 끝으로 보냄
        swap(arr[0], arr[i]);

        // 맨 뒤로 확정된 원소를 제외하고, 남은 트리(크기 i)에 대해 다시 루트부터 최대 힙 구성
        Heapify(arr, i, 0);
    }
}