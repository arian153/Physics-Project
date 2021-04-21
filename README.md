# Physics-Project

## API
* Win32
* DirectX 11
* Direct2D
* DirectWrite

## Library 
* jconcpp                
Under MIT license, or public domain

* DirectXTex texture processing library        
Under MIT Lisence

* Dear ImGui
under MIT License

## A. How to use User Interface
Menu Bar
File                     - Space file related Interface.
    Open Space               - Open a Space file from disk, load world data. 
    Exit                     - Close the application.

Edit
    Most of it doesn't work yet.

Object
    Create 3D Object  - Create Presaved Object from files.

General Camera Usage
    Hold left mouse button and move the mouse, camera moves on the spherical coordinates, and camera look at the target.
    Scroll the mouse wheel, adjust the radius of the spherical coordinates.
    Hold W key, move both target and camera position upward to the camera coordinates. 
    Hold S key, move both target and camera position downwards to the camera coordinates. 
    Hold A key, move both target and camera position to the left of the camera coordinates. 
    Hold D key, move both target and camera position to the right of the camera coordinates. 
    Hold E key, move both target and camera position forward to the camera coordinates. 
    Hold Q key, move both target and camera position rearward to the camera coordinates.

Commands Window
Tracking implemented command when editing world. But I haven't finished yet. 

Hierarchy Window
Manage objects in the world as a list. When selected, allows editing in the Inspector window.

Inspector Window
You can edit each component of an object or read information. However, some implementations are not complete.
You can select an object in the world by clicking it.

Space Setting Window
You can edit the world's settings.

Space Window
You can see the world simulation.


## Assumtion
Test in release mode is recommended.
Place the resource folder in a "../../Resource" relative to the executable.
like "../../Resource". 

i.e)
Project/Bin/Debug/Physics-Project.exe
Project/Bin/Release/Physics-Project.exe
Project/Resource/..
Project/Source/..

## Build and Recompile
This framework build using visual studio 2019 and c++17,  also it depends on win32 and DirectX11.
Use solution file to recompile it.

## Execution
Execute Physics-Project.exe in "Bin/Release/Physics-Project.exe"

## Missing Components
There are many components that only create outline and have not yet finished development.
Broad-Phase
 - Grid-Based Space Partitioning
 - Octree-Based Space Partitioning

Collider Primitive
 - Plane Collider
 - Terrain Collider
 - Polyhedron Collider (Convex Hull of given 3D mesh)
 - Polygon Collider (Convex Hull of given 2D mesh)

Resolution Phase
 - Constraints
    - Point Joint Constraints (Connect 2 Rigid Bodies with point)
 - Stablity
    - Still jitter when turn off sleep
    - Not fully stable when build contact manifold. (most case has 1~3 contact points)
    - Sometimes calculate nan with velocity term. (At that case resolution cannot solve contact constraints)
