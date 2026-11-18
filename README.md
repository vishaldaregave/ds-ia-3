# Data Structures Internal Activity 3 – Question 2

## Student details

- **Name:** Vishal Daregave
- **PRN:** 202501100056
- **Subject:** Data Structures
- **Project:** Build-in-the-Open Lab Project – Hash Table with Recorded Development Log
- **Language:** C++

## Project description

This menu-free program inserts the personalized Mango Varieties dataset into a
hash table. It uses the division method and linear probing, reports every
collision during insertion, rejects duplicate and negative keys, and displays
the final table and insertion statistics.

## Personalization and configuration

- Last four PRN digits, `S`: 60
- Scenario: Mango Varieties
- Dataset formula: `v[i] = (S + 13*i) % 100`, for `i = 0..19`
- Table size: 29, retained from the existing project (no assignment PDF was
  present in the workspace)
- Hash function: `h(key) = key % 29`
- Collision resolution: Linear probing

The dataset is:

```text
60, 73, 86, 99, 12, 25, 38, 51, 64, 77,
90, 3, 16, 29, 42, 55, 68, 81, 94, 7
```

## Features

- Inserts all 20 dataset values and shows each initial hash index, collision,
  and final insertion position.
- Counts each occupied slot encountered during probing as one collision.
- Rejects a duplicate key and a negative key without changing the table.
- Displays all 29 indexes, occupied values, and empty positions.
- Reports the input and successful insertion counts, collisions, occupied and
  empty positions, and load factor.

## Compile and run

From the project directory, compile with a C++17 compiler:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic IA3_Q2.cpp -o IA3_Q2
```

On Windows, run:

```powershell
.\IA3_Q2.exe
```

The program is deterministic and requires no interactive input.

## Output image

The captured output for the personalized dataset is available at
[screenshots/program_output.png](screenshots/program_output.png).
