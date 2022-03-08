import gnu.io.CommPortIdentifier;
import gnu.io.PortInUseException;
import gnu.io.SerialPort;
import gnu.io.UnsupportedCommOperationException;

import java.io.*;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.Scanner;

public class FileManager {
    private static final int TIME_OUT = 2000;
    private static final int DATA_RATE = 9600;
    ArrayList<String> commands = new ArrayList<String>();
    Scanner scan = new Scanner(System.in);
    private File file = new File("C:\\Users\\Jaime\\Documents\\GitHub\\Drawing_Arduino_Bot\\Code\\Tests\\textToSend.txt");
    private SerialPort serialPort;
    private BufferedReader inputStream;
    private OutputStream outputStream;

    public FileManager() {

        Enumeration portList = CommPortIdentifier.getPortIdentifiers();

        while (portList.hasMoreElements()) {

            CommPortIdentifier portId = (CommPortIdentifier) portList.nextElement();
            if (portId.getPortType() == CommPortIdentifier.PORT_SERIAL) {
                try {
                    this.serialPort = (SerialPort)
                            portId.open("SimpleWriteApp", this.TIME_OUT);

                    this.outputStream = this.serialPort.getOutputStream();
                    this.inputStream = new BufferedReader(new InputStreamReader(this.serialPort.getInputStream()));

                    this.serialPort.setSerialPortParams(this.DATA_RATE,
                            SerialPort.DATABITS_8,
                            SerialPort.STOPBITS_1,
                            SerialPort.PARITY_NONE);

                    // --------- Write in OutputStream ---------
                    try {
                        this.read();
                    } catch (IOException e) {
                        System.err.println(e);
                    }
                    for (String command : this.commands) {
                        this.outputStream.write(command.getBytes());
                        System.out.println(command);
                        while (inputStream.readLine()!="Done"){
                            System.out.println("Waiting...");
                        }
                        System.out.println(command);
                    }


                    // --------- End of writing ---------

                    this.outputStream.close();
                    this.serialPort.close();

                } catch (IOException e) {
                    System.out.println(e);
                } catch (PortInUseException e) {
                    System.out.println(e);
                } catch (UnsupportedCommOperationException e) {
                    System.out.println(e);
                }
            }

        }
    }

    public void setFile(File file) {
        this.file = file;
    }

    public String getFileName() {
        if (this.file == null) return "null";
        return this.file.getName();
    }

    public String getPort() {
        if (this.serialPort == null) return "null";
        return this.serialPort.getName();
    }

    public void read() throws IOException {

        BufferedReader br = new BufferedReader(new FileReader(this.file));
        this.commands.clear();

        String line = br.readLine();
        while (line != null && line.charAt(0) != '(' && line.charAt(0) != '%') {
            this.commands.add(line);
            line = br.readLine();
        }
        br.close();
    }
/*
    public String changeDifferentPort() {
        SerialPort[] portNames = SerialPort.getCommPorts();
        if (portNames.length == 0) {
            serialPort = null;
            return "Serial Port not found.";
        }
        serialPort = portNames[rand.nextInt(portNames.length)];
        return "Connected to " + serialPort.getSystemPortName();
    }
    */


/*
    public void sendStringToComm(String str) throws IOException {
        output.write(str.getBytes(StandardCharsets.UTF_8));
    }

 */
/*
    public void upload() {
        serialPort.setBaudRate(9600);
        output = serialPort.getOutputStream();

        Scanner reader = new Scanner(System.in);  // Reading from System.in
        String line = "";
        while (line != "exit") {
            System.out.println("next line ? ");
            line = reader.nextLine();

            try {
                sendStringToComm(line);
            } catch (IOException e) {
                System.err.println(e);
            }
        }

 */
        /*
        for (String line : this.commands) {
            System.out.println("next line ? ");
            //reader.next();
            sendStringToComm(reader.next());

        }
        */


}



