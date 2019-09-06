# Hacking the Make Time Clock

## What is the Make Time Clock? 

The [Make Time Clock](https://www.maketimeclock.com/) (MTC) was a project that launched on [kickstarter](https://www.kickstarter.com/projects/chapambrose/make-time-clock-get-serious-about-side-projects/description) on November 2, 2015.

It was a project designed to help people track how often they worked on a thing and for how long. The original project included a single hardware device and a free app that needed to pair with the device. 
## Purpose of this project

The MTC was a really simple idea that had a lot of moving parts - parts that fell into disrepair as the original team moved on to other things. As it happens, an MTC unit fell into my lap and I decided to resurrect some simple version of it again. This project serves as a way for other tinkers to breathe life back into their wooden cubes and even perhaps repurpose it for something else.

## How this version of the MTC works at the moment

The cube is now stand alone and acts as a very simple tracker. Press it once to illuminate a light. Twice will illuminate two lights, and so on. Once you have 6 presses in during a session ( which lasts indefinitely ) the 7th press will execute a short lived colorful celebration. Congradulations! You've done the thing 7 times in a week!

## Roadmap

- [ ] Add a notion of time so only one press can be made per day, making the celebration only occur if the user has done the thing every day of the previous week
- [ ] Push the daily updates to something ( maybe a simple flask server, maybe a lamda, maybe firebase ) that caches them and generates csvs available for download
- [ ] Push the generated csvs to a secure location like google drive

