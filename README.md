# Maze Downloader

## Description
For one of the last labs of the semester as I was TAing, I wanted to make a fun lab that used some things that the students hadn't used or seen before. I also wanted to show them and give them code for something that they might first guess is hard. So, I gave them code to enter a form on a website and download a webpage. I set it up to target a website that generates random text art mazes. The students would use the code to download a maze, and then they had to create a character class, and walk the character through the maze.

## Controls
- w,a,s,d, followed by 'Enter' to move the character. Very basic movement so the students didnt have to spend much time on it

## Compiling
```sh
g++ main2.cpp character.cpp maze.cpp mazeDownloader.cpp
```
