package mineSweeper;

import javax.swing.JPanel;
import javax.swing.JButton;
import java.awt.event.*;
import javax.swing.JRadioButton;

public class ControlPanel extends JPanel
{
	private MineModel model;

	public ControlPanel(final MineModel model)
	{
		super();
		JButton reset = new JButton("New Game");
		JButton exit = new JButton("Exit");
		JButton reveal = new JButton("Reveal");

		final JRadioButton easy = new JRadioButton("Easy");
     	final	JRadioButton normal = new JRadioButton("Normal");
		final JRadioButton hard = new JRadioButton("Hard");

		easy.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent e)
				{
					if(easy.isSelected())
					{
					easy.setSelected(true);
					normal.setSelected(false);
					hard.setSelected(false);
					model.setMines(10);
					model.newGame();
					}
				}
			}
		);
   
		normal.addActionListener(new ActionListener()
			
			
			{
				public void actionPerformed(ActionEvent e)
				{	
					if(normal.isSelected())
					{
					easy.setSelected(false);
					normal.setSelected(true);
					hard.setSelected(false);
					model.setMines(15);
					model.newGame();
					}
				}	
			}
		);

		hard.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent e)
				{
					if(hard.isSelected())
					{
					easy.setSelected(false);
					normal.setSelected(false);
					hard.setSelected(true);
					model.setMines(20);
					model.newGame();
					}
				}
			}
		);

		reveal.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent e)
				{
					model.reveal();
				}
			}
		);


		reset.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent e)
				{
					model.newGame();
				}
			}
		);

		exit.addActionListener(new ActionListener()
			{
				public void actionPerformed(ActionEvent e)
				{
					 System.exit(0);
				}
			}
		);
		
		add(easy);
		add(normal);
		add(hard);
		add(reveal);
		add(reset);
		add(exit);
	}
}
