#include <iostream> // cin cout
#include <string> // text handling
#include <algorithm> // only for remove_if i will use 
#include <vector> // dynamic arrays

using namespace std;


class Task{ // bluepring of tasks
    public:
        string description; // task descriptions
        bool isCompleted; // tracking true or false for task done

        Task(string desc) {
            description = desc;
            isCompleted = false;
        }
};

class TodoList {
    private:
        vector<Task> tasks;

    public:
        void addingTask(string desc) { // adds task here i guess (yes)
            tasks.push_back(Task(desc));
        }

        void checkTasks() {
            if (tasks.empty()) {
                cout << "Either you completed all your tasks or you didn't start (if didn't start START NOW!) \n";
                return;
            }
            cout << "Your Tasks listed below: \n";
            for (size_t i = 0; i < tasks.size(); i++) {
                cout << i + 1 << ". [" << (tasks[i].isCompleted ? "✔" : "✘") << "] " << tasks[i].description << "\n";
            }
        }

        void TaskCompletionMark(int index) {
            if (index < 1 || index > tasks.size()) {
                cout << "No Task Exists with this task number. \n";
                return;
            }
            tasks[index - 1].isCompleted = true;
            cout << "This Task Has Been Completed (Marked). \n";
        }

        void removetask(int index) {
            if (index < 1 || index > tasks.size()) {
                cout << "This Task Number Doesn't Exist \n";
                return;
            }
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task Removed (Completed I Guess \n)";
        }

        void clearCompletedTask() {
            tasks.erase(remove_if(tasks.begin(), tasks.end(), [](Task &t) { return t.isCompleted; }), tasks.end());
            cout << "ALL THE TASKS YOU COMPLETED ARE (REMOVED)";
        }
};

int main() {
    TodoList todolist;
    int choice;

    while (true) {
        cout << "\n======== TO DO LIST by DANIEL ========\n";
        cout << " 1. Add Task \n 2. Check In On Tasks \n 3. Mark This Task As Completed \n 4. Remove Task \n 5. Clear Completed Tasks \n 6. EXIT \n";
        cout << "Enter your Choice: ";
        cin >> choice;

        if (choice == 1) {
            cin.ignore();
            string task;
            cout << "Enter The Tasks Description: ";
            getline(cin, task);
            todolist.addingTask(task);
        } else if (choice == 2) {
            todolist.checkTasks();
        } else if (choice == 3) {
            int taskNumber;
            cout << "Enter Task Number To Mark As Completed: ";
            cin >> taskNumber;
            todolist.TaskCompletionMark(taskNumber);
        } else if (choice == 4) {
            int taskNumber;
            cout << "Enter Task number to remove: ";
            cin >> taskNumber;
            todolist.removetask(taskNumber);
        } else if (choice == 5) {
            todolist.clearCompletedTask();
        } else if (choice == 6) {
            cout << "Exiting TO-DO List \n";
            break;
        } else {
            cout << "Invalid Choice Try Again \n";
        }
    }

    return 0;
}