![philosophersm](https://user-images.githubusercontent.com/63206471/176322105-536b43cf-d6a4-46c0-9c3a-3336cf6e791c.png)

# Philosophers

* [Introduction](#introduction)
* Notion
* [The Project](#the-project)

## Introduction
In this project, I learned how to deal with threading. Also, I had to use mutexes to prevent things like _data racing_ and _dead locks_.

## Skills that I have improved
* Imperative programming
* Rigor
* Unix

## The Project
In order to succeed in doing this project I had to master the following:
* Manage threads
* Understand CPU scheduling
* Parallellism
* Concurrency

### Philosophers Dining Problem
* One or more philosophers sit at a round table.
* There is a large bowl of spaghetti in the middle of the table.
• The philosophers alternatively eat, think, or sleep.
* While they are eating, they are not thinking nor sleeping;
* While thinking, they are not eating nor sleeping;
* While sleeping, they are not eating nor thinking.
• There are also forks on the table. There are as many forks as philosophers.
• Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.
• When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.
• Every philosopher needs to eat and should never starve.
• Philosophers don’t speak with each other.
• Philosophers don’t know if another philosopher is about to die.
• No need to say that philosophers should avoid dying!

### Diagram
![Philosophers](https://user-images.githubusercontent.com/63206471/176323139-cdc7a72e-7c4c-421a-9ec6-e9304a32312d.png)

### How to run it?

```
1 - make or make bonus
2 - Example => ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
It should behave like:
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

You can also run with here_doc
Example =>  ./pipex here_doc LIMITER cmd1 cmd2 ... cmdn file
IT should behave like:
cmd << LIMITER | cmd1 >> file
```
