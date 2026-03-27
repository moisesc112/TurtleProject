# The Long Crawl (Unreal Engine 5)

A real-time gameplay prototype built in Unreal Engine 5 using a hybrid C++ and Blueprint architecture.  
The project focuses on performance-conscious gameplay systems, modular design, and real-time AI behavior.

---

## Overview

In this prototype, the player controls a turtle navigating a hazardous environment while managing stamina, avoiding predators, and reacting to dynamic threats.

The project emphasizes:
- Real-time system design
- Gameplay architecture in Unreal Engine
- Performance and scalability considerations

---

## Core Features

### Gameplay Systems
- Custom movement system with stamina mechanics implemented in C++
- Slope-aware movement affecting speed and stamina drain
- Modular component-based design for extensibility

### AI Behavior
- Enemy types: birds (aerial threats) and crabs (ground threats)
- Event-driven AI interactions (trigger-based engagement, attack behavior)
- State-based logic for patrol, chase, and attack behaviors

### Architecture
- Hybrid C++ and Blueprint workflow:
  - C++ for performance-critical systems
  - Blueprints for orchestration and iteration
- Use of reusable components and interfaces to decouple gameplay systems

### Performance
- Designed systems with real-time constraints in mind
- Minimized per-frame computation in gameplay loops
- Structured update logic to scale with additional entities
