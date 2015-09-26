package noughtsCrosses;

import java.util.Observable;

public class NoughtsCrossesModel extends Observable

{
	
	private NoughtsCrosses oxo;
	
	public NoughtsCrossesModel(NoughtsCrosses oxo)

	{

		super();

		this.oxo=oxo;

	}
	
	public int get(int i,int j)
	
	{

		return oxo.get(i,j);

	}
	
	public boolean isCrossTurn()
	
	{

		return oxo.isCrossTurn();

	}
	
	public void turn(int i,int j)

	{
	
		oxo.turn(i,j);

		setChanged();

		notifyObservers();
	
	}
	
	public int whoWon()
	
	{
		
		return oxo.whoWon();

	}
	
	public void newGame()

	{
	
		oxo.newGame();
	
		setChanged();

		notifyObservers();

	}

}
