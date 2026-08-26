class Solution {
public:
    unordered_map<int, Employee*> employees;

    int dfs(int id) {
        Employee* employee = employees[id];

        int total = employee->importance;

        for (int subordinate : employee->subordinates) {
            total += dfs(subordinate);
        }

        return total;
    }

    int getImportance(vector<Employee*> employeesList, int id) {

        // Store employees by their ID
        for (Employee* employee : employeesList) {
            employees[employee->id] = employee;
        }

        return dfs(id);
    }
};