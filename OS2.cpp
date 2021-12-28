
#include <iostream>
#include <vector>
#include <string>

using namespace std;
void erase(int x, vector<int>& p) {

	vector<int>temp;

	for (int i = 0; i < p.size(); i++) {
		if (i != x) { //we will ignore the process that was placed in the freeblock vector
			temp.push_back(p[i]);
		}
	}

	p.clear();
	p = temp;

}


void firstFit(int numOfBlocks, vector<int>& block, int numOfProcesses, vector<int>& process)
{
	vector<int>freeblock;
	for (int y = 0; y < numOfBlocks; y++) {
		freeblock.push_back(0);
	}


	for (int i = 0; i < numOfBlocks; i++) {
		int temp = -1;
		for (int x = 0; x < process.size(); x++) {
			if (block[i] >= process[x]) {

				freeblock[i] = process[x];
				temp = x;

				break;
			}

		}
		if (temp > -1) {
			erase(temp, process);
			temp = -1;
		}

	}
	cout << "First fit: " << endl;
	cout << "Blocks " << " " << "Processes in blocks" << endl;
	for (int j = 0; j < freeblock.size(); j++) {
		cout << " " << block[j] << "   |    ";
		cout << freeblock[j];
		cout << endl;
	}

}

void choose(int num, int numOfBlocks, vector<int>& block, int numOfProcesses, vector<int>& process)
{
	if (num == 1)
	{
		firstFit(numOfBlocks, block, numOfProcesses, process);
	}
	else if (num == 2)
	{
		
	}
	else if (num == 3)
	{
		
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


	for (int i = 0; i < numberOfBlocks; i++) {
		cout << "Enter block size: ";
		cin >> blockSize;
		block.push_back(blockSize);
		cout << endl;
	}
	cout << endl;

	cout << "Enter number of processes: ";
	cin >> numberOfProcesses;
	cout << endl;

	for (int i = 0; i < numberOfProcesses; i++) {
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