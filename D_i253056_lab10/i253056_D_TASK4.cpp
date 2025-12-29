#include <iostream>
using namespace std;

int main()
{
    int departments, course, students;
    cout << "Enter number of departments: ";
    cin >> departments;
    cout << "Enter number of courses per department: ";
    cin >> course;
    cout << "Enter number of students per course: ";
    cin >> students;

    int marks[10][10][50];
    float deptavg[10], courseavg[10][10];
    float totalsum = 0;
    int totalcount = 0;

    for (int i = 0; i < departments; i++)
    {
        float deptsum = 0;
        cout << "\nDepartment " << i + 1 << ":\n";
        for (int j = 0; j < course; j++)
        {
            float coursesum = 0;
            cout << "Course " << j + 1 << " marks:\n";
            for (int k = 0; k < students; k++)
            {
                cin >> marks[i][j][k];
                coursesum += marks[i][j][k];
            }
            courseavg[i][j] = coursesum / students;
            deptsum += coursesum;
            totalsum += coursesum;
            totalcount += students;
        }
        deptavg[i] = deptsum / (course * students);
    }

    float uniavg = totalsum / totalcount;

    cout << "\n\t STUDENT PERFORMANCE REPORT\t\n";
    for (int i = 0; i < departments; i++)
    {
        cout << "\nDepartment " << i + 1 << ":\n";
        for (int j = 0; j < course; j++)
        {
            cout << "Course " << j + 1 << " Average = " << courseavg[i][j] << "\n";
        }
        cout << "Department " << i + 1 << " Average = " << deptavg[i] << "\n";
    }
    cout << "Overall Uni Average = " << uniavg<<endl;

    float highest = deptavg[0], lowest = deptavg[0];
    int highdept = 1, lowdept = 1;

    for (int i = 1; i < departments; i++)
    {
        if (deptavg[i] > highest)
        {
            highest = deptavg[i];
            highdept = i + 1;
        }
        if (deptavg[i] < lowest)
        {
            lowest = deptavg[i];
            lowdept = i + 1;
        }
    }

    cout << "\n Highest Department Average = " << highest << " (Department " << highdept << ")\n";
    cout << "Lowest Department Average = " << lowest << " (Department " << lowdept << ")\n";

    return 0;
}
