#include<iostream>
#include<iomanip>
#include<ctime>
#include "DeckOfCards.h"

DeckOfCards::DeckOfCards()
{
	for (size_t row = 0; row <= 3; row++)
	{
		for (size_t column = 0; column <= 12; column++)
		{
			deck[row][column] = 0;
		}
	}
	srand(time(0));
}
void DeckOfCards::shuffle()
{
	int row, column;
	for (size_t card = 1; card <= 52; card++)
	{
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (deck[row][column] != 0);
		deck[row][column] = card;
	}
}
void DeckOfCards::deal()
{
	static const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	static const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	
	for (size_t card = 1; card <= 52; card++)
	{
		for (size_t row = 0; row <= 3; row++)
		{
			for (size_t column = 0; column <= 12; column++)
			{
				if (deck[row][column] == card)
				{
					std::cout << face[column] << " of " << suit[row] << std::endl;
				}
			}
		}
	}
}