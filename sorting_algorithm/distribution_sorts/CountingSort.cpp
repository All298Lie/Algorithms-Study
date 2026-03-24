#include <vector>
#include <algorithm> // max_element 함수 사용

using namespace std;

// 계수 정렬 메인 함수
void CountingSort(vector<int>& arr) {
    if (arr.empty()) return;

    int n = arr.size();

    // 1. 원본 배열에서 최댓값 찾기
    int max_val = *max_element(arr.begin(), arr.end());

    // 2. 카운팅 배열(Counting Array) 생성 및 0으로 초기화
    // 인덱스가 최댓값까지 있어야 하므로 크기는 max_val + 1
    vector<int> count(max_val + 1, 0);

    // 정렬된 결과를 임시로 담을 배열
    vector<int> output(n);

    // 3. 각 원소의 등장 횟수 세기
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // 4. 카운팅 배열을 누적합(Prefix Sum)으로 변환
    // 각 값이 결과 배열에서 위치할 마지막 인덱스를 계산
    for (int i = 1; i <= max_val; i++) {
        count[i] += count[i - 1];
    }

    // 5. 원본 배열을 뒤에서부터 순회하며 결과 배열에 배치 (안정 정렬 보장)
    for (int i = n - 1; i >= 0; i--) {
        int val = arr[i];

        // 누적합에서 1을 뺀 값이 결과 배열에서의 실제 인덱스
        count[val]--;
        output[count[val]] = val;
    }

    // 6. 정렬된 결과를 원본 배열에 덮어쓰기
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}