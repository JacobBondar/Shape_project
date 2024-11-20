Title:
Ex #1: Build and draw different shapes.

===================================================

Student Data:
Written by: Jacob Bondar and Shelly Chausovsky,
 	    id = 322336488 and 323998526.

General Idea Of The Program:
The program reads vertexes from the user. The user enters the data as he
wishes, according to the rules. The user will have 4 different shapes, which
will be inserted into the shapes data (the shapes are: rectangle, triangle,
window and isosceles triangle).
After the user finished inserting the data he was asked to fill, every shape
will show how it looks like, according to the users data(if the user entered
invalid vertexes points, the shape will be shown in its default state).
The user will see the following things on the board:
	1. The shape on the board.
	2. The shape on the board with a rectangle that blocks it perfectly.
	3. The vertexes that the user entered.
	4. The shape's area.
	5. The shape's perimeter.
	6. The center of the object.
	7. The height (for the isosceles triangle).
	8. All of the above again, only this time, the Vertexes' data is 
		multiplied by a positive number.

Files That We Created:
Rectangle.h -> This file holds the class definition, with its public functions,
private functions and private members. The file has all the rectangle features,
which are the two vertexes that define it.

Rectangle.cpp -> This file implements the private, public and constructor 
function that the rectangle holds.

Triangle.h -> This file holds the class definition, with its public functions,
private functions and private members. The file has all the triangle features,
which are the three vertexes that define it.

Triangle.cpp -> This file implements the private, public and constructor
function that the rectangle holds.

Window.h -> This file holds the class definition, with its public functions,
private functions and private members. The file has all the window features,
which are the two vertexes that define the rectangle and another vertex which
represents the divison point.

Window.cpp -> This file implements the private, public and constructor function
that the window holds.

IsoscelesTriangle.h -> This file holds the class definition, with its public 
functions, private functions and private members. The file has all the 
isosceles triangle features, which are the three vertexes that define it.

IsoscelesTriangle.cpp -> This file implements the private, public and 
constructor function that the isosceles triangle holds.

In general, every shape has its limits and rules, which will be discussed in 
the "Extra Comments" subject.


Data Structor:
Struct Vertex represents a point, it has two members,
which are the x,y coordinates.

Algorithm:

Known Bugs:

Extra Comments:
The shapes, as we mentioned, have different rules. If the user tries to enter
some values, and for some reason the shape doesn't appear as the user 
inserted, the data in invalid for the rules.
The rules are:
	1. X value is under 70 and above 0.
	2. Y value is under 50 and above 0.
	3. Rectangle:
		- The first Vertex should be under and to the left of the 
			second Vertex.
	4. Window:
		- Besides the same for the rectangle, the split point should 
			be inside the rectangle.
	5. Triangle:
		- One side should be parallel to the X axis.
	6. Isosceles triangle:
		- Besides the same for triangle, the two none parallel side,
			 should be equal length.
