#include "bits/stdc++.h"
using namespace std;
char tab[9][9];

//imprimir tabuleiro
void print_tab(int n)
{
	cout << "tabuleiro Caso " << n << " :" << endl;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout << tab[i][j]-'0';
		}
		cout << endl;
	}
}
//checar linhas e colunas
void check_row_col()
{

}

int main(int argc, char const *argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string line;

	int num_cases = 0;
	cin >> num_cases;
	int counter = 1;
	getline(cin, line);
	while(num_cases)
	{	
		//reading tab...
		for (int i = 0; i < 9; ++i)
		{
			getline(cin, line);
			//cout << "line = " << line << endl;
			for (int j = 0; j < 9; ++j)
			{
				tab[i][j] = (char)line[j];
			}
		}
		print_tab(counter);

		//execution...
		
		++counter;
		--num_cases;
	}
	return 0;
}