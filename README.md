# Guessing Game (C-based)

A classic number guessing game written in C. The computer generates a random number within a user-defined range, and the player's goal is to guess it in as few attempts as possible.

## Features
- **Dynamic Range:** Choose your own lower and upper boundaries.
- **Robust Input Handling:** Prevents crashes or infinite loops when entering non-numeric characters (e.g., "ghost", "a").
- **Modular Architecture:** Core utility functions are separated into a dedicated module (`mod/tools.h`).
- **Cross-Platform Build:** Includes a Makefile supporting both Windows (MinGW) and Linux/WSL.
- **Timestamped Logs:** Each guess is displayed with a real-time timestamp.

## Prerequisites
- A C compiler (e.g., `gcc`)
- `make` (for automated builds)

## Getting Started

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/Michael2211967/guessing-spiel.git](https://github.com/Michael2211967/guessing-spiel.git)
   cd guessing-spiel 
