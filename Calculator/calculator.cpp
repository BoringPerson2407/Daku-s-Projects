// Date: 27/01/2025
// Project: Calculator
// Project function: Simple calculator that can add, sub, mult, div, mod and expo of two numbers

#include<iostream>
#include<cmath>
using namespace std;

float add(float* num1, float* num2);
float sub(float* num1, float* num2);
float mult(float* num1, float* num2);
float div(float* num1, float* num2);
float modul(float* num1, float* num2);
float expo(float* num1, float* num2);

int main()
{   
    float num1, num2;
    cout << "Enter num1 and num2: ";
    cin >> num1 >> num2;

    char op;
    cout << "Enter the operator: ";
    cin >> op;

    switch (op)
    {
    case '+':
        cout << "sum: " << add(&num1, &num2) << endl;
        break;
    
    case '-':
        cout << "sub: " << sub(&num1, &num2) << endl;
        break;
    
    case '*':
        cout << "mult: " << mult(&num1, &num2) << endl;
        break;
    
    case '/':
        cout << "div: " << div(&num1, &num2) << endl;
        break;
    
    case '%':
        cout << "mod: " << modul(&num1, &num2) << endl;
        break;
    
    case '^':
        cout << "expo: " << expo(&num1, &num2) << endl;
        break;
    default:
        cout << "Invalid operator" << endl;
        break;
    }
    return 0;
}
float add(float* num1, float* num2)
{
    return *num1 + *num2;
}
float sub(float* num1, float* num2)
{
    return *num1 - *num2;
}
float mult(float* num1, float* num2)
{
    return (*num1) * (*num2);
}
float div(float* num1, float* num2)
{
    return (*num1) / (*num2);
}
float modul(float* num1, float* num2)
{
    return fmod(*num1, *num2);
}
float expo(float* num1, float* num2)
{
    return pow(*num1, *num2);
}
