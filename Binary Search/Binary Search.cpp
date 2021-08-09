//Binary Search�� ����
#include <iostream>
#include <algorithm>

using namespae std;

bool BinarySearch_repetition(int* arr, int len, int key) //Binary Search �ݺ���
{
    int start = 0;
    int end = len - 1;
    int mid;

    while (end - start >= 0) {
        mid = (start + end) / 2;    //�߾� ��

        if (arr[mid] == key) {    //key���� ã������
            return true;

        }
        else if (arr[mid] > key) {   //key���� mid�� ������ ������ (��������)
            end = mid - 1;

        }
        else {  //key���� mid�� ������ Ŭ�� (����������)
            start = mid + 1;

        }
    }
    return false;
}


bool BinarySearch_recursive(int* arr, int start, int end, int key) // Binary Search ���
{
    if (start > end) return false; //key ���� ���� ��

    int mid = (start + end) / 2;

    if (arr[mid] == key) {    //key ���� ã���� ��
        return true;

    }
    else if (arr[mid] > key) { //key ���� mid �� ������ ������(��������)
        return BinarySearch_recursive(arr, start, mid - 1, key);

    }
    else {  //key ���� mid �� ������ ������(��������)
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

    binary_search(arr, arr + n, 70); //STL(Standard Template Library)�� �̿�
    
    return 0;
}

// ��ó: https://blockdmask.tistory.com/167 [������ ������]