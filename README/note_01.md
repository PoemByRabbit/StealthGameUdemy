# Notes

## Setup Objective UI with UMG, Section 2, Lecture 14

- HUD for FPSCharacter
  - Create new "Widget Blueprint" (WBP_ObjectiveInfo) to display FPSCharacter bIsCarryingObjective
    - In Widget Blueprint "designer" add "Text"
    - With "Text" selected select Content > Text > "Create Binding" and name it "GetObjectiveText".  ![](2018-05-20-192822_1920x2141_scrot.png)
    - In "Graph" edit "GetObjectiveText" ![](2018-05-20-192922_1920x2141_scrot.png)
  - Create new Blueprint class, "BP_HUD", from "FPSHUD"
    - On "Event BeginPlay" add WBP_ObjectiveInfo" to the viewport ![](2018-05-20-193522_1920x2141_scrot.png)

