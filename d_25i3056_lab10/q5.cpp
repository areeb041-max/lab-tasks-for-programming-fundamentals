#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Display student info
    cout << "Name: Your Name" << endl;
    cout << "Roll No: 25i-3056" << endl;

    cout << "Task 05: 3D Structural Cube Analyzer\n" << endl;
    
    int machines, sensors, timeslots;
    cout << "Enter number of machines (layers): ";
    cin >> machines;
    cout << "Enter number of sensors (rows): ";
    cin >> sensors;
    cout << "Enter number of time slots (columns): ";
    cin >> timeslots;
    
    int cube[machines][sensors][timeslots]; 
    
    srand(time(0));
    
    cout << " GENERATING CUBE DATA " << endl;
    for(int i = 0; i < machines; i++) {
        for(int j = 0; j < sensors; j++) {
            for(int k = 0; k < timeslots; k++) {
                cube[i][j][k] = (rand() % 9) + 1; // 1 to 9
            }
        }
    }
    
    // Display all layers
    cout << " CUBE LAYERS " << endl;
    for(int i = 0; i < machines; i++) {
        cout << "\nMachine " << (i+1) << " (Layer " << (i+1) << "):" << endl;
        for(int j = 0; j < sensors; j++) {
            for(int k = 0; k < timeslots; k++) {
                cout << cube[i][j][k] << " ";
            }
            cout << endl;
        }
    }
    
    // Layer Analysis
    cout << " LAYER ANALYSIS " << endl;
    int healthpoints = 0;
    int totalChecks = 0;
    
    for(int i = 0; i < machines; i++) {
        int evencount = 0;
        int sum = 0;
        int totalreadings = sensors * timeslots;
        
        // Count even readings and calculate sum
        for(int j = 0; j < sensors; j++) {
            for(int k = 0; k < timeslots; k++) {
                if(cube[i][j][k] % 2 == 0) {
                    evencount++;
                }
                sum += cube[i][j][k];
            }
        }
        
        double average = (double)sum / totalreadings;
        
        cout << "Machine " << (i+1) << ":" << endl;
        cout << "Even readings: " << evencount << endl;
        cout << "Average: " << average << endl;
        
        // Classification
        bool isStable = (evencount <= 3);
        bool isActive = (average > 4);
        
        cout << "  Classification: ";
        if(isStable && isActive) {
            cout << "Stable & Active" << endl;
        } else if(isStable && !isActive) {
            cout << "Stable but Inactive" << endl;
        } else if(!isStable && isActive) {
            cout << "Active but Unstable" << endl;
        } else {
            cout << "Unstable & Inactive" << endl;
        }
    }
    
    cout << " STRUCTURAL CHECKS" << endl;
    
    bool diagonalSymmetric = true;
    for(int i = 0; i < machines && diagonalSymmetric; i++) {
        for(int j = 0; j < sensors && diagonalSymmetric; j++) {
            for(int k = 0; k < timeslots && diagonalSymmetric; k++) {
                if(j < sensors && k < timeslots) {
                    if(cube[i][j][k] != cube[i][k][j]) {
                        diagonalSymmetric = false;
                    }
                }
            }
        }
    }
    totalChecks++;
    if(diagonalSymmetric) healthpoints++;
    cout << "1. Diagonal Symmetry: " << (diagonalSymmetric ? "YES" : "NO") << endl;
    
    bool allLayersmirrored = true;
    for(int i = 0; i < machines && allLayersmirrored; i++) {
        for(int j = 0; j < sensors && allLayersmirrored; j++) {
            for(int k = 0; k < timeslots/2; k++) {
                if(cube[i][j][k] != cube[i][j][timeslots-1-k]) {
                    allLayersmirrored = false;
                }
            }
        }
    }
    totalChecks++;
    if(allLayersmirrored) healthpoints++;
    cout << "2. All Layers Mirror Symmetric: " << (allLayersmirrored ? "YES" : "NO") << endl;
    
    // Check 3: Top and bottom layers mirror each other
    bool topBottommirror = true;
    if(machines >= 2) {
        for(int j = 0; j < sensors && topBottommirror; j++) {
            for(int k = 0; k < timeslots; k++) {
                if(cube[0][j][k] != cube[machines-1][j][k]) {
                    topBottommirror = false;
                }
            }
        }
    }
    totalChecks++;
    if(topBottommirror) healthpoints++;
    cout << "3. Top-Bottom Layer Mirror: " << (topBottommirror ? "YES" : "NO") << endl;
    
    // Cube Health
    cout << " CUBE HEALTH " << endl;
    cout << "Health Points: " << healthpoints << "/" << totalChecks << endl;
    double healthPercentage = ((double)healthpoints / totalChecks) * 100;
    cout << "Health Percentage: " << healthPercentage << "%" << endl;
    
    cout << "Status: ";
    if(healthPercentage == 100) {
        cout << "Perfectly Balanced" << endl;
    } else if(healthPercentage >= 50) {
        cout << "Mostly Stable" << endl;
    } else {
        cout << "Unstable" << endl;
    }
    
    return 0;
}
