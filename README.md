# Exis Project
Shy try for a modern Operating System.

!2021 notes:
!stop trying to make the perfect kernel and operation system, maybe its not possible? :/ we dont have infinity time to think and code. thx to myself.

# Design Goals (Concepts)
- Portable (meant both, new arch portability, and capability to run from any entity)
- Secure
- Peek performance (both native, and any JIT / emulation)
- Generalized interfaces and IT protocols
- Component based build system
- Prepared for future data management

# UI (HumanFlowUI)
- Independent UI system from the application source
- Cross platform / arch
- The ability to develop the UI framework without touching the app logic sources
- Backward and forward compatibility?

# Source Directory Description
## Boot
- UEFI bootloader sources, any other boot manager for Exis
## Build
- Build system scripts and utilities
## Docs
- Documentation
## Source
- OS source code organized in execution privilege (rings) / API level / module hierarchy

# Developers
Tibor P., sumib96, (c) 2019 - 2020
Execution Interface System
