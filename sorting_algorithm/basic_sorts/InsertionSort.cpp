#include <vector>

using namespace std;

void InsertionSort(vector<int>& arr)
{
	int n = arr.size();

	// 두번째 원소(1)부터 시작 (첫 번째 원소는 이미 정렬된 것으로 간주)
	for (int i = 1; i < n; i++)
	{
		int key = arr[i]; // 현재 삽입할 값을 따로 저장
		int j = i - 1;

		// j가 0 이상이고, 앞의 원소가 key보다 크다면
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j]; // 앞의 값을 뒤로 한 칸 밀어냄
			j--; // 더 앞쪽을 검사하기 위해 인덱스 감소
		}

		// 반복문이 끝나면 j + 1 위치가 key가 들어갈 자리
		arr[j + 1] = key;
	}
}