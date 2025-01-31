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
        int row, column;
        vector<vector<int>> mat;
    public:
        matrix(int r, int c, int val) : row(r), column(c), mat(r, vector<int>(column, val)) {} // initializer 
        void print();   // function to print the value
        void set_val(); // function to set value of the matrix
        void set_rand_val(int start, int end); // function to set the value of matrix with randomly generated integers between start and end



};
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
void matrix :: set_val()
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
void matrix :: set_rand_val(int start, int end)
{
    srand(time(0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < j; j++)
        {
            mat[i][j] = rand() % end + start;
        } 
    }
    
}
int main()
{   
    matrix m1(3,3,0);
    m1.print();
    cout << endl;
    m1.set_rand_val(1,100);
    m1.print();

    return 0;
}