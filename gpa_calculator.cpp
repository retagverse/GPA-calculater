#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


double gradeToGPA(string grade) {
    if (grade == "A+") return 4.0;
    if (grade == "A")  return 3.8;
    if (grade == "A-") return 3.6;
    if (grade == "B+") return 3.4;
    if (grade == "B")  return 3.2;
    if (grade == "B-") return 3.0;
    if (grade == "C+") return 2.8;
    if (grade == "C")  return 2.6;
    if (grade == "C-") return 2.4;
    if (grade == "D+") return 2.2;
    if (grade == "D")  return 2.0;
    if (grade == "F")  return 0.0;
    return -1; // Invalid grade sentinel
}

int main() {
    int numSubjects;

    cout << "=============================\n";
    cout << "       GPA CALCULATOR        \n";
    cout << "=============================\n\n";

    cout << "How many subjects do you have? ";
    cin >> numSubjects;

    if (numSubjects <= 0) {
        cout << "Number of subjects must be greater than 0.\n";
        return 1;
    }

    double totalPoints = 0.0;
    int validCount    = 0;

    for (int i = 1; i <= numSubjects; i++) {
        string grade;
        double points = -1;

        
        while (points == -1) {
            cout << "Subject " << i << " - Enter grade (e.g. A, B+, C-): ";
            cin >> grade;

            // Convert input to uppercase for consistency
            for (char& c : grade) c = toupper(c);

            points = gradeToGPA(grade);

            if (points == -1)
                cout << "  Invalid grade. Please use A+, A, A-, B+, B, B-, C+, C, C-, D+, D, or F.\n";
        }

        cout << "  -> " << grade << " = " << points << " points\n";
        totalPoints += points;
        validCount++;
    }

    
    double gpa = totalPoints / validCount;

    
    cout << "\n=============================\n";
    cout << fixed << setprecision(2);
    cout << "  Your GPA: " << gpa << "\n";

    
    if (gpa >= 3.5)
        cout << "  Performance: Excellent! Keep it up!\n";
    else if (gpa >= 2.5)
        cout << "  Performance: Good. You can do even better!\n";
    else
        cout << "  Performance: Needs Improvement. Don't give up!\n";

    cout << "=============================\n";

    return 0;
}
