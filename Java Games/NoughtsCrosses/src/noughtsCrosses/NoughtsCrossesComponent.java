package noughtsCrosses;

import java.awt.BorderLayout;
import java.awt.event.*;
import javax.swing.event.*;
import javax.swing.JButton;
import javax.swing.JPanel;
public class NoughtsCrossesComponent extends JPanel

{
	
	public NoughtsCrossesComponent(NoughtsCrosses oxo)

	{	
		
		super();
	
		NoughtsCrossesModel model=new NoughtsCrossesModel(oxo);
		
		BoardView view=new BoardView(model);
		
		ButtonPanel buttons=new ButtonPanel(model);
				model.addObserver(view);
		
		setLayout(new BorderLayout());
		
		add(view,BorderLayout.CENTER);	
		
		add(buttons,BorderLayout.SOUTH);		
	
	}

}
