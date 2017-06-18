Full Name: Yoel Lev
ID: •••••

The program is designed in a way that the PreSimulation Class prepares all the data necessary to start a proper simulation.
if data is missing or entered incorrectly the program will generate a message end quit.
if all data from the files are valid the preSimulation will create a Simulation instance and will call the startSimulation Method.

in my design a cyber Package is an instance of the Package Class that has all of the operators defined and even more! as the "==" returns 
the equality of strength. the strength returned is the one of the package in the LHS. 

each class that needs the BIG Three is implemented with a Copy C'tor, D'tor,and an Equal operator.
the [] and the % operators are implemented in the Package Class.
i also implemented the << (cout) for debugging purposes !

the TLC packages inherit from the package class and are initiated in the Simulation class, once all data was verified.
the simulation starts and adds all of the returned packages that were matching the offense team to the Generic LL.

after that it selects a group of TLC packages which has the Closest match to the Offense team. 


(the program was successfully compiled with all warnings, error, pedantic flags).

Enjoy.
