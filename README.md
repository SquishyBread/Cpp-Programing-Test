# ReadMe

This software simulates a random walk of disks that cannot overlap with each other. It is hard to know exactly why it was originally written but it seemed to me to be a good simulation for brownian motion. To this end I updated the simulation to use a gaussian distribution for its random movements.

Bellow is detailed the repairs that were made to the codebase along with further modifications I made under their version number. Three branches were used throughout, main, Repair and Dev. Repair was used to implement all repairs that eventually got merged into main for version 1.0. From that point on the Dev branch was used to implement new features. I deemed it unnecessary to have a separate branch for each new feature as there were none that were large enough to justify it. Instead everything was done through the Dev branch and periodically merged back into main for a new version.

`git log` can be used to show the commit history.

`git log --graph` is a more complex view showing how the different branches split and merged.

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
