#include <vector>
#include <algorithm> // swap 함수 사용

using namespace std;

void SelectionSort(vector<int>& arr)
{
	int n = arr.size();

	// i : 정렬이 완료된 부분의 끝을 나타냄 (0부터 n - 2까지)
	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i;

		// j : 최솟값을 찾기 위한 탐색 루프
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}

		// 최솟값이 자기 자신이 아니라면 교환
		if (minIndex != i)
		{
			swap(arr[i], arr[minIndex]);
		}
	}
}