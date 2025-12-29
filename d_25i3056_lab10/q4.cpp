#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	 cout << "Name: Your Name" << endl;
	cout << "Roll No: 25i-3056" << endl;

    	cout << "Task 04: 3D Game Scoreboard\n" << endl;
    
	 int p, r, l;
    cout << "Enter number of Players: ";
    cin >> p;
    cout << "Enter number of Rounds: ";
    cin >> r;
    cout << "Enter number of Levels per round: ";
    cin >> l;
    
    int score[10][10][10]; 
    
    srand(time(0));
    
    // Auto-generate scores
    cout << " GENERATING SCORES" << endl;
    for(int i = 0; i < p; i++) {
        for(int j = 0; j < r; j++) {
            for(int k = 0; k < l; k++) {
                score[i][j][k] = rand() % 101; // 0 to 100
            }
        }
    }
    
    cout << " FULL SCOREBOARD " << endl;
    for(int i = 0; i < p; i++) {
        cout << "\nPlayer " << (i+1) << ":" << endl;
        cout << "Round\t";
        for(int j = 0; j < l; j++) {
            cout << "L" << (j+1) << "\t";
        }
        cout << endl;
        
        for(int k = 0; k < r; k++) {
            cout << "R" << (k+1) << "\t";
            for(int j = 0; j < l; j++) { 
                cout << score[i][k][j] << "\t";
            }
            cout << endl;
        }
    }
    
    cout << " PLAYER STATISTICS " << endl;
    int bestplayerindex = 0;
    int bestplayertotal = 0;
    
    for(int i = 0; i < p; i++) {
        int total = 0;
        int bestscore = 0;
        int bestround = 0;
        int bestlevel = 0;
        
        for(int j = 0; j < r; j++) {
            for(int k = 0; k < l; k++) {
                total += score[i][j][k];
                
                if(score[i][j][k] > bestscore) {
                    bestscore = score[i][j][k];
                    bestround = j; 
                    bestlevel = k;
                }
            }
        }
        
        double average = (double)total / (r * l);
        
        cout << "\nPlayer " << (i+1) << ":" << endl; 
        cout << "  Total Score: " << total << endl;
        cout << "  Average Score: " << average << endl;
        cout << "  Best Level: Round " << (bestround+1) << ", Level " << (bestlevel+1);
        cout << " (Score: " << bestscore << ")" << endl;
        
        // Track best player overall
        if(total > bestplayertotal) {
            bestplayertotal = total;
            bestplayerindex = i; 
        }
    }
    
    cout << "\n=== OVERALL BEST PLAYER ===" << endl;
    cout << "Player " << (bestplayerindex+1) << " performed best overall!" << endl;
    cout << "Total Score: " << bestplayertotal << endl;
    
    return 0;
}
