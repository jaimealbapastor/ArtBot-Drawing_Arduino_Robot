package Code.app;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

import jssc.SerialPortList;


public class FileManager {
    private File file;
    private String port;

    public void setFile(File file) {
        this.file = file;
    }

    public String getFileName() {
        return file.getName();
    }

    public String getPort() {
        return port;
    }

    private void setPort(String port) {
        this.port = port;
    }

    public String read() throws Exception {

        BufferedReader br = new BufferedReader(new FileReader(file));
        StringBuilder sb = new StringBuilder();
        String line = br.readLine();
        while (line != null) {
            sb.append(line);
            sb.append(System.lineSeparator());
            line = br.readLine();
        }
        String everything = sb.toString();
        br.close();
        return everything;
    }

    private String getNextPort(String port) {
        String[] portNames = SerialPortList.getPortNames();

        if (portNames.length == 0) {
            return null;
        }
        for (int i = 0; i < portNames.length; i++) {
            if (portNames[i].equals(port)) {
                if (i == portNames.length - 1) {
                    return portNames[0];
                }
                return portNames[i + 1];
            }
        }
        return portNames[0];
    }

    public void changePort() {
        setPort(getNextPort(getPort()));
    }
}


