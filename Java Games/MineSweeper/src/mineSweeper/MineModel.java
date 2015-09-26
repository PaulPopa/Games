package mineSweeper;

import java.util.Observable;
public class MineModel extends Observable
{
	private MineSweeper ms;
	public MineModel(MineSweeper ms)
	{
		super();
		this.ms=ms;
	}
	
	/**
	Sets the number of mines
 	@param nrMine the new number of mines
	*/
	public void setMines(int nrMine)
	{
		ms.setMines(nrMine);
		setChanged();
		notifyObservers();
	}
	
	/**
	Get the symbol at given location
	@param i the row
	@param j the column
 	@return if there is a mine or not
	*/
	public boolean ifMine(int i,int j)
	{
		return ms.ifMine(i, j);
	}
	
	/**
	Gets the number of mines
 	@return number of mines
	*/
	public int nrMine()
	{
		return ms.nrMine();
	}
	
	/**
	Get symbol at given location
	@param i the row
	@param j the column
	@return the symbol at that location
	*/
	public int getCell(int i,int j)
	{
		return ms.getCell(i, j);
	}
	
	/**
	Sets the board in a new array
	@param i the row
	@param j the column
	*/
	public void setCell(int i,int j)
	{
		ms.setCell(i, j);
		setChanged();
		notifyObservers();
	}
	
	/**
	Get symbol at given location
	@param i the row
	@param j the column
	@return the symbol at that location
	*/
	public int getBoard(int i,int j)
	{
		return ms.getBoard(i, j);
	}
	
	/**
	Reveals all the mines in the game
	*/
	public void reveal()
	{
			ms.reveal();
			setChanged();
			notifyObservers();	
	}

	/**
	Creates a new board for the game
	*/
	public void newGame()
	{
		ms.newGame();
		setChanged();
		notifyObservers();
	}
		
}
