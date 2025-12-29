#include <iostream>
using namespace std;

int main() {
    cout << "Name: M.Areeb" << endl;
    cout << "Roll No: 25i-3056" << endl;
    cout << "Task 02: Cinema Seat Booking System\n" << endl;
    
    int seats[5][5] = {0}; 
    int totalSeats = 25;
    int bookedSeats = 0;
    int availableSeats = 25;
    
    while(availableSeats > 0) {
        cout << "\nCurrent Seat Map (0 = Available, 1 = Booked):" << endl;
        cout << "   ";
        for(int j = 0; j < 5; j++) {
            cout << "C" << j+1 << " ";
        }
        cout << endl;
        
        for(int i = 0; i < 5; i++) {
            cout << "R" << i+1 << " ";
            for(int j = 0; j < 5; j++) {
                cout << " " << seats[i][j] << " ";
            }
            cout << endl;
        }
        
        int row, col;
        cout << "\nEnter seat position to book:" << endl;
        cout << "Row (0-4): ";
        cin >> row;
        cout << "Column (0-4): ";
        cin >> col;
        
        if(row < 0 || row >= 5 || col < 0 || col >= 5) {
            cout << "Invalid seat position! Please choose valid row and column." << endl;
            continue;
        }
        
        if(seats[row-1][col-1] == 0) {
            seats[row-1][col-1] = 1;
            bookedSeats++;
            availableSeats--;
            cout << "Seat booked successfully!" << endl;
        } else {
            cout << "Seat already booked. Choose another seat." << endl;
        }
    }
    
    // Display final seating chart
    cout << "\n=== FINAL SEATING CHART ===" << endl;
    cout << "   ";
    for(int j = 0; j < 5; j++) {
        cout << "C" << j << " ";
    }
    cout << endl;
    
    for(int i = 0; i < 5; i++) {
        cout << "R" << i << " ";
        for(int j = 0; j < 5; j++) {
            cout << " " << seats[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nTotal Seats: " << totalSeats << endl;
    cout << "Booked Seats: " << bookedSeats << endl;
    cout << "Available Seats: " << availableSeats << endl;
    cout << "\n*** FULLY BOOKED! ***" << endl;
    
    return 0;
}