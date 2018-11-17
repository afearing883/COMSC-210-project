#ifndef QUEENS_H
#define QUEENS_H

#include <vector>
#include <string>
#include <iostream>
#include <ostream>
bool solveQueens(std::vector<std::size_t>& board, const std::size_t currentRank)
{
	bool validPlace = true;
	if (currentRank == board.size())
	{
		return true;
	}
	for (std::size_t file = 0; file < board.size(); ++file, validPlace = true)
	{
		for (std::size_t i = 0; (i < currentRank) && (validPlace = (file != board.at(i)) && (file + (currentRank - i)) != board.at(i) && (file - (currentRank - i)) != board.at(i)); ++i)
		{
		}
		if (validPlace)
		{
			board.at(currentRank) = file;
			if (solveQueens(board, currentRank + 1))
			{
				return true;
			}
		}
	}
	return false;
}

void printPositions(const std::vector<std::size_t>& board, std::ostream& os = std::cout)
{
	for (std::size_t rank = 0; rank < board.size(); ++rank)
	{
		os << static_cast<char>(board.at(rank)+'A') << rank+1 << " ";
	}
	os << std::endl;
}

void printBoard(const std::vector<std::size_t>& board, std::ostream& os = std::cout)
{
	std::vector<std::string> chessBoard;
	for (std::size_t i = 0; i < board.size(); ++i)
	{
		std::string rank(board.size(), ' ');
		rank.at(board.at(i)) = 'Q';
		chessBoard.push_back(rank);
		std::cout << rank << std::endl;
	}
}

std::vector<std::size_t> queens(std::size_t n = 8)
{
	std::size_t currentRank = 0;
	std::vector<std::size_t> board(n, std::string::npos);
	solveQueens(board, currentRank);


	return board;
}

#endif // !QUEENS_H
