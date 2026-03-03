#include <bits/stdc++.h>
#include <conio.h>

using namespace std;
int matrix_global[50][50];

short key;
int a[50][50], aa[50][50], bb[50][50], result[50][50], n, m, k, l, p, filter_mat[50][50], image_mat[50][50];
float inv_mat[50][50];

void read_square_matrix();
void display_inv_matrix(float a[50][50]);
void read_matrix(int a[50][50], int n, int m);
void display_matrix(int a[50][50], int n, int m);
void addition();
void subtraction();
void multiplication();
void scalar_multiplication();
void power_elevation();
int determinant(int a[50][50], int n);
void inverse();
void transposition();
void convolution();

void menu()
{
    cout << "Application Menu\n\n";
    cout << "1.Addition of 2 matrices\n";
    cout << "2.Subtraction of 2 matrices\n";
    cout << "3.Multiplication of 2 matrices\n";
    cout << "4.Scalar multiplication of a matrix\n";
    cout << "5.Raise matrix to a power\n";
    cout << "6.Matrix determinant\n";
    cout << "7.Matrix inverse\n";
    cout << "8.Matrix transposition\n";
    cout << "9.Convolution of 2 matrices\n";
    cout << "0.Exit\n\n";
    cout << "Option: ";
}

int main()
{
    do
    {
        menu();
        cin >> key;
        switch (key)
        {
        case 1:
            // Read number of rows and columns
            cout << "Number of rows=";
            cin >> n;
            cout << "Number of columns=";
            cin >> m;
            // Read first matrix
            cout << "Read first matrix\n";
            read_matrix(aa, n, m);
            // Read second matrix
            cout << "Read second matrix\n";
            read_matrix(bb, n, m);
            // Addition
            addition();
            // Display first matrix
            cout << "Display first matrix\n";
            display_matrix(aa, n, m);
            // Display second matrix
            cout << "Display second matrix\n";
            display_matrix(bb, n, m);
            // Display sum matrix
            cout << "Display sum matrix\n";
            display_matrix(result, n, m);
            getch();
            break;
        case 2:
            // Read number of rows and columns
            cout << "Number of rows=";
            cin >> n;
            cout << "Number of columns=";
            cin >> m;
            // Read first matrix
            cout << "Read first matrix\n";
            read_matrix(aa, n, m);
            // Read second matrix
            cout << "Read second matrix\n";
            read_matrix(bb, n, m);
            // Subtraction
            subtraction();
            // Display first matrix
            cout << "Display first matrix\n";
            display_matrix(aa, n, m);
            // Display second matrix
            cout << "Display second matrix\n";
            display_matrix(bb, n, m);
            // Display difference matrix
            cout << "Display difference matrix\n";
            display_matrix(result, n, m);
            getch();
            break;
        case 3:
            // Read number of rows and columns
            cout << "First matrix:\n";
            cout << "Number of rows=";
            cin >> n;
            cout << "Number of columns=";
            cin >> m;
            // Read first matrix
            read_matrix(aa, n, m);
            // Read number of rows and columns
            cout << "Second matrix:\n";
            cout << "The number of rows must be equal to the number of columns of the first matrix\n";
            cout << "Number of rows=";
            cin >> k;
            cout << "Number of columns=";
            cin >> l;
            // Read second matrix
            read_matrix(bb, k, l);
            // Multiplication and display
            if (k == m)
            {
                multiplication();
                // Display first matrix
                cout << "First matrix\n";
                display_matrix(aa, n, m);
                // Display second matrix
                cout << "Second matrix\n";
                display_matrix(bb, k, l);
                // Display multiplication matrix
                cout << "Display multiplication matrix\n";
                display_matrix(result, n, l);
            }
            else
            {
                cout << "Matrices cannot be multiplied!";
            }
            getch();
            break;
        case 4:
            // Read scalar
            cout << "Scalar: ";
            cin >> p;
            // Read number of rows and columns
            cout << "Number of rows: ";
            cin >> n;
            cout << "Number of columns: ";
            cin >> m;
            // Read matrix
            cout << "Matrix:\n";
            read_matrix(a, n, m);
            // Perform multiplication
            scalar_multiplication();
            // Display scalar
            cout << "Scalar: " << p;
            cout << "\n";
            // Display result matrix
            cout << "Result matrix:\n";
            display_matrix(result, n, m);
            getch();
            break;
        case 5:
            // Read
            cout << "Power(positive)= ";
            cin >> p;
            // Raise to power
            if (p < 1)
            {
                cout << "\nError in choosing the power!";
            }
            if (p == 1)
            {
                // Read matrix
                read_square_matrix();
                // Display matrix
                cout << "The matrix remains unchanged!\n";
                display_matrix(a, n, n);
            }
            if (p > 1)
            {
                // Read matrix
                read_square_matrix();
                // Power elevation
                power_elevation();
                // Display result matrix
                cout << "Result matrix:\n";
                display_matrix(result, n, n);
            }
            getch();
            break;
        case 6:
            // Read matrix
            read_square_matrix();
            // Display determinant
            cout << "Determinant: " << determinant(a, n);
            getch();
            break;
        case 7:
            // Read matrix
            read_square_matrix();
            if (determinant(a, n) != 0)
            {
                // Calculate inverse
                inverse();
                // Display inverse matrix
                cout << "Inverse matrix:\n";
                display_inv_matrix(inv_mat);
            }
            else
            {
                cout << "Matrix cannot be inverted! Determinant equals 0!";
            }
            getch();
            break;
        case 8:
            // Read number of rows and columns
            cout << "Number of rows= ";
            cin >> n;
            cout << "Number of columns= ";
            cin >> m;
            // Read matrix
            read_matrix(a, n, m);
            // Transposition
            transposition();
            // Display initial matrix
            cout << "Initial matrix\n";
            display_matrix(a, n, m);
            // Display transposed matrix
            cout << "Transposed matrix\n";
            display_matrix(result, m, n);
            getch();
            break;
        case 9:
            // Read number of rows and columns for filter matrix
            cout << "Number of filter matrix rows= ";
            cin >> n;
            cout << "Number of filter matrix columns= ";
            cin >> m;
            cout << "Filter matrix:\n";
            // Read matrix
            read_matrix(filter_mat, n, m);
            cout << "Number of image matrix rows= ";
            cin >> k; // k > n
            cout << "Number of image matrix columns= ";
            cin >> l; // l > m
            cout << "Image matrix:\n";
            // Read matrix
            read_matrix(image_mat, k, l);
            convolution();
            cout << "Resulting matrix after convolution:\n";
            display_matrix(result, k - n + 1, l - m + 1);
            getch();
            break;
        case 0:
            break;
        default:
            cout << "Wrong option!!";
            getch();
        }
    } while (key != 0);

    return 0;
}

void read_square_matrix()
{
    // Read matrix
    int i, j;
    cout << "Square matrix:\n";
    cout << "n= ";
    cin >> n;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];
}

void display_inv_matrix(float a[50][50])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << a[i][j] << ' ';

        cout << "\n";
    }
}

void read_matrix(int a[50][50], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> a[i][j];

    cout << "\n";
}

void display_matrix(int a[50][50], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}

void addition()
{
    int i, j;

    // Matrix addition
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            result[i][j] = aa[i][j] + bb[i][j];
}

void subtraction()
{
    int i, j;

    // Matrix subtraction
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            result[i][j] = aa[i][j] - bb[i][j];
}

void multiplication()
{
    int i, j, h;

    // Matrix multiplication
    for (i = 0; i < n; i++)
        for (j = 0; j < l; j++) // corrected to use l (columns of second matrix)
        {
            result[i][j] = 0;
            for (h = 0; h < m; h++)
                result[i][j] += aa[i][h] * bb[h][j];
        }
}

void scalar_multiplication()
{
    int i, j;

    // Multiply matrix by scalar
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            result[i][j] = a[i][j] * p;
}

void power_elevation()
{
    int aux[50][50], i, j, h;

    // Raise to power
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            result[i][j] = a[i][j];
    int nr = 1;
    while (nr < p)
    {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            {
                aux[i][j] = 0;
                for (h = 0; h < n; h++)
                    aux[i][j] += result[i][h] * a[h][j];
            }

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                result[i][j] = aux[i][j];
        nr++;
    }
}

int determinant(int a[50][50], int n)
{
    int i, j;

    // Calculate determinant
    int det = 0;
    if (n == 1)
    {
        det = a[0][0];
    }
    if (n == 2)
    {
        det = a[0][0] * a[1][1] - a[0][1] * a[1][0];
    }
    if (n > 2)
    {
        // Using a temporary copy to avoid modifying original 'a' globally
        int temp_a[100][50];
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                temp_a[i][j] = a[i][j];

        for (i = n; i < n * 2 - 1; i++)
            for (j = 0; j < n; j++)
                temp_a[i][j] = temp_a[i - n][j];

        int prod1, prod2;
        for (i = 0; i < n; i++)
        {
            prod1 = 1;
            prod2 = 1;
            for (j = 0; j < n; j++)
            {
                prod1 *= temp_a[i + j][j];
                prod2 *= temp_a[i + j][n - j - 1];
            }
            det += prod1;
            det -= prod2;
        }
    }

    return det;
}

void inverse()
{
    int helper_mat[50][50], adj_mat[50][50], b[50][50], i, j;

    // calculate determinant
    int determ = determinant(a, n);
    if (determ != 0) // check if invertible
    {
        // create transpose in b
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                b[j][i] = a[i][j];

        // construct adjugate
        int x, y, helper_det;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            {
                int o_idx, p_idx;
                o_idx = p_idx = 0;
                for (x = 0; x < n; x++)
                    for (y = 0; y < n; y++)
                        if (x != i && y != j)
                        {
                            if (p_idx < (n - 1))
                            {
                                helper_mat[o_idx][p_idx] = b[x][y];
                                p_idx++;
                            }
                            else
                            {
                                p_idx = 0;
                                o_idx++;
                                helper_mat[o_idx][p_idx] = b[x][y];
                            }
                        }
                helper_det = determinant(helper_mat, n - 1);
                adj_mat[i][j] = helper_det;
            }
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if ((i + j) % 2 != 0)
                    adj_mat[i][j] *= -1;

        // calculate inverse
        float q;
        q = 1.0 / determ;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                inv_mat[i][j] = q * adj_mat[i][j];
    }
}

void transposition()
{
    int i, j;

    // Create transposed matrix in result
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            result[j][i] = a[i][j];
}

void convolution()
{
    int i, j, ki, kj, x = k - n + 1, y = l - m + 1; // Dimensions of result matrix
    // Traverse each valid position in the large matrix where the filter can be applied
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            int sum = 0;
            // Apply filter on the current area of the large matrix
            for (ki = 0; ki < n; ki++)
                for (kj = 0; kj < m; kj++)
                    sum += image_mat[i + ki][j + kj] * filter_mat[ki][kj];
            result[i][j] = sum;
        }
    }
}
