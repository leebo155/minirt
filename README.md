# miniRT
  RayTracer with [miniLibX](https://github.com/42Paris/minilibx-linux)
 
  <img alt="main" src="https://github.com/leebo155/minirt/blob/master/img/miniRT.jpg">
  
## Introduction
* This project creates a program that converts a text file into an image using ray tracing.
* the program displays the image in a window and respect the following rules:   
  ◦ Pressing ESC must close the window and quit the program cleanly.   
  ◦ Clicking on the red cross on the window’s frame must close the window and quit the program cleanly.   
* Program must take as a first argument a scene description file with the .rt extension.   
  ◦ Each type of element can be separated by one or more line break(s).   
  ◦ Each type of information from an element can be separated by one or more space(s).   
  ◦ Each type of element can be set in any order in the file.   
  ◦ Elements which are defined by a capital letter can only be declared once in the scene.
  ◦ Each element first’s information is the type identifier (composed by one or two character(s)), followed by all specific information for each object in a strict order such as:
     
  ◦ Ambient lightning:   
     > ∗ identifier: **A**   
     > ∗ ambient lighting ratio in range [0.0,1.0]: **0.2**   
     > ∗ R,G,B colors in range [0-255]: **255, 255, 255**
     > ```shall
     >       A  0.2  255, 255, 255
     > ```
  ◦ Camera:   
     > ∗ identifier: **C**   
     > ∗ x,y,z coordinates of the view point: **-50.0, 0, 20**   
     > ∗ 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: **0.0, 0.0, 1.0**   
     > ∗ FOV : Horizontal field of view in degrees in range [0,180]: **70**
     > ```shell
     >       C  -50.0,0,20  0,0,1  70
     > ```
  ◦ Light:   
     > ∗ identifier: **L**   
     > ∗ x,y,z coordinates of the light point: **-40.0, 50.0, 0.0**   
     > ∗ the light brightness ratio in range [0.0,1.0]: **0.6**   
     > ∗ (unused in mandatory part)R,G,B colors in range [0-255]: **10, 0, 255**
     > ```shell
     >       L  -40.0,50.0,0.0  0.6  10,0,255
     > ```
  ◦ Sphere:   
     > ∗ identifier: **sp**   
     > ∗ x,y,z coordinates of the sphere center: **0.0, 0.0, 20.6**   
     > ∗ the sphere diameter: **12.6**   
     > ∗ R,G,B colors in range [0-255]: **10, 0, 255**
     > ```shell
     >       sp  0.0,0.0,20.6  12.6  10,0,255
     > ```
  ◦ Plane:   
     > ∗ identifier: **pl**   
     > ∗ x,y,z coordinates of a point in the plane: **0.0, 0.0, -10.0**   
     > ∗ 3d normalized normal vector. In range [-1,1] for each x,y,z axis: **0.0, 1.0, 0.0**   
     > ∗ R,G,B colors in range [0-255]: **0, 0, 225**   
     > ```shell
     >       pl  0.0,0.0,-10.0  0.0,1.0,0.0  0,0,225
     >```
  ◦ Cylinder:   
     > ∗ identifier: **cy**   
     > ∗ x,y,z coordinates of the center of the cylinder: **50.0, 0.0, 20.6**   
     > ∗ 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis: **0.0, 0.0, 1.0**   
     > ∗ the cylinder diameter: **14.2**   
     > ∗ the cylinder height: **21.42**   
     > ∗ R,G,B colors in range [0,255]: **10, 0, 255**     
     > ```shall
     >      cy  50.0,0.0,20.6  0.0,0.0,1.0  14.2  21.42  10,0,255
     > ```

## Process
   **If any of these checks fail, an error is displayed, and the program terminates.**
  <img alt="image00" src="https://github.com/leebo155/minirt/blob/master/img/miniRT1.jpg">
   <br><br>
   **The scene structure stores objects and generates rays to record in a hit_record structure, which is used to calculate the returned color.**
  <img alt="image01" src="https://github.com/leebo155/minirt/blob/master/img/miniRT2.jpg">
   <br><br>
   **This is a visualization of the information about the objects.**
  <img alt="image02" src="https://github.com/leebo155/minirt/blob/master/img/miniRT3.jpg">
   <br><br>
   **When constructing the scene, first create the camera and viewport.**   
   **The aspect ratio is calculated from the canvas size, which is used to determine the viewport size.**
  <img alt="image03" src="https://github.com/leebo155/minirt/blob/master/img/miniRT4.jpg">
   <br><br>
   **Calculate the left bottom vertex of the viewport. The height vector and width vector of the viewport can be found by taking the cross product of the camera's normal vector.**
  <img alt="image04" src="https://github.com/leebo155/minirt/blob/master/img/miniRT5.jpg">
   <br><br>
   **The focal length can be determined using the tan() function. Since the return value of the tan() function is in radians, we calculated the viewport width by converting it to radians.**
  <img alt="image05" src="https://github.com/leebo155/minirt/blob/master/img/miniRT6.jpg">
   <br><br>
   **Once the left bottom vertex is calculated, you can compute the coordinates of the pixels for ray tracing. Generate the camera ray using the camera's origin and the pixel coordinates.**
  <img alt="image06" src="https://github.com/leebo155/minirt/blob/master/img/miniRT7.jpg">
   <br><br>
   **Perform hit detection using the generated ray and the objects in the scene.**
  <img alt="image07" src="https://github.com/leebo155/minirt/blob/master/img/miniRT8.jpg">
   <br><br>
   **If an object is hit during hit detection, proceed with light calculation for that coordinate.**
  <img alt="image08" src="https://github.com/leebo155/minirt/blob/master/img/miniRT9.jpg">
  <img alt="image09" src="https://github.com/leebo155/minirt/blob/master/img/miniRT10.jpg">
  <img alt="image10" src="https://github.com/leebo155/minirt/blob/master/img/miniRT11.jpg">
   <br><br>
   **Once the color is returned, place the color into the pixel coordinates of the image.**
  <img alt="image11" src="https://github.com/leebo155/minirt/blob/master/img/miniRT12.jpg">
   <br><br>  
   **Here is an example of the image.**
  <img alt="image12" src="https://github.com/leebo155/minirt/blob/master/img/miniRT13.jpg">
   <br><br>
   **This is the flowchart.**
  <img alt="flow" src="https://github.com/leebo155/minirt/blob/master/img/miniRT_flow.jpg">

## Makefile

| Rules | Description |
| ----- | ----------- |
| all | Compile a program miniRT. |
| clean | Remove all the temporary generated files. |
| fclean | Remove all the generated files. |
| re | Remove all the generated files and compile a miniRT. |

## Usage

```shall
$> ./miniRT [FILE.rt]
```
