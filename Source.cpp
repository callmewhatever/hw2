#include <iostream>
#include <typeinfo>
#include <fstream>

using namespace std;

template <class T>
void inputuser(T* a, const int n)
{

	for (int i = 0; i < n; i++)
	{

		cin >> a[i];

	}

	cout << endl;

}

template <class T>
void smallest(T* a, const int n)
{

	T smallest = a[0];
	T sec_smallest;

	int i;
	int num = n;

	if (a[num - 1] == '\0')
	{

		num--;

	}

	for (i = 0; i < num; i++)
	{

		if (smallest > a[i])
		{

			smallest = a[i];

		}

	}

	if (a[0] != smallest)
	{

		sec_smallest = a[0];

	}

	else
	{

		sec_smallest = a[1];

	}

	for (i = 0; i < num; i++)
	{

		if (a[i] == smallest)
		{

			continue;

		}

		if (sec_smallest > a[i])
		{

			sec_smallest = a[i];

		}

	}

	cout << "This is the smallest value: " << smallest << endl;
	cout << "This is the second smallest value: " << sec_smallest << endl;

}

template <class T>
void sortdec(T* a, const int n)
{

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n - 1; j++)
		{

			if (a[j] < a[j + 1])
			{

				T temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;

			}

		}

	}

	for (int i = 0; i < n; i++)
	{

		cout << a[i] << "  ";

	}

	cout << endl;

}

template <class T>
void savefile(T* a, const int n, string filename)
{

	ofstream outfile(filename, ios::out);

	for (int i = 0; i < n; i++)
	{

		outfile << a[i] << endl;

	}

	outfile.close();

}

template<class T>
void readfile(T* a, const int n, string filename)
{

	ifstream infile(filename, ios::in);

	for (int i = 0; i < n; i++)
	{

		T temp;
		infile >> a[i];

	}

	infile.close();
}

template<class T>
void print(T* a, const int n)
{

	for (int i = 0; i < n; i++)
	{

		cout << a[i] << "  ";

	}

	cout << endl;

}

int main()
{

	const int n1 = 5, n2 = 7, n3 = 6;
	int a[n1];
	float b[n2];
	char c[n3];

	cout << "Please enter int values: " << endl;
	inputuser(a, n1);
	cout << "Please enter float values: " << endl;
	inputuser(b, n2);
	cout << "Please enter char values: " << endl;
	inputuser(c, n3);

	cout << "--------------------------------------" << endl << endl;

	cout << "Int array:" << endl;
	smallest(a, n1);
	cout << endl << "Float array:" << endl;
	smallest(b, n2);
	cout << endl << "Char array:" << endl;
	smallest(c, n3);

	cout << endl << "--------------------------------------" << endl << endl;

	cout << "Int array sorted in decending order: " << endl;
	sortdec(a, n1);
	cout << endl << "Float array sorted in decending order: " << endl;
	sortdec(b, n2);
	cout << endl << "Char array sorted in decending order: " << endl;
	sortdec(c, n3);

	cout << endl << "--------------------------------------" << endl << endl;

	cout << "The int array: " << endl;
	print(a, n1);
	cout << endl << "The float array: " << endl;
	print(b, n2);
	cout << endl << "The char array: " << endl;
	print(c, n3);

	savefile(a, n1, "d:\\int_array.txt");
	savefile(b, n2, "d:\\float_array.txt");
	savefile(c, n3, "d:\\char_array.txt");

	int a1[n1];
	float b1[n2];
	char c1[n3];

	readfile(a1, n1, "d:\\int_array.txt");
	readfile(b1, n2, "d:\\float_array.txt");
	readfile(c1, n3, "d:\\char_array.txt");

	cout << endl << "--------------------------------------" << endl << endl;

	cout << "Printed values from read file: " << endl << endl;
	cout << "The int array: " << endl;
	print(a1, n1);
	cout << endl << "The float array: " << endl;
	print(b1, n2);
	cout << endl << "The char array: " << endl;
	print(c1, n3);

	return 0;

}