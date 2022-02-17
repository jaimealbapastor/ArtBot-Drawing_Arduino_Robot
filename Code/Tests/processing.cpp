/*
    A simple "Hello Wold" program using a file from your computer
    and send to an Arduino with a LCD display.

    By Serge J Desjardins aka techone,tech37
*/

import processing.serial.*;

Serial myport;

int portindex = 3; // Arduino USB port number from the serial list
int sz;

void setup()
{
    size(200, 200);
    byte data[] = loadBytes("test.txt");
    sz = data.length; // How big is the array
    // Show the size of the file
    println("The size of the file is : " + sz + "\n");
    // Show the ports list of your computer system
    println(Serial.list());
    println("Connecting to " + Serial.list()[portindex]);
    // init Port COM7 <- in the author case...
    myport = new Serial(this, Serial.list()[portindex], 2400);
    println("Sending Data...\n");
    // Sending the content of the array
    for (int i = 0; i < sz; i++)
    {
        print(char(data[i]));        // Monitor send data
        myport.write(char(data[i])); // Convert Decimal to ASCII
                                     // And send data out.
    }
    println("\nFinish.\n");
}

void draw()
{
}