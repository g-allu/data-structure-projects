#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream file("drivers.txt");
    if (!file.is_open()) {
        cout << "Failed to open drivers.txt\n";
        return 1;
    }
    
    for (int i = 1; i <= 100; i++) {
        string id = "DRV" + to_string(1000 + i);
        string name = "Driver_" + to_string(i);
        string dob = "1/1/1980";
        string street = "Street_" + to_string(i);
        string city = "CityA";
        string county = "CountyX";
        int work = i % 5;
        int exp = i % 25;
        int med = i % 4;
        string lic = "1/1/2000";
        int tick = (i % 3 == 0) ? 1 : 0;
        string loc = (tick == 1) ? "Hwy1" : "None";
        
        file << id << "," << name << "," << dob << "," 
             << street << "," << city << "," << county << "," 
             << work << "," << exp << "," << med << "," 
             << lic << "," << tick << "," << loc << "\n";
    }
    file.close();
    cout << "Generated drivers.txt with 100 entries.\n";
    return 0;
}
