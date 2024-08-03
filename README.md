# Philosophers

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    <div class="header-container">
        <img src="https://github.com/ayogun/42-project-badges/blob/main/covers/cover-philosophers-bonus.png" width="400" alt="Imagem 1"/>
        <img src="https://media2.giphy.com/media/v1.Y2lkPTc5MGI3NjExcDd1aG41d3hlanVxcnlkNndmNmJzbjFxejU2enBzcjR1eHU0ZXJhMyZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/3ohhwuTUMOxvXLtrMc/giphy.webp" width="358" alt="Imagem 2"/>
    </div>
</body>
</html>


<h1 align="center">Because Eating with a Single Fork Is Too Much Trouble()</h1>

## About
This project is the first one in the 42 curriculum that requires the use of threads. The goal is to simulate the Dining Philosophers problem, where multiple philosopher threads share resources (forks) to eat spaghetti. The project involves managing synchronization and preventing issues that arise with concurrent processes.

## Challenges
- Multi threads
- Data Racing: Address and resolve issues of data races between philosopher threads.
- Deadlocks: Prevent and handle deadlocks caused by mutexes used for resource management.
- Philosopher Lifecycle: Implement mechanisms to monitor and manage the time philosophers spend eating and prevent them from "dying" due to starvation.

## Instructions

### 1. Compiling the archives

To compile the project, go to its path and run:

For __mandatory__ functions:
```
$ make
```
### 2. Cleaning all binary (.o) and executable files (.a)

To delete all files generated with make, go to the path and run:
```
$ make fclean
```

### 3. How to use

- ./philo [Number_of_philo] [Time_to_die] [Time_to_eat] [Time_to_sleep] [OPTIONAL: Number_of_time_need_to_eat]

```
$ ./philo 10 800 200 200 5
```

## Testing
This project have been tested with [Nafuka Visualizer](https://nafuka11.github.io/philosophers-visualizer/).
