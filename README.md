# EmbeddedIntentRecognizer

The project recognises predefined ententes from predefined questions.

Install cmake on Linux

```sh
apt-get install cmake
```

Install cmake on Macintosh

```sh
brew install cmake
```

Install cmake on Windows
Follow the link (https://cmake.org/download/)

Creating the build directory

```sh
mkdir build
cd build
```

Building the project.

```sh
cmake .. -G "Unix Makefiles"
cmake --build .
```

Running the Command line interface.

```sh
cd cli/intent_recognizer/
./IntentRecognizer data/state_machine_decription.csv "what is the weather like today"
```

Running the google test (inside the build folder)

```sh
ctest
```

Running the specific google test (inside the build folder)

```sh
cd test/state_machine
./StateMachineTests
```

or

```sh
cd test/state_machine_generator
./StateMachineGeneratorTests
```
