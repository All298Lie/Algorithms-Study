#include <vector>
#include <algorithm> // swap 함수 사용

using namespace std;

// 퀵 정렬 메인 함수 (중간값을 피벗으로 사용하는 방식)
void QuickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return; // 원소가 1개 이하면 종료

    // 배열의 중간 위치의 값을 피벗으로 설정 (최악의 경우 방지용)
    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    // 분할 (Partition) 과정
    while (i <= j) {
        // 왼쪽 포인터(i)는 피벗보다 크거나 같은 값을 찾을 때까지 이동
        while (arr[i] < pivot) i++;
        // 오른쪽 포인터(j)는 피벗보다 작거나 같은 값을 찾을 때까지 이동
        while (arr[j] > pivot) j--;

        // 두 포인터가 교차하지 않았다면 두 값을 교환하고 포인터 이동
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // 피벗을 기준으로 나뉜 두 부분 배열에 대해 재귀 호출
    QuickSort(arr, left, j);   // 왼쪽 부분 정렬
    QuickSort(arr, i, right);  // 오른쪽 부분 정렬
}