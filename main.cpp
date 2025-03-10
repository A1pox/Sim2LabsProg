#include <iostream>
#include <iomanip>
using namespace std;
struct School {
    int number;
    int graduates;
    int admitted;
};
int main(){
    int n;
    cout << "Enter number of schools: ";
    cin >> n;
    School* schools = new School[n];
    for(int i = 0; i < n; i++){
        cout << "Enter school number, number of graduates and number admitted: ";
        cin >> schools[i].number >> schools[i].graduates >> schools[i].admitted;
    }
    int* indices = new int[n];
    for(int i = 0; i < n; i++){
        indices[i] = i;
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            double perc_i = static_cast<double>(schools[indices[i]].admitted) / schools[indices[i]].graduates;
            double perc_j = static_cast<double>(schools[indices[j]].admitted) / schools[indices[j]].graduates;
            if(perc_i > perc_j){
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }
    cout << "\nSchool\tGraduates\tPercentage admitted\n";
    for(int i = 0; i < n; i++){
        int idx = indices[i];
        double percentage = static_cast<double>(schools[idx].admitted) / schools[idx].graduates * 100;
        cout << schools[idx].number << "\t" << schools[idx].graduates << "\t\t"
             << fixed << setprecision(2) << percentage << "%" << "\n";
    }
    delete[] schools;
    delete[] indices;
    return 0;
}
