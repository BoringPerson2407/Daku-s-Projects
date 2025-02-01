// Date: 30/01/2025
// Project: Matrix_Operations
// Program functionality: It's main functionality is to do matrix operations
// Status: work in progress

#include<iostream>
#include<vector>
#include<random>

using namespace std;

class matrix
{
    private:
        vector<vector<int>> mat;
    public:
        int row, column;
        matrix(int r, int c, int val) : row(r), column(c), mat(r, vector<int>(column, val)) {} // initializer 
        void print();   // function to print the value
        void set_mat(); // function to set value of the matrix
        void set_el(int i, int j, int val); // function to set the value of the elements of the matrix
        void set_rand_val(int start, int end); // function to set the value of matrix with randomly generated integers between start and end
        vector<vector<int>> get_mat() const; // getter function

};
matrix add(const matrix& m1, const matrix& m2); // function to add two matrices and assisgn their res;
bool issamedime(const matrix& m1, const matrix& m2); // function to check if the two matrices have same dimensions;

int main()
{   
    srand(time(0));
    matrix m1(3,3,0);
    matrix m2(3,3,0);
    m1.set_rand_val(1, 10);
    m2.set_rand_val(1, 10);
    m1.print();
    cout << endl;
    m2.print();
    matrix re = add(m1, m2);
    re.print();
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
            cout << "Enter value(" << i << "," << j <<"): ";
            cin >> mat[i][j];
            cout << endl;
        }
    }
}
void matrix :: set_el(int i, int j, int val)
{
    if (i>=0 && i<row && j>=0 && j<column)
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
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            mat[i][j] = rand() % end + start;
        } 
    }
    
}
bool issamedime(const matrix& m1, const matrix& m2)
{
    if (m1.row==m2.row && m1.column==m2.column)
    {
        return true;
    }
    return false;
}
vector<vector<int>> matrix :: get_mat() const
{
    return mat;
}
matrix add(const matrix& m1, const matrix& m2)
{
    if (!issamedime(m1, m2))
    {
        cerr << "ERROR: matrices must have same dimensions to perform matrix adddition.";
        exit(EXIT_FAILURE);
    }

    matrix r(m1.row, m1.column, 0);
    for (int i = 0; i < m1.row; i++)
    {
        for (int j = 0; j < m1.column; j++)
        {
            r.set_el(i, j , (m1.get_mat()[i][j] + m2.get_mat()[i][j]));
        }
    }
    
    return r;
}