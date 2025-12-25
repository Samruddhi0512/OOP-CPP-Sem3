/**
 * Name: Samruddhi Sunil Bate
 * Roll No: 14
 * Class: CS-SEDA-B
 * Aim: Design and develop inheritance for a given case study, identify objects and relationships and
implement inheritance wherever applicable. Employee class hasEmp_name, Emp_id,
Address, Mail_id, and Mobile_no as members. Inherit the classes: Programmer, Team Lead,
Assistant Project Manager and Project Manager from employee class. Add Basic Pay (BP) as
the member of all the inherited classes with 52% of BP as DA, 27 % of BP as HRA, 12% of
BP as PF, 0.1% of BP for staff club fund. Generate pay slips for the employees with their
gross and net salary.


 */
 // ************    ASSIGNMENT 6    ************* 

#include <iostream>
#include <string>
using namespace std;

//  Base Class 
class Employee {
protected:
    string emp_name, emp_id, address, mail_id;
    long long mobile_no;

public:
    void getDetails() {
        
        cout << "Enter Employee Name: ";
        getline(cin, emp_name);

        cout << "Enter Employee ID: ";
        getline(cin, emp_id);

        cout << "Enter Address: ";
        getline(cin, address);

        cout << "Enter Mail ID: ";
        getline(cin, mail_id);

        cout << "Enter Mobile Number: ";
        cin >> mobile_no;
        while (to_string(mobile_no).length() != 10) {
            cout << "Invalid! Enter a 10-digit mobile number: ";
            cin >> mobile_no;
        }
    }

    void displayDetails() {
        cout << "\n Employee Details \n";
        cout << "Name: " << emp_name << endl;
        cout << "ID: " << emp_id << endl;
        cout << "Address: " << address << endl;
        cout << "Mail ID: " << mail_id << endl;
        cout << "Mobile No: " << mobile_no << endl;
    }
};

//  Derived Class: Programmer 
class Programmer : public Employee {
protected:
    float bp; 
public:
    void getPayDetails() {
        cout << "Enter Basic Pay: ";
        cin >> bp;
        while (bp <= 0) {
            cout << "Invalid! Basic Pay must be positive. Enter again: ";
            cin >> bp;
        }
    }

    void generatePaySlip() {
        float DA = 0.52 * bp;
        float HRA = 0.27 * bp;
        float PF = 0.12 * bp;
        float staffFund = 0.001 * bp;

        float gross = bp + DA + HRA;
        float net = gross - PF - staffFund;

        displayDetails();
        cout << "\n--- Programmer Pay Slip ---\n";
        cout << "Basic Pay: " << bp << endl;
        cout << "DA (52%): " << DA << endl;
        cout << "HRA (27%): " << HRA << endl;
        cout << "PF (12%): " << PF << endl;
        cout << "Staff Club Fund (0.1%): " << staffFund << endl;
        cout << "Gross Salary: " << gross << endl;
        cout << "Net Salary: " << net << endl;
    }
};

//  Derived Class: Team Lead 
class TeamLead : public Employee {
protected:
    float bp;
public:
    void getPayDetails() {
        cout << "Enter Basic Pay: ";
        cin >> bp;
        while (bp <= 0) {
            cout << "Invalid! Basic Pay must be positive. Enter again: ";
            cin >> bp;
        }
    }

    void generatePaySlip() {
        float DA = 0.52 * bp;
        float HRA = 0.27 * bp;
        float PF = 0.12 * bp;
        float staffFund = 0.001 * bp;

        float gross = bp + DA + HRA;
        float net = gross - PF - staffFund;

        displayDetails();
        cout << "\n--- Team Lead Pay Slip ---\n";
        cout << "Basic Pay: " << bp << endl;
        cout << "DA (52%): " << DA << endl;
        cout << "HRA (27%): " << HRA << endl;
        cout << "PF (12%): " << PF << endl;
        cout << "Staff Club Fund (0.1%): " << staffFund << endl;
        cout << "Gross Salary: " << gross << endl;
        cout << "Net Salary: " << net << endl;
    }
};

// Derived Class: Assistant Project Manager 
class AssistantProjectManager : public Employee {
protected:
    float bp;
public:
    void getPayDetails() {
        cout << "Enter Basic Pay: ";
        cin >> bp;
        while (bp <= 0) {
            cout << "Invalid! Basic Pay must be positive. Enter again: ";
            cin >> bp;
        }
    }

    void generatePaySlip() {
        float DA = 0.52 * bp;
        float HRA = 0.27 * bp;
        float PF = 0.12 * bp;
        float staffFund = 0.001 * bp;

        float gross = bp + DA + HRA;
        float net = gross - PF - staffFund;

        displayDetails();
        cout << "\n--- Assistant Project Manager Pay Slip ---\n";
        cout << "Basic Pay: " << bp << endl;
        cout << "DA (52%): " << DA << endl;
        cout << "HRA (27%): " << HRA << endl;
        cout << "PF (12%): " << PF << endl;
        cout << "Staff Club Fund (0.1%): " << staffFund << endl;
        cout << "Gross Salary: " << gross << endl;
        cout << "Net Salary: " << net << endl;
    }
};

//  Derived Class: Project Manager 
class ProjectManager : public Employee {
protected:
    float bp;
public:
    void getPayDetails() {
        cout << "Enter Basic Pay: ";
        cin >> bp;
        while (bp <= 0) {
            cout << "Invalid! Basic Pay must be positive. Enter again: ";
            cin >> bp;
        }
    }

    void generatePaySlip() {
        float DA = 0.52 * bp;
        float HRA = 0.27 * bp;
        float PF = 0.12 * bp;
        float staffFund = 0.001 * bp;

        float gross = bp + DA + HRA;
        float net = gross - PF - staffFund;

        displayDetails();
        cout << "\n--- Project Manager Pay Slip ---\n";
        cout << "Basic Pay: " << bp << endl;
        cout << "DA (52%): " << DA << endl;
        cout << "HRA (27%): " << HRA << endl;
        cout << "PF (12%): " << PF << endl;
        cout << "Staff Club Fund (0.1%): " << staffFund << endl;
        cout << "Gross Salary: " << gross << endl;
        cout << "Net Salary: " << net << endl;
    }
};

//  Main Function 
int main() {
    int choice;
    cout << "\n--- Employee Pay Slip Generation ---\n";
    cout << "1. Programmer\n";
    cout << "2. Team Lead\n";
    cout << "3. Assistant Project Manager\n";
    cout << "4. Project Manager\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            Programmer p;
            p.getDetails();
            p.getPayDetails();
            p.generatePaySlip();
            break;
        }
        case 2: {
            TeamLead t;
            t.getDetails();
            t.getPayDetails();
            t.generatePaySlip();
            break;
        }
        case 3: {
            AssistantProjectManager a;
            a.getDetails();
            a.getPayDetails();
            a.generatePaySlip();
            break;
        }
        case 4: {
            ProjectManager pm;
            pm.getDetails();
            pm.getPayDetails();
            pm.generatePaySlip();
            break;
        }
        default:
            cout << "Invalid choice! Program exiting.\n";
    }

    cout << "\n Program Executed Successfully!\n";
    return 0;
}