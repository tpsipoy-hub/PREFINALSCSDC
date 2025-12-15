#include <iostream>
#include <string>
using namespace std;

// Global variables
bool isMerciful = false;
int Blazer_Impression_Score = 0;
bool isRomanticTensionActive = false;
int Tactical_Efficiency = 0;
bool gameOver = false;

// Utility functions
void divider() {
    cout << "\n-----------------------------\n";
}

int get_choice(string prompt, string option1, string option2) {
    int choice;
    cout << prompt << "\n";
    cout << "1. " << option1 << "\n";
    cout << "2. " << option2 << "\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;
    return choice;
}

// Scene 1: Apartment Interrogation
void scene_interrogation() {
    divider();
    cout << "Scene 1: Apartment Interrogation\n";
    int c = get_choice("Robert must decide:", "Pull him back", "Let him drop");

    switch (c) {
        case 1: // Merciful path
            isMerciful = true;
            cout << "Robert shows mercy.\n";
            // Nested choice inside merciful path
            {
                int sub = get_choice("Do you reassure him?", "Yes", "No");
                switch (sub) {
                    case 1: cout << "Robert reassures the suspect.\n"; break;
                    case 2: cout << "Robert stays silent.\n"; break;
                }
            }
            break;
        case 2: // Ruthless path
            isMerciful = false;
            cout << "Robert lets him drop.\n";
            // Nested choice inside ruthless path
            {
                int sub = get_choice("Do you report the incident?", "Yes", "No");
                switch (sub) {
                    case 1: cout << "Robert files a cold report.\n"; break;
                    case 2: cout << "Robert hides the truth.\n"; break;
                }
            }
            break;
        default:
            cout << "Invalid choice. Defaulting to ruthless.\n";
            isMerciful = false;
    }
}

// Scene 2: Street Fight
void scene_street_fight() {
    divider();
    cout << "Scene 2: Street Fight\n";
    int c = get_choice("Robert must act:", "Right hand punch", "Left hand punch");

    switch (c) {
        case 1:
            cout << "Robert is countered and struck. Game over.\n";
            gameOver = true;
            break;
        case 2:
            cout << "Robert knocks out the attacker.\n";
            Tactical_Efficiency += 2;
            // Nested choice: follow up action
            {
                int sub = get_choice("Do you chase the fleeing accomplice?", "Yes", "No");
                switch (sub) {
                    case 1: cout << "Robert gives chase, increasing efficiency.\n"; Tactical_Efficiency += 1; break;
                    case 2: cout << "Robert stays put, conserving energy.\n"; break;
                }
            }
            break;
        default:
            cout << "Invalid choice. Robert hesitates and is defeated.\n";
            gameOver = true;
    }
}

// Scene 3: Superhero Bar Scene
void scene_bar_flambae() {
    divider();
    cout << "Scene 3: Superhero Bar Scene\n";
    int c = get_choice("Robert must choose:", "Throw water", "Throw alcohol");

    switch (c) {
        case 1:
            cout << "Flames extinguished. Blonde Blazer nods.\n";
            Blazer_Impression_Score += 1;
            break;
        case 2:
            cout << "Flambae explodes in fire. Blonde Blazer is impressed.\n";
            Blazer_Impression_Score += 3;
            // Nested choice: aftermath
            {
                int sub = get_choice("Do you boast about it?", "Yes", "No");
                switch (sub) {
                    case 1: cout << "Robert boasts, increasing impression.\n"; Blazer_Impression_Score += 1; break;
                    case 2: cout << "Robert stays humble.\n"; break;
                }
            }
            break;
        default:
            cout << "Invalid choice. Robert hesitates.\n";
    }
}

// Scene 4: Billboard Romance
void scene_billboard() {
    divider();
    cout << "Scene 4: Billboard Romance\n";
    int c = get_choice("Robert must decide:", "Choose to kiss", "Let the moment pass");
    isRomanticTensionActive = true;

    switch (c) {
        case 1:
            cout << "They kiss. The city fades behind them.\n";
            Blazer_Impression_Score += 2;
            break;
        case 2:
            cout << "The moment passes. Tension remains.\n";
            Blazer_Impression_Score += 1;
            // Nested choice: follow-up
            {
                int sub = get_choice("Do you confess feelings later?", "Yes", "No");
                switch (sub) {
                    case 1: cout << "Robert confesses later.\n"; break;
                    case 2: cout << "Robert keeps silent.\n"; break;
                }
            }
            break;
        default:
            cout << "Invalid choice. The moment slips away.\n";
    }
}

// Scene 5: Combat vs Toxic
void scene_combat_toxic() {
    divider();
    cout << "Scene 5: Combat vs Toxic\n";
    cout << "Toxic: \"This is a limited time offer dud.\"\n";
    int c = get_choice("Choose your response:", "[IGNORE HIM]", "Bullshit.");

    switch (c) {
        case 1:
            cout << "Robert ignores the bluff. Tactical restraint.\n";
            Tactical_Efficiency += (isMerciful ? 2 : 1);
            break;
        case 2:
            cout << "Robert calls the bluff. Toxic is stomped.\n";
            Tactical_Efficiency += (isMerciful ? 1 : 2);
            // Nested choice: aftermath
            {
                int sub = get_choice("Do you spare Toxic?", "Yes", "No");
                switch (sub) {
                    case 1: cout << "Robert spares Toxic.\n"; isMerciful = true; break;
                    case 2: cout << "Robert finishes Toxic.\n"; isMerciful = false; break;
                }
            }
            break;
        default:
            cout << "Invalid choice. Toxic overwhelms Robert.\n";
            gameOver = true;
    }
}

// Epilogue Summary
void epilogue_summary() {
    divider();
    cout << "Epilogue Summary\n";

    if (isMerciful) {
        cout << "Robert is remembered for compassionate leadership.\n";
    } else {
        cout << "Robert is remembered for pragmatic efficiency.\n";
    }

    if (Blazer_Impression_Score >= 4) {
        cout << "Blonde Blazer recalls Robert’s spectacle.\n";
    } else {
        cout << "Blonde Blazer recalls Robert’s restraint.\n";
    }

    if (isRomanticTensionActive) {
        cout << "Romantic tension lingers between them.\n";
    }

    cout << "Final Tactical Efficiency: " << Tactical_Efficiency << "\n";
}

// Main function
int main() {
    scene_interrogation();
    scene_street_fight();
    if (gameOver) return 0;
    scene_bar_flambae();
    scene_billboard();
    scene_combat_toxic();
    if (!gameOver) epilogue_summary();
    return 0;
}
