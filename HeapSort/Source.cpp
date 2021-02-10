#include <fstream>

using namespace std;
void SwapHeap(int a[], int i, int n)
{
		/*while (a[i] < a[2 * i + 1] || a[i] < a[2 * i + 2])
		{
			if (2 * i + 2 < n)
			{
				if (a[2 * i + 1] > a[2 * i + 2])
				{
					swap(a[i], a[2 * i + 1]);
					i = 2 * i + 1;
				}
				else
				{
					swap(a[i], a[2 * i + 2]);
					i = 2 * i + 2;
				}
			}
			else
			{
				if (2 * i + 1 < n && a[i] < a[2 * i + 1])
				{
					swap(a[i], a[2 * i + 1]);
					i = 2 * i + 1;
				}
				else
				{
					break;
				}
			}
				
		}*/
	while (2 * i + 1 < n)
	{
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		int tmp = left;
		if (right < n && a[right] > a[left])
		{
			tmp = right;
		}
		if (a[i] >= a[tmp])
		{
			break;
		}
		swap(a[i], a[tmp]);
		i = tmp;
	}
}

void BuildHeap(int a[], int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		SwapHeap(a, i, n);
	}
}
void HeapSort(int a[], int n)
{	
	BuildHeap(a, n);
	for (int i = n - 1; i > 0; i++)
	{
		swap(a[i], a[0]);
		BuildHeap(a, i);
	}
}

int main()
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	//ifstream fin("sort.in");
	//ofstream fout("sort.out");
	int n;
	fin >> n;
	int* heap = new int[n];
	for (int i = 0; i < n; i++)
	{
		fin >> heap[i];
	}
	HeapSort(heap, n);
	for (int i = 0; i < n; i++)
	{
		fout << heap[i] << " ";
	}
	delete[] heap;
	fin.close();
	fout.close();
	return 0;
}