/*
Hailee Tran
CS 37
Homework 2
*/
#include <iostream>
#include<fstream>
using namespace std;

//function template to print an array

template <class T>

void printarray(T* a, const int n)

{

    for (int i = 0; i < n; i++)

        cout << a[i] << " ";

    cout << endl;

}
/* allow the user to enter the array data from the keyboard*/
template<class T>
void insertData(T* a, const int n)
{
    cout << "Enter " << n << " elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> *(a + i);
    }

}
/* print the smallest and second smallest values for an array *without sorting**/
template<class T>
void printSmallestAndSecondSmallest(T* a, const int n)
{
    //find smallest
    T smallest = *(a + 0);
    for (int i = 0; i < n; i++)
    {
        if (smallest > *(a + i))
        {
            smallest = *(a + i);
        }
    }
    //Find second smallest
    T secondSmallest = *(a + 1);
    for (int i = 0; i < n; i++)
    {
        if (secondSmallest > *(a + i) && *(a + i) != smallest)
        {
            secondSmallest = *(a + i);
        }
    }
    cout << "Smallest = " << smallest << " Second smallest: " << secondSmallest << endl;
}
/*sort the array data in descending order*/
template<class T>
void sort(T* a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(a + i) < *(a + j))
            {
                T temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }
}
/*save the array data to a text file*/
template<class T>
void save(T* a, const int n)
{
    //open file
    ofstream outfile("output.txt");
    if (!outfile)
    {
        cout << "FILE NOT FOUND!!!" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        outfile << *(a + i) << " ";
    }
    outfile << endl;
    //close the stream
    outfile.close();
}
/*retrieve the array data from the text file*/
template<class T>
void getDataFromFile(T* a, const int size)
{
    //open file to read
    ifstream infile("output.txt");
    if (!infile)
    {
        cout << "FILE NOT FOUND!!!" << endl;
        return;
    }
    int i = 0;
    while (infile >> *(a + i))
    {
        i++;
    }
    infile.close();
}
int main()

{

    const int n1 = 5, n2 = 7, n3 = 6;

    int a[n1] = { 2, 4, 6, 8, 10 };

    float b[n2] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };

    char c[n3] = "HELLO";

    cout << "the integer array" << endl;
    //Test all the functions
    printarray(a, n1);
    insertData(a, n1);
    printSmallestAndSecondSmallest(a, n1);
    cout << "Sort Integer array: ";
    sort(a, n1);
    printarray(a, n1);
    //Save data to file
    save(a, n1);
    cout << "\nretrieve data from file: " << endl;
    int d[n1];
    getDataFromFile(d, n1);
    printarray(d, n1);
    cout << "the float array" << endl;

    printarray(b, n2);
    insertData(b, n2);
    printSmallestAndSecondSmallest(b, n2);
    cout << "Sort float array: ";
    sort(b, n2);
    printarray(b, n2);
    //Save data to file
    save(b, n2);
    cout << "\nretrieve data from file: " << endl;
    float e[n2];
    getDataFromFile(e, n2);
    printarray(e, n2);
    cout << "the string is" << endl;

    printarray(c, n3);
    insertData(c, n3);
    printSmallestAndSecondSmallest(c, n3);
    cout << "Sort char array: ";
    sort(c, n3);
    printarray(c, n3);
    //Save data to file
    save(c, n3);
    cout << "\nretrieve data from file: " << endl;
    char f[n3];
    getDataFromFile(f, n3);
    printarray(f, n3);
    return 0;
}
/*
the integer array
2 4 6 8 10
Enter 5 elements
45 67 23 42 44
Smallest = 23 Second smallest: 42
Sort Integer array: 67 45 44 42 23

retrieve data from file:
67 45 44 42 23
the float array
1.1 2.2 3.3 4.4 5.5 6.6 7.7 
Enter 7 elements
4.5 2.3 4.5 1.2 6.7 1.1 1.9
Smallest = 1.1 Second smallest: 1.2
Sort float array: 6.7 4.5 4.5 2.3 1.9 1.2 1.1

retrieve data from file:
6.7 4.5 4.5 2.3 1.9 1.2 1.1
the string is 
H E L L O
Enter 6 elements
JIMMIE
Smallest: E Second smallest: I
Sort char array: M M J I I E

retrieve data from file:
M M J I I E

*/