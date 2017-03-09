// This is a function u want to write in C and run in Python.

int fact(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    { 
        return n * fact(n - 1);
    }
}