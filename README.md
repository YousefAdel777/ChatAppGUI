# ChatAppGUI

A desktop chat application GUI implemented in C++ using Qt.  
This project demonstrates core chat functionality with a modern Qt-based interface: multiple chat rooms, message routing, file transfer, and voice recording features — built as a learning/demo application and for coursework.

---

## Table of Contents
- [Features](#features)
- [Tech Stack](#tech-stack)
- [Prerequisites](#prerequisites)
- [Build & Run](#build--run)
  - [Open in Qt Creator (recommended)](#open-in-qt-creator-recommended)
  - [Build with qmake](#build-with-qmake)
  - [Build with CMake](#build-with-cmake)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [Contact](#contact)
- [Acknowledgements](#acknowledgements)

---

## Features

- Modern Qt GUI (chat windows, conversation list, message bubbles)  
- Multiple chat rooms / channels  
- Room creation and management UI  
- Message routing and local message history  
- File transfer (attach and send files)  
- Voice recording and playback (basic audio capture)  
- Basic user presence / status indicators  
- Clean, modular code intended for learning and extension  

> Note: This is a demo/learning project. Networking (peer-to-peer or client/server) and authentication can be added/extended easily; see the contributing ideas below.

---

## Tech Stack

- **Language:** C++  
- **GUI toolkit:** Qt (Qt 5.12+ or Qt 6)  
- **Build:** qmake or CMake  
- **Audio:** Qt Multimedia (QAudioInput / QAudioOutput)  
- **Version control:** git

---

## Prerequisites

Make sure you have the following installed:

- Qt (Qt 5.12+ or Qt 6) — Qt Creator recommended  
- C++ compiler:
  - Linux: `g++` / `clang++`
  - Windows: MSVC (Visual Studio) or MinGW
  - macOS: Xcode toolchain
- CMake >= 3.10 (if using CMake)
- qmake (if building with qmake)
- Optional: `pkg-config`, `pulseaudio` development headers (Linux) for audio troubleshooting

**Ubuntu / Debian example**
```bash
sudo apt update
sudo apt install build-essential qtbase5-dev qttools5-dev-tools qtmultimedia5-dev cmake git
```

**Windows**
- Install Qt via the online installer and choose an MSVC or MinGW kit.
- Open the project in Qt Creator (recommended) or use CMake from the Visual Studio developer command prompt.

**macOS**
- Install Qt via the official installer or Homebrew (careful with versions).
- Install Xcode command line tools: `xcode-select --install`.

---

## Build & Run

### Open in Qt Creator (recommended)
1. Open Qt Creator.
2. File → Open File or Project → select `ChatAppGUI.pro` (if present) or `CMakeLists.txt`.
3. Configure the build kit (select a Qt version and compiler).
4. Build and Run from the Qt Creator interface.

### Build with qmake
If a `.pro` file exists:
```bash
qmake ChatAppGUI.pro
make            # or mingw32-make on Windows with MinGW
./ChatAppGUI    # executable name may vary
```

### Build with CMake
If `CMakeLists.txt` is present:
```bash
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --parallel
# run the produced executable (name depends on target)
./ChatAppGUI
```

**Windows (Visual Studio generator)**
```powershell
mkdir build; cd build
cmake .. -G "Visual Studio 17 2022" -A x64
cmake --build . --config Release
# run the exe inside Release or Debug folder
```

---

## Usage

1. Launch the application (from Qt Creator or the built binary).  
2. Create a new chat room or join an existing one using the UI.  
3. Type messages in the input box and press Enter / Send.  
4. Attach files via the attach button; files will appear in the conversation history.  
5. Record a voice clip using the microphone/record button; record and play back in the conversation.  
6. Check the user list/presence panel for active participants.

> If the repository does not include real networking, the UI demonstrates local message routing and room management only.

---

## Project Structure

A suggested layout — adapt to your repo’s actual tree:

```
ChatAppGUI/
├── assets/                 # screenshots, icons, sample audio
├── src/
│   ├── main.cpp
│   ├── AppWindow.*         # main window
│   ├── ChatManager.*       # manages rooms, messages
│   ├── MessageModel.*      # model for messages
│   ├── Network/            # optional: network client/server code
│   ├── Audio/              # audio capture & playback logic
│   └── ui/                 # .ui files and custom widgets
├── CMakeLists.txt
├── ChatAppGUI.pro
├── README.md
└── LICENSE
```

---


## Contributing

Contributions are welcome. Steps:

1. Fork the repository.  
2. Create a feature branch:
   ```bash
   git checkout -b feat/my-feature
   ```
3. Implement changes and add tests when possible.  
4. Commit, push, and open a Pull Request with a clear description.

**Ideas for contributions**
- Add a client-server backend (WebSocket, TCP) and a reference server.  
- Persist chat history to SQLite.  
- Add user authentication and profiles.  
- Integrate end-to-end encryption (libsodium).  
- Improve UI (emoji picker, reactions, typing indicators).  
- Add automated tests and CI.

---

## Contact

Mohamed Ramadan — mohamed.ramadan.abd.alfatah@gmail.com  
GitHub: https://github.com/Mohamed-Ramadan-2005

---

## Acknowledgements

- Built with Qt — https://www.qt.io  
- Qt documentation and community examples for UI patterns, audio, and networking.
