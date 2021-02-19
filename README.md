# Raise The Terrain
**An isometric projection of a grid that rotates when pressing Right or Left arrow**
![grid1](/grid1.jpg)
![grid2](/grid2.jpg)
![grid3](/grid3.jpg)
****
## About this project
Raise The Terrain is a voluntary project at Holberton School taking part of the "Low-level programming & Algorithm" projects.\
It is created using the **C programming Language** and **SDL2**.
## How it works
 - The program reads the file "altitudes".
 - Gets the altitude of each point.
 - Draws an isometric projection of a grid (64 connected points). Each point has its x, y and z coordinates (z = altitude).
 - Rotates the grid to Right or Left, when the user presses on Right or Left arrow.
 - Quits when the user presses ESC key or when clicks on window Quit button.
## USAGE
You can run this program by following these steps:
> **Step 1:** Clone my repository using this command, (you need to have git, gcc and SDL2 installed on your machine first)
````
git clone https://github.com/MatriMariem/Raise_the_terrain
````
> **Step 2:** Change directory to Raise_the_terrain:
````
cd Raise_the_terrain
````
> **Step 3:** Compile the C files in this way:
````
gcc *.c -lm $(sdl2-config --cflags --libs) -o terrain
````
> **Step 4:** Run the program
````
./terrain altitudes
````
**Exiting the program**
When you want to exit the program, you can use one of the following methods:
> **1: Click on window close button**
````
exit
````
> **2: Press on ESC key**
 - **You can change the name of the program** by typing it instead of "terrain" in compilation step (Step 3).
 - **You can change altitudes of the points of the grid by editing the file "altitudes"** but make sure to keep the same number of integers in the file.
 - **You can also change the name of the file "altitudes"** but make sure to give the new name of the file to your program when you run it "./terrain <new name>".
****
## Files description
 - **altitudes** -> altitudes of all points in the grid
 - **terrain.c** -> main function
 - **terrain.h** -> header file
 - **fn_altitudes.c** -> all functions related to getting altitudes
 	- **_atoi** -> converts a string to an integer
	- **_strdup** -> copies a string in a newly allocated memory area
	- **splitstring** -> creates an array of words from a string
	- **freearv** -> frees an array of words
	- **get_altitudes** -> reads the file of altitudes
 - **makegrid.c**
 	- **allocategrid** -> allocates memory for a (8x8) grid
	- **makegrid** -> creates a simple grid
	- **makerow** -> fills the rows of a simple grid
	- **makecol** -> fills the columns of a simple grid
	- **makeiso** -> makes a grid become isometric
 - **all_grid.c**
 	- **All_isogrid** -> creates and draws an isometric grid
	- **Drawgrid** -> draws a grid on the renderer
	- **makerot** -> rotates the points of a grid
	- **rotategrid** -> creates a grid, rotates its points and draws it
 - **free.c**
	- **freegrid** -> frees the allocated memory of a (8x8) grid
	- **freenumbers** -> frees a 2D array (8x8) of integers
	- **Destroy_Quit** -> destroys the Renderer and the window and Quits
****
## Bugs
No Known Bugs.
## AUTHOR
Mariem Matri : [LinkedIn] | [GitHub] | [Twitter]

[LinkedIn]: <https://www.linkedin.com/in/mariem-matri-249620178>
[GitHub]: <https://github.com/MatriMariem>
[Twitter]: <https://twitter.com/MatriMariem>

## AUTHOR DESCRIPTION (Mariem Matri)
 - I'm a Food Process Engineer and a software engineering student at Holberton School.
  - I have been studying low-level programming, high-level
 programming, system engineering and devops, and web
 stack programming (Front-end & Back-end) using a
 methodology based on peer-learning and projects.
  - I'm curious, adaptable, a fast learner and I love developing
 my skills.
