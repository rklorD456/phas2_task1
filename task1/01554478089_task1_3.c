#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task {
    int id;
    char description[100];
    int completed;
};

void addTask(struct Task *tasks, int *numTasks) {
    struct Task newTask;
    newTask.id = (*numTasks) + 1;
    newTask.completed = 0;
	
	fflush(stdin);
    printf("Enter task description: ");
    gets(newTask.description);

    tasks[*numTasks] = newTask;
    (*numTasks)++;

    printf("Task added successfully!\n");
}

void viewTasks(struct Task *tasks, int numTasks) {
    if (numTasks == 0) {
        printf("No tasks found.\n");
        return;
    }

    printf("Current Tasks:\n");
    printf("%-10s %-30s %s\n", "Task ID", "Description", "Status");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < numTasks; i++) {
        printf("%-10d %-30s %s\n", tasks[i].id, tasks[i].description,
               tasks[i].completed ? "Completed" : "Incomplete");
    }
}
void markTaskCompleted(struct Task *tasks, int numTasks)
{
    int taskId;
    printf("Enter task ID to mark as completed: ");
    scanf("%d", &taskId);

    for (int i = 0; i < numTasks; i++)
    {
        if (tasks[i].id == taskId)
        {
            tasks[i].completed = 1;
            printf("Task marked as completed!\n");
            return;
        }
    }
    printf("Task not found.\n");
}

void viewCompletedTasks(struct Task *tasks, int numTasks)
{
    printf("Completed Tasks:\n");
    printf("%-10s %-30s\n", "Task ID", "Description");
    printf("---------------------------------\n");
    for (int i = 0; i < numTasks; i++)
    {
        if (tasks[i].completed)
        {
            printf("%-10d %-30s\n", tasks[i].id, tasks[i].description);
        }
    }
}
void viewIncompleteTasks(struct Task *tasks, int numTasks)
{
    printf("Incomplete Tasks:\n");
    printf("%-10s %-30s\n", "Task ID", "Description");
    printf("---------------------------------\n");

    for (int i = 0; i < numTasks; i++)
    {
        if (!tasks[i].completed)
        {
            printf("%-10d %-30s\n", tasks[i].id, tasks[i].description);
        }
    }
}

int main() {
    int option;
    struct Task *tasks = NULL;
    int numTasks = 0;

    do {
        printf("Minions Task Manager\n");
        printf("1. Add Task\n");
        printf("2. View All Tasks\n");
        printf("3. View Completed Tasks\n");
        printf("4. View Incomplete Tasks\n");
        printf("5. Mark Task as Completed\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                tasks = realloc(tasks, (numTasks + 1) * sizeof(struct Task));
                addTask(tasks, &numTasks);
                break;
            case 2:
                viewTasks(tasks, numTasks);
                break;
            case 3:
                viewCompletedTasks(tasks, numTasks);
                break;
            case 4:
                viewIncompleteTasks(tasks, numTasks);
                break;
            case 5:
                markTaskCompleted(tasks, numTasks);
                break;
            case 6:
                printf("Exiting Minions Task Manager. Have a great day!\n");
                break;
            default:
                printf("Invalid option. Please select a valid option.\n");
        }
    } while (option != 6);

    return 0;
}