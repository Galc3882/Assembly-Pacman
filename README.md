# Assembly-Pacman

## Introduction
Assembly-Pacman is an assembly language version of the classic Pacman game for the 8086 Intel processor. The game is a complete recreation of the original game, including all the original gameplay and graphics. It is written in pure assembly language, making it one of the smallest and most efficient versions of Pacman ever created. This project is perfect for anyone who wants to learn how to program in assembly language or for anyone who wants to create their own Pacman clone.

## Table of Contents
- [Explanation of Project and Code](#explanation-of-project-and-code)
- [Special Considerations](#special-considerations)
- [Examples](#examples)
- [Requirements and File Architecture](#requirements-and-file-architecture)
- [Instructions](#instructions)
- [Next Steps](#next-steps)

## Explanation of Project and Code
This project is an assembly language recreation of the classic Pacman game. The code is written in pure assembly language and runs on the 8086 Intel processor. The game includes all the original gameplay and graphics from the original game, and is one of the smallest and most efficient versions of Pacman ever created.

The code for this project is split up into several files, including p.asm, dseg.h, drawB.h, drawP.h, and DMG.h. These files contain the code for the game, including the main game loop, the graphics, and the ghost AI.

## Special Considerations
Creating a game in assembly language can be a challenging task, especially for those who are new to programming in assembly. This project requires a good understanding of assembly language and the 8086 Intel processor. Additionally, debugging code in assembly can be more challenging than debugging code in higher-level languages.

## Examples
The game includes all the original gameplay and graphics from the original game, and can be played using the arrow keys on the keyboard.
![image](https://user-images.githubusercontent.com/86870298/124348811-e2e39180-dbf4-11eb-9710-3eca77b96ee1.png)

## Requirements and File Architecture
### File Architecture
```
├── README.md
├── p.asm
├── p.obj
├── p.exe
├── dseg.h
├── drawB.h
├── drawP.h
├── DMG.h
```
The main code for the game is contained in p.asm. The other files contain code for the graphics and AI.

## Instructions
To run the game, simply complie and run p.asm. The game can be played using the arrow keys on the keyboard.

## Next Steps
- [ ] Add new features to the game, such as additional levels or power-ups
- [ ] Optimize the code for improved performance and efficiency
- [ ] Create a version of the game for other processors or platforms
- [ ] Improve ghost AI
