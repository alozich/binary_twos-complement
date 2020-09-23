//This program converts numbers to binary and Two's complement

#include <iostream>
#include <iomanip>
using namespace std;

const int numBits = 8;
const int numDigits = 128;
const int numNums = 256;

void calcBin(int num);
void calcTwos(int num);

int main()
{
	cout << "Converting to binary..." << endl;
	for (int i = 0; i < numNums; i++)
	{
		cout << right << setw(3) << i << setw(5);
		calcBin(i);
		cout << endl;
	}

	cout << endl << "Two's complement..." << endl;
	for (int i = -(numDigits); i < numDigits; i++) //from -(numDigits) to (numDigits)
	{
		cout << right << setw(3) << i << setw(5);
		calcTwos(i);
		cout << endl;
	}
}

void calcBin(int num)
{
	for (int i = numDigits; i >= 1; (i /= 2))
	{
		if (num >= i)
		{
			cout << "1";
			num -= i;
		}
		else
		{
			cout << "0";
		}
	}
}

void calcTwos(int num)
{
	if (num < 0) //if negative number
	{
		cout << "1";

		for (int i = (numDigits / 2); i >= 1; (i /= 2)) //for each bit
		{
			if (abs(num) > i)
			{
				cout << "0";
				num += i;
			}
			else
			{
				cout << "1";
			}
		}
	}
	else //if positive number
	{
		cout << "0"; 

		for (int i = (numDigits / 2); i >= 1; (i /= 2)) //for each bit
		{
			if (num >= i)
			{
				cout << "1";
				num -= i;
			}
			else
			{
				cout << "0";
			}
		}
	}
}