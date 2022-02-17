package Code.app;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyFrame extends JFrame implements ActionListener {

    JButton ImportButton;

    public MyFrame() {

        this.setTitle("Txt file processor to Serial");
        this.setSize(500, 500);
        this.setResizable(false);
        // this.setIconImage(new ImageIcon("Images\\logo.jpg").getImage());
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
        this.setLayout(null);

        JPanel ButtonPanel = new JPanel();
        ButtonPanel.setBackground(PColor.LIGHT.get());
        ButtonPanel.setLayout(null);
        ButtonPanel.setBounds(250, 0, 250, 500);

        JPanel FilePanel = new JPanel();
        FilePanel.setBackground(PColor.MEDIUM.get());
        FilePanel.setLayout(null);
        FilePanel.setBounds(0, 0, 250, 500);
        this.add(FilePanel);

        this.ImportButton = new JButton();
        this.ImportButton.setBounds(300, 300, 50, 20);
        this.add(this.ImportButton);
        this.add(ButtonPanel);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == this.ImportButton) {
            System.out.println("lol");
        }

    }
}
