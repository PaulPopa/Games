package noughtsCrosses;

import javax.swing.JFrame;

public class NoughtsCrossesGUI
{
	public static void main(String[] args)
	{
		JFrame frame=new JFrame("Noughts and Crosses");		
		frame.setSize(600,600);
	
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		NoughtsCrosses oxo=new NoughtsCrosses();
	
		NoughtsCrossesComponent comp=new NoughtsCrossesComponent(oxo);
		frame.add(comp);

		frame.setVisible(true);
	}
}
