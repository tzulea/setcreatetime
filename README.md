# setcreatetime osx
set osx create time for file or folders

This utility function sets create time in OSX for a specific file or folder
Run: setcreatetime -p your_path -t YYYYMMDDHH

This utility function does not depened on additional libraries and can be used standalone.

No need to download xcode comand line tools.

# Run published releas
1. Download the exectuable file: https://github.com/tzulea/setcreatetime/releases/download/first/setcreatetime
2. open terminal on osx
3. go to the downloaded file
4. run following comand: ./setcreatetime -p your_path -t YYYYMMDDHH

example: ./setcreatetime -p /Users/squirrel/Downloads/time -t 2002030308

# Build
1. clone repo
2. go to source files
3. create a folder build and enter
4. run cmake ..
5. run cmake --build .
