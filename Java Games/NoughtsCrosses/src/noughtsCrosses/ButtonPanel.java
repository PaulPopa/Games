package noughtsCrosses;

import javax.swing.JButton;
import javax.swing.JPanel;
public class ButtonPanel extends JPanel
{
	public ButtonPanel(NoughtsCrossesModel model)
	{
		super();
		JButton reset=new JButton("New Game");
		JButton exit=new JButton("Exit");
		reset.addActionListener(e->model.newGame());
		/*
		reset.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				model.newGame();
			}
		}
		);
		*/
		exit.addActionListener(e->System.exit(0));
		/*
		exit.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				System.exit(0);
			}
		}
		);
		*/
		add(reset);
		add(exit);
	}
}
