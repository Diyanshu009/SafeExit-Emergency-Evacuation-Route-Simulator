# 🧯 SafeExit – Emergency Evacuation Route Simulator

---

## 📘 Project Overview

**SafeExit** is a text-based evacuation assistant system built in C. The user inputs a room number and receives the safest exit route based on data from a file. It demonstrates fundamental concepts of C programming, file handling, and user interaction.

---

## 🎯 Objectives
- Simulate emergency evacuation logic using basic C programming.
- Enable command-line user interaction with file-based routing.
- Practice searching, string parsing, and handling special commands (`HELP`, `QUIT`).

---

## 🚀 Features
- 📄 **File Reading**: Loads routing data from `routes.txt`.
- 🔍 **Search Functionality**: Finds and displays correct routes for input room.
- 🔡 **Case-Insensitive Commands**: Commands like `help`, `HELP` work identically.
- 👤 **CLI Interface**: Lightweight and responsive user interaction.

---

## ⚙️ Technologies Used
- C Programming Language
- Standard C File I/O (`fopen`, `fgets`)
- String Parsing (`strcmp`, `strtok`, `strcasecmp`)
- Command Line Input/Output (`scanf`, `printf`)

---

## 🧪 System Testing & Contributions
- **Ayush**: Documentation, usability testing
- **Anil**: Core logic, file reading, debugging
- **Diyanshu**: HELP/QUIT feature, routes.txt structure
- **Vedant**: Compatibility testing, formatting

---

## 📈 Future Work
- Integrate GUI for better accessibility
- Add route validation and error correction
- Implement graph-based logic for realistic mapping
- Connect to real-time sensor inputs for smart alerts

---

## 🗂 Sample `routes.txt` Format
```
ROOM101 -> EXIT A
ROOM102 -> EXIT B
ROOM103 -> EXIT A
...
```

---

## 🏁 How to Run
### 🛠 Compile
```bash
gcc safe_exit.c -o safe_exit
```

### ▶️ Execute
```bash
./safe_exit routes.txt
```

---

## 📌 Commands
- Type a **room number** (e.g., `ROOM101`) to get an escape route.
- Type `HELP` to display all room-exit mappings.
- Type `QUIT` to terminate the program.

---

## 📝 License
This project is for educational purposes as part of CSE 1320 coursework at UT Arlington.
