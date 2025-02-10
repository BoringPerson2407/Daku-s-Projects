#include<bits/stdc++.h>
using namespace std;

class matrix
{
    private:
        vector<vector<int>> mat;
    public:
        int row, column;
        matrix(int r, int c, int val) : row(r), column(c), mat(r, vector<int>(c, val)) {} // initializer 
        void print();   // function to print the value
        void set_mat(); // function to set value of the matrix
        void set_el(int i, int j, int val); // function to set the value of the elements of the matrix
        void set_rand_val(int start, int end); // function to set the value of matrix with randomly generated integers between start and end
        vector<vector<int>> get_mat() const; // getter function
};

matrix add(const matrix& m1, const matrix& m2); // function to add two matrices and assign their result
bool issamedime(const matrix& m1, const matrix& m2); // function to check if the two matrices have same dimensions

int main()
{   
    srand(time(0));
    matrix m(3, 3, 0); // Create a 3x3 matrix initialized with 0
    matrix m1(3, 3, 0);
    m.set_rand_val(1, 100);
    m1.set_rand_val(1, 100);
    m.print();
    cout << endl;
    m1.print();
    cout << endl;
    matrix r = add(m, m1);
    r.print();
    cout << endl;
    
    return 0;
}

void matrix :: print()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void matrix :: set_mat()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << "Enter value(" << i << "," << j << "): ";
            cin >> mat[i][j];
        }
    }
}

void matrix :: set_el(int i, int j, int val)
{
    if (i >= 0 && i < row && j >= 0 && j < column)
    {
        mat[i][j] = val;
    }
    else
    {
        cout << "Index out of range!" << endl;
    }
}

void matrix :: set_rand_val(int start, int end)
{
    if (start > end)
    {
        cerr << "ERROR: Invalid range for random values." << endl;
        return;
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            mat[i][j] = start + rand() % (end - start + 1);
        } 
    }
}

bool issamedime(const matrix& m1, const matrix& m2)
{
    return (m1.row == m2.row && m1.column == m2.column);
}

vector<vector<int>> matrix :: get_mat() const
{
    return mat;
}

matrix add(const matrix& m1, const matrix& m2)
{
    if (!issamedime(m1, m2))
    {
        cerr << "ERROR: Matrices must have the same dimensions to perform addition." << endl;
        exit(EXIT_FAILURE);
    }

    matrix r(m1.row, m1.column, 0);
    const vector<vector<int>>& mat1 = m1.get_mat();
    const vector<vector<int>>& mat2 = m2.get_mat();

    for (int i = 0; i < m1.row; i++)
    {
        for (int j = 0; j < m1.column; j++)
        {
            r.set_el(i, j, mat1[i][j] + mat2[i][j]);
        }
    }
    
    return r;
}