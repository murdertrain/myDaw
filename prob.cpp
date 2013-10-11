#include <iostream>
#include <cstdlib>

typedef char direction;
typedef char peg;
size_t num_rows;
size_t num_cols;

bool isSolved(peg * myBoard);
direction canMove(char* board, int position);
bool makeMove(char** board, int position, direction myDirection);

using namespace std; 

int main()
{

	cin >> num_rows >> num_cols;
	string bs;
	getline(cin, bs); 
	peg* board = new peg[num_rows * num_cols];

	for (size_t row = 0; row < num_rows; row++)
	{
		string line;

    getline(cin, line);
    if (line.size() != num_cols)
    {
        cout << "Error! Size is " << line.size() << " rather than " << num_cols << endl;
        exit(1);
    }

    for (size_t col = 0; col < num_cols; col++)
    {
        board[(row * num_cols) + col] = line[col];
    }
	}

	cout << "Board is: " << board << endl;

	while(!isSolved(board))
	{
		// tryMove(board);

	}
}
	
bool isSolved(peg * board)
{
	int numPegs = 0;
	for (size_t row = 0; row < num_rows; row++)
	  for (size_t col = 0; col < num_cols; col++)
		{
			if(board[(row * num_cols) + col] = '0')
				numPegs++;
			if(numPegs > 1)
				return false;
		}
}

direction canMove(char* board, int position)
{
	if(board[position] != '0')
		return 'z';
	if(board[position - 2] == '.' && board[position - 1] == '0')
		return 'w';
	if(board[position + 2] == '.' && board[position + 1] == '0')
		return 'e';
	if(board[position - (2 * num_cols)] == '.' && board[position - num_cols] == '0')
		return 'n';
	if(board[position + (2 * num_cols)] == '.' && board[position + num_cols] == '0')
		return 's';
	else return 'x';
}

bool makeMove(char**board, int position, direction myDirection)
{
	*board[position] = '.';
	if(myDirection == 'n')
		*board[position - num_cols] = '0';

}
