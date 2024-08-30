### CCOM 3033 - Lab 01


To use the fmt library:
* `conda install -c conda-forge fmt`
* Compile using: `g++ -std=c++17 -o ex001 ex001.cpp -lfmt -L/opt/conda/lib -I/opt/conda/include`
* export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/conda/lib
* 