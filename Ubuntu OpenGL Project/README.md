
<h1 align="center">Ubuntu OpenGL Project</h1>
<p align="center"><strong>Created by Sammie Vaicius and Lucas Lasecla </strong>
<br>C++ using Ubuntu Linux</p>
<br/>
<h2>Demo</h2>
Loom: <a href="https://www.loom.com/share/a35877f2a3704d059268b5eb5fb7e202" target="_blank">Demo Video</a>

<h2>Goal</h2>

The objective of this project was to recreate a digital representation of a captured image through the utilization of vertexes, shaders, and textures, 
with the aim of constructing shapes and delivering a visually accurate portrayal.


<h2>Installation</h2>

To run this program you must have:
g++, glut, glew, glu, GL 
Ubuntu must also be up to date
 <br/>  
 <br/>

1. Download this project as zip and extract it
2. Import it in Ubuntu Folder
3. Ensure the libraries above are installed
4. compile the program with the following command: <br/>
          g++ scene.cpp Mesh.cpp shader.cpp Texture.cpp stb_image.c -o scene -lGL -lglfw -lGLEW -lSOIL -lglut -lGLU
5. After the program is compiled, you can run it with the following command: <br/>
         ./scene

<h2> Program Instructions</h2>
Once the program is running, you will traverse the scene with the following methods:<br/>
    UP ARROW : Move forward in the direction you are looking <br/>
    DOWN ARROW : Move backward in the direction you are looking <br/>
    LEFT CLICK + DRAG: Look around on the x - axis <br/>
<br/>
To end the program, simply close the window
