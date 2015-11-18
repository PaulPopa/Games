package mineSweeper;

import java.awt.BorderLayout;
import javax.swing.JPanel;
public class MineComponent extends JPanel
{
	public MineComponent(MineSweeper ms)
	{	
		super();
		final MineModel model=new MineModel(ms);
		
		BoardView view=new BoardView(model);
		ControlPanel panel = new ControlPanel(model);
		
		model.addObserver(view);
		
		setLayout(new BorderLayout());
		
		add(view,BorderLayout.CENTER);	
		add(panel,BorderLayout.SOUTH);	
	}
}
