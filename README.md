# Poker Tournament Management System

A comprehensive tournament management system for national poker tournaments, developed as part of Programming III coursework. The system models a round-robin tournament where every player plays against every other player, with the winner being the player who wins the most matches.

## 🎮 Demo

![Tournament Demo](docs/images/demo.gif)
*Complete tournament workflow: player registration, match recording, and results*

## 🎯 Features

- **Player Registration**: Register tournament participants with complete profile information
- **Match Recording**: Log matches in chronological order with automatic statistics updates
- **Tournament Status**: Track tournament progress and determine when complete
- **Player Statistics**: Maintain win/loss records and participation history
- **Subdivision Analysis**: Determine if two players belong to the same tournament subdivision
- **Winner Identification**: Automatically identify tournament winners

## 🏗️ Architecture

### Graph-Based Modeling
The system uses **graph theory** as its conceptual foundation:
- **Vertices**: Represent tournament players
- **Edges**: Represent matches played between players
- **Complete Graph**: Tournament concludes when all players have played each other

### Key Data Structures
- **Hash Table**: Optimized player lookup by ID number (O(1) average)
- **Adjacency Matrix**: Efficient match relationship storage for dense graphs
- **Linked List**: Chronological match history with FIFO ordering

## 🛠️ Technical Implementation

### Core Modules
- **Player Management**: Player registration, data management, and statistics
- **Match System**: Match recording and validation
- **Tournament Engine**: Graph-based tournament state management
- **Query System**: Advanced tournament analysis and reporting

### Data Types (TADs)
- `Jugadores`: Hash table for player storage and retrieval
- `Torneo`: Adjacency matrix representing match relationships
- `PartidasJugadas`: Sequential list of completed matches
- `Jugador`: Player entity with complete profile and statistics
- `Partida`: Match entity with participants and results

## 🚀 Getting Started

### Prerequisites
- C++ compiler (GCC recommended)
- Make build system

### Compilation
```bash
make all
```

### Running the System
```bash
./tournament
```

### Configuration
To modify the maximum number of players, update these constants:
- `B` in `include/Jugadores.h` (hash table size)
- `N` in `include/Torneo.h` (tournament matrix size)

**Note**: Currently set to 3 players for quick testing.

## 📊 System Operations

### 1. Player Management
- Register new tournament participants
- View all registered players
- Display individual player statistics and match history

### 2. Match Management
- Record matches between registered players
- Automatic validation (no duplicate matches)
- View complete match history

### 3. Tournament Analysis
- Check if two players are in the same subdivision (graph connectivity)
- Determine tournament completion status
- Identify tournament winners

### 4. Statistical Queries
- Player birth date analysis
- Win/loss statistics
- Tournament progress tracking

## 🔧 System Design

### Graph Theory Application
The tournament structure leverages graph algorithms:
- **Connectivity Analysis**: DFS traversal to determine player subdivisions
- **Completeness Check**: Matrix analysis to verify all matches played
- **Efficient Queries**: O(1) edge existence checking

### Performance Optimizations
- **Hash-based Player Lookup**: Average O(1) player retrieval
- **Matrix-based Match Storage**: O(1) match existence verification
- **Sequential Match History**: Preserves chronological order

## 📁 Project Structure

```
include/           # Header files (.h)
├── Sistema.h     # Main system interface
├── Jugadores.h   # Player management
├── Torneo.h      # Tournament graph
├── Partida.h     # Match representation
└── ...

src/              # Implementation files (.cpp)
├── main.cpp      # Application entry point
├── Sistema.cpp   # Core system logic
├── Jugadores.cpp # Player operations
└── ...
```

## 🎮 User Interface

The system provides an interactive console menu with the following options:
1. Register new player
2. List all players
3. Display player details by ID
4. Record match between players
5. List all matches
6. Analyze players by birth date
7. Check if players are in same subdivision
8. View tournament completion status and winners

## ⚡ Key Algorithms

### Subdivision Detection
Uses Depth-First Search (DFS) to determine if two players belong to the same connected component in the tournament graph.

### Tournament Completion
Verifies that the adjacency matrix represents a complete graph by checking all possible player pairs have corresponding matches.

### Winner Determination
Identifies players with the maximum number of wins across the entire tournament.

## 📋 System Requirements

- **Memory Management**: Dynamic allocation for scalable data structures
- **Input Validation**: Comprehensive validation for all user inputs
- **Error Handling**: Robust error detection and user feedback
- **Data Integrity**: Prevents duplicate matches and invalid operations

## 👥 Authors

- **Valdo Castiglia**
- **Shoan Genes**

**Course**: Programming III  
**Professor**: Joel Estramil  
**Institution**: [University Name]

## 📄 License

This project is developed for academic purposes as part of university coursework.

---

*This system demonstrates practical application of data structures, graph theory, and software engineering principles in tournament management.*