package mineSweeper;

import javax.swing.JButton;
import javax.swing.JPanel;
import java.awt.GridLayout;
import java.util.Observer;
import java.util.Observable;
public class BoardView extends JPanel implements Observer
{
	MineModel model;
	JButton[][] cell;

	public BoardView(MineModel model)
	{
		super();
		this.model=model;
		this.cell=new JButton[10][10];

		setLayout(new GridLayout(10,10));
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				cell[i][j]=new JButton(" ");
				cell[i][j].addActionListener(new SquareListener(model,i,j));
				add(cell[i][j]);
			}
		}
	}
	public void update(Observable obs, Object obj)
	{
		boolean win=true;
		for(int i=0;i<10;i++)
		{	
			for(int j=0;j<10;j++)
			{
				if(model.getCell(i,j)==100)
				{
					cell[i][j].setText(" ");
					cell[i][j].setEnabled(true);
				}
				else
					if(model.getBoard(i,j)<0)
					{
						win=false;
						cell[i][j].setText("X");
						cell[i][j].setEnabled(false);
					}
					else
						if(model.getBoard(i, j)>=0 && model.getBoard(i, j)<10)
						{
							cell[i][j].setText(Integer.toString(model.getBoard(i, j)));
							cell[i][j].setEnabled(false);			
						}
			}

			if(win==false)
			{
				for(int a=0;a<10;a++)
				{
					for(int b=0;b<10;b++)
					{	
						if(model.getBoard(a, b)<0)
						{
							cell[a][b].setText("X");
						
						}
						cell[a][b].setEnabled(false);
					}
				}
			}
		}
		repaint();
	}
}
