# Diagram / Code Tree

## **Class: Pen**

The pen mouvement will be assimilated to the [turtle](https://docs.python.org/3/library/turtle.html) python library. 

Constants  | Values
------------- | -------------
stepsPerRev  | 200
cmPerRev  | **steps** x pi x **r** / 100
motorInterfaceType  | 1  

Variables  | Initial Value
------------- | -------------
CurrentDirection | 0

### **FUNCTIONS**

Move and draw  | Description
------------- | -------------
forward  | Moves in the current direction
backward  | Moves in the opposite direction  
left  | Changes the direction in -90º
right  | Changes the direction in 90º
turn  | Makes a specific angle (degrees)
setHeading  |  Sets specific absolute direction
goto  | Moves to a specific absolute position  
home |  Moves to default position

Tell Pen’s state  | Description
------------- | -------------
position  | Gives current absolute position
heading  | Gives current direction
calibrate  | Calibrates the position

Pen control  | Description
------------- | -------------
penDown  | The pen draws when moven
penUp  | The pen doesn't draws when moven
color  | Choose color
fill | Fills a closed shape


