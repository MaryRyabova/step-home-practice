#include <iostream>
using namespace std;

/*ќднажды известный профессор обнаружил описани€ k конечных автоматов. 
ѕо его мнению, нетривиальность конечного автомата, имеющего n состо€ний и m переходов, 
можно описать целым числом d = 19m + (n + 239)*(n + 366) / 2 . 
„ем больше d, тем больший интерес дл€ науки представл€ет изучение его свойств.
ѕомогите профессору вычислить нетривиальность имеющихс€ у него автоматов и определить самый интересный из них. */

void main()
{
	int n, m, counter = 0;
	char answer;
	double d;
	double *resMas = new double[counter];

	do
	{
		cout << "How much states do you have?";
		cin >> n;

		cout << "How much transitions do you have?";
		cin >> m;

		d = double(19 * m + (n + 239) * (n + 366) / 2);
		resMas[counter] = d;
		counter++;


		cout << "Do you want rapid enetering the data? (y/n)";
		cin >> answer;

	} while (answer != 'n');

	cout << endl;

	for (int i = 0; i < counter; i++)
	{
		cout << resMas[i] << endl;
	}

	cout << endl;

	double maxVal;
	for (int i = 0; i < counter; i++)
	{
		for (int j = i + 1; j < counter; j++)
		{
			if (resMas[i] < resMas[j])
				maxVal = resMas[j];
			else
				maxVal = resMas[i];
		}
	}

	cout << maxVal << endl;
	system("pause");
}
