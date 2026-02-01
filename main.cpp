#include <iostream>
#include <string>
using namespace std;

class NutritionForToday {
protected:
    int todaycalories;
    int todayProtein;
    const int target_calories_for_losing_weights = 2200;
    const int target_calories_for_gaining_muscle = 3200;
    const int target_protein_for_losing_weights = 200;
    const int target_proteins_for_gaining_muscle = 250;
    const int target_calories_for_maintain_weights = 2200;
    const int target_protein_for_maintain_weights = 200;
    const int height = 170;

public:
    NutritionForToday(int cal, int pro) : todaycalories(cal), todayProtein(pro) {}

    virtual void checkcalstatus() {
        cout << "today you still need: " << target_calories_for_maintain_weights - todaycalories << " calories" << endl;
    }
    virtual void checkprostatus() {
        cout << "today you still need: " << target_protein_for_maintain_weights - todayProtein << " todaypro" << endl;
    }
}; 

class Cuttinggoal : public NutritionForToday {
public:
    Cuttinggoal(int cal, int pro) : NutritionForToday(cal, pro) {}

    void checkcalstatus() override {
        if ((target_calories_for_losing_weights - todaycalories) > 0) {
            cout << "you still need " << target_calories_for_losing_weights - todaycalories << " to achieve the goal." << endl;
        } else if ((target_calories_for_losing_weights - todaycalories) == 0) {
            cout << "you did a perfect job today!! Keep the determination." << endl;
        } else {
           cout << "your calories already exceeded about " << todaycalories - target_calories_for_losing_weights << ", Please stop consuming or if you want to be a fatass." << endl;
        } 
    } 

    void checkprostatus() override {
        if ((target_protein_for_losing_weights - todayProtein) > 0) {
            cout << "you still need " << target_protein_for_losing_weights - todayProtein << " to achieve the goal." << endl;
        } else if ((target_protein_for_losing_weights - todayProtein) == 0) {
            cout << "you did a perfect job today!! Keep the determination." << endl;
        } else {
            cout << "your protein already exceeded about " << todayProtein - target_protein_for_losing_weights << ", Please stop consuming or if you dont want to have a kidney dieases." << endl;
        }
    }
}; 

int main() {
    int eatCal, eatPro;
    cout << "Please input the calories of today: ";
    cin >> eatCal;
    cout << "Please input the protein of today: ";
    cin >> eatPro;

    Cuttinggoal today(eatCal, eatPro);
    today.checkcalstatus();
    today.checkprostatus();

    return 0; 
}




