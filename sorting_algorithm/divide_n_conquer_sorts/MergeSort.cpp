#include <vector>

using namespace std;

// 두 개의 정렬된 부분 배열을 병합하는 함수
void Merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 임시 배열 생성
    vector<int> L(n1), R(n2);

    // 데이터 복사
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // 두 부분 배열을 비교하며 원본 배열에 정렬하여 덮어쓰기
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 왼쪽 배열에 남은 원소가 있다면 모두 복사
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 오른쪽 배열에 남은 원소가 있다면 모두 복사
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 분할 정복을 수행하는 메인 정렬 함수
void MergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right) return; // 원소가 1개 이하면 종료

    int mid = left + (right - left) / 2; // 중간 지점 계산 (오버플로우 방지)

    MergeSort(arr, left, mid);       // 왼쪽 절반 분할
    MergeSort(arr, mid + 1, right);  // 오른쪽 절반 분할
    Merge(arr, left, mid, right);    // 분할된 두 배열 병합
}