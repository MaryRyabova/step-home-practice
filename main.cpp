#include <iostream>
#include <cmath>

using namespace std;

//Задано натуральное число n. Определить есть  ли  среди  чисел n+1, n+2,..., 2*n близнецы, 
//т.е. простые  числа,  разность  между которыми равна двум. (Определить процедуру,  позволяющую  
//распоз­навать простые числа.

bool simpleNum( int userNum )
{

	bool result = true;

	if (userNum % 2 == 0)
	{
		result =  false;

	}

	for (int i = 3; i < floor(sqrt(userNum) + 0.5); i++)
	{
		if (userNum % i == 0)
			result = false;
	}

	return result;
}

void main()
{
	int userMainNum;
	bool isNumSimple;

	cout << "Enter number:";
	cin >> userMainNum;


	int countSimpleNum = 0;

	for (int i = userMainNum; i < 2 * userMainNum; i++)
	{
		isNumSimple = simpleNum(i);
		if (isNumSimple)
		{
			cout << i << endl;
			countSimpleNum++;

		}
	}

	int *resMas = new int[countSimpleNum];
	int j = 0;

	for (int i = userMainNum; i < 2 * userMainNum; i++)
	{
		isNumSimple = simpleNum(i);
		if (isNumSimple)
		{
			resMas[j] = i;
			j++;
		}
	}

	printf("Number twins betwen %i to %i\n", userMainNum, userMainNum * 2);
	for (int i = 0; i < countSimpleNum; i++)
	{
		if (resMas[i + 1] - resMas[i] == 2)
		{
			cout << resMas[i] << " - " << resMas[i + 1] << endl;
		}
	}

	delete[]resMas;
	system("pause");
}
