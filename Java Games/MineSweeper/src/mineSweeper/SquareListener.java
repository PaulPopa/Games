package mineSweeper;

import java.awt.event.*;
public class SquareListener implements ActionListener
{
	private MineModel model;
	private int row;
	private int column;	
	public SquareListener(MineModel model,int row,int column)
	{	
		this.model=model;
		this.row=row;
		this.column=column;
	}
	public void actionPerformed(ActionEvent e)
	{
		model.setCell(row,column);
	}
}

