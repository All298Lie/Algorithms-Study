#include <vector>

using namespace std;

// 순차 탐색 메인 함수
// 찾고자 하는 target이 있으면 해당 인덱스를, 없으면 배열의 크기를 반환
int SequentialSearch(const vector<int>& arr, int target) {
    int n = arr.size();

    // 배열의 처음부터 끝까지 순차적으로 탐색
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // 일치하는 데이터를 찾으면 즉시 인덱스 반환
        }
    }

    // 배열을 끝까지 순회했음에도 찾지 못한 경우
    return arr.size();
}