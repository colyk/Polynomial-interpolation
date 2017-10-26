#include<iostream>
using namespace std;

int min_(int *tab, int len)
{
	int i;
	int min_dig = tab[0];
	for (i = 0; i < len; i++) if (tab[i] < min_dig) min_dig = tab[i];
	return min_dig;
}


int max_(int *tab, int len)
{
	int i;
	int max_dig = tab[0];
	for (i = 0; i < len; i++) if (tab[i] > max_dig) max_dig = tab[i];
	return max_dig;
}


float* fi(int *tab_x, int *tab, int len)
{
	int i, j;
	int copy_f[20];
	for (i = 0; i <= len; i++) copy_f[i] = tab[i];
	float *result = new float [20];
	for (i = 0; i < len; i++)
	{
		result[i] = copy_f[i];
		for (j = len - 1; j > 0; j--)
		{
			if (j == i - 1) continue;
			copy_f[j] = float(float(copy_f[j]) - copy_f[j - 1]) / (float(tab_x[j]) - tab_x[j - i - 1]);
		}
	}

	return result;
}


int main()
{
	int i;
	int tab_x[20];
	int tab_f[20];
	int point_x;
	int len;

	cout << "Give x elements in ascending order!\nGive the number of points: ";
	cin >> len;
	for (i = 0; i < len; i++)
	{
		cout << "Give x" << i << " point: ";
		cin >> tab_x[i];
		cout << "Give func(x" << i << "): ";
		cin >> tab_f[i];
	}
	cout << "Give a point in which you need to define the value of the function: ";
	cin >> point_x;

	int min_dig = min_(tab_x, len);
	int max_dig = max_(tab_x, len);

	if (point_x < min_dig || point_x > max_dig)
	{
        cout << "Your point must be between " << min_dig << " and " << max_dig << endl;
		return 0;
	}
	float *result_tab = new float [20];
	result_tab = fi(tab_x, tab_f, len);

	float mul = point_x - tab_x[0];
	float result = result_tab[0];
	for (i = 1; i < len; i++)
	{
		result += result_tab[i] * mul;
		mul *= (point_x - tab_x[i]);
	}

	cout << "f(" << point_x << ") = " << result;
	return 0;
}
