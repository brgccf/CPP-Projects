#include <iostream>
#include <string>
using namespace std;
int tab[9][9];
bool finished;
int qt[10]; //contador de quantas vezes numero foi inserido no tab
//imprimir tabuleiro
inline void print_tab()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout << tab[i][j];
		}
		cout << endl;
	}
}

//checar linhas e colunas
inline bool check_row_col(int value, int row, int col)
{
	for (int i = 0; i < 9; ++i)
	{
		if(tab[row][i] == value || tab[i][col] == value)
			return false;
	}
	return true;
}
//checar linha 
inline bool check_row (int value, int row)
{
	for (int i = 0; i < 9; ++i)
	{
		if (tab[row][i] == value)
		{
			return true;
		}
	}
	return false;
}
//verificar quadrante
inline bool check_square(int value, int row, int col)
{
	row = row - row%3;
	col = col - col%3;
	for (int i = row; i < row + 3; ++i)
	{
		for (int j = col; j < col + 3; ++j)
		{
			if(value == tab[i][j]) return false;
		}
	}
	return true;
}
//verificar quadrante, linha e coluna ao mesmo tempo
inline bool possible(int value, int row, int col)
{
	return(!(tab[row][col]) && check_square(value, row, col)
		&& check_row_col(value, row, col));
}

void backtrack(int value, int row)
{
	if(finished) return;
	if(value > 9) 
	{
		print_tab();
	    finished = true;
		return;
	}
	else if (qt[value] > 8)
	{
		backtrack(value+1, 0);
	}
	if (check_row(value, row)) //se ja houver numero na linha
	{
		backtrack(value, row+1); //tenta add na linha abaixo
		return;
	}

	for (int i = 0; !finished && i < 9; ++i)
	{
		if (possible(value, row, i))
		{
			tab[row][i] = value;
			++qt[value];
			backtrack(value, row+1);
			--qt[value];
			tab[row][i] = 0;
		}
	}

}

int main()
{
	string line;
	int num_cases = 0;
	cin >> num_cases;
	getline(cin, line);
	
	while(num_cases--)
	{	
		finished = false;
		for (int i = 0; i < 10; ++i) qt[i] = 0;
		//reading tab...
		for (int i = 0; i < 9; ++i)
		{
			cin >> line;
			for (int j = 0; j < 9; ++j)
			{
				tab[i][j] = line[j]-'0';
				++qt[tab[i][j]];
			}
		}

		//execution...
		backtrack(1, 0);
	}
	return 0;
}