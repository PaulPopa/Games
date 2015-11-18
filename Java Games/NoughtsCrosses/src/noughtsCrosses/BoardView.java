package noughtsCrosses;

import java.awt.GridLayout;
import java.util.Observable;
import java.util.Observer;

import javax.swing.JButton;
import javax.swing.JPanel;

public class BoardView extends JPanel implements Observer
{
	NoughtsCrossesModel model;
	JButton[][] cell;

	public BoardView(NoughtsCrossesModel model)
	{
		super();
		this.model=model;
		this.cell=new JButton[3][3];
		setLayout(new GridLayout(3,3));

		for(int i=0;i<3;i++)
		{
			
			for(int j=0;j<3;j++)
			{
				cell[i][j]=new JButton(" ");
				cell[i][j].addActionListener(new ButtonListener(model,i,j));	
				add(cell[i][j]);
			}
	
		}
	}
	
	public void update(Observable obs, Object obj)
	{
		for(int i=0;i<3;i++)
		{	
			for(int j=0;j<3;j++)
			{
				if(model.get(i,j)==NoughtsCrosses.NOUGHT)
				{
					cell[i][j].setText("0");
					cell[i][j].setEnabled(false);
				}
				else if(model.get(i,j)==NoughtsCrosses.CROSS)
				{
					cell[i][j].setText("X");
					cell[i][j].setEnabled(false);
				}
				else
				{
					cell[i][j].setText(" ");
					boolean notOver=(model.whoWon() == NoughtsCrosses.BLANK);
					cell[i][j].setEnabled(notOver);
				}
			}
		}
		repaint();
	}
}
