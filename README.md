# CPP Ecosystem Project

## Launching tests
In order to test the different features developed, you first need to compile the relevant files using the following command line :
```bash
make -f [theCorrectMakeFile].mk
```
Then, you just have to run the executable created by the makefile (that should have the same name ad the corresponding makefile).

## Launching simulation
If you want to launch the full simulation, just run the following lines :
```bash
$ make
$ ./main
```
Then, your code will run.

## Results analysis
At the end of the simulation, a `.csv` file will have been generated in the directory of your `main`. This `.csv` file contains the number of each behaviour, accessory and captors at each step of the simulation.

All behaviour's names are stored such as `b_behaviourName`. Same logic for captors and accessories that are respectively stored such as `c_captorName` and `a_accessoryName`.

You can plot a graph of the evolution of the different populations inside the environment of simulation using Excel, python or any tool that is able to read a `.csv` file.

If you want to have access to the total number of animal in the aquarium, you will just need to sum all subpopulations of the different behaviours (and behaviour only, not accessories and captors).

## Miscellaneous

This repository contains a directory *templates* which contains some code templates to get a common base for the coding styles adopted while developing this project.
It is highly recommended to have a look at these files before coding here.

