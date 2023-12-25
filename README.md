# CSGO_Prop_Project

Trying to learn Arduino (and maybe microcontrollers) by making a CSGO Bomb Prop and Defuse Kit Prop

> [!IMPORTANT]
> 
> **THIS IS NOT A REAL BOMB**
> 
> Just covering my butt. These are props from the games CSGO / CS2.

> [!NOTE]
> 
> This is a personal project for me to learn new things.
> As a result, I am trying to avoid repositories and other completed projects like these like the plague.
> 
> While it is great to learn from others, I want to undergo the problem solving and engineering process on my own.

## Project Goals

- [ ] Create a working prop bomb.
  - [X] Display to an LCD.
  - [X] Take input from a Numerical Keypad.
  - [X] Output basic audio cues.
  - [ ] Take an input signal that interrupts the countdown (Bomb Defusal Kit Input)
    - [ ] Signal should be required to be continuous otherwise defusal timer resets.
  - [ ] Mimic the game.
    - [ ] Timer beeps should match the frequency of the bomb timings.
    - [ ] Speaker should also output the final "bomb charged" sounds.
    - [ ] Speaker should output an explosion sound (may require reading `.wav` files).
- [ ] Create a working prop bomb defusal kit.
  - [ ] Trigger pushes a signal to output.
    - [ ] 2 Triggers: Normal (Without Kit), Fast (With Kit).
  - [ ] Signal interrupts prop bomb.
  - [ ] Output basic audio cues.
  - [ ] Mimic the game
    - [ ] On defuse, play sound cue.
    - [ ] On release, play sound cue.

### Need To Look Into

- [ ] Programming a Microcontroller
- [ ] Basic Circuits
- [ ] Designing and Printing a 3D Model

## Project Dependencies

[Keypad by Mark Stanley and Alexander Brevig](https://www.arduino.cc/reference/en/libraries/keypad/) (v3.1.1)

[Liquid Crystal I2C by Frank de Brabander](https://reference.arduino.cc/reference/en/libraries/liquidcrystal-i2c/) (v1.1.2)

