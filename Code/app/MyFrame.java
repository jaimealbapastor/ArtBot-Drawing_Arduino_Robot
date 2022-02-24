package Code.app;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JProgressBar;
import javax.swing.SwingConstants;

import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyFrame extends JFrame implements ActionListener {

    JButton importButton = new JButton("Import File");
    JButton uploadButton = new JButton("Upload");
    JButton changePortButton = new JButton("Change Port");

    JProgressBar bar = new JProgressBar(0, 100);
    JFileChooser fc = new JFileChooser();

    JLabel logMessage = new JLabel();
    JLabel infoLabel = new JLabel();

    String message = "<html>";
    int progress = 0;

    FileManager fm;

    public MyFrame(FileManager fm) {

        this.fm = fm;
        this.fm.changePort();

        // ------------- Frame -------------
        this.setTitle("TXT Serial Processor");
        this.setSize(416, 339); // Width = 400, Height = 300
        this.setResizable(false);
        // this.setIconImage(new ImageIcon("Images\\logo.jpg").getImage());
        this.setBackground(PColor.MEDIUM.get());
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // ------------- Panels -------------

        JPanel logPanel = new JPanel();
        logPanel.setBackground(PColor.MEDIUM.get());
        logPanel.setLayout(null);
        logPanel.setBounds(0, 0, 250, 300);

        JPanel buttonPanel = new JPanel();
        buttonPanel.setBackground(PColor.LIGHT.get());
        buttonPanel.setLayout(null);
        buttonPanel.setBounds(250, 0, 150, 300);


        // ------------- Buttons -------------

        importButton.setBounds(25, 100, 100, 20);
        importButton.addActionListener(this);
        importButton.setFocusable(false);
        importButton.setSize(100, 20);
        importButton.setFont(new Font("Comic Sans", Font.ITALIC, 12));
        importButton.setBackground(PColor.DARK.get());
        importButton.setForeground(PColor.FULL_LIGHT.get());
        importButton.setBorder(BorderFactory.createEtchedBorder());
        buttonPanel.add(importButton);

        changePortButton.setBounds(25, 140, 100, 20);
        changePortButton.addActionListener(this);
        changePortButton.setFocusable(false);
        changePortButton.setSize(100, 20);
        changePortButton.setFont(new Font("Comic Sans", Font.ITALIC, 12));
        changePortButton.setBackground(PColor.DARK.get());
        changePortButton.setForeground(PColor.FULL_LIGHT.get());
        changePortButton.setBorder(BorderFactory.createEtchedBorder());
        buttonPanel.add(changePortButton);

        uploadButton.setBounds(25, 180, 100, 20);
        uploadButton.addActionListener(this);
        uploadButton.setFocusable(false);
        uploadButton.setSize(100, 20);
        uploadButton.setFont(new Font("Comic Sans", Font.ITALIC, 12));
        uploadButton.setBackground(PColor.DARK.get());
        uploadButton.setForeground(PColor.FULL_LIGHT.get());
        uploadButton.setBorder(BorderFactory.createEtchedBorder());
        buttonPanel.add(uploadButton);

        // ------------- Other Elements -------------

        setInfoFile("?");
        this.infoLabel.setBounds(20, 10, 120, 40);
        this.infoLabel.setForeground(PColor.FULL_DARK.get());
        buttonPanel.add(infoLabel);

        bar.setValue(0);
        bar.setBounds(10, 270, 230, 20);
        bar.setStringPainted(true);
        bar.setVisible(false);
        logPanel.add(bar);

        logMessage.setBounds(10, 10, 230, 250);
        logMessage.setBackground(PColor.DARK.get());
        logMessage.setForeground(PColor.FULL_LIGHT.get());
        logMessage.setOpaque(true);
        logMessage.setBorder(BorderFactory.createRaisedBevelBorder());
        logPanel.add(logMessage);

        this.add(logPanel);
        this.add(buttonPanel);

        this.setLayout(null);
        this.setVisible(true);

    }

    public void log(String msg) {
        message += "<br/><p>> " + msg + "</p>";
        this.logMessage.setText(message + "</html>");
        this.logMessage.setVerticalAlignment(SwingConstants.BOTTOM);
    }

    private void setInfoFile(String file) {
        this.infoLabel.setText("<html>File: " + file + "<br/>Port: " + this.fm.getPort() + "</html>");
    }

    private void setInfoPort(String port) {
        this.infoLabel.setText("<html>File: " + this.fm.getFileName() + "<br/>Port: " + port + "</html>");
    }

    @Override
    public void actionPerformed(ActionEvent e) {

        if (e.getSource() == this.importButton) {
            int returnVal = fc.showOpenDialog(this);
            if (returnVal == JFileChooser.APPROVE_OPTION) {
                fm.setFile(fc.getSelectedFile());
                setInfoFile(fm.getFileName());
                log("Opening: " + fm.getFileName() + ".");
                // Here open the file
            } else {
                log("Open command cancelled by user.");
            }

            // this.importButton.setEnabled(false);
        } else if (e.getSource() == this.uploadButton) {
            log("Reading...");
            bar.setVisible(true);
            bar.setValue(progress++);

        } else if (e.getSource() == this.changePortButton) {
            log("USB Port Changed");
            fm.changePort();
        }
    }

}
