//Binary Search의 구현
#include <iostream>
#include <algorithm>

using namespae std;

bool BinarySearch_repetition(int* arr, int len, int key) //Binary Search 반복문
{
    int start = 0;
    int end = len - 1;
    int mid;

    while (end - start >= 0) {
        mid = (start + end) / 2;    //중앙 값

        if (arr[mid] == key) {    //key값을 찾았을때
            return true;

        }
        else if (arr[mid] > key) {   //key값이 mid의 값보다 작을때 (왼쪽으로)
            end = mid - 1;

        }
        else {  //key값이 mid의 값보다 클때 (오른쪽으로)
            start = mid + 1;

        }
    }
    return false;
}


bool BinarySearch_recursive(int* arr, int start, int end, int key) // Binary Search 재귀
{
    if (start > end) return false; //key 값이 없을 때

    int mid = (start + end) / 2;

    if (arr[mid] == key) {    //key 값을 찾았을 때
        return true;

    }
    else if (arr[mid] > key) { //key 값이 mid 의 값보다 작을때(왼쪽으로)
        return BinarySearch_recursive(arr, start, mid - 1, key);

    }
    else {  //key 값이 mid 의 값보다 작을때(왼쪽으로)
        return BinarySearch_recursive(arr, mid + 1, end, key);

    }
}

int main()
{
    int n = 100;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    binary_search(arr, arr + n, 70); //STL(Standard Template Library)을 이용
    
    return 0;
}

// 출처: https://blockdmask.tistory.com/167 [개발자 지망생]