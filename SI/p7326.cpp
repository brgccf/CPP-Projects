#include "bits/stdc++.h"
#define max 200001
using namespace std;

typedef struct fence
{
	int r1;
	int c1;
	int r2;
	int c2;
}fence;

typedef struct flowers
{
	int r;
	int c;
}flower;

typedef struct cows
{
	int r;
	int c;
}cow;

typedef struct information
{
	int rows;
	int cols;
}info;

void print_fences(fence *pos, int qtd)
{
	cout << "Fences positions: " << endl;
	for (int i = 1; i <= qtd; ++i)
	{
		cout << "fence " << i << ":" << endl;
		cout << pos[i].r1 << " " << pos[i].c1 << endl;
		cout << pos[i].r2 << " " << pos[i].c2 << endl;
	}
}

void print_flowers(flower *pos, int qtd)
{
	cout << "Flowers positions: " << endl;
	for (int i = 1; i <= qtd; ++i)
	{
		cout << "flower " << i << ":" << endl;
		cout << pos[i].r << " " << pos[i].c << endl;
	}
}

void print_cows(cow *pos, int qtd)
{
	cout << "Cows positions: " << endl;
	for (int i = 1; i <= qtd; ++i)
	{
		cout << "cow " << i << ":" << endl;
		cout << pos[i].r << " " << pos[i].c << endl;
	}
}

void read_fences(int qtd, fence *fences)
{
	for(int i = 1; i <= qtd; ++i)
	{
		cin >> fences[i].r1;
		cin >> fences[i].c1;
		cin >> fences[i].r2;
		cin >> fences[i].c2;

	}
}

void read_flowers(int qtd, flower *flows)
{
	for (int i = 1; i <= qtd; ++i)
	{
		cin >> flows[i].r;
		cin >> flows[i].c;
	}
}

void read_cows(int qtd, cow *cows)
{
	for (int i = 1; i <= qtd; ++i)
	{
		cin >> cows[i].r;
		cin >> cows[i].c;
	}
}

int main()
{
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	string line;
	fence fences[max];
	flower flows[max];
	cow cows[max];
	fences[0].r1 = 0;
	fences[0].r2 = 0;
	fences[0].c1 = 0;
	fences[0].c2 = 0;
	int num_fences, num_cows, num_flows;
	int blocks = 1;
	int qtd = 0;
	
	//reading parameters...
	while(1)
	{
		if(!getline(cin, line)) break;
		stringstream stream(line);
		//cout << "Line: " << line << endl;
		switch(blocks)
		{
			case(1):
				stream >> qtd;
				num_fences = qtd;
				read_fences(qtd, fences);
				//print_fences(fences, qtd);
				break;
			case(2):
				stream >> qtd;
				num_flows = qtd;
				read_flowers(qtd, flows);
				//print_flowers(flows, qtd);
				break;
			case(3):
				stream >> qtd;
				num_cows = qtd;
				read_cows(qtd, cows);
				//print_cows(cows, qtd);
				break;
			default:
				cout << "default" << endl;

		}
		getline(cin, line);
		
		++blocks;
		if (blocks > 3)
		{
			blocks = 1;
			//execution...
			//array of information
			//guarda o resultado das subtracoes entre pos de flor e pos de vaca
			info info[max];
			info[0].rows = 0;
			info[0].cols = 0;
			int counter = 0; //contador para a resposta final
			bool reachable = true; //verificar se flor eh alcançavel
			//para cada vaca
			for (int i = 1; i <= num_cows; ++i)
			{
				//fazer subtracao da posicao da flor com a da vaca
				//para cada flor
				for (int j = 1; j <= num_flows; ++j)
				{
					info[i].rows = flows[j].r - cows[i].r;
					info[i].cols = flows[j].c - cows[i].c;
					if (info[i].rows < 0 || info[i].cols < 0) reachable = false;
					else
					{
						//para cada fence
						for (int k = 1; k <= num_fences; ++k)
						{
							//verificar se flor esta dentro de fence
							if((flows[j].r >= fences[k].r1 && 
								flows[j].r <= fences[k].r2) &&
								(flows[j].c >= fences[k].c1 &&
								flows[j].c <= fences[k].c2))
							{
								//se a vaca estiver fora desta fence
								if(cows[i].r < fences[k].r1 || 
									cows[i].r > fences[k].r2 ||
									cows[i].c < fences[k].c1 ||
									cows[i].c > fences[k].c2)
								reachable = false;
							}
							//verificar se nao eh inalcançavel mesmo fora da fence
							//(caso da linha - esta do outro lado da fence)
							else if((cows[i].r >= fences[k].r1 &&
								cows[i].r <= fences[k].r2) &&
								(cows[i].c < fences[k].c1) &&
								(flows[j].c > fences[k].c2) && 
								(flows[j].r <= fences[k].r2 &&
									flows[j].r >= fences[k].r1))
							{
								reachable = false;
							}
							//verificar se nao eh inalcançavel mesmo fora da fence
							//(caso da coluna - esta do outro lado da fence)
							else if((cows[i].c >= fences[k].c1 &&
								cows[i].c <= fences[k].c2) &&
								(cows[i].r < fences[k].r1) &&
								(flows[j].r > fences[k].r2) && 
								(flows[j].c >= fences[k].c1 &&
									flows[j].c <= fences[k].c2))
							{
								reachable = false;
							}
							//verificar se vaca esta dentro da fence
							else if((cows[i].r >= fences[k].r1 &&
								cows[i].r <= fences[k].r2) &&
								(cows[i].c >= fences[k].c1 &&
									cows[i].c <= fences[k].c2))
							{
								//verificar se ha flores alcançaveis dentro da fence
								
								reachable = false;
							}
						}
					}
					if(reachable) ++counter;
					reachable = true;
				}
				//imprime resultado para cada vaca
				//cout << "cow " << i << " : " << counter << endl;
				cout << counter << endl;
				counter = 0; 
			}
		}
	}

	return 0;
}