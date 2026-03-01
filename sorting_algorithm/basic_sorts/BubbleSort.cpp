#include <vector>
#include <algorithm> // swap 함수 사용

using namespace std;

void BubbleSort(vector<int>& arr)
{
	int n = arr.size();

	// i : 고정될 뒷 부분의 시작 인덱스를 결정하기 위한 루프
	for (int i = 0; i < n - 1; i++)
	{
		bool isSwapped = false; // 이번 턴에 교환이 있었는지 확인

		// j : 실제 비교 및 교환을 수행하는 루프 (이미 정렬된 뒤쪽은 제외 : n - 1 - j)
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				isSwapped = true;
			}
		}

		// 이번 회차에서 교환이 한 번도 없었다면 이미 정렬된 상태이므로 루프 탈출
		if (!isSwapped) break;
	}
}