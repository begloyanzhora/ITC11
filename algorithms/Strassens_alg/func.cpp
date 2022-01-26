#include <iostream>

int** inputMatrix(int n) {

	int** matrix = new int* [n];

	for (int i = 0; i < n; ++i) {

		matrix[i] = new int [n];
		for (int j = 0; j < n; ++j) {
			std::cin >> matrix[i][j];
		}
	}

	return matrix;
}

void printMatrix(int** matrix, int n) {

	for (int i = 0; i < n; ++i) {

		for (int j = 0; j < n; ++j) {
			std::cout << matrix[i][j] << " ";
		}

		std::cout << std::endl;
	}
}

int** sum (int **a, int **b, int n) {

    int **res = new int *[n];

    for (int i = 0; i < n; ++i){
        res[i] = new int [n];
        for (int j = 0; j < n; ++j){
            res[i][j] = a[i][j] + b[i][j];
        }
    }

    return res;
}

int** mulStrass(int** a, int** b, int n) {

	int** res =  new int* [n];
	for (int i = 0; i < n; i++) {
		res[i] = new int [n];
	}

	if (n == 1) {
		res[0][0] = a[0][0] * b[0][0];

		return res;
	}

	if (n == 2) {

		int P, Q, R, S, T, U, V;

		P = (a[0][0] + a[1][1]) *  (b[0][0] + b[1][1]);
		Q = (a[1][0] + a[1][1]) * b[0][0];
		R = a[0][0] * (b[0][1] - b[1][1]);
		S = a[1][1] * (b[1][0] - b[0][0]);
		T = (a[0][0] + a[0][1]) * b[1][1];
		U = (a[1][0] - a[0][0]) *  (b[0][0] + b[0][1]);
		V = (a[0][1] - a[1][1]) *  (b[1][0] + b[1][1]);

		res[0][0] = P + S - T + V;
		res[0][1] = R + T;
		res[1][0] = Q + S;
		res[1][1] = P + R - Q + U;

		return res;
	}

	int m = n / 2;

	int** a11 = new int* [m];
	int** a12 = new int* [m];
	int** a21 = new int* [m];
	int** a22 = new int* [m];

	int** b11 = new int* [m];
	int** b12 = new int* [m];
	int** b21 = new int* [m];
	int** b22 = new int* [m];

	for (int i = 0; i < m; ++i) {
		a11[i] = new int[m];
		for (int j = 0; j < m; ++j) {
			a11[i][j] = a[i][j];
		}
	}

	for (int i = 0; i < m; ++i) {
		a12[i] = new int[m];
		for (int j = m, y = 0; j < n, y < m; ++j, ++y) {
			a12[i][y] = a[i][j];
		}
	}

	for (int i = m, x = 0; i < n, x < m; ++i, ++x) {
		a21[x] = new int[m];
		for (int j = 0; j < m; ++j) {
			a21[x][j] = a[i][j];
		}
	}

	for (int i = m, x = 0; i < n, x < m; ++i, ++x) {
		a22[x] = new int[m];
		for (int j = m, y = 0; j < n, y < m; ++j, ++y) {
			a22[x][y] = a[i][j];
		}
	}

	for (int i = 0; i < m; ++i) {
		b11[i] = new int[m];
		for (int j = 0; j < m; ++j) {
			b11[i][j] = b[i][j];
		}
	}

	for (int i = 0; i < m; ++i) {
		b12[i] = new int[m];
		for (int j = m, y = 0; j < n, y < m; ++j, ++y) {
			b12[i][y] = b[i][j];
		}
	}

	for (int i = m, x = 0; i < n, x < m; ++i, ++x) {
		b21[x] = new int[m];
		for (int j = 0; j < m; ++j) {
			b21[x][j] = b[i][j];
		}
	}

	for (int i = m, x = 0; i < n, x < m; ++i, ++x) {
		b22[x] = new int[m];
		for (int j = m, y = 0; j < n, y < m; ++j, ++y) {
			b22[x][y] = b[i][j];
		}
	}

	int** res11 = sum(mulStrass(a11, b11, m), mulStrass(a12, b21, m), m);
	int** res12 = sum(mulStrass(a11, b12, m), mulStrass(a12, b22, m), m);
	int** res21 = sum(mulStrass(a21, b11, m), mulStrass(a22, b21, m), m);
	int** res22 = sum(mulStrass(a21, b12, m), mulStrass(a22, b22, m), m);

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			res[i][j] = res11[i][j];
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = m, y = 0; j < n, y < m; ++j, ++y) {
			res[i][j] = res12[i][y];
		}
	}

	for (int i = m, x = 0; i < n, x < m; ++i, ++x) {
		for (int j = 0; j < m; ++j) {
			res[i][j] = res21[x][j];
		}
	}

	for (int i = m, x = 0; i < n, x < m; ++i, ++x) {
		for (int j = m, y = 0; j < n, y < m; ++j, ++y) {
			res[i][j] = res22[x][y];
		}
	}

	delete a11;
	delete a12;
	delete a21;
	delete a22;

	delete b11;
	delete b12;
	delete b21;
	delete b22;

	delete res11;
	delete res12;
	delete res21;
	delete res22;

	return res;
}