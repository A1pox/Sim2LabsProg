#include <iostream>
#include <string>
using namespace std;
struct Room {
    int roomNumber;
    double area;
    string faculty;
    int residents;
};
int main(){
    int n;
    cout << "Enter number of rooms: ";
    cin >> n;
    Room* rooms = new Room[n];
    for(int i = 0; i < n; i++){
        cout << "Enter room number, area, faculty, and number of residents for room " << i + 1 << ": ";
        cin >> rooms[i].roomNumber >> rooms[i].area >> rooms[i].faculty >> rooms[i].residents;
    }
    int facultyCount = 0;
    string* faculties = new string[n];
    for(int i = 0; i < n; i++){
        bool exists = false;
        for(int j = 0; j < facultyCount; j++){
            if(rooms[i].faculty == faculties[j]){
                exists = true;
                break;
            }
        }
        if(!exists){
            faculties[facultyCount++] = rooms[i].faculty;
        }
    }
    cout << "\nFaculty Summary:\n";
    cout << "Faculty\tRooms\tStudents\tAvg area per student\n";
    for(int i = 0; i < facultyCount; i++){
        int roomCount = 0;
        int totalStudents = 0;
        double totalArea = 0;
        for(int j = 0; j < n; j++){
            if(rooms[j].faculty == faculties[i]){
                roomCount++;
                totalStudents += rooms[j].residents;
                totalArea += rooms[j].area;
            }
        }
        double avgArea = (totalStudents > 0) ? totalArea / totalStudents : 0;
        cout << faculties[i] << "\t" << roomCount << "\t" << totalStudents << "\t\t" << avgArea << "\n";
    }
    delete[] rooms;
    delete[] faculties;
    return 0;
}
