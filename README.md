# Philosofers

This project simulates the dining philosophers problem. In conputer science, this is an example of a common problem to illustrate synchronization issues and techniques for resolving them. The problem was designed to illustrate the challenges of avoiding deadlock, a system state in which no progress is possible.

# Usage

The program takes 4 or 5 arguments:

◦ Number of philosophers: The number of philosophers and also the number
of forks.

◦ Time to die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.

◦ Time to eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.

◦ Time to sleep (in milliseconds): The time a philosopher will spend sleeping.

◦ Number of times each philosopher must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.
