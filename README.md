# miniRT
  RayTracer with miniLibX
 
  <img alt="image" src="https://github.com/leebo155/minirt/blob/master/img/miniRT.jpg">
  
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
     > ∗ identifier: A   
     > ∗ ambient lighting ratio in range [0.0,1.0]: 0.2   
     > ∗ R,G,B colors in range [0-255]: 255, 255, 255
     > ```shall
     >       A  0.2  255, 255, 255
     > ```
  ◦ Camera:   
     > ∗ identifier: C   
     > ∗ x,y,z coordinates of the view point: -50.0,0,20   
     > ∗ 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0   
     > ∗ FOV : Horizontal field of view in degrees in range [0,180]: 70
     > ```shell
     >       C  -50.0,0,20  0,0,1  70
     > ```
  ◦ Light:   
     > ∗ identifier: L   
     > ∗ x,y,z coordinates of the light point: -40.0,50.0,0.0   
     > ∗ the light brightness ratio in range [0.0,1.0]: 0.6   
     > ∗ (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255
     > ```shell
     >       L  -40.0,50.0,0.0  0.6  10,0,255
     > ```
  ◦ Sphere:   
     > ∗ identifier: sp   
     > ∗ x,y,z coordinates of the sphere center: 0.0,0.0,20.6   
     > ∗ the sphere diameter: 12.6   
     > ∗ R,G,B colors in range [0-255]: 10, 0, 255
     > ```shell
     >       sp  0.0,0.0,20.6  12.6  10,0,255
     > ```
  ◦ Plane:   
     > ∗ identifier: pl   
     > ∗ x,y,z coordinates of a point in the plane: 0.0,0.0,-10.0   
     > ∗ 3d normalized normal vector. In range [-1,1] for each x,y,z axis: 0.0,1.0,0.0   
     > ∗ R,G,B colors in range [0-255]: 0,0,225   
     > ```shell
     >       pl  0.0,0.0,-10.0  0.0,1.0,0.0  0,0,225
     >```
  ◦ Cylinder:   
     > ∗ identifier: cy   
     > ∗ x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6   
     > ∗ 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0   
     > ∗ the cylinder diameter: 14.2   
     > ∗ the cylinder height: 21.42   
     > ∗ R,G,B colors in range [0,255]: 10, 0, 255     
     > ```shall
     >      cy  50.0,0.0,20.6  0.0,0.0,1.0  14.2  21.42  10,0,255
     > ```

## Process
  <img alt="image" src="https://github.com/leebo155/minirt/blob/master/img/miniRT1.jpg">
  <img alt="image" src="https://github.com/leebo155/minirt/blob/master/img/miniRT2.jpg">
  <img alt="image" src="https://github.com/leebo155/minirt/blob/master/img/miniRT3.jpg">
  <img alt="image" src="https://github.com/leebo155/minirt/blob/master/img/miniRT4.jpg">
  <img alt="image" src="https://github.com/leebo155/minirt/blob/master/img/miniRT5.jpg">
  <img alt="image" src="https://github.com/leebo155/minirt/blob/master/img/miniRT6.jpg">
  <img alt="image" src="https://github.com/leebo155/minirt/blob/master/img/miniRT7.jpg">
  <img alt="image" src="https://github.com/leebo155/minirt/blob/master/img/miniRT8.jpg">
  <img alt="image" src="https://github.com/leebo155/minirt/blob/master/img/miniRT9.jpg">
  <img alt="image" src="https://github.com/leebo155/minirt/blob/master/img/miniRT10.jpg">
  <img alt="image" src="https://github.com/leebo155/minirt/blob/master/img/miniRT11.jpg">
  <img alt="image" src="https://github.com/leebo155/minirt/blob/master/img/miniRT12.jpg">
  <img alt="image" src="https://github.com/leebo155/minirt/blob/master/img/miniRT13.jpg">
  <img alt="image" src="https://github.com/leebo155/minirt/blob/master/img/miniRT_flow.jpg">

## Makefile

| Rules | Description |
| ----- | ----------- |
| all | Compile a program miniRT. |
| clean | Remove all the temporary generated files. |
| fclean | Remove all the generated files. |
| re | Remove all the generated files and compile a miniRT. |

## Usage

* Basic Execution
  ```shall
  $> ./miniRT [FILE.rt]
  ```
