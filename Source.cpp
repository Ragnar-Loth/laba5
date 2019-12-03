#include <iostream>
using namespace std;

class Matrix {
private:
	int matr1x[5];
public:
	void inputelement(int a) {
		cin >> matr1x[a];
	}
	void sMatrix(int a) {
		static int arraysize = 0;
		matr1x[arraysize] = a;
		if (arraysize == 4) arraysize = -1;
		arraysize++;
	}

	int* getmatrix() {
		return matr1x;
	}

	friend void outputMatrix(Matrix* A, int n);


	void merge(int start, int mid, int end) {
		int t[5];
		int i = start, j = mid + 1, k = 0;

		while (i <= mid && j <= end) {
			if (this->matr1x[i] <= this->matr1x[j]) {
				t[k] = this->matr1x[i];
				k++;
				i++;
			}
			else {
				t[k] = this->matr1x[j];
				k++;
				j++;
			}
		}

		while (i <= mid) {
			t[k] = this->matr1x[i];
			k++;
			i++;
		}

		while (j <= end) {
			t[k] = this->matr1x[j];
			k++;
			j++;
		}
		for (i = start; i <= end; i++) {
			this->matr1x[i] = t[i - start];
		}
	}

	void mergeSort(int start, int end) {

		if (start < end) {
			int mid = (start + end) / 2;
			mergeSort(start, mid);
			mergeSort(mid + 1, end);
			merge(start, mid, end);
		}

	}
};

void outputMatrix(Matrix* matr1x, int n) {
	for (int i = 0; i < n; ++i)
	{
		cout << matr1x->matr1x[i];
	}
	cout << endl;
}


int main() {
	Matrix matrix[5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			matrix[j].inputelement(i);
		}
	Matrix matrix1;
	for (int i = 0; i < 5; i++)
		matrix[i].mergeSort(0, 4);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << matrix[j].getmatrix()[i] << "\t ";
			matrix1.sMatrix(matrix[j].getmatrix()[i]);
		}
		cout << endl;
	}
	double sum = 0;
	int f1 = 1, f2 = 1, f3 = 1, f4 = 1;
	for (int i = 0; i < 4; i++) {                                  // f1
		f1 *= matrix[i].getmatrix()[0];
	}
	for (int i = 0; i < 3; i++) {                                  // f1
		f2 *= matrix[i].getmatrix()[1];
	}
	for (int i = 0; i < 2; i++) {                                  // f1
		f3 *= matrix[i].getmatrix()[2];
	}
	for (int i = 0; i < 1; i++) {                                  // f1
		f4 *= matrix[i].getmatrix()[3];
	}
	cout << "\n";
	sum = (f1 + f2 + f3 + f4);
	cout << "f1(): " << f1 << "\n" << "f2(): " << f2 << "\n" << "f3(): " << f3 << "\n" << "f4(): " << f4 << "\n\n";
	cout << "F(f()): " << sum << "\n";

	return 0;
}