# ReadMe

This software simulates a random walk of disks that cannot overlap with each other. It is hard to know exactly why it was originally written but it seemed to me to be a good simulation for brownian motion. To this end I updated the simulation to have the option to use a gaussian distribution for its random movements as it is a better fit for Brownian motion.

The c++ code compiles into a binary that generates a file for each iteration in the confs/ folder. The python script view.py can then be run to create an animation of the disks moving in the box.

Bellow is instruction on how to compile the code and details on the repairs that were made to the codebase, along with further modifications I made under their version numbers. Three Git branches were used throughout, main, Repair and Dev. Repair was used to implement all repairs that eventually got merged into main for version 1.0. From that point on the Dev branch was used to implement new features. I deemed it unnecessary to have a separate branch for each new feature as there were none that were large enough to justify it. Instead everything was done through the Dev branch and periodically merged back into main for a new version.

`git log` can be used to show the commit history.

`git log --graph` is a more complex view showing how the different branches split and merge.

## Compilation
To compile and run the code use `make Win ARGS = "1 2 3 4 5"` if you are on a Windows machine or `make Unix ARGS = "1 2 3 4 5"` if you are on a Unix based OS. Where the numbers are replaced with the parameters for the system of interest. The five arguments that can be passed into the make command:
1. The number of disks - **int**
2. The maximum displacement of the disks (if using a uniform distribution) or the standard deviation (if using a gaussian distribution) - **float**
3. The disk radius - **float**
4. Box length - **float**
5. Uniform or Gaussian - **0 for uniform, 1 for gaussian**

For example, `make Win ARGS = "40 0.5 0.6 15 0"` will create a simulation for a windows machine with 40 disks inside a 15x15 box where each disk has a radius of 0.6 and will move randomly according to a uniform distribution between -0.5 and 0.5 in each direction.

If `make Win` or `make Unix` is run without arguments then they will default to 20 0.05 0.5 20 0. `make Wclean` and `make Uclean` will delete the binary and the contents of the confs folder. If you wish to visualise the data again without having to regenerate it, you can simply run the `view.py` file.


**It may be useful to change the interval in the python script to change the animation speed.**

## Repairs
- Added the missing header files using the information from refman.pdf.
- Completed the missing sections of:
    - disk.cpp by implementing the distance function which calculates the distance between a given disk and itself.
    - system.cpp by adding two more required #include statements and the uniform method which generates a random number between a given max and min.
    - main.cpp by adding one missing #include statement.
- Fixed a bug in the system step function that would stop the system from changing in time.
- Changed the python code so that it would run on Windows.

## Changelog
#### version 1.0
- All repairs.
#### version 1.1
- Refactored parts of the code to better encapsulate the classes.
- Added the simulation parameters as arguments to pass into the binary.
- Improved the Makefile so that it could take in arguments and would run the python visualisation after generating the data. Also added separate commands for Windows and Unix systems.
- Improved the view.py file so that it would run on both Windows and Unix systems.
#### version 1.2
- Changed the simulation to not allow the disks to phase halfway through the wall. Now a disk cannot move into the wall if it is within its radius distance from the wall. 
- Added the ability to change from a uniform distribution to a gaussian with another command line argument.
