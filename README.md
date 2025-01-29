# Quiz System

This project is an **object-oriented C++ quiz system** designed for creating, managing, and playing quizzes. It demonstrates essential object-oriented programming (OOP) principles such as inheritance, polymorphism, and encapsulation, making it a great learning resource for OOP concepts.

## Features

- **Dynamic Quiz Creation**:
  - Supports Yes/No Questions.
  - Includes Direct Answer Questions.
  - Offers Multiple Choice Questions.
- **Player and Leaderboard Management**:
  - Tracks player scores and ranks in real-time.
- **File Handling**:
  - Save and load quizzes, player scores, and leaderboards.
- **Object-Oriented Design**:
  - Implements OOP principles for modular and maintainable code.

## Prerequisites

To run this project, you need:

1. **Visual Studio 2022 Community Edition**:
   - Download it from the [official Visual Studio website](https://visualstudio.microsoft.com/).
   - During installation, select the following workload:
     - **Desktop development with C++**
   - Ensure the following components are installed:
     - MSVC compiler tools.
     - C++ CMake tools (optional but recommended for advanced builds).
2. **Basic C++ Knowledge**:
   - Understanding of object-oriented programming is helpful.

## How to Run the Project

1. **Clone the Repository**:
   ```bash
   git clone <repository_url>
   cd <repository_folder>
   ```

2. **Open the Project in Visual Studio**:
   - Launch Visual Studio 2022.
   - Go to **File > Open > Folder** and select the project folder.

3. **Build the Project**:
   - Press `Ctrl + Shift + B` or navigate to **Build > Build Solution**.

4. **Run the Application**:
   - Press `F5` to execute the program in Debug mode.
   - Follow the on-screen instructions to interact with the quiz system.

## Project Structure

The project is organized into the following components:

```
.
├── src/
│   ├── main.cpp                # Entry point for the application
│   ├── Question.cpp            # Base class implementation
│   ├── Question.h              # Base class header
│   ├── YesNoQuestion.cpp       # Yes/No question implementation
│   ├── YesNoQuestion.h         # Yes/No question header
│   ├── DirectAnswerQuestion.cpp# Direct answer question implementation
│   ├── DirectAnswerQuestion.h  # Direct answer question header
│   ├── MultipleChoiceQuestion.cpp # Multiple choice question implementation
│   ├── MultipleChoiceQuestion.h   # Multiple choice question header
│   ├── Player.cpp              # Player class implementation
│   ├── Player.h                # Player class header
│   ├── Leaderboard.cpp         # Leaderboard implementation
│   ├── Leaderboard.h           # Leaderboard header
│   ├── Quiz.cpp                # Core quiz logic
│   ├── Quiz.h                  # Quiz header
│   ├── QuizHandler.cpp         # Quiz management implementation
│   ├── QuizHandler.h           # Quiz management header
└── UML Diagram/
    └── class_diagram.jpg       # UML representation of the system
```

## UML Diagram

A UML diagram is included to illustrate the relationships between classes and their interactions. You can find it in the `UML Diagram` folder or view it below:

(Attach or reference the UML diagram image here if available.)

## Contribution Guidelines

We welcome contributions to this project. To contribute:

1. **Fork the repository**.
2. **Create a feature branch**:
   ```bash
   git checkout -b feature/your-feature-name
   ```
3. **Commit your changes and push to your fork**.
4. **Open a pull request** and describe your changes.

## License

This project is licensed under the **MIT License**. You are free to use, modify, and distribute the code as long as you retain the original license.
