# TowerClimber

An early C++17/SFML game experiment with the beginnings of a labyrinth data model. The current application opens an empty 1920 × 1080 window, caps rendering at 144 frames per second, and handles closing the window. There is no playable tower-climbing game yet.

## Current implementation

- `src/main.cpp` contains the SFML window and event loop.
- `src/backend/labyrinth/Labcell.h` declares four private wall flags; there is no public cell interface yet.
- `src/backend/labyrinth/Labgen.h` and `Labgen.cpp` declare a generator and allocate a two-dimensional cell vector. The seed is unused, no passages are carved, and the generator is not connected to the application.
- `CMakeLists.txt` builds the `main` executable and fetches SFML from its `2.6.x` branch.
- `.github/workflows/ci.yml` contains an inherited cross-platform build matrix.

## Build status and prerequisites

The source needs small repairs before a portable build can be expected:

1. Match the source paths in `CMakeLists.txt` to the tracked names `Labgen.cpp`, `Labgen.h`, `Labcell.cpp`, and `Labcell.h`. Their current lowercase spellings fail on case-sensitive filesystems.
2. Include `<tuple>` where the generator uses `std::tuple` and `std::get`.
3. Give `Labgen::Generate` a defined return value or change its return type; it currently declares `int` and falls through without returning.

Use CMake 3.28 or newer, Git, and a C++17 compiler. Initial configuration needs network access to fetch SFML. SFML's system dependencies are also required; the original template lists these packages for Debian/Ubuntu:

```sh
sudo apt update
sudo apt install libxrandr-dev libxcursor-dev libudev-dev libfreetype-dev libopenal-dev libflac-dev libvorbis-dev libgl1-mesa-dev libegl1-mesa-dev
```

After addressing the source issues, the intended commands from the repository root are:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

For a single-configuration generator, run `./build/bin/main` on Linux/macOS or `./build/bin/main.exe` on Windows. Visual Studio generators normally place the executable at `build/bin/Release/main.exe`. A graphical desktop is required.

Use a new `build` directory rather than the committed `cmake-build-debug` cache and binaries, which belong to an earlier local environment. SFML's branch reference is not an immutable dependency pin.

## Development limits

There are no gameplay controls, rendered level, player, collision system, or completed maze-generation algorithm. Repeated generator calls also append to existing storage rather than rebuilding a clean grid. No automated test target is defined; the CI workflow configures and compiles only. Once the source builds, opening and closing the empty window is the available manual smoke check.

## Origin and license

The project started from [SFML's CMake project template](https://github.com/SFML/cmake-sfml-project), through the `Lorekp/sfml-cmake-template` template repository. The labyrinth scaffolding is the project-specific addition; SFML and the inherited build setup are upstream work.

The repository retains the template's dual public-domain/MIT terms in [LICENSE.md](LICENSE.md), including Copyright (c) 2022 Lukas Dürrenberger. Preserve that notice when redistributing applicable code. SFML is a separate dependency with its own license.
