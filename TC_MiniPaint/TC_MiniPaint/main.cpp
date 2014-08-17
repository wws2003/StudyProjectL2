//
//  main.cpp
//  TC_MiniPaint
//
//  Created by wws2003 on 8/16/14.
//  Copyright (c) 2014 wws2003. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <climits>

void initProblem(const char* lineStrs[], int**& problem, int numberOfRow, int numberOfColumn);

int calculateMinMispainted(int** problem, int numberOfRow, int numberOfColumn, int maxStroke);

void calculateMinMispaintedVectorForRow(int* row, int size, int* mispaintedVector);
void calculateBaseSubMispaintedTable(int* row, int size, int*** subMispaintedTable);

int calculateMinMispaintedFromMispaintedTable(int** mispaintedTable, int numberOfRow, int numberOfColumn, int maxStroke);
void calculateGTableBaseValues(int*** g, int** mispaintedTable, int numberOfRow, int numberOfColumn, int maxStroke);

int*** create3DTable(int numberOfLayer, int numberOfRow, int numberOfColumn);
void release3DTable(int*** table, int numberOfLayer, int numberOfRow);

int** createTable(int numberOfRow, int numberOfColumn);
void releaseTable(int** table, int numberOfRow);

#define min(x,y) (x < y) ? x : y
#define max(x,y) (x > y) ? x : y

#if DEBUG
#define PRINT_TABLE(table, numberOfRow, numberOfColumn) print(table, numberOfRow, numberOfColumn)
void print(int** table, int numberOfRow, int numberOfColumn);
#else
#define PRINT_TABLE(table, numberOfRow, numberOfColumn)
#endif

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    const char* lineStrs[] = {
        "BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
        "BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
        "BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
        "BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
        "BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW",
        "BWBWBWBWBWBWBWBWBWBWBWBWBWBWBW"};
    
    int** problem = NULL;
    int numberOfRow = sizeof(lineStrs) / sizeof(char*);
    int numberOfColumn = (int)strlen(lineStrs[0]);
    
    initProblem(lineStrs, problem, numberOfRow, numberOfColumn);
    
    int maxStroke = 100;
    
    int minMispainted = calculateMinMispainted(problem, numberOfRow, numberOfColumn, maxStroke);
    
    std::cout << "Min mispainted = " << minMispainted << std::endl;
    return 0;
}

void initProblem(const char* lineStrs[], int**& problem, int numberOfRow, int numberOfColumn) {
    problem = createTable(numberOfRow, numberOfColumn);
    
    for (int i = 0; i < numberOfRow; i++) {
        for (int j = 0; j < numberOfColumn; j++) {
            if (lineStrs[i][j] == 'B') {
                problem[i][j] = 0;
            }
            else {
                problem[i][j] = 1;
            }
        }
    }
}

int calculateMinMispainted(int** problem, int numberOfRow, int numberOfColumn, int maxStroke) {
    int **mispaintedTable = createTable(numberOfRow, numberOfColumn + 1);
    for (int i = 0; i < numberOfRow; i++) {
        int* row = problem[i];
        calculateMinMispaintedVectorForRow(row, numberOfColumn, mispaintedTable[i]);
    }
    
    int minMispainted = calculateMinMispaintedFromMispaintedTable(mispaintedTable, numberOfRow, numberOfColumn, maxStroke);
    
    releaseTable(mispaintedTable, numberOfRow);
    
    return minMispainted;
}

void calculateMinMispaintedVectorForRow(int* row, int size, int* mispaintedVector) {
    int*** subMispaintedTable = create3DTable(size + 1, size, size);
    
    calculateBaseSubMispaintedTable(row, size, subMispaintedTable);
    
    for (int stroke = 2; stroke <= size; stroke++) {
        for (int start = 0; start < size; start++) {
            for (int end = start + stroke - 1; end < size; end++) {
                int minMispainted = (stroke == size) ? 0 : size;
                for (int i = start + stroke - 1; i < end; i++) {
                    int tempMisPainted = subMispaintedTable[stroke - 1] [start][i]+ subMispaintedTable[1][i + 1][end];
                    minMispainted = min(minMispainted, tempMisPainted);
                    assert(minMispainted >= 0);
                }
                subMispaintedTable[stroke][start][end] = minMispainted;
            }
        }
    }
    
    for (int stroke = 0; stroke <= size; stroke++) {
        mispaintedVector[stroke] = subMispaintedTable[stroke][0][size - 1];
        assert(mispaintedVector[stroke] >= 0);
    }
    
    release3DTable(subMispaintedTable, size + 1, size);
}

void calculateBaseSubMispaintedTable(int* row, int size, int*** subMispaintedTable) {
    for (int start = 0; start < size; start++) {
        int painted0 = 0;
        int painted1 = 0;
        for (int end = start; end < size; end++) {
            subMispaintedTable[0][start][end] = end - start + 1;
            if (row[end] == 0) {
                painted0++;
            }
            else {
                painted1++;
            }
            subMispaintedTable[1][start][end] = min(painted0, painted1);
        }
    }
}

int calculateMinMispaintedFromMispaintedTable(int** mispaintedTable, int numberOfRow, int numberOfColumn, int maxStroke) {
    PRINT_TABLE(mispaintedTable, numberOfRow, numberOfColumn + 1);
    
    int*** g = create3DTable(maxStroke + 1, numberOfRow, numberOfRow);
    
    calculateGTableBaseValues(g, mispaintedTable, numberOfRow, numberOfColumn, maxStroke);

    for (int stroke = 2; stroke <= maxStroke; stroke++) {
        for (int start = 0; start < numberOfRow; start++) {
            //TODO Consider the value of end respecting stroke
            int rowGap = max(1, stroke / numberOfColumn);
            for (int end = start + rowGap; end < numberOfRow; end++) {
               int minMisPainted = min(g[stroke][start][start] + g[0][start + 1][end], g[0][start][end - 1] + g[stroke][end][end]);
                
               for (int l = start + rowGap; l < end; l++) {
                   int leftMispainted = g[stroke - 1][start][l] + g[1][l + 1][end];
                   int rightMispainted = g[1][start][l] + g[stroke - 1][l + 1][end];
                   int tempMisPainted = min(leftMispainted, rightMispainted);
                   minMisPainted = min(minMisPainted, tempMisPainted);
                }
                
                if (minMisPainted > g[stroke - 1][start][end]) {
                    int d = 2222;
                }
                g[stroke][start][end] = minMisPainted;
            }
        }
    }
    
    for (int stroke = 0; stroke <= maxStroke; stroke++) {
        PRINT_TABLE(g[stroke], numberOfRow, numberOfRow);
    }

    int ret = g[maxStroke][0][numberOfRow - 1];
    
    release3DTable(g, maxStroke + 1, numberOfRow);
    return ret;
}

void calculateGTableBaseValues(int*** g, int** mispaintedTable, int numberOfRow, int numberOfColumn, int maxStroke) {
    for (int stroke = 0; stroke <= maxStroke; stroke++) {
        for (int row = 0; row < numberOfRow; row++) {
            g[stroke][row][row] = (stroke <= numberOfColumn) ? mispaintedTable[row][stroke] : INT32_MAX;
        }
    }
    
    for (int start = 0; start < numberOfRow; start++) {
        for (int end = start + 1; end < numberOfRow; end++) {
            g[0][start][end] = (end - start + 1) * numberOfColumn;
        }
    }
    
    if (maxStroke >= 1) {
        for (int start = 0; start < numberOfRow; start++) {
            int minMispainted = mispaintedTable[start][1];
            for (int end = start + 1; end < numberOfRow; end++) {
                int mispainted = mispaintedTable[end][1];
                minMispainted = min(minMispainted, mispainted);
                g[1][start][end] = minMispainted + (end - start) * numberOfColumn;
            }
        }
    }
}

int*** create3DTable(int numberOfLayer, int numberOfRow, int numberOfColumn) {
    int*** table3D = (int***)malloc(sizeof(int**) * numberOfLayer);
    for (int i = 0; i < numberOfLayer; i++) {
        table3D[i] = createTable(numberOfRow, numberOfColumn);
    }
    return table3D;
}

void release3DTable(int*** table, int numberOfLayer, int numberOfRow) {
    for (int i = 0; i < numberOfLayer; i++) {
        releaseTable(table[i], numberOfRow);
    }
    free(table);
}

int** createTable(int numberOfRow, int numberOfColumn) {
    int **table = (int**)malloc(sizeof(int*) * numberOfRow);
    for (int i = 0; i < numberOfRow; i++) {
        table[i] = (int*)malloc(sizeof(int) * numberOfColumn);
    }
    return table;
}

void releaseTable(int** table, int numberOfRow) {
    for (int i = 0; i < numberOfRow; i++) {
        free(table[i]);
    }
    free(table);
}

#if DEBUG
void print(int** table, int numberOfRow, int numberOfColumn) {
    std::cout << "Table content " << numberOfRow << " x " << numberOfColumn << "\n";
    for (int i = 0; i < numberOfRow; i++) {
        for (int j = 0; j < numberOfColumn; j++) {
            std::cout << table[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
#endif