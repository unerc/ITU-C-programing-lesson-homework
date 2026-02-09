# Hospital Management System (C Language)

A simple console-based Hospital Management System built using C. This program allows users to manage patient records using a file-based storage system.

## Features

* **Add New Patient:** Register new patients with details (Name, Surname, Birthday, Email, Department).
* **Search Patient:** Search records by ID, Name, Surname, or other criteria.
* **Update Record:** Edit existing patient details.
* **Delete Record:** Remove a patient from the system (Soft delete).
* **Show All:** List all active patient records.
* **File Handling:** Automatically saves and loads data from `patient.txt`.

## How to Run

1.  Compile the code using a C compiler (like GCC):
    ```bash
    gcc main.c -o hospital
    ```
2.  Run the executable:
    ```bash
    ./hospital
    ```

## Technical Notes

* **Platform:** This code is optimized for **Windows** (uses `system("cls")` for clearing the screen).
* **Data Storage:** Data is stored in a `patient.txt` file created in the same directory.
* **Input Handling:** Uses standard file I/O operations in C.

## License

This project is open source and available for educational purposes.
