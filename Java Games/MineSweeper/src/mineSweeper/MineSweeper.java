package mineSweeper;

import java.util.Random;

public class MineSweeper
{
	private Random generator;
	public static final int BLANK = 0;
	public static final int MINE = -100;
	public static final int EMPTY=100;
	private int nrMine;
	private int[][] board;
	private int[][] cell;
	
/**
Create a new game with empty board
*/
	public MineSweeper(int nrMine)
	{
		this.nrMine=nrMine;
		generator=new Random();
		board=new int[10][10];
		cell=new int[10][10];
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				board[i][j]=BLANK;
				cell[i][j]=EMPTY;
			}
		}
		calcBoard();
		
	}
	/**
	Gets the number of mines
 	@return number of mines
	*/
	public int nrMine()
	{
		return nrMine;
	}

	/**
	Calculates the neighbours of the mines
	*/
	public void calcBoard()
	{
		for(int i=0;i<nrMine;i++)
		{
			int r=generator.nextInt(10);
			int c=generator.nextInt(10);
			if(board[r][c]==MINE)
			{
				r=generator.nextInt(10);
				c=generator.nextInt(10);
			}
			board[r][c]=MINE;
			if(r==0 && c==0)
			{
				board[r][c+1]++;
				board[r+1][c]++;
				board[r+1][c+1]++;
			}
			else
				if(r==9 && c==9)
				{
					board[r][c-1]++;
					board[r-1][c-1]++;
					board[r-1][c]++;
				}
				else
					if(r==0 && c==9)
					{
						board[r][c-1]++;
						board[r+1][c-1]++;
						board[r+1][c]++;
					}
					else
						if(r==9 && c==0)
						{
							board[r][c+1]++;
							board[r-1][c]++;
							board[r-1][c+1]++;
						}
						else
							if(r==0)
							{
								board[r][c-1]++;
								board[r][c+1]++;
								board[r+1][c]++;
								board[r+1][c-1]++;
								board[r+1][c+1]++;
							}
							else
								if(r==9)
								{
									board[r][c-1]++;
									board[r][c+1]++;
									board[r-1][c]++;
									board[r-1][c-1]++;
									board[r-1][c+1]++;
								}
								else
									if(c==0)
									{
										board[r-1][c]++;
										board[r+1][c]++;
										board[r+1][c+1]++;
										board[r-1][c+1]++;
										board[r][c+1]++;
									}
									else
										if(c==9)
										{
											board[r][c-1]++;
											board[r+1][c]++;
											board[r+1][c-1]++;
											board[r-1][c-1]++;
											board[r-1][c]++;
										}
										else
										{
											board[r][c-1]++;
											board[r][c+1]++;
											board[r-1][c]++;
											board[r-1][c-1]++;
											board[r-1][c+1]++;
											board[r+1][c]++;
											board[r+1][c+1]++;
											board[r+1][c-1]++;
										}
		}
	}

	/**
	Sets the number of mines
 	@param nrMine the new number of mines
	*/
	public void setMines(int nrMine)
	{
		this.nrMine=nrMine;
	}
	
	/**
	Get the symbol at given location
	@param i the row
	@param j the column
 	@return if there is a mine or not
	*/
	public boolean ifMine(int i,int j)
	{
		if(getCell(i,j)<0)
		{
			return true;
		}
		else
			return false;
	}

	/**
	Get symbol at given location
	@param i the row
	@param j the column
	@return the symbol at that location
	*/
	public int getCell(int i, int j)
	{
		return cell[i][j];
	}

	/**
	Creates a new board for the game
	*/
	public void newGame()
	{
		generator=new Random();
		board=new int[10][10];
		cell=new int[10][10];
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				board[i][j]=BLANK;
				cell[i][j]=EMPTY;
			}
		
		}
		calcBoard();
	}
	
	/**
	Reveals all the mines in the game
	*/
	public void reveal()
	{
		for(int i=0; i<10 ; i++)
		{
			for(int j=0; j<10 ; j++)
			{
				if(board[i][j] == MINE)
				{
					cell[i][j] = MINE;
				}
			}
		}
	}
	
	/**
	Sets the board in a new array
	@param i the row
	@param j the column
	*/
	public void setCell(int i,int j)
	{
		cell[i][j]=board[i][j];
	}
	
	/**
	Get symbol at given location
	@param i the row
	@param j the column
	@return the symbol at that location
	*/
	public int getBoard(int i,int j)
	{
		return board[i][j];
	}
}

