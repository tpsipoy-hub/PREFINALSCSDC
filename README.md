# DISPATCH DECISION ENGINE DOCUMENTATION

## Introduction
The Dispatch Decision Engine is a C++ program that adapts Episode 1 of *Dispatch* into a text-based visual novel.  
The program follows Robert Robertson as he transitions from frontline superhero to dispatcher.  
The narrative is divided into five decision points, each implemented as a separate function.  
User input determines the flow of the story, updates global variables, and influences the customized epilogue.

---

## Global Variables
```cpp
bool isMerciful = false;              // Tracks Robert's moral path
int Blazer_Impression_Score = 0;      // Blonde Blazer’s perception of Robert
bool isRomanticTensionActive = false; // Romance route flag
int Tactical_Efficiency = 0;          // Tracks tactical success
bool gameOver = false;                // Ends story if Robert fails

Functions and Decision Paths
Scene 1 — Apartment Interrogation
void scene_interrogation() {
    int c = get_choice("Robert must decide:",
                       "Pull him back",
                       "Let him drop");
    if (c == 1) {
        isMerciful = true;
    } else {
        isMerciful = false;
    }
}
Explanation: This scene sets Robert’s moral compass. Choosing to pull him back activates the Merciful Track, while letting him drop activates the Ruthless Track. The Boolean isMerciful acts as a signal that will influence later tactical and epilogue outcomes.

Scene 2 — Street Fight
void scene_street_fight() {
    int c = get_choice("Robert must act:",
                       "Right hand punch",
                       "Left hand punch");
    if (c == 1) {
        gameOver = true;
    } else {
        Tactical_Efficiency += 2;
    }
}

Explanation: This scene tests Robert’s combat instincts. A right-hand punch leads to failure (gameOver = true), ending the story prematurely. A left-hand punch increases Tactical_Efficiency, signaling Robert’s competence in combat.

Scene 3 — Superhero Bar Scene
void scene_bar_flambae() {
    int c = get_choice("Robert must choose:",
                       "Throw water",
                       "Throw alcohol");
    if (c == 1) {
        Blazer_Impression_Score += 1;
    } else {
        Blazer_Impression_Score += 3;
    }
}


Explanation: This scene influences Blonde Blazer’s perception. Throwing water is practical but unimpressive, while throwing alcohol creates a chaotic spectacle that earns a stronger impression.

Scene 4 — Billboard Romance
void scene_billboard() {
    int c = get_choice("Robert must decide:",
                       "Choose to kiss",
                       "Let the moment pass");
    if (c == 1) {
        isRomanticTensionActive = true;
        Blazer_Impression_Score += 2;
    } else {
        isRomanticTensionActive = true;
        Blazer_Impression_Score += 1;
    }
}

Explanation: This scene sets the Romance Track. Regardless of choice, isRomanticTensionActive is set to true. Choosing to kiss strengthens the impression score, while letting the moment pass keeps tension unresolved but active.

Scene 5 — Combat vs Toxic
void scene_combat_toxic() {
    int c = get_choice("Robert must choose:",
                       "Punt",
                       "Stomp");
    if (c == 1) {
        Tactical_Efficiency += (isMerciful ? 2 : 1);
    } else {
        Tactical_Efficiency += (isMerciful ? 1 : 2);
    }
}
Explanation: This scene combines tactical and moral signals. Choosing Punt is flashy and creative, rewarding efficiency more if Robert is merciful. Choosing Stomp is brutal, rewarding efficiency more if Robert is ruthless. Earlier signals (isMerciful) influence later outcomes.

Epilogue — Summary
void epilogue_summary() {
    if (isMerciful) {
        cout << "Robert is remembered for compassionate leadership.";
    } else {
        cout << "Robert is remembered for pragmatic efficiency.";
    }
}
Explanation: The epilogue integrates all signals (isMerciful, Blazer_Impression_Score, isRomanticTensionActive, Tactical_Efficiency) to produce a customized ending. Just like a railway system, the final station reflects every switch thrown and every signal set along the journey.
