#include <iostream>
#include <vector>

/*-----Quick Sort Function For Vector-------*/
std::vector<int> merge(std::vector<int> v1, int n, std::vector<int> v2) {

	v1.push_back(n);

	for (auto i = v2.begin(); i != v2.end(); ++i) {
		v1.push_back(*i);
	}
	return v1;
}

std::vector<int> qSortVec (std::vector<int> vec) {
	int size = vec.size();

	if (size < 2) {
		return vec;
	}

	int p = vec[0];
	std::vector<int> leftVec;
	std::vector<int> rightVec;

	for (auto i = vec.begin() + 1; i != vec.end(); ++i) {

		if (*i <= p) {

			leftVec.push_back(*i);
		} else {

			rightVec.push_back(*i);
		}

	}

	return merge(qSortVec(leftVec), p, qSortVec(rightVec));
}

void printVec (std::vector<int> vec) {
	for(auto i = vec.begin(); i != vec.end(); ++i) {

		std::cout << *i << ' ';
	}
}
/*-----Quick Sort Function For Array-------*/
void swap (int& a, int& b) {
	int tmp = b;
	b = a;
	a = tmp;
}

int splitPoint (int arr[], int begin, int end) {
	int pivot = arr[begin];
	int left = begin + 1;

	for(int i = left; i <= end; ++i) {

		if (arr[i] < pivot) {

			if (i != left) {
				swap(arr[left], arr[i]);
			}
			++left;
		}
	}

	arr[begin] = arr[left - 1];
	arr[left - 1] = pivot;

	return left - 1;


}

void qSortArr (int arr[], int begin, int end) {

	if(begin < end) {

		int split = splitPoint(arr, begin, end);
		qSortArr(arr, begin, split - 1);
		qSortArr(arr, split + 1, end);
	}
}

void printArr(int arr[], int length) {
	for (int i = 0; i < length; ++i) {
		std::cout << arr[i] << ' ';
	}
}