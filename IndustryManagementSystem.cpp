#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Employee {
public:
    string name;
    string post;
    int employeeID;
    string gender;
    int age;
    string address;
    string joiningDate;
    int departmentID;

    Employee(string n, string p, int id, string g, int a, string addr, string jDate, int dID)
        : name(n), post(p), employeeID(id), gender(g), age(a), address(addr), joiningDate(jDate), departmentID(dID) {}
};
class Department {
public:
    string departmentName;
    int departmentID;
    string city;
    string address;

    Department(string name, int id, string c, string addr)
        : departmentName(name), departmentID(id), city(c), address(addr) {}
};
class HRDepartment {
public:
    int departmentID;
    string post;
    double salary;
    double joiningBonus;
    double annualBonus;
    int leaves;

    HRDepartment(int id, string p, double s, double jBonus, double aBonus, int l)
        : departmentID(id), post(p), salary(s), joiningBonus(jBonus), annualBonus(aBonus), leaves(l) {}
};
class EmployeeDatabase {
private:
    vector<Employee> employees;
    vector<Department> departments;
    vector<HRDepartment> hrDetails;

public:
    void addEmployee() {
        string name, post, gender, address, joiningDate;
        int employeeID, age, departmentID;

        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter employee post: ";
        
        getline(cin, post);
        cout << "Enter employee ID: ";
        cin >> employeeID;
        cout << "Enter employee gender: ";
        cin >> gender;
        cout << "Enter employee age: ";
        cin >> age;
        cout << "Enter employee address: ";
        cin.ignore();
        getline(cin, address);
        cout << "Enter employee joining date (YYYY-MM-DD): ";
        cin >> joiningDate;
        cout << "Enter Department ID: ";
        cin >> departmentID;
        employees.emplace_back(name, post, employeeID, gender, age, address, joiningDate, departmentID);
        cout << "Employee added successfully!\n";
    }
    void addDepartment() {
        string name, city, address;
        int id;

        cout << "Enter department name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Department ID: ";
        cin >> id;
        cout << "Enter Department city: ";
        cin.ignore();
        getline(cin, city);
        cout << "Enter Department address: ";
        
        getline(cin, address);
        departments.emplace_back(name, id, city, address);
        cout << "Department added successfully!\n";
    }

    void addHRDetails() {
        int id; 
        string post; 
        double salary; 
        double joiningBonus; 
        double annualBonus; 
        int leaves;

        cout << "Enter  Department ID: ";
        cin >> id;
        cout << "Enter post: ";
        cin.ignore();
        getline(cin, post);
        cout << "Enter salary: ";
        cin >> salary;
        cout << "Enter joining bonus: ";
        cin >> joiningBonus;
        cout << "Enter annual bonus: ";
        cin >> annualBonus;
        cout << "Enter number of leaves: ";
        cin >> leaves;

        hrDetails.emplace_back(id, post, salary, joiningBonus, annualBonus, leaves);
        cout << "HR details added successfully!\n";
    }

    void showAllEmployees() {
       if (employees.empty()) {
            cout << "No employees found.\n";
            return;
       }
       
       for (const auto& emp : employees) {
            cout << "Name: " << emp.name << endl;
            cout << " Post: " << emp.post<< endl;
            cout << " ID: " << emp.employeeID<< endl; 
            cout << " Gender: " << emp.gender<< endl;
            cout << " Age: " << emp.age << endl;
            cout << " Address: " << emp.address <<endl;
            cout << " Joining Date: " << emp.joiningDate <<endl;
            cout << " Department ID: " << emp.departmentID;
            cout << endl;  
       }
   }

   void showAllDepartments() {
       if (departments.empty()) {
            cout << "No departments found.\n";
            return;  
       }
       
       for (const auto& dept : departments) {
            cout << "Department Name: " << dept.departmentName<<endl;
            cout << " Department ID: " << dept.departmentID<<endl;
            cout << " City: " << dept.city<<endl;
            cout << " Address: " << dept.address;
            cout << endl;  
       }
   }

   void showSalaryDetails(int empID) {
       for (const auto& emp : employees) {
           if (emp.employeeID == empID) {
               for (const auto& hr : hrDetails) {
                   if (hr.departmentID == emp.departmentID && hr.post == emp.post) {
                       cout << "Employee ID: " << emp.employeeID <<endl;
                       cout << " Post: " << emp.post <<endl;
                       cout << " Salary: $" << hr.salary <<endl;
                       cout << " Joining Bonus: $"  << hr.joiningBonus<<endl;
                       cout << " Annual Bonus: $"  << hr.annualBonus<<endl;
                       cout << " Leaves Allowed: "<< hr.leaves;
                       cout << endl;  
                       return;  
                   }
               }
           }
       }
       cout<< "No salary details found for Employee ID "<< empID<<endl;  
   }

   void deleteDepartment(int deptID) {
       auto it = remove_if(departments.begin(), departments.end(),
                           [deptID](const Department& dept) { return dept.departmentID == deptID; });
       if (it != departments.end()) {
           departments.erase(it, departments.end()); 
           cout<< "Department deleted successfully!\n";  
       } else {
           cout<< "Department not found!\n";  
       }
   }
};


int main() {
    EmployeeDatabase db;

    while (true) {
      int choice;
      cout<< "\nMenu:\n";
      cout<< 1<<" Add Employee\n";
      cout<< 2<<" Add Department\n";
      cout<< 3<<" Add Employee  Details in HR\n";
      cout<< 4<<" Show All Employees\n";
      cout<< 5<<" Show All Departments\n";
      cout<< 6<<" Show Salary Details by Employee ID\n";
      cout<< 7<<" Delete Department\n";
      cout<< 8<<" Exit\n";
      cout<< "\nChoose an option (1-8): ";  
      cin>> choice;

      switch(choice) {
          case 1:
              db.addEmployee();
              break;

          case 2:
              db.addDepartment();
              break;

          case 3:
              db.addHRDetails();
              break;

          case 4:
              db.showAllEmployees();
              break;

          case 5:
              db.showAllDepartments();
              break;

          case 6:
              int empId;  
              cout<< "\nEnter Employee ID to view salary details: ";  
              cin>> empId;  
              db.showSalaryDetails(empId);  
              break;

          case 7:
              int deptId;  
              cout<< "\nEnter Department ID to delete: ";  
              cin>> deptId;  
              db.deleteDepartment(deptId);  
              break;

          case 8:
              exit(0);

          default:
              cout<< "\nInvalid choice! Please try again.\n";  
      }
   }

   return 0;   
}
