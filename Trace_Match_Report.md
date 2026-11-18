# Trace-Match Report

**Student:** Vishal Daregave
**PRN:** 202501100056
**Subject:** Data Structures
**Project:** Internal Activity 3 – Question 2

## Configuration

- Scenario: Mango Varieties
- Personalization seed: `S = 60`
- Dataset formula: `v[i] = (S + 13*i) % 100`, for `i = 0..19`
- Table size: 29, retained from the existing project; no assignment PDF was
  present in the workspace
- Hash function: `h(key) = key % 29`
- Collision resolution: linear probing, wrapping from index 28 to index 0
- Dataset: `60, 73, 86, 99, 12, 25, 38, 51, 64, 77, 90, 3, 16, 29, 42, 55, 68, 81, 94, 7`

## Independent hand prediction

Starting with 29 empty slots, each key was placed at its remainder modulo 29;
when that slot was occupied, the next slots were checked in order. The
collisions move `12` from 12 to 13, `3` from 3 to 4, `42` from 13 to 14, and
`7` from 7 to 8. This independent trace predicts:

| Index | Expected value | Index | Expected value | Index | Expected value |
|---:|:---|---:|:---|---:|:---|
| 0 | 29 | 10 | 68 | 20 | Empty |
| 1 | Empty | 11 | Empty | 21 | Empty |
| 2 | 60 | 12 | 99 | 22 | 51 |
| 3 | 90 | 13 | 12 | 23 | 81 |
| 4 | 3 | 14 | 42 | 24 | Empty |
| 5 | Empty | 15 | 73 | 25 | 25 |
| 6 | 64 | 16 | 16 | 26 | 55 |
| 7 | 94 | 17 | Empty | 27 | Empty |
| 8 | 7 | 18 | Empty | 28 | 86 |
| 9 | 38 | 19 | 77 |  |  |

Expected counts: 20 inserted keys, 4 collisions, 20 occupied positions, 9 empty
positions, and load factor `20 / 29 = 0.689655...`, displayed to four decimal
places as `0.6897`.

## Actual program output

Captured by compiling and running `IA3_Q2.cpp` with the required C++17 warning
flags. Whitespace in the code block is normalized for readability (the dataset
line's trailing space and the table's tab separators are omitted):

```text
DATA STRUCTURES IA 3 - QUESTION 2
Student: Vishal Daregave
PRN: 202501100056
Scenario: Mango Varieties
Personalization: v[i] = (60 + 13*i) % 100
Hash Function: h(key) = key % 29
Collision Handling: Linear Probing
Table Size: 29

Personalized Dataset:
60 73 86 99 12 25 38 51 64 77 90 3 16 29 42 55 68 81 94 7

========== INSERTION PROCESS ==========
Inserting 60 | Hash index = 2 | Inserted at index 2
Inserting 73 | Hash index = 15 | Inserted at index 15
Inserting 86 | Hash index = 28 | Inserted at index 28
Inserting 99 | Hash index = 12 | Inserted at index 12
Inserting 12 | Hash index = 12 | Collision at index 12 | Inserted at index 13
Inserting 25 | Hash index = 25 | Inserted at index 25
Inserting 38 | Hash index = 9 | Inserted at index 9
Inserting 51 | Hash index = 22 | Inserted at index 22
Inserting 64 | Hash index = 6 | Inserted at index 6
Inserting 77 | Hash index = 19 | Inserted at index 19
Inserting 90 | Hash index = 3 | Inserted at index 3
Inserting 3 | Hash index = 3 | Collision at index 3 | Inserted at index 4
Inserting 16 | Hash index = 16 | Inserted at index 16
Inserting 29 | Hash index = 0 | Inserted at index 0
Inserting 42 | Hash index = 13 | Collision at index 13 | Inserted at index 14
Inserting 55 | Hash index = 26 | Inserted at index 26
Inserting 68 | Hash index = 10 | Inserted at index 10
Inserting 81 | Hash index = 23 | Inserted at index 23
Inserting 94 | Hash index = 7 | Inserted at index 7
Inserting 7 | Hash index = 7 | Collision at index 7 | Inserted at index 8

========== DUPLICATE KEY TEST ==========
Duplicate key 60 ignored.

========== INVALID KEY TEST ==========
Invalid key -10. Negative values are not allowed.

========== INSERTION SUMMARY ==========
Total input values: 20
Successfully inserted: 20
Total collisions: 4
Occupied positions: 20
Empty positions: 9
Load factor: 0.6897

========== FINAL HASH TABLE ==========
Index   Value
0       29
1       Empty
2       60
3       90
4       3
5       Empty
6       64
7       94
8       7
9       38
10      68
11      Empty
12      99
13      12
14      42
15      73
16      16
17      Empty
18      Empty
19      77
20      Empty
21      Empty
22      51
23      81
24      Empty
25      25
26      55
27      Empty
28      86
```

## Match and collision analysis

The actual output matches the hand-predicted value at every index from 0
through 28. All 20 dataset keys were inserted. The four collisions are exactly
the occupied initial slots encountered when inserting `12`, `3`, `42`, and `7`.
The duplicate test and negative-key test are rejected before probing and do not
change the occupied-slot or collision counts.

| Measure | Expected | Actual | Match |
|:---|---:|---:|:---:|
| Input values | 20 | 20 | Yes |
| Successfully inserted | 20 | 20 | Yes |
| Collisions | 4 | 4 | Yes |
| Occupied positions | 20 | 20 | Yes |
| Empty positions | 9 | 9 | Yes |
| Load factor | 0.6897 | 0.6897 | Yes |

There were no mismatches to explain.
