# Chessboard Construction and Detection System

## 1. Chessboard Construction: Mechanical Layer

### 🎯 Goal:
Build a chessboard surface where each square detects pressure reliably.

### 🧩 Board Stack (Layer by Layer)

<img src="DIAGRAM_1A.png" alt="dig1">


> 📝 **Notes:**
> - The pressure sensor layer is the core.
> - Use **force-sensitive resistors (FSR)** or **DIY conductive foam/rubber**.
> - Under every square, there's a sensor connected to a specific row and column.

---

## 2. Electrical Design: Matrix Configuration

### 🧩 Concept:
Just like a keyboard — matrix scanning.

- **Rows (R1-R8):** Horizontal wires (top layer).
- **Columns (C1-C8):** Vertical wires (bottom layer).

For an **8×8 chessboard**:
- Total: **8 rows + 8 columns = 16 pins.**

### ⚙️ Circuit Operation:
- Microcontroller activates one row at a time (sends voltage).
- Reads values from all columns:
  - **Pressure present:** Resistance drops → current flows.
  - **No pressure:** High resistance (or open circuit).

### 🧩 Wiring Diagram (Simplified):




---

## 3. Sensor Operation: How Does It Detect Piece Movement?

### 🧐 What does the microcontroller "see"?

| State             | Sensor Reading            |
|------------------|---------------------------|
| No piece         | High resistance (>10 MΩ)  |
| Piece present    | Lower resistance (~1-5 kΩ)|

### 🧩 Action Flow:
1. At startup, the controller records a **baseline** state.
2. During play:
   - **Square pressed → released:** Piece lifted (origin square).
   - **Square released → pressed:** Piece placed (destination square).

### ⏱️ Timing:
- Scan all squares every few milliseconds.
- With debounce: wait ~50ms to confirm genuine signal.

---

## 4. Software Logic (Microcontroller)

### 🧩 Initialization:
- Initialize row/column pins.
- Perform baseline scan and store initial state.

### 🔄 Scanning Loop (Pseudo-code):

```c
for (each row R) {
    activateRow(R);
    for (each column C) {
        int value = analogRead(C);
        if (value < threshold) {
            mark square (R, C) as "pressed";
        } else {
            mark square (R, C) as "released";
        }
    }
}

compare current state to previous state:
    if (square changed from pressed -> released):
        origin_square = this square;
    if (square changed from released -> pressed):
        destination_square = this square;

if (origin_square && destination_square) {
    sendMoveToComputer(origin_square, destination_square);
}

 Move: E2 to E4 
```
----------------

## 5. Handling Edge Cases

| **Scenario**                                   | **Solution**                                     
|------------------------------------------------|--------------
| Player lifts piece, holds it in the air        | Wait until    both origin and destination are detected.        |
| Board gets bumped (false signal)               | Use debounce timing and multiple scan confirmations.          |
| Multiple pieces moved at once (illegal move)   | Detect >2 changes, alert user (illegal move).              |
| Piece weight variations                        | Calibrate threshold or standardize piece weights.          |

---

## 6. Visual Diagrams

### 🧩 Chessboard Top View:

<!-- dig2 -->

### 🧩 Chessboard Layer Side View:

<!-- dig3 -->


---

## 7. Final Output Example

If the player moves from **E2 to E4**, the system detects:

- **E2:** Changes from "pressed" to "released" (origin square).
- **E4:** Changes from "released" to "pressed" (destination square).

Microcontroller sends:


Computer software updates:
- GUI board position.
- Chess engine (e.g., Stockfish) processes next move.

---

# ✅ End of Part A
