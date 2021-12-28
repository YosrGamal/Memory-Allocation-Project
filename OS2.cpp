
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Result
{
public:
	int block;
	int process;

	Result(int block, int process)
	{
		this->block = block;
		this->process = process;
	}
};

void erase(int x, vector<int> &p)
{

	vector<int> temp;

	for (int i = 0; i < p.size(); i++)
	{
		if (i != x)
		{ //we will ignore the process that was placed in the freeblock vector
			temp.push_back(p[i]);
		}
	}

	p.clear();
	p = temp;
}

void firstFit(int numOfBlocks, vector<int> &block, int numOfProcesses, vector<int> &process)
{
	vector<int> freeblock;
	for (int y = 0; y < numOfBlocks; y++)
	{
		freeblock.push_back(0);
	}

	for (int i = 0; i < numOfBlocks; i++)
	{
		int temp = -1;
		for (int x = 0; x < process.size(); x++)
		{
			if (block[i] >= process[x])
			{

				freeblock[i] = process[x];
				temp = x;

				break;
			}
		}
		if (temp > -1)
		{
			erase(temp, process);
			temp = -1;
		}
	}
	cout << "First fit: " << endl;
	cout << "Blocks "
		 << " "
		 << "Processes in blocks" << endl;
	for (int j = 0; j < freeblock.size(); j++)
	{
		cout << " " << block[j] << "   |    ";
		cout << freeblock[j];
		cout << endl;
	}
}

void bestFit(int numOfBlocks, vector<int> &block, int numOfProcesses, vector<int> &process)
{

	vector<Result> result;
	for (int i = 0; i < numOfBlocks; i++)
	{
		result.push_back(Result(block[i], 0));
	}

	int indexOfCurrentBest = -1;
	int subValueOfCurrBest = -1;

	for (int i = 0; i < numOfProcesses; i++)
	{

		for (int x = 0; x < result.size(); x++)
		{
			if (result[x].block >= process[i] && result[x].process == 0)
			{

				if (result[x].block == process[i])
				{
					subValueOfCurrBest = 0;
					indexOfCurrentBest = x;

					break;
				}
				else
				{
					int subVal = result[x].block - process[i];
					if (subValueOfCurrBest == -1 || subVal < subValueOfCurrBest)
					{
						subValueOfCurrBest = subVal;
						indexOfCurrentBest = x;
					}
				}
			}
		}
		if (indexOfCurrentBest >= 0)
		{
			result[indexOfCurrentBest].process = process[i]; //inserting the process in the block
			indexOfCurrentBest = -1;
			subValueOfCurrBest = -1;
		}
	}
	int counter = 0;
	cout << "Best fit: " << endl;
	cout << "Blocks"
		 << " "
		 << "Processes in blocks" << endl;
	for (int j = 0; j < result.size(); j++)
	{
		if (result[j].process == 0)
		{
			counter++;
		}
		cout << " " << result[j].block << "   |    ";
		cout << result[j].process;
		cout << endl;
	}

	int count = process.size() - result.size();
	if (count > 0)
	{
		cout << "Number of processes is bigger than available blocks therefore there is " << count + counter << " that weren't allocated in the memory" << endl;
		cout << "There was " << counter << " block of memory that remained empty" << endl;
	}
}

void worstFit(int numOfBlocks, vector<int> &block, int numOfProcesses, vector<int> &process)
{

	vector<Result> result;
	for (int i = 0; i < numOfBlocks; i++)
	{
		result.push_back(Result(block[i], 0));
	}

	int indexOfCurrentWorst = -1;
	int subValueOfCurrWorst = -1;

	for (int i = 0; i < numOfProcesses; i++)
	{

		for (int x = 0; x < result.size(); x++)
		{
			if (result[x].block >= process[i] && result[x].process == 0)
			{

				int subVal = result[x].block - process[i];
				if (subValueOfCurrWorst == -1 || subVal > subValueOfCurrWorst)
				{
					subValueOfCurrWorst = subVal;
					indexOfCurrentWorst = x;
				}
			}
		}
		if (indexOfCurrentWorst >= 0)
		{
			result[indexOfCurrentWorst].process = process[i];

			indexOfCurrentWorst = -1;
			subValueOfCurrWorst = -1;
		}
	}
	int counter = 0;
	cout << "Worst fit: " << endl;
	cout << "Blocks "
		 << " "
		 << "Processes in blocks" << endl;
	for (int j = 0; j < result.size(); j++)
	{
		if (result[j].process == 0)
		{
			counter++;
		}
		cout << " " << result[j].block << "   |    ";
		cout << result[j].process;
		cout << endl;
	}
	int count = process.size() - result.size();
	if (count > 0)
	{
		cout << "Number of processes is bigger than available blocks therefore there is " << count + counter << " that weren't allocated in the memory" << endl;
		cout << "There was " << counter << " block of memory that remained empty" << endl;
	}
}

void choose(int num, int numOfBlocks, vector<int> &block, int numOfProcesses, vector<int> &process)
{
	if (num == 1)
	{
		firstFit(numOfBlocks, block, numOfProcesses, process);
	}
	else if (num == 2)
	{
		bestFit(numOfBlocks, block, numOfProcesses, process);
	}
	else if (num == 3)
	{
		worstFit(numOfBlocks, block, numOfProcesses, process);
	}
}
int main()
{

	vector<int> block;
	vector<int> process;

	int blockSize;
	int numberOfBlocks;
	int numberOfProcesses;
	int processSize;
	int allocationMethod;

	cout << "Enter number of blocks: ";
	cin >> numberOfBlocks;
	cout << endl;

	for (int i = 0; i < numberOfBlocks; i++)
	{
		cout << "Enter block size: ";
		cin >> blockSize;
		block.push_back(blockSize);
		cout << endl;
	}
	cout << endl;

	cout << "Enter number of processes: ";
	cin >> numberOfProcesses;
	cout << endl;

	for (int i = 0; i < numberOfProcesses; i++)
	{
		cout << "Enter process size: ";
		cin >> processSize;
		process.push_back(processSize);
		cout << endl;
	}
	cout << endl;

	cout << "Enter 1 for firstfit" << endl;
	cout << "Enter 2 for bestfit" << endl;
	cout << "Enter 3 for worstfit" << endl;
	cin >> allocationMethod;
	cout << endl;

	choose(allocationMethod, numberOfBlocks, block, numberOfProcesses, process);
}