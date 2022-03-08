import javax.swing.*;
import java.awt.*;
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

    FileManager fm = new FileManager();

    public MyFrame() {

        // ------------- Frame -------------
        this.setTitle("TXT Serial Processor");
        this.setSize(416, 339); // Width = 400, Height = 300
        this.setResizable(false);
        // this.setIconImage(new ImageIcon("Images\\logo.jpg").getImage());
        this.setBackground(PColor.MEDIUM);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // ------------- Panels -------------

        JPanel logPanel = new JPanel();
        logPanel.setBackground(PColor.MEDIUM);
        logPanel.setLayout(null);
        logPanel.setBounds(0, 0, 250, 300);

        JPanel buttonPanel = new JPanel();
        buttonPanel.setBackground(PColor.LIGHT);
        buttonPanel.setLayout(null);
        buttonPanel.setBounds(250, 0, 150, 300);


        // ------------- Buttons -------------

        importButton.setBounds(25, 100, 100, 20);
        importButton.addActionListener(this);
        importButton.setFocusable(false);
        importButton.setSize(100, 20);
        importButton.setFont(new Font("Comic Sans", Font.ITALIC, 12));
        importButton.setBackground(PColor.DARK);
        importButton.setForeground(PColor.FULL_LIGHT);
        importButton.setBorder(BorderFactory.createEtchedBorder());
        buttonPanel.add(importButton);

        changePortButton.setBounds(25, 140, 100, 20);
        changePortButton.addActionListener(this);
        changePortButton.setFocusable(false);
        changePortButton.setSize(100, 20);
        changePortButton.setFont(new Font("Comic Sans", Font.ITALIC, 12));
        changePortButton.setBackground(PColor.DARK);
        changePortButton.setForeground(PColor.FULL_LIGHT);
        changePortButton.setBorder(BorderFactory.createEtchedBorder());
        buttonPanel.add(changePortButton);

        uploadButton.setBounds(25, 180, 100, 20);
        uploadButton.addActionListener(this);
        uploadButton.setFocusable(false);
        uploadButton.setSize(100, 20);
        uploadButton.setFont(new Font("Comic Sans", Font.ITALIC, 12));
        uploadButton.setBackground(PColor.DARK);
        uploadButton.setForeground(PColor.FULL_LIGHT);
        uploadButton.setBorder(BorderFactory.createEtchedBorder());
        buttonPanel.add(uploadButton);

        // ------------- Labels -------------

        setInfoFile("null");
        this.infoLabel.setBounds(20, 10, 120, 40);
        this.infoLabel.setForeground(PColor.FULL_DARK);
        buttonPanel.add(infoLabel);

        logMessage.setBounds(10, 10, 230, 250);
        logMessage.setBackground(PColor.DARK);
        logMessage.setForeground(PColor.FULL_LIGHT);
        logMessage.setOpaque(true);
        logMessage.setBorder(BorderFactory.createRaisedBevelBorder());
        logPanel.add(logMessage);

        // ------------- Progress Bar -------------

        bar.setValue(0);
        bar.setBounds(10, 270, 230, 20);
        bar.setStringPainted(true);
        bar.setVisible(false);
        logPanel.add(bar);

        this.add(logPanel);
        this.add(buttonPanel);
        this.setLayout(null);
        this.setVisible(true);

    }

    public static void main(String[] args) {
        //MyFrame frame = new MyFrame();
        FileManager fm = new FileManager();
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
            //fm.upload();

        } else if (e.getSource() == this.changePortButton) {
            //String msg = fm.changeDifferentPort();
            //log(msg);
            setInfoPort(fm.getPort());
            //fm.initialize();
        }
    }

}
