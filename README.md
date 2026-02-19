# File_Based Database

[![C++](https://img.shields.io/badge/C++17-blue?logo=c%2B%2B)](https://isocpp.org/) 
[![Build](https://img.shields.io/badge/build-passing-brightgreen)]()
[![License](https://img.shields.io/badge/license-MIT-green)]()

- [Overview](#overview)  
- [Features](#features)  
- [Concepts Used](#Concepts-Used)  
- [Project structure](#Project-structure)
- [Running Instructions](#Running-Instructions)
- [Data Format Example](#Data-Format-Example)
- [Ideas Learned](#Ideas-Learned)      
- [Author](#Author)
- [License](#license) 

## Overview
This project is a c++ file based database. It allows the user to store, retrieve, update, and delete records.

Data is stored in a text file and loaded to memory to allow changes inbetween program executions.

## Features
- Load data from file at startup
- Save data to file on exit
- Add new records
- Search records by ID
- Update existing records
- Delete records
- Display all stored data
- Clean object oriented design

## Concepts Used

### C++ OOP

- Classes 
- Encapsulation
- Constructors & methods

### STL

- vector for dynamic storage

### File Handling

- ifstream / ofstream
- Persistent data storage

### Program Design

- Separation of concerns
- Modular file structure
- Menu driven interface

## Project Structure

```bash
FileDatabase/
│
├── product.h 
├── product.cpp   
├── Database.h   
├── Database.cpp  
├── main.cpp  
└── products.txt  

```

## Running Instructions
```bash
make
./database
```

## Data Format Example

```bash
1,Keyboard,49.99,10
2,Mouse,19.99,25
```

## Ideas Learned
- How real applications persist data beyond runtime
- Designing systems using object oriented principles
- Managing dynamic collections using STL vectors
- Structuring programs into modular, maintainable components

## Author

Shukayb Yezdani

## License

- This project is licensed under the MIT License — free to use, modify, and share.