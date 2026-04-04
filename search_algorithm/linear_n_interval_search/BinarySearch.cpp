#include <vector>
#include <iostream>

using namespace std;

// 이진 탐색 메인 함수 (반복문 사용)
// 찾고자 하는 target이 있으면 해당 인덱스를, 없으면 -1을 반환
int BinarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    // 시작점이 끝점을 역전하기 전까지 반복
    while (left <= right) {
        // (left + right) / 2 와 같지만 오버플로우를 방지하는 안전한 수식
        int mid = left + (right - left) / 2;

        // 1. 중간점의 데이터가 타겟과 일치하는 경우
        if (arr[mid] == target) {
            return mid;
        }
        // 2. 타겟이 중간점의 데이터보다 작은 경우 (왼쪽 절반 탐색)
        else if (target < arr[mid]) {
            right = mid - 1;
        }
        // 3. 타겟이 중간점의 데이터보다 큰 경우 (오른쪽 절반 탐색)
        else {
            left = mid + 1;
        }
    }

    // 배열을 끝까지 탐색했음에도 찾지 못한 경우
    return arr.size();
}